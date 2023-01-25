/*  nombre: Búsqueda en un arreglo
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 25 de octubre de 2022
*/

#define SIZE 10

#include<stdio.h>
#include<stdbool.h>

int main () {
    char miArreglo[SIZE] = {97};
    char letrita = 97;
    bool flag = false;
    for (int i = 0; i < SIZE; i++) {
        printf("Letrita en %d: ", i);
        scanf("%s", &miArreglo[i]);
    }
    printf("Letrita a buscar: ");
    scanf("%s", &letrita);
    for (int i = 0; i < SIZE; i++) {
        if (miArreglo[i] == letrita) {
            printf("Sí está, en la posición %d.", i);
            flag = true;
            break;
        }
    }
    if (!flag) {
        printf("Si lo vi, ni me acuerdo.");
    }
}