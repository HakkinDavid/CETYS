/*	nombre: Realizar operaciones aritméticas con fracciones
	autor: David Emmanuel Santana Romero
	fecha: 31 de marzo de 2023
	descripción: Realizar operaciones aritméticas con fracciones
*/

#include <iostream>
#include <stdexcept>

class Fraction {
    private:
        int a = 0, b = 1;
    public:
        Fraction () {
            a = 0;
            b = 1;
        }
        Fraction (int a) {
            this -> a = a;
            b = 1;
        }
        Fraction (int a, int b) {
            this -> a = a;
            this -> b = b;
        }
        ~Fraction () {
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
            std::cout << "  " << a << "\n-----\n" << "  " << b << std::endl;
        }
        void displayFloat () const {
            std::cout << (float) a/b << std::endl;
        }
};

class Racional {
    private:
        Fraction p, q, r;
    public:
        Racional () {};
        Racional (Fraction &p, Fraction &q) {
            this -> p = p;
            this -> q = q;
        }
        ~Racional () {};

        void setP (Fraction &p) {
            this -> p = p;
        }

        void setQ (Fraction &q) {
            this -> p = p;
        }

        Fraction getP () const {
            return p;
        }

        Fraction getQ () const {
            return q;
        }

        void substract () {
            r.setB(p.getB() * q.getB());
            r.setA((p.getA() * q.getB()) - (q.getA() * p.getB()));
        }

        void divide () {
            r.setA(p.getA() * q.getB());
            r.setB(p.getB() * q.getA());
        }

        void display (bool floating = false) {
            std::cout << "El resultado es" << std::endl;
            floating ? r.displayFloat() : r.display();
        }
};

void configurarFracciones (Fraction &f) {
    int numA = 0, numB = 0;
    std::cout << "Numerador: " << std::endl;
    std::cin >> numA;
    f.setA(numA);
    std::cout << "Denominador: " << std::endl;
    std::cin >> numB;
    f.setB(numB);

    std::cout << "\n\n\n\n[Fracción]" << std::endl;
    f.display();
}

int main () {
    Fraction x, y;
    configurarFracciones (x);
    configurarFracciones (y);

    Racional w (x, y);
    std::cout << "Resta" << std::endl;
    w.substract();
    w.display();
    w.display(true);
    std::cout << "División" << std::endl;
    w.divide();
    w.display();
    w.display(true);
}