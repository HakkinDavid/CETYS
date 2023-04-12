/*  nombre: Constructor y destructor
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 10 de febrero de 2023
*/

#include <iostream>
using namespace std;

class Vaca {
    public:
        // Constructor
        Vaca () {
            pasto = 0;
            cout << "*nace*" << endl;
        }
        // Destructor
        ~Vaca () {
            cout << "MUUUUUU *muere*" << endl;
        }
        void vive () {
            pasto = rand() % 100;
            for (int i = 0; pasto > i; i++) {
                cout << "MUU ";
            }
            cout << endl;
        }
    private:
        int pasto;
};

int main () {
    Vaca vaca;
    vaca.vive();
    return 0;
}