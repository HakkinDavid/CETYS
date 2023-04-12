/*  nombre: Constructor con herencia
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#include <iostream>
using namespace std;

class Padre {
    public:
        Padre () {
            cout << "Dentro de la clase padre" << endl;
        }
};

class Hija : public Padre {
    public:
        Hija () {
            cout << "Dentro de la clase hija" << endl;
        }
};

class PadreA {
    public:
        PadreA () {
            cout << "Dentro de la clase padre A" << endl;
        }
};

class PadreB {
    public:
        PadreB () {
            cout << "Dentro de la clase padre B" << endl;
        }
};

class Hijo : public PadreA, public PadreB {
    public:
        Hijo () {
            cout << "Dentro de la clase hijo" << endl;
        }
};

int main () {
    Hija hijita;
    Hijo hijito;
    return 0;
}