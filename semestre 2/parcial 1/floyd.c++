/*  nombre: Triángulo de Floyd
    autor: David Emmanuel Santana Romero y Sebastian Soto
    versión: 1.0
    fecha: 10 de febrero de 2023
*/

#include <iostream>
using namespace std;

class Floyd {
    public:
        Floyd () {
            level = 1;
            cout << "Vamos a construir una construcción" << endl;
        }
        ~Floyd () {
            level = 0;
            cout << "Vamos a destruir la pirámide" << endl;
        }
        void setLevel (int x) {
            if (x < 1) {
                cout << "No se puede construir una pirámide menor a un nivel" << endl;
                return;
            }
            level = x;
        }
        int getLevel () const {
            return level;
        }
        void construir () const {
            int elementos = 1, n = 1;
            for (int i = 1; i <= level; i++) {
                for (int j = 0; j < elementos; j++) {
                    cout << n << "\t";
                    n++;
                }
                cout << endl;
                elementos++;
            }
        }
    private:
        int level;
};

int main () {
    Floyd floyd;
    int nivel = 0;
    cout << "Nivel: " << endl;
    cin >> nivel;
    floyd.setLevel(nivel);
    cout << "\n" << endl;

    floyd.construir();
}