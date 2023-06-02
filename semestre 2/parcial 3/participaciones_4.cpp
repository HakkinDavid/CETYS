#include <iostream>
using namespace std;

// definir la clase Base
class Base {
    public:
    // método fun de Base
    void fun() {
        cout << "Estamos en la clase Base" << endl;
    }
};

// definir la clase Derived
class Derived : public Base {
    public:
    // método fun de Derived
    void fun() {
        cout << "Estamos en la clase Derivada" << endl;
        Base::fun(); // llama al método fun de Base
    }
};

int main () {
    Derived d, d1; // objetos de tipo Derived
    Base *d1Ptr = &d1; // definimos un puntero tipo Base que apunta al objeto tipo Derived
    d.fun(); // llamamos al método fun de Derived
    d1Ptr -> fun(); // llamamos al método fun de Base
    return 0;
}