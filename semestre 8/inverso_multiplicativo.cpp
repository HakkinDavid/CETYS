// use c++20 para compilar, profe. es que la librería ranges está padrísima.
#include <iostream>
#include <vector>
#include <tuple>
#include <ranges>
#include <algorithm>
using namespace std;

tuple<int, int, int> resolver(int v, const int A, const int B, vector<tuple<int, int, int, int>> &r_despejado, vector<int> &r_id, int profundidad = 0)
{
    tuple<int, int, int> ABc = {0, 0, 0};

    if (v == A)
    {
        std::get<0>(ABc)++;
    }
    else if (v == B)
    {
        std::get<1>(ABc)++;
    }
    else if (v == 0)
    {
        return ABc;
    }
    else
    {
        auto r_id_it = std::find(r_id.begin(), r_id.end(), v);
        if (r_id_it != r_id.end())
        {
            int r_id_idx = std::distance(r_id.begin(), r_id_it);

            tuple<int, int, int, int> &r_despejado_elemento = r_despejado.at(r_id_idx);

            cout << string(profundidad, '\t') << "[" << profundidad << "] Expandiendo " << v << " = " << std::get<1>(r_despejado_elemento) << " - " << std::get<2>(r_despejado_elemento) << " * " << std::get<3>(r_despejado_elemento) << endl;

            tuple<int, int, int> a = resolver(std::get<1>(r_despejado_elemento), A, B, r_despejado, r_id, profundidad + 1), b = resolver(std::get<3>(r_despejado_elemento), A, B, r_despejado, r_id, profundidad + 1);
            int q = std::get<2>(r_despejado_elemento);

            ABc = a;

            std::get<0>(b) *= q;
            std::get<1>(b) *= q;
            std::get<2>(b) *= q;

            std::get<0>(ABc) -= std::get<0>(b);
            std::get<1>(ABc) -= std::get<1>(b);
            std::get<2>(ABc) -= std::get<2>(b);

            cout << string(profundidad, '\t') << "[" << profundidad << "] Resuelto " << v << " = " << std::get<0>(ABc) << "A + " << std::get<1>(ABc) << "B + " << std::get<2>(ABc) << endl;
        }
        else
        {
            std::get<2>(ABc) = v;
        }
    }
    return ABc;
}

int main()
{
    int A, B;
    char canónico;
    cout << "¿A qué número buscaremos inverso multiplicativo?" << endl;
    cin >> A;
    cout << endl;
    cout << "¿Bajo qué módulo?" << endl;
    cin >> B;
    cout << endl;
    cout << "¿Utilizaremos representante canónico? [y/n]" << endl;
    cin >> canónico;
    cout << endl;

    if (canónico == 'y')
    {
        cout << endl
             << "Representante canónico" << endl
             << A << " mod " << B << " = " << A % B << endl
             << endl;
        A = A % B;
    }

    cout << "Operación de congruencia" << endl
         << A << "x ≡ 1\tmod " << B << endl
         << "gcd(" << A << ", " << B << ") = 1" << endl
         << A << "s + " << B << "t = 1" << endl
         << "A = " << A << ", B = " << B << endl
         << endl;

    vector<tuple<int, int, int, int>> r;
    int i = 0;

    {
        r.push_back({A, B, A / B, A % B});
        tuple<int, int, int, int> &actual = r.back();
        cout << "[" << i << "]  " << std::get<0>(actual) << " = " << std::get<1>(actual) << " * " << std::get<2>(actual) << " + " << std::get<3>(actual) << endl;
        i++;
    }

    do
    {
        tuple<int, int, int, int> &previo = r.back();
        r.push_back({std::get<1>(previo), std::get<3>(previo), std::get<1>(previo) / std::get<3>(previo), std::get<1>(previo) % std::get<3>(previo)});

        tuple<int, int, int, int> &actual = r.back();
        cout << "[" << i << "]  " << std::get<0>(actual) << " = " << std::get<1>(actual) << " * " << std::get<2>(actual) << " + " << std::get<3>(actual) << endl;

        i++;
    } while (std::get<3>(r.back()) > 0);

    r.pop_back();
    i--;

    if (std::get<3>(r.back()) != 1)
    {
        cout << "❌ No existe el inverso multiplicativo para " << A << " bajo módulo " << B << endl;
        return 0;
    }
    else
    {
        cout << "✅ Podemos proceder a despejar el inverso multiplicativo para " << A << " bajo módulo " << B << endl
             << endl;
    }

    vector<tuple<int, int, int, int>> r_despejado;
    vector<int> r_id;
    r_despejado.reserve(r.size());
    r_id.reserve(r.size());

    i = 0;

    cout << "Residuos despejados" << endl;
    for (tuple<int, int, int, int> ri : r | std::views::reverse)
    {
        r_despejado.push_back({std::get<3>(ri), std::get<0>(ri), std::get<2>(ri), std::get<1>(ri)}); // pareciera que se está riendo, puro ri ri ri ri
        r_id.push_back(std::get<3>(ri));

        tuple<int, int, int, int> &actual = r_despejado.back();
        cout << "[" << i << "]  " << std::get<0>(actual) << " = " << std::get<1>(actual) << " - " << std::get<2>(actual) << " * " << std::get<3>(actual) << endl;
        i++;
    }

    cout << "Sustituyendo residuos hacia atrás" << endl;

    tuple<int, int, int> sAtB = resolver(1, A, B, r_despejado, r_id);

    cout << endl;

    if (std::get<0>(sAtB) < 0)
    {
        cout << "Elegiremos el valor positivo más próximo para s y ajustaremos t (por identidades de Bézout)" << endl
             << std::get<0>(sAtB) << " + " << B << " = " << std::get<0>(sAtB) + B << " como s" << endl
             << std::get<1>(sAtB) << " - " << A << " = " << std::get<1>(sAtB) - A << " como t"
             << endl
             << endl;
        std::get<0>(sAtB) += B;
        std::get<1>(sAtB) -= A;
    }

    cout << "x = " << std::get<0>(sAtB) << endl
         << std::get<0>(sAtB) << " es el primer inverso multiplicativo positivo de " << A << " bajo módulo " << B << endl
         << endl;

    cout << "Podemos comprobar que " << std::get<0>(sAtB) << " * " << A << " + " << std::get<1>(sAtB) << " * " << B << " + " << std::get<2>(sAtB) << " = " << std::get<0>(sAtB) * A + std::get<1>(sAtB) * B + std::get<2>(sAtB) << endl;
}