/*  nombre: Intercambio de valor
    autor: David Emmanuel Santana Romero, en equipo con Fernando Pulido Mendivil
    fecha: 30 de agosto de 2022
    propósito: Cambiar el valor de las variables entre sí
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "es_MX");
    int a, b, c;
    printf("Escribe el valor de a: ");
    scanf("%d", &a);
    printf("Escribe el valor de b: ");
    scanf("%d", &b);
    c = a;
    a = b;
    b = c;
    printf("a: %d, b: %d", a, b);
    return 0;
}