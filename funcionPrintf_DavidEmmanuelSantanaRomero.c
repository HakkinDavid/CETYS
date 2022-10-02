/*
 * nombre: Función printf
 * autor: David Emmanuel Santana Romero
 * descripción: Demostrar el uso de printf()
 * version: 1.0
 * fecha: 2022-08-24
 */

#include <stdio.h>

int main () {
    printf("Tenemos %d monedas en el banco\n", 1000);
    printf("Tenemos %f monedas en el banco\n", 125.7);
    printf("Año = %d\n", 2020);
    printf("Tu calificación promedio es: %f\n", 95.13);
    printf("num1 = %d, num2 = %d, suma = %d\n", 5, 7, 5+7);
    printf("num1 = %f, num2 = %f, sum = %f\n", 5.2, 7.3, 5.2+7.3);
    printf("num1 = %d, num2 = %d, resta = %d\n", 5, 3, 5-3);
    printf("a = %d, b = %d, suma = a + b = %d\n", 3, 5, 3+5);
    printf("a = %d, b = %d, suma = %d + %d = %d\n", 3, 5, 3, 5, 3+5);
    printf("Yo tengo %d\nMi hermano tiene %f\n", 150, 25.63);
    return 0;
}