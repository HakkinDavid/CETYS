/*  nombre: Programa que obtenga el factorial del número dado
    autor: David Emmanuel Santana Romero
    fecha: 25 de septiembre de 2022
    versión: 1.0
*/

#include<iostream>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "spanish");
    int n = 0, f = 1;
    std::cout << "Proporciona un número: ";
    std::cin >> n;
    std::cout << n << "! = ";
    for (int i = 0; i < n; i++) {
        std::cout << n-i;
        f *= n-i;
        if (n-i > 1) std::cout << "x";
    }
    std::cout << "=" << f;
    return 0;
}