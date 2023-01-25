/*
    nombre: Bubble Sort
    autor: David Emmanuel Santana Romero
    fecha: 28 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 20
#define RANGO 100

int main() {
    int numbers[SIZE] = {0};
    int range = SIZE;

    do {
        printf("Número de elementos (máximo %d): ", SIZE);
        scanf("%d", &range);
    } while (range < 1 || range > SIZE);

    srand(time(NULL));

    printf("Generando arreglo de números ... \n\tnumbers [%d] = { ", range);
    for (int i = 0; i < range; i++) {
        int n = (rand() % RANGO);
        if (rand() % 2) n -= (2*n);
        printf("%d", n);
        if (i+1 < range) printf(", ");
        numbers[i] = n;
    }
    printf(" };\n");

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < (range-i); j++) {
            if (numbers[j] < numbers[j+1]) {
                numbers[j] += numbers[j+1];
                numbers[j+1] = numbers[j] - numbers[j+1];
                numbers[j] -= numbers[j+1];
            }
        }
    }

    printf("Ordenando arreglo de números ... \n\tnumbers [%d] = { ", range);
    for (int i = 0; i < range; i++) {
        printf("%d", numbers[i]);
        if (i+1 < range) printf(", ");
    }
    printf(" };\n");
}