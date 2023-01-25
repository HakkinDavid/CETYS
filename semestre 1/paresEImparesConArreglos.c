/*
    nombre: Imprimir números pares e impares
    autor: David Emmanuel Santana Romero
    fecha: 28 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10
#define RANGO 100

int main() {
    int numbers[SIZE] = {0};
    int pares = 0;
    srand(time(NULL));

    printf("Generando arreglo de números ... \n\tnumbers [SIZE] = { ");
    for (int i = 0; i < SIZE; i++) {
        int n = (rand() % RANGO);
        if (rand() % 2) n -= (2*n);
        printf("%d", n);
        if (i+1 < SIZE) printf(", ");
        numbers[i] = n;
    }
    printf(" };\n");

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 == 0) {
            printf("\t\t\t%d\tes par\n", numbers[i]);
            pares++;
        }
        else printf("\t\t\t%d\tes impar\n", numbers[i]);
    }

    printf("Hubo %d pares y %d impares.", pares, SIZE-pares);
}