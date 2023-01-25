/*
    nombre: Imprimir números pares e impares
    autor: David Emmanuel Santana Romero
    fecha: 28 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdbool.h>

#define SIZE 10

int main() {
    int numbers[SIZE] = {0};
    int uniqueValues = 0;
    int range = SIZE;

    do {
        printf("Número de elementos (máximo %d): ", SIZE);
        scanf("%d", &range);
    } while (range < 1 || range > SIZE);

    for (int i = 0; i < range; i++) {
        printf("Proporciona un valor (%d/%d): ", i+1, range);
        scanf("%d", &numbers[i]);
    }

    printf("Valores únicos: ");
    for (int i = 0; i < range; i++) {
        int unique = true;
        for (int j = (i-1); j >= 0; j--) {
            if (numbers[i] == numbers[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            printf("%d ", numbers[i]);
            uniqueValues++;
        }
    }
    printf("\nTotal: %d", uniqueValues);
}