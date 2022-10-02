/*  nombre: Calcular área de un triángulo con solo sus lados
    autor: David Emmanuel Santana Romero, en equipo con Fernando Pulido Mendivil
    fecha: 30 de agosto de 2022
    propósito: Calcular el área de un triángulo cualesquiera conociendo solo los lados
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>
#include<math.h>

int main() {
    setlocale(LC_ALL, "spanish");
    int ladoA, ladoB, ladoC;
    long double area;
    long double sp;
    printf("Proporciona los lados del triángulo.\n");
    scanf("%d %d %d", &ladoA, &ladoB, &ladoC);
    sp = (long double) ((ladoA + ladoB + ladoC)/2); // declaramos el semiperímetro, necesario para usar la fórmula de Herón
    area = (long double) sqrt((sp)*(sp-ladoA)*(sp-ladoB)*(sp-ladoC));
    printf("El área es %f", area);
    return 0;
}