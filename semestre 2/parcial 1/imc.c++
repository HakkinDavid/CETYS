/*  nombre: Calcular IMC
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 27 de enero de 2023
*/

#include <iostream>

#define NORMAL 18.5
#define OVERWEIGHT 25
#define OBESITY 30

int main () {
    float weight = 0.0, height = 0.0, imc = 0.0;

    std::cout << "Peso (kg)" << std::endl;
    std::cin >> weight;
    std::cout << "Estatura (m)" << std::endl;
    std::cin >> height;

    imc = weight / (height * height);

    std::cout << "Tu IMC es de " << imc;

    if (imc < NORMAL) {
        std::cout << " BAJO DE PESO" << std::endl;
    }
    else if (imc >= NORMAL && imc < OVERWEIGHT) {
        std::cout << " NORMAL" << std::endl;
    }
    else if (imc >= OVERWEIGHT && imc < OBESITY) {
        std::cout << " SOBREPESO" << std::endl;
    }
    else if (imc >= OBESITY) {
        std::cout << " OBESIDAD" << std::endl;
    }
}