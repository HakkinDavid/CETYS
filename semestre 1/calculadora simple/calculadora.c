#include "calculadora.h"
#include <stdio.h>

int suma (int num1, int num2) {
    return num1 + num2;
}
int resta (int num1, int num2) {
    return num1 - num2;
}
int multiplicar(int num1, int num2) {
    return num1 * num2;
}
int dividir(int num1, int num2) {
    if (num2 == 0) return NULL;
    return num1 / num2;
}