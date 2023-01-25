/*  nombre: Programa que sume los dígitos de un número dado
    autor: David Emmanuel Santana Romero
    fecha: 25 de septiembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "spanish");
    int n = 0, suma = 0;
    printf("Proporciona un número: ");
    scanf("%d", &n);
    while (n > 0) {
        printf("%d", (n%10));
        suma += (n % 10);
        n /= 10;
        if (n > 0) printf("+");
    }
    printf("=%d", suma);
    return 0;
}