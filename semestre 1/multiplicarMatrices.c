/*  nombre: Multiplicar matrices
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 1 de noviembre de 2022
*/

#include <stdio.h>
#include<locale.h>

#define Ai 2
#define Aj 3
#define Bi 3
#define Bj 2

int main() {
    setlocale(LC_ALL, "es_MX");
    int A[Ai][Aj] = {0},
        B[Bi][Bj] = {0},
        C[Ai][Bj] = {0};

    puts("Define A");
    for (int i = 0; i < Ai; i++) {
        for (int j = 0; j < Aj; j++) {
            printf("A[%d][%d]: ", (i+1), (j+1));
            scanf("%d", &A[i][j]);
        }
    }

    puts("Define B");
    for (int i = 0; i < Bi; i++) {
        for (int j = 0; j < Bj; j++) {
            printf("B[%d][%d]: ", (i+1), (j+1));
            scanf("%d", &B[i][j]);
        }
    }

    for (int l = 0; l < Bj; l++) {
        for (int i = 0; i < Ai; i++) {
            for (int j = 0; j < Aj; j++) {
                C[i][l] += (A[i][j] * B[j][l]);
            }
        }
    }

    puts("Imprime C, donde C = AB");
    for (int i = 0; i < Ai; i++) {
        for (int j = 0; j < Bj; j++) {
            printf("C[%d][%d]: %d\n", (i+1), (j+1), C[i][j]);
        }
    }
}