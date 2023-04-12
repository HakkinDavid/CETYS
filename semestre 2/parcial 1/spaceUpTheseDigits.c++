/*  nombre: Espaciar un número de cinco dígitos
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 25 de enero de 2023
*/

#include <iostream>
#include <math.h>

int main () {
    int num = 0;
    std::cout << "Indica un numerito" << std::endl;
    std::cin >> num;
    for (int i = 0; i < 5; i++) {
        // obtener el dígito más grande
        std::cout << num/(10000 / (int) pow(10, i)) << "\t";
        // obtener el residuo y reasignar
        num = num%(10000/(int) pow(10, i));
    }
    return 0;
}