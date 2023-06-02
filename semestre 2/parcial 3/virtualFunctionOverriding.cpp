#include <iostream>
using namespace std;

// definimos la clase Base
class Base {
    public:
    // método virtual fun de Base
    virtual void fun () {
        cout << "Estamos en la clase Base" << endl;
    }
    // método display de Base
    void display () {
        cout << "Ya casi que se acaba el semestre" << endl;
    }
};

class Derived : public Base{
    public:
    // método fun de Derived
    void fun () {
        cout << "Estamos en la clase Derivada" << endl;
    }
    // método display de Derived
    void display () {
        cout << "Ya deben de estar haciendo su proyecto" << endl;
    }
};

int main () {
    // creamos 2 objetos tipo Derived
    Derived d, d1;
    // puntero tipo Base hacia objeto Derived
    Base *d1Ptr = &d1;
    // accedemos al método fun de Derived (ya que el de Base es virtual)
    d1Ptr -> fun();
    // accedemos al método display de Base
    d1Ptr -> display();
    return 0;
}