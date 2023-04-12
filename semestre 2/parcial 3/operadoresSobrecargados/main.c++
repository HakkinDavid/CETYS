/*  nombre: Operadores sobrecargados
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de abril de 2023
*/

#include "caja.h"
#include "complex.h"
#include <iostream>
using namespace std;

int main () {
    Caja a (20.3, 2.12, 9.8), b (6.5, 33.3, 2.14), c;
    c = a + b;
    c.display();

    Complex i;

    cin >> i;

    cout << "El número complejo es: " << i << endl;
}