/*  nombre: Programa que sume enteros pares hasta el 100
    autor: David Emmanuel Santana Romero
    fecha: 25 de septiembre de 2022
    versión: 1.0
*/

#include<stdio.h>

int main() {
    int s = 0;
    for (int i = 2; i <= 100; i+=2) {
        printf("%d", i);
        s += i;
        if (i < 100) printf("+");
    }
    printf("=%d", s);
    return 0;
}