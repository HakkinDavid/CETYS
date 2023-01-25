/*
    nombre: Imprimir números pares e impares, con funciones
    autor: David Emmanuel Santana Romero
    fecha: 28 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define SIZE 10
#define RANGO 100

void generateArray(int array[], int size, char name[]) {
    printf("Generando arreglo de números ... \n\t%s [%d] = { ", name, size);
    for (int i = 0; i < size; i++) {
        int n = (rand() % RANGO);
        if (rand() % 2) n -= (2*n);
        printf("%d", n);
        if (i+1 < size) printf(", ");
        array[i] = n;
    }
    printf(" };\n\n");
}

bool isEven(int num) {
    if (num % 2 == 0) {
        printf("\t\t\t%d\tes par\n", num);
        return true;
    }
    else {
        printf("\t\t\t%d\tes impar\n", num);
        return false;
    }
}

int main() {
    int numbers[SIZE] = {0};
    int pares = 0;
    srand(time(NULL));
    
    generateArray(numbers, SIZE, "numbers");

    for (int i = 0; i < SIZE; i++) {
        if (isEven(numbers[i])) pares++;
    }

    printf("Hubo %d pares y %d impares.", pares, SIZE-pares);
}