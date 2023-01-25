/*  nombre: Programa que determine si un número es palíndromo
    autor: David Emmanuel Santana Romero
    fecha: 25 de septiembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>
#include<math.h>

int main() {
    setlocale(LC_ALL, "spanish");
    int n = 0, m = 0, l = 0;
    printf("Proporciona un número: ");
    scanf("%d", &n);
    l = n;
    while(l > 0) {
        m *= 10;
        m += (l % 10);
        l /= 10;
    }
    (m == n) ? puts("Es un palíndromo.") : puts("No es un palíndromo.");
    return 0;
}