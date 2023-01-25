/*  nombre: Imprimir un diamante
    autor: David Emmanuel Santana Romero
    fecha: 7 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int width = 3; // ancho del diamante
    printf("Proporciona un tamaño de diamante: ");
    scanf("%d", &width);
    for (int i = 1; i <= (width*2); i+=2) {
        int asteriscos = 1; // contador de asteriscos
        if (i > width) {
            asteriscos += (2*(i-width)); // cuando pasamos la mitad del diamante, empezamos a disminuir el rango de los asteriscos a imprimir
        }
        for (int j = 0; j < (abs(width-i)/2); j++) {
            printf(" "); // espacios antes la fila
        }
        for (; asteriscos <= i; asteriscos++) {
            printf("*"); // asteriscos a imprimir
        }
        printf("\n");
    }
    return 0;
}