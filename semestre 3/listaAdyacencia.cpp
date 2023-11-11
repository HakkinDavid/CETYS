/*
    nombre: Lista de adyacencia
    autor: David Emmanuel Santana Romero
    fecha: 27 de octubre de 2023, actualizado 31 de octubre de 2023
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// declarar la clase de lista de adyacencia
class AdjacencyList {
    private:
        // vector que almacena la lista
        vector<int>* A;
        // ¿es la lista de un solo sentido? (grafo dirigido)
        bool oneway;
        // número de nodos
        int nodes;
        // distancias
        int* distance;
        // tiempos
        int** time;
        // padres
        int* parent_BFS;
        int* parent_DFS;
        // enmascarar la etiqueta de nombre
        string* nickname;
        // color de los nodos
        int* color_BFS; // 0 = negro, 1 = gris, 2 = blanco
        int* color_DFS;
        // origen del último BFS ejecutado
        int BFS_source;
        // raíces de los árboles del bosque DFS || i es el árbol, [i] es la raíz
        int* DFS_sources;
        // tiempo de ejecución DFS
        int c_time;
        // índice actual en el bosque DFS
        int c_tree_index;
        // árboles a los que pertenecen los nodos
        int* DFS_tree;
        // nodos ordenados topológicamente
        int* TS;
        // índice en el stack de Topological Sort
        int TS_stack_i;
    public:
        // inicializar la clase
        // permitir al usuario definir el número de nodos
        // definir si la lista es de un solo sentido
        // definir los apodos para los nodos... internamente trabajaremos con índices de 0 a nodes
        AdjacencyList (int nodes = 0, bool oneway = false, initializer_list<string> nicknames = {}) {
            A = new vector<int>[nodes];
            distance = new int[nodes];
            parent_BFS = new int[nodes];
            color_BFS = new int[nodes];
            parent_DFS = new int[nodes];
            color_DFS = new int[nodes];
            nickname = new string[nodes];
            time = new int*[nodes];
            BFS_source = -1;
            DFS_sources = new int[nodes];
            DFS_tree = new int[nodes];
            TS = new int[nodes];
            for (int i = 0; i < nodes; i++) {
                nickname[i] = (i >= nicknames.size() ? to_string(i) : *(nicknames.begin() + i));
                time[i] = new int[2];
            }
            this->oneway = oneway;
            this->nodes = nodes;
            c_time = -1;
            c_tree_index = -1;
            TS_stack_i = -1;
        }
        // eliminar elementos de la lista
        // limpiar la memoria
        ~AdjacencyList () {
            for (int i = 0; i < nodes; i++) {
                A[i].clear();
                delete [] time[i];
            }
            delete [] A;
            delete [] distance;
            delete [] parent_BFS;
            delete [] parent_DFS;
            delete [] nickname;
            delete [] color_BFS;
            delete [] color_DFS;
            delete [] time;
            delete [] DFS_sources;
            delete [] DFS_tree;
            delete [] TS;
        }

        // enlazar un nodo a otro
        void link (int i, int j, bool nested = false) {
            // invalidar cálculos de BFS y DFS
            if (c_time != -1 || BFS_source != -1) {
                BFS_source = -1;
                c_time = -1;
            }
            // ¿están fuera del rango de operación?
            if (i >= nodes || j >= nodes || i < 0 || j < 0) {
                cout << "NODE OUT OF RANGE." << endl;
                return;
            }
            // ¿es la lista de un solo sentido?
            if (oneway && !A[j].empty()) {
                // buscar si el nodo ya se ha enlazado en el sentido opuesto
                for (int n = 0; n < A[j].size(); n++) {
                    if (A[j][n] == i) {
                        cout << "Cannot link nodes " << nickname[i] << "->" << nickname[j] << " since adjacency is set one-way." << endl;
                        return;
                    }
                }
            }

            // si el nodo tiene enlaces
            if (!A[i].empty()) {
                // revisar cada enlace
                for (int k = 0; k <= A[i].size(); k++) {
                    // no permitir valores repetidos
                    if (A[i][k] == j) {
                        cout << "Nodes " << nickname[i] << "->" << nickname[j] << " already linked" << endl;
                        return;
                    }
                    // introducir los valores ya ordenados
                    // si el elemento revisado actual es menor al que se busca insertar, continuar
                    if (A[i][k] < j && k+1 <= A[i].size()) {
                        continue;
                    }

                    // insertar
                    A[i].insert(A[i].begin() + k, j);

                    // si esta llamada a función no está dentro de otra y la lista no es de un solo sentido
                    // enlazar en el sentido opuesto
                    if (!oneway && !nested) link(j, i, true);
                    break;
                }
            }
            // si el nodo no tiene enlaces
            else {
                // simplemente insertar el enlace
                A[i].emplace_back(j);
                // si esta llamada a función no está dentro de otra y la lista no es de un solo sentido
                // enlazar en el sentido opuesto
                if (!nested && !oneway) link(j, i, true);
            }
        }

        // sobrecargar la función link para permitir múltiples enlaces por llamada
        void link (int i, initializer_list<int> j) {
            for (int n = 0; n < j.size(); n++) {
                link(i, *(j.begin() + n));
            }
        }

        // sobrecargar link para usar apodos
        void link (string i, string j) {
            link(unmask(i), unmask(j));
        }

        // sobrecargar link para usar múltiples apodos
        void link (string i, initializer_list<string> j) {
            for (int n = 0; n < j.size(); n++) {
                link(i, *(j.begin() + n));
            }
        }

        // imprimir la lista
        void print () {
            for (int i = 0; i < nodes; i++) {
                cout << nickname[i] << " -> ";
                for (int j = 0; j < A[i].size(); j++) {
                    cout << nickname[A[i][j]] << " -> ";
                }
                cout << "/" << endl;
            }
        }

        // convertir a un arreglo (matriz cuadrada) de 0 y 1
        int** toArray() {
            // definir el puntero a memoria con tamaño del total de nodos
            // es un arreglo de punteros a enteros
            int** alpha = new int*[nodes];
            for (int i = 0; i < nodes; i++) {
                // definir los punteros a memoria con tamaño del total de nodos
                // es un arreglo de enteros
                alpha[i] = new int[nodes];
                // inicializar en 0
                for (int j = 0; j < nodes; j++) {
                    alpha[i][j] = 0;
                }
            }

            // iterar en la lista
            for (int i = 0; i < nodes; i++) {
                for (int j = 0; j < A[i].size(); j++) {
                    // establecer la posición correspondiente en 1
                    alpha[i][A[i][j]] = 1;
                }
            }

            return alpha;
        }

        // imprimir como arreglo (arte ascii)
        void printAsArray () {
            int** LtoArr = toArray(); // obtener el arreglo
            
            // para cada fila del arreglo
            for (int i = 0; i < nodes; i++) {

                // imprimir el nombre
                cout << nickname[i];

                //averiguar si necesitamos espaciar desde el nombre para mantener la consistencia del arte
                for (int s = nodes; s / 10 > 0; s /= 10) {
                    cout << " ";
                }

                // para cada elemento
                for (int j = 0; j < nodes; j++) {
                    // si es 1, imprimir en blanco, sino en negro
                    cout << (LtoArr[i][j] ? "⬜" : "⬛");
                }
                cout << endl; // siguiente línea
                // liberar la memoria
                delete [] LtoArr[i];
            }
            // liberar el espacio asignado en memoria
            delete [] LtoArr;
        }

        // calcular breadth first search
        void BFS (int origin) {
            // ¿está fuera del rango de operación?
            if (origin >= nodes || origin < 0) {
                cout << "NODE OUT OF RANGE." << endl;
                return;
            }
            // establecer el origen de nuestra ejecución BFS
            BFS_source = origin;
            // inicializar la queue
            int q_i = 0;
            int q_j = 0;
            int* Q = new int [nodes];
            // restablecer color, distancia y jerarquía en todos los nodos
            for (int i = 0; i < nodes; i++) {
                color_BFS[i] = 2;
                distance[i] = INT_MAX;
                parent_BFS[i] = -1;
            }
            // inicializar el origen
            color_BFS[origin] = 1;
            distance[origin] = 0;
            parent_BFS[origin] = -1;
            // enqueue origen
            Q[q_j] = origin;
            q_j++;
            while (q_i < q_j) { // mientras la queue no está vacía
                // dequeue u
                int u = Q[q_i];
                q_i++;
                // para cada vecino ...
                for (int i = 0; i < A[u].size(); i++) {
                    int v = A[u][i];
                    // si el color es blanco
                    if (color_BFS[v] == 2) {
                        // colorear gris
                        color_BFS[v] = 1;
                        // establecer la distancia como la del padre (u) +1
                        distance[v] = distance[u] + 1;
                        // establecer el padre como u
                        parent_BFS[v] = u;
                        // enqueue v
                        Q[q_j] = v;
                        q_j++;
                    }
                }
                // colorear de negro
                color_BFS[u] = 0;
            }
            // eliminar la queue
            delete [] Q;
        }

        // sobrecargar BFS para permitir usar apodo
        void BFS (string origin) {
            BFS(unmask(origin));
        }

        // now ...
        // say my name.
        int unmask (string name) {
            for (int i = 0; i < nodes; i++) {
                if (nickname[i] == name) {
                    return i;
                }
            }
            // [name] ??? who's [name] ??? there is no [name] !!!
            cout << "There is no node called " << name << "." << endl;
            return -1;
        }

        // imprimir los resultados del BFS
        void printBFS () {
            // no hemos ejecutado BFS
            if (BFS_source == -1) {
                cout << "No previous execution of Breadth First Search found." << endl;
                return;
            }
            // traducir colores
            string color_names [3] = {"Negro", "Gris", "Blanco"};
            // para cada nodo
            for (int i = 0; i < nodes; i++) {
                // imprimir nombre
                cout << nickname[i] << " # ";
                // si la distancia es distinta al centinela y mayor a 0, imprimir
                if (distance[i] > 0 && distance[i] != INT_MAX) cout << "Distancia: " << distance[i] << " | ";
                // si la distancia es 0, es el origen
                else if (distance[i] == 0) cout << "Es el origen | ";
                // si la distancia es el centinela... ¡CAMINANTE, NO HAY CAMINO!
                else cout << "No existe ruta | ";
                // si el padre existe, imprimir
                if (parent_BFS[i] != -1) cout << "Padre: " << nickname[parent_BFS[i]] << " | ";
                // imprimir el color final
                cout << "Color: " << color_names[color_BFS[i]];
                cout << endl;
            }
        }

        // sobrecargar printBFS para permitir llamar a BFS de manera anidada
        void printBFS (int origin) {
            // si la última ejecución no fue con el origen especificado
            if (BFS_source != origin) {
                // ejecutar BFS
                BFS(origin);
            }
            // imprimir BFS
            printBFS();
        }

        // sobrecargar printBFS para aceptar el apodo
        void printBFS (string origin) {
            printBFS(unmask(origin));
        }

        void DFS () {
            c_time = 0;
            c_tree_index = 0;
            TS_stack_i = 0;
            for (int i = 0; i < nodes; i++) {
                time[i][0] = 0;
                time[i][1] = 0;
                parent_DFS[i] = -1;
                color_DFS[i] = 2;
                DFS_sources[i] = -1;
                DFS_tree[i] = -1;
            }
            for (int u = 0; u < nodes; u++) {
                if (color_DFS[u] == 2) {
                    DFS_sources[c_tree_index] = u;
                    DFS_Visit(u);
                    c_tree_index++;
                }
            }
        }

        void DFS_Visit (int u) {
            color_DFS[u] = 1;
            time[u][0] = ++c_time;
            for (int i = 0; i < A[u].size(); i++) {
                int v = A[u][i];
                if (color_DFS[v] == 2) {
                    parent_DFS[v] = u;
                    DFS_Visit(v);
                }
            }
            color_DFS[u] = 0;
            time[u][1] = ++c_time;
            TS[TS_stack_i++] = u;
            if (DFS_tree[u] == -1) DFS_tree[u] = c_tree_index;
        }

        void printDFS () {
            // no hemos ejecutado DFS
            if (c_time == -1) {
                cout << "No previous execution of Depth First Search found." << endl;
                return;
            }
            // traducir colores
            string color_names [3] = {"Negro", "Gris", "Blanco"};
            // para cada nodo
            for (int i = 0; i < nodes; i++) {
                // imprimir nombre
                cout << nickname[i] << " # ";
                cout << "Árbol: " << DFS_tree[i] << " (de " << nickname[DFS_sources[DFS_tree[i]]] << ") | ";
                // imprimir tiempo
                cout << "Tiempo: " << time[i][0] << "/" << time[i][1] << " | ";
                // si el padre existe, imprimir
                if (parent_DFS[i] != -1) cout << "Padre: " << nickname[parent_DFS[i]] << " | ";
                // imprimir el color final
                cout << "Color: " << color_names[color_DFS[i]];
                cout << endl;
            }
        }

        void TopologicalSort () {
            if (c_time == -1) DFS();
            stringstream ts_string;
            stringstream linking_string;
            cout << "Topological Sort" << endl;
            ts_string << "|";
            int* textpos = new int[nodes];
            for (int i = nodes-1; i >= 0; i--) {
                textpos[TS[i]] = ts_string.str().size() + nickname[TS[i]].size()/2 - 1;
                ts_string << nickname[TS[i]] << string("|");
            }
            for (int i = nodes-1; i >= 0; i--) {
                bool in_range = false;
                int linked_to = 0;
                if (A[TS[i]].size() == 0) continue;
                for (int s = 0; s < ts_string.str().size(); s++) {
                    if (s == textpos[TS[i]]) {
                        linking_string << "┗";
                        in_range = true;
                    }
                    else if (in_range) {
                        for (int j = 0; j < A[TS[i]].size(); j++) {
                            if (s == textpos[A[TS[i]][j]]) {
                                linking_string << "🠹";
                                linked_to++;
                                if (linked_to == A[TS[i]].size()) {
                                    in_range = false;
                                    break;
                                }
                            }
                            else if (j == A[TS[i]].size()-1) {
                                linking_string << "━";
                            }
                        }
                    }
                    else if (linked_to < A[TS[i]].size()) {
                        linking_string << " ";
                    }
                    else {
                        break;
                    }
                }
                linking_string << endl;
            }
            cout << ts_string.str() << endl;
            cout << linking_string.str();
            delete [] textpos;
        }
};

int main () {
    cout << "Ingeniería en Minecraft" << endl;
    AdjacencyList MinecraftEngineering (16, true, {"Combat", "Mine", "Explore", "Farm", "Craft", "Trade", "Tame", "Fish", "Redstone", "Cook", "Smelt", "Witchcraft", "Summon Entities", "Build", "Ranching", "Enchantment"});

    MinecraftEngineering.link("Combat", {"Witchcraft", "Summon Entities"});
    MinecraftEngineering.link("Mine", {"Redstone", "Smelt", "Build", "Enchantment"});
    MinecraftEngineering.link("Explore", {"Mine", "Trade", "Tame", "Ranching"});
    MinecraftEngineering.link("Farm", {"Ranching", "Cook", "Witchcraft", "Tame"});
    MinecraftEngineering.link("Craft", {"Farm", "Witchcraft", "Redstone", "Fish", "Enchantment", "Build"});
    MinecraftEngineering.link("Cook", "Witchcraft");
    MinecraftEngineering.link("Smelt", "Enchantment");
    MinecraftEngineering.link("Build", {"Farm", "Ranching", "Redstone"});

    MinecraftEngineering.DFS();
    MinecraftEngineering.printDFS();
    MinecraftEngineering.TopologicalSort();
}