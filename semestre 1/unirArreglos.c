/*  nombre: Programa para unir dos arreglos en un tercer arreglo
    autor: David Emmanuel Santana Romero
    fecha: 3 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 50
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

int main() {
    // crear arreglos con un tamaño plantilla
    int arr1[MAXSIZE] = {0},
        arr2[MAXSIZE] = {0},
        resultado[2*MAXSIZE] = {0},
    // variable del tamaño real
        size = 5,
        repetidos = 0;

    // semilla aleatoria
    srand(time(NULL));

    // obtener tamaño
    do {
        printf("Proporciona el tamaño del arreglo [de 1 a %d]: ", MAXSIZE);
        scanf("%d", &size);
    } while(size < 1 || size > MAXSIZE);

    // generar arreglos
    generateArray(arr1, size, "arr1");
    generateArray(arr2, size, "arr2");

    // iterar y copiar los valores
    for (int i = 0; i < size; i++) {
        resultado[i] = arr1[i];
    }
    for (int i = 0; i < size; i++) {
        resultado[i+size] = arr2[i];
    }

    // ordenar resultado
    for (int i = 0; i < (2*size); i++) {
        for (int j = 0; j < ((2*size)-i); j++) {
            if (resultado[j] == resultado[j+1]) {
                // valor inválido
                resultado[j] = ((-1)*(RANGO+1));
            }
            if (resultado[j] > resultado[j+1]) {
                resultado[j] += resultado[j+1];
                resultado[j+1] = resultado[j] - resultado[j+1];
                resultado[j] -= resultado[j+1];
            }
        }
    }

    // limpiar arreglo
    for (int i = 0; i < (2*size); i++) {
        if (resultado[i] < (-1*RANGO)) {
            repetidos++;
            continue;
        };
        if (repetidos == 0) break;
        resultado[i-repetidos] = resultado[i];
        if (((2*size)-1-i) < repetidos) {
            resultado[i] = ((-1)*(RANGO+1));
        }
    }

    // iterar e imprimir los valores
    printf("\tresultado[%d] = {", (2*size-repetidos));
    for (int i = 0; i < (2*size); i++) {
        printf(" %d", resultado[i]);
        if ((i+1) < (2*size)) {
            if (resultado[i+1] < (-1*RANGO)) break;
            printf(",");
        }
    }
    printf(" };");
}