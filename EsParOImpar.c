/*  nombre: ¿Es par o impar?
    autor: David Emmanuel Santana Romero
    fecha: 9 de septiembre de 2022
    versión: 1.0
*/

#include<stdio.h>

int main() {
    int n;
    printf("Indica un número a evaluar: ");
    scanf("%d", &n);
    ((n % 2) == 0) ? puts("Es par") : puts("Es impar");
    return 0;
}