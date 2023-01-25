/*  nombre: Programa que imprima las tablas de multiplicar (por si las necesito en un examen)
    autor: David Emmanuel Santana Romero
    fecha: 23 de septiembre de 2022
    versión: 1.0
*/

#include<iostream>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "spanish");
    int n = 0;
    std::cout << "Proporciona un número: ";
    std::cin >> n;
    for (int i = 1; i <= 12; i++) {
        std::cout << n << "x" << i << "=" << n*i << std::endl;
    }
    return 0;
}