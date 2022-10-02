/*  nombre: Máximo de 3 números
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
            printf("%d", a);
        }
        else {
            printf("%d", c);
        }
    }
    else {
        if (b > c) {
            printf("%d", b);
        }
        else {
            printf("%d", c);
        }
    }
    return 0;
}