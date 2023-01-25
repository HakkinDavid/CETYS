/*  nombre: Gráfica de barras
    autor: David Emmanuel Santana Romero
    fecha: 7 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>

int main() {
    int num = 0;
    for (int i = 0; i < 5; i++) {
        do {
            printf("\nProporciona un valor del 1 al 30: ");
            scanf("%d", &num);
        }
        // requerimos el valor hasta que sea 1 < x < 30
        while (num < 1 || num > 30);
        printf("%d|", num);
        // imprimimos la cantidad de asteriscos correspondientes
        for (int j = 0; j < num; j++) {
            printf("*");
        }
    }
    return 0;
}