/*  nombre: Clase caja
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 3 de marzo de 2023
*/

#include <iostream>
#include "caja.h"

using namespace std;

void printDimensions (Caja &c) {
    cout << "La caja mide " << c.ancho << "cm x " << c.largo << "cm" << endl;
}

int main () {
    Caja cajita;
    printDimensions(cajita);
    return 0;
}