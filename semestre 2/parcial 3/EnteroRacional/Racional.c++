/*  nombre: Operadores sobrecargados: Racional
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 14 de abril de 2023
*/

#include <iostream>
#include <stdexcept>

class Racional {
    private:
        int a = 0, b = 1;
    public:
        Racional () {
            a = 0;
            b = 1;
        }
        Racional (int a) {
            this -> a = a;
            b = 1;
        }
        Racional (int a, int b) {
            this -> a = a;
            this -> b = b;
        }
        ~Racional () {
            a = 0;
            b = 0;
        }
        void setA (int x) {
            a = x;
        }
        int getA () const {
            return a;
        }
        void setB (int x) {
            if (x == 0) {
                throw std::invalid_argument("NO SE PUEDE. LAS MATEMÁTICAS NO SON TAN AVANZADAS. ¿QUIERES QUE EXPLOTE EL UNIVERSO?");
            }
            b = x;
        }
        int getB () const {
            return b;
        }
        void display () const {
            std::cout << a << "/" << b << std::endl;
        }
        void displayFloat () const {
            std::cout << (float) a/b << std::endl;
        }
        Racional operator + (const Racional & f) {
            Racional r;
            r.setA((a*f.b) + (f.a*b));
            r.setB((b*f.b));
            return r;
        }
        Racional operator / (const Racional & f) {
            Racional r;
            r.setA(b*f.a);
            r.setB(a*f.b);
            return r;
        }

        friend std::ostream & operator << (std::ostream & out, const Racional & r);
        friend std::istream & operator >> (std::istream & in, Racional & r);
};

std::ostream & operator << (std::ostream & out, const Racional & r) {
    out << r.a << "/" << r.b;
    return out;
}
std::istream & operator >> (std::istream & in, Racional & r) {
    std::cout << "Fracción:" << std::endl;
    in >> r.a;
    std::cout << "---" << std::endl;
    in >> r.b;
    return in;
}

int main () {
    Racional x, y, z;

    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    std::cout << "X + Y + Z" << std::endl;
    std::cout << x + y + z << std::endl;

    std::cout << "X / Z" << std::endl;
    std::cout << x / z << std::endl;
}