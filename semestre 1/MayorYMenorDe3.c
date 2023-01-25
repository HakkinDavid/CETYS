/*  nombre: Máximo y mínimo de 3 números
    autor: David Emmanuel Santana Romero
    fecha: 9 de septiembre de 2022
*/  
#include<stdio.h>

int main() {
    int a, b, c;
    printf("Indica 3 números: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("El mayor número es ");
    if (a > b) {
        if (a > c) {
            printf("%d\n", a);
        }
        else {
            printf("%d\n", c);
        }
        if (b > c) {
            printf("El menor número es %d\n", c);
        }
        else {
            printf("El menor número es %d\n", b);
        }
    }
    else {
        if (b > c) {
            printf("%d\n", b);
        }
        else {
            printf("%d\n", c);
        }
        if (a > c) {
            printf("El menor número es %d\n", c);
        }
        else {
            printf("El menor número es %d\n", a);
        }
    }
    if (a == b) {
        (a == c) ? printf("(los 3 números son iguales)") : printf("(a y b son iguales)");
    }
    else {
        if (a == c) {
            printf("(a y c son iguales)");
        }
        else if (b == c) {
            printf("(b y c son iguales)");
        }
    }
    return 0;
}