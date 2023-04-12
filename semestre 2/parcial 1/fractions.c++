/*  nombre: Fracciones
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 3 de febrero de 2023
*/

#include <iostream>
#include <stdexcept>

class Fraction {
    private:
        int a = 0, b = 1;
    public:
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
            std::cout << "  " << a << "\n-----\n" << "  " << b << std::endl;
        }
};

int main () {
    int numA = 0, numB = 0;
    Fraction f;
    std::cout << "Numerador: " << std::endl;
    std::cin >> numA;
    f.setA(numA);
    std::cout << "Denominador: " << std::endl;
    std::cin >> numB;
    f.setB(numB);

    std::cout << "\n\n\n\n[Fracción]" << std::endl;
    f.display();
}