/*
    nombre: Lista de adyacencia
    autor: David Emmanuel Santana Romero
    fecha: 27 de octubre de 2023
*/

#include <iostream>
#include <vector>
using namespace std;

// declarar la clase de lista de adyacencia
class AdjacencyList {
    private:
        // vector que almacena la lista
        vector<vector<int>> A;
        // ¿es la lista de un solo sentido? (grafo dirigido)
        bool oneway;
        // número de nodos
        int nodes;
    public:
        // inicializar la clase
        // permitir al usuario definir el número de nodos
        // definir si la lista es de un solo sentido
        AdjacencyList (int nodes = 0, bool oneway = false) {
            A.resize(nodes);
            this->oneway = oneway;
            this->nodes = nodes;
        }
        // eliminar elementos del vector
        ~AdjacencyList () {
            A.clear();
        }

        int getNodes () {
            return nodes;
        }

        // enlazar un nodo a otro
        void link (int i, int j, bool nested = false) {
            // ¿están fuera del rango de operación?
            if (i >= A.size() || j >= A.size()) {
                cout << "NODE OUT OF RANGE." << endl;
                return;
            }
            // ¿es la lista de un solo sentido?
            if (oneway && !A[j].empty()) {
                // buscar si el nodo ya se ha enlazado en el sentido opuesto
                for (int n = 0; n < A[j].size(); n++) {
                    if (A[j][n] == i) {
                        cout << "Cannot link nodes " << i << "->" << j << " since adjacency is set one-way." << endl;
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
                        cout << "Nodes " << i << "->" << j << " already linked" << endl;
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

        // imprimir la lista
        void print () {
            for (int i = 0; i < A.size(); i++) {
                cout << "V[" << i << "] -> ";
                for (int j = 0; j < A[i].size(); j++) {
                    cout << A[i][j] << " -> ";
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
            for (int i = 0; i < getNodes(); i++) {

                // imprimir el nombre
                cout << "V[" << i << "]";

                //averiguar si necesitamos espaciar desde el nombre para mantener la consistencia del arte
                for (int s = getNodes(); s / 10 > 0; s /= 10) {
                    cout << " ";
                }

                // para cada elemento
                for (int j = 0; j < getNodes(); j++) {
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
};

int main () {
    AdjacencyList L (10);

    L.link(0, {8, 6, 1});
    L.link(1, {9, 4, 6, 0});
    L.link(2, {4, 6});
    L.link(3, {4, 5, 8});
    L.link(4, {1, 2, 3, 5, 9});
    L.link(5, {3, 4});
    L.link(6, {0, 1, 2});
    L.link(7, {8, 9});
    L.link(8, {0, 3, 7});
    L.link(9, {1, 4, 7});

    L.print();

    L.printAsArray();
}