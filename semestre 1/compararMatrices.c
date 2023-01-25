/*  nombre: Comparar matrices
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 6 de noviembre de 2022
*/

#include<stdio.h>
#include<locale.h>
#include<stdbool.h>

#define lines 2
#define columns 3

int main() {
    setlocale(LC_ALL, "es_MX");
    int A[lines][columns] = {0},
        B[lines][columns] = {0};
    bool equal = true;

    puts("Define A");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("A[%d][%d]: ", (i+1), (j+1));
            scanf("%d", &A[i][j]);
        }
    }

    puts("Define B");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("B[%d][%d]: ", (i+1), (j+1));
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < lines && equal; i++) {
        for (int j = 0; j < columns && equal; j++) {
            if (A[i][j] != B[i][j]) {
                equal = false;
                break;
            }
        }
    }

    equal ? puts("Las matrices son iguales.") : puts("Las matrices NO son iguales.");
}