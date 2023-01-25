/*  nombre: Programa para encontrar el elemento mínimo o máximo de un arreglo de N elementos
    autor: David Emmanuel Santana Romero
    fecha: 3 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>

#define MAXSIZE 100

int main() {
    // crear arreglo con un tamaño plantilla
    int array[MAXSIZE] = {0},
    // variable del tamaño real
        size = 5,
    // variables de máximo y mínimo
        max,
        min;

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
    
    // inicializar min y max con valores del arreglo
    min = array[0];
    max = array[0];

    // iterar y comparar los valores
    for (int i = 0; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    printf("El máximo es %d y el mínimo es %d", max, min);
}