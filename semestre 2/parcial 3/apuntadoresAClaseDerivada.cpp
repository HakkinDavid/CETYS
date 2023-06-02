#include <iostream>
using namespace std;

// declarar la clase base
class Base {
    public:
        int b;
        void show () {
            cout << "b = " << b << endl;
        }
};

// declarar la clase derivada
class Derivada : public Base {
    public:
        int d;
        void show () {
            cout << "b = " << b << endl; cout << "d = " << d << endl;
        }
};

int main () {
    // crear un puntero a un objeto en memoria heap de la clase base
    Base *bPtr = new Base;

    // establecer el dato miembro b del objeto referenciado a 100
    bPtr -> b = 100;
    cout << "bPtr apunta a objeto base " << endl;

    // utilizar el método show del objeto de tipo base
    bPtr -> show();

    // crear un objeto estático de tipo Derivada
    Derivada deri;

    // establecer que el apuntador de tipo Base apunte a la dirección del objeto tipo Derivada
    bPtr = &deri;

    // establecer el dato miembro b de deri a 200
    bPtr -> b = 200;
    
    // bPtr -> d = 300; // error, no se puede accesar a un dato miembro de la clase derivada con el puntero de la clase base

    cout << "usando bPtr para accesar a la clase derivada" << endl;

    // definir un puntero de tipo Derivada
    Derivada *dPtr;

    // apuntar a deri con el puntero de tipo Derivada
    dPtr = &deri;

    // establecer el dato miembro d de deri en 300
    dPtr -> d = 300;
    cout << "dPtr apunta a objeto derivada " << endl;

    // desplegar deri
    dPtr -> show ();
    cout << "using ((Derivada *)bPtr)" << endl;

    // castear el puntero de tipo Base a tipo Derivada para acceder a los miembros de la clase Derivada
    ((Derivada *) bPtr) -> d = 400;
    ((Derivada *) bPtr) -> show ();
    return 0;
}