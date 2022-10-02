/*  nombre: Calcular el promedio de 3 números enteros y 3 números con punto decimal
    autor: David Emmanuel Santana Romero, en equipo con Fernando Pulido Mendivil
    fecha: 30 de agosto de 2022
    propósito: Calcular el promedio de 3 números enteros cualesquiera y 3 números con punto decimal cualesquiera
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "es_MX");
    int a, b, c;
    float d, e, f, avgInt, avgFloat;
    printf("Escribe 3 números enteros.\n");
    scanf("%d %d %d", &a, &b, &c);
    avgInt = (float)(a + b + c)/3;
    printf("El promedio es %f\n", avgInt);
    printf("Escribe 3 números con punto decimal.\n");
    scanf("%f %f %f", &d, &e, &f);
    avgFloat = (float)(d + e + f)/3.0;
    printf("El promedio es %f", avgFloat);
    return 0;
}