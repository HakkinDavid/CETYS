/*  nombre: Obtener el código ASCII
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 25 de enero de 2023
*/

#include <iostream>

int main () {
    char c = 0;
    std::cout << "Proporciona un carácter" << std::endl;
    std::cin >> c;
    std::cout << "Es " << (int) c;
    return 0;
}