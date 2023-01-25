/*  nombre: Programa que sume enteros pares hasta el número dado
    autor: David Emmanuel Santana Romero
    fecha: 25 de septiembre de 2022
    versión: 1.0
*/

#include<iostream>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "spanish");
    int n = 0, s = 0;
    std::cout << "Proporciona un número: ";
    std::cin >> n;
    for (int i = 2; i <= n; i+=2) {
        std::cout << i;
        s += i;
        if (i < (n-(n%2))) std::cout << "+";
    }
    std::cout << "=" << s;
    return 0;
}