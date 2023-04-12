/*  nombre: Complejos con operadores
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de abril de 2023
*/

#include <iostream>
#include "complex.h"
using namespace std;

Complex :: Complex (float r = 0.0, float i = 0.0) {
    R = r;
    I = i;
}
Complex :: ~Complex () {
    R = 0;
    I = 0;
}

void Complex :: setR (float r) {
    R = r;
}
void Complex :: setI (float i) {
    I = i;
}

float Complex :: getR () const {
    return R;
}
float Complex :: getI () const {
    return I;
}

ostream & operator << (ostream &out, Complex &c) {
    out << c.R << " + " << c.I << "i";
    return out;
}
istream & operator >> (istream &in, Complex &c) {
    cout << "Real: ";
    in >> c.R;
    cout << "Imaginario: ";
    in >> c.I;
    return in;
}