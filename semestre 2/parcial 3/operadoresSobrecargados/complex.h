/*  nombre: Complejos con operadores
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de abril de 2023
*/

#include <iostream>
using namespace std;

#ifndef COMPLEX_OPERADORES_H
#define COMPLEX_OPERADORES_H

class Complex {
    private:
        float R, I;
    public:
        Complex (float, float);
        ~Complex ();

        void setR (float);
        void setI (float);

        float getR () const;
        float getI () const;

        friend ostream & operator << (ostream &, Complex &);
        friend istream & operator >> (istream &, Complex &);
};

#include "complex.cpp"
#endif