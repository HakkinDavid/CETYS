#include <iostream>
#include <vector>
#include <algorithm>

struct job {
    int duration;
    int profit;
    int deadline;
    bool done = false;
};

bool compare_deadlines (const job& a, const job& b) {
    return a.deadline < b.deadline;
}

int coins[] = {1, 2, 5, 10, 20, 100};
int n_coins = sizeof(coins) / sizeof(coins[0]);
int llamadas_brutas = 0;

void max_sum () {
    std::vector<int> S, Z, Zt, snake_sum;
    int n, m, snake_sum_total;
    std::cout << "Tamaño de S: ";
    std::cin >> n;
    std::cout << "S tendrá un tamaño de " << n << ". Proporcione a continuación los elementos." << std::endl;
    S.reserve(n);
    for (int i = 0; i < n; i++) {
        std::cout << "S[" << i << "] = ";
        std::cin >> S[i];
    }
    std::cout << "Número de sumandos (m): ";
    std::cin >> m;
    std::cout << "Encontrando la máxima suma Z por fuerza bruta en " << m << " elementos de S." << std::endl;
    Z.reserve(m + 1);
    const int max_index = n-m+1;
    for (int i = 0; i < max_index; i++) {
        Zt.clear();
        Zt.reserve(m + 1);
        Zt[m] = 0;
        std::cout << "\t";
        for (int j = 0; j < m; j++) {
            Zt[j] = S[i+j];
            std::cout << Zt[j] << (j == m-1 ? " = " : " + ");
            Zt[m] += Zt[j];
        }
        std::cout << Zt[m] << std::endl;
        if (Zt[m] > Z[m]) Z = Zt;
    }
    std::cout << "\tLa máxima suma es " << Z[m] << " con los elementos: ";
    for (int i = 0; i < m; i++) {
        std::cout << Z[i] << (i == m-1 ? "." : ", ");
    }
    std::cout << std::endl;

    Z.clear();

    std::cout << "Encontrando la máxima suma Z por programación dinámica en " << m << " elementos de S." << std::endl;
    snake_sum.reserve(m + 1);
    for (int i = 0; i < n; i++) {
        snake_sum.push_back(S[i]);
        snake_sum_total += S[i];
        if (snake_sum.size() == m + 1) {
            snake_sum_total -= snake_sum[0];
            snake_sum.erase(snake_sum.begin());
        }
        if (snake_sum_total > Z[m]) {
            Z = snake_sum;
            Z[m] = snake_sum_total;
        }
    }

    std::cout << "\tLa máxima suma es " << Z[m] << " con los elementos: ";
    for (int i = 0; i < m; i++) {
        std::cout << Z[i] << (i == m-1 ? "." : ", ");
    }
    std::cout << std::endl;
}

void max_profit () {
    int time = 0;
    std::vector<job> jobs = {
        {3, 120, 7},
        {5, 180, 9},
        {2, 90, 6},
        {4, 150, 10},
        {7, 200, 12},
        {1, 70, 3},
        {6, 170, 11},
        {3, 100, 8},
        {4, 130, 5},
        {2, 80, 4},
        {5, 190, 15},
        {3, 110, 13},
        {6, 150, 10},
        {4, 160, 8},
        {2, 100, 6},
        {3, 120, 9},
        {1, 50, 2},
        {4, 140, 7},
        {7, 180, 11},
        {2, 60, 4}
    };

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), compare_deadlines); // O(nlogn)

    std::vector<job> brute_force_jobs = jobs;
    
    std::vector<int> memory(n+1, 0);
    for (int j = 1; j <= n; ++j) {
        // Si no se hace el trabajo, la ganancia es la misma que la anterior (no existe penalización)
        memory[j] = memory[j-1];
        // Buscamos el trabajo inmediatamente próximo al actual
        int index = lower_bound(jobs.begin(), jobs.end(), jobs[j-1], compare_deadlines) - jobs.begin();
        // Calculamos la ganancia total si realizamos el trabajo j
        int total_profit = memory[index] + jobs[j-1].profit;
        // Actualizamos la ganancia máxima si es beneficioso realizar el trabajo j
        if (total_profit > memory[j]) {
            jobs[j-1].done = true;
            memory[j] = total_profit;
        }
    }

    std::cout << "La ganancia de los trabajos según la estrategia de la programación dinámica es " << memory[n] << std::endl;

    int brute_profit = 0;

    for (int i = 0; i < n; i++) {
        if (brute_force_jobs[i].deadline >= time + brute_force_jobs[i].duration) {
            time += brute_force_jobs[i].duration;
            brute_force_jobs[i].done = true;
            brute_profit += brute_force_jobs[i].profit;
        }
    }

    std::cout << "La ganancia de los trabajos según la estrategia de la fuerza bruta es " << brute_profit << std::endl;
}

int min_coin_brute (int C) {
    llamadas_brutas++;
    if (C <= 0) return 0; // Para obtener 0 no se necesitan monedas

    int result = INT_MAX;

    for (int i = n_coins-1; i >= 0; i--) {
        if (coins[i] <= C) {
            int previous_result = min_coin_brute(C - coins[i]); // Averiguar el mínimo para el restante del dinero
            if (previous_result != INT_MAX && previous_result + 1 < result) { // Si encontramos una cantidad, asegurarse de que la nueva propuesta sea inferior
                result = previous_result + 1; // Sumar la cantidad de monedas e incrementar en uno
            }
        }
    }

    return result;
};

void min_coin (int C) {
    std::vector<int> memory(C+1, INT_MAX); // Almacenar los cálculos intermedios

    memory[0] = 0; // Para obtener 0 no se necesitan monedas

    for (int i = 1; i <= C; i++) {
        for (int j = 0; j < n_coins; j++) {
            if (coins[j] <= i) {
                int previous_result = memory[i - coins[j]];
                if (previous_result != INT_MAX && previous_result + 1 < memory[i]) { // Si encontramos una cantidad, asegurarse de que la nueva propuesta sea inferior
                    memory[i] = previous_result + 1; // Sumar la cantidad de monedas e incrementar en uno
                }
            }
        }
    }
    
    std::cout << "Según la programación dinámica implementada, el mínimo de monedas necesario para obtener $" << C << " es " << memory[C] << "." << std::endl;

    std::cout << "Según la programación por fuerza bruta implementada, el mínimo de monedas necesario para obtener $" << C << " es " << min_coin_brute(C) << ", con " << llamadas_brutas << " llamadas a función." << std::endl;
    
}

void minimal_difference_subset() {
    int S [] = {3,2,7,9,2};
    int n = sizeof(S)/sizeof(S[0]);
    int add_total = 0; // Almacenar el total en S (S1 y S2 no pueden tener más que esto por sí solos ni en conjunto)
    for (int i = 0; i < n; ++i) {
        add_total += S[i];
    }

    // Matriz para determinar y recordar si se puede generar una suma j (desde 0 hasta add_total) en los primeros i elementos
    std::vector<std::vector<bool>> memory
        (n + 1, std::vector<bool>
            (add_total + 1, false)
        );

    // Inicializamos la primera columna como verdadera, ya que siempre se podrá obtener una suma con 0 para cualquier i
    for (int i = 0; i <= n; ++i) {
        memory[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= add_total; ++j) {
            if (S[i - 1] <= j) {
                memory[i][j] = memory[i - 1][j] || memory[i - 1][j - S[i - 1]]; // Establecer a alguna de estas sumas válidas (preferible distinto a 0)
            } else {
                memory[i][j] = memory[i - 1][j]; // Si el i-ésimo elemento es literalmente mayor a la suma, elegirlo
            }
        }
    }

    // Encontramos la mitad de la suma total para determinar el rango de búsqueda
    int half_total_addition = add_total / 2;

    // Encontramos la suma más grande menor o igual que half_total_addition que es posible obtener
    int first_addition = 0;
    for (int j = half_total_addition; j >= 0; --j) {
        if (memory[n][j]) {
            first_addition = j;
            break;
        }
    }

    // Calculamos la diferencia entre las dos sumas
    int second_addition = add_total - first_addition;
    int diff = abs(first_addition - second_addition);
    std::cout << "La diferencia mínima mediante programación dinámica es |" << first_addition << " - " << second_addition << "| = " << diff << std::endl;

    int brute_diff = INT_MAX;
    std::vector<int> s1(0,0), s2(0,0), s1t(0,0), s2t(0,0);
    int final_fsum = 0; int final_ssum = 0;

    // Iterar a través de todos los posibles subconjuntos
    for (int subset = 0; subset < (1 << n); ++subset) { // Generar un conjunto
        s1t.clear(); s2t.clear();
        int fsum = 0;
        for (int i = 0; i < n; ++i) {
            if (~subset & (1 << i)) {
                fsum += S[i]; // Si el elemento NO pertenece al conjunto, sumarlo
                s1t.push_back(S[i]);
            }
        }
        int ssum = 0;
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                ssum += S[i]; // Si el elemento SÍ pertenece al conjunto, sumarlo
                s2t.push_back(S[i]);
            }
        }

        // Actualizar la mínima diferencia
        int new_diff = abs(fsum-ssum);
        if (brute_diff > new_diff) {
            brute_diff = new_diff;
            s1 = s1t;
            s2 = s2t;
            final_fsum = fsum;
            final_ssum = ssum;
        }
    }

    std::cout << "La diferencia mínima mediante fuerza bruta es |" << final_fsum << " - " << final_ssum << "| = " << brute_diff << std::endl;

    std::cout << "S1: ";
    for (int i = 0; i < s1.size(); i++) {
        std::cout << s1.at(i) << (i == s1.size()-1 ? "." : ", ");
    }
    std::cout << std::endl;

    std::cout << "S2: ";
    for (int i = 0; i < s2.size(); i++) {
        std::cout << s2.at(i) << (i == s2.size()-1 ? "." : ", ");
    }
    std::cout << std::endl;
}

int main () {
    //max_sum (); // O(n*m) [fuerza bruta] vs O(n) [programación dinámica]
    max_profit (); // O(nlgn) [fuerza bruta] vs O(nlgn) [programación dinámica]
    min_coin (12); // O(n*2^n) [fuerza bruta] vs O(C*n) [programación dinámica] ... El programa tarda bastante alrededor de C >= 31 si se usa fuerza bruta.
    minimal_difference_subset();
}