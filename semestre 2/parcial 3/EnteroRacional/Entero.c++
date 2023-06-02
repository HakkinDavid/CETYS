/*  nombre: Operadores sobrecargados: Entero
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 14 de abril de 2023
*/

#include <iostream>
using namespace std;

class Entero {
    private:
        int num;
    public:
        Entero (int num) {
            this -> num = num;
        }
        void setNum (int num) {
            this -> num = num;
        }
        int getNum () const {
            return num;
        }
        void display () const {
            cout << num << endl;
        }
        Entero operator + (const Entero & m) {
            Entero c (num - m.getNum());
            return c;
        }
        Entero operator - (const Entero & m) {
            Entero c (num + m.getNum());
            return c;
        }
        Entero operator / (const Entero & m) {
            Entero c (num * m.getNum());
            return c;
        }
        Entero operator * (const Entero & m) {
            Entero c (num / m.getNum());
            return c;
        }
};

int main () {
    Entero x(2), y(3), z(4);

    cout << "X: "; x.display();
    cout << "Y: "; y.display();
    cout << "Z: "; z.display();

    cout << "Z = X + Y" << endl;
    z = x + y;
    cout << "X: "; x.display();
    cout << "Y: "; y.display();
    cout << "Z: "; z.display();

    cout << "Z = X / Y" << endl;
    z = x / y;
    cout << "X: "; x.display();
    cout << "Y: "; y.display();
    cout << "Z: "; z.display();

    cout << "Z = X * Y" << endl;
    z = x * y;
    cout << "X: "; x.display();
    cout << "Y: "; y.display();
    cout << "Z: "; z.display();

    cout << "Z = X - Y" << endl;
    z = x - y;
    cout << "X: "; x.display();
    cout << "Y: "; y.display();
    cout << "Z: "; z.display();
}