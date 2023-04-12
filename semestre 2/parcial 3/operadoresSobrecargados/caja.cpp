/*  nombre: Caja con operadores
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de abril de 2023
*/

#include "caja.h"
#include <iostream>
using namespace std;

Caja :: Caja (float x = 1, float y = 1, float z = 1) {
    this -> x = x;
    this -> y = y;
    this -> z = z;

    cout << "Caja creada con dimensiones X: " << x << " Y: " << y << " Z: " << z << endl;
}

Caja :: ~Caja () {
    x = 0;
    y = 0;
    z = 0;
}

void Caja :: setX (float x) {
    this -> x = x;
}
void Caja :: setY (float y) {
    this -> y = y;
}
void Caja :: setZ (float z) {
    this -> z = z;
}
float Caja :: getX () const {
    return x;
}
float Caja :: getY () const {
    return y;
}
float Caja :: getZ () const {
    return z;
}
void Caja :: display () const {
    cout << "Volumen: " << x*y*z << endl;
}
Caja & Caja :: operator + (const Caja &c) {
    x += c.x;
    y += c.y;
    z += c.z;
    return *this;
}