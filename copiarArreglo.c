/*  nombre: Programa para copiar un arreglo de N elementos a otro
    autor: David Emmanuel Santana Romero
    fecha: 3 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>

#define MAXSIZE 100

int main() {
    // crear arreglos con un tamaño plantilla
    int array[MAXSIZE] = {0},
        copia[MAXSIZE] = {0},
    // variable del tamaño real
        size = 5;

    // obtener tamaño
    do {
        printf("Proporciona el tamaño del arreglo [de 1 a %d]: ", MAXSIZE);
        scanf("%d", &size);
    } while(size < 1 || size > MAXSIZE);

    // pedir valores
    for (int i = 0; i < size; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &array[i]);
    }

    // iterar y copiar los valores
    printf("array[%d] = {", size);
    for (int i = 0; i < size; i++) {
        printf(" %d", array[i]);
        if ((i+1) != size) printf(",");
        copia[i] = array[i];
    }
    printf(" };\n");

    // iterar e imprimir los valores
    printf("copia[%d] = {", size);
    for (int i = 0; i < size; i++) {
        printf(" %d", copia[i]);
        if ((i+1) != size) printf(",");
    }
    printf(" };");
}