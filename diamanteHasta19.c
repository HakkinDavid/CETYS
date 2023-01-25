/*  nombre: Imprimir un diamante
    autor: David Emmanuel Santana Romero
    fecha: 7 de octubre de 2022
    versión: 2.0
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int width = 3; // ancho del diamante
    do {
        printf("Proporciona un tamaño de diamante (impar, de 1 a 19): ");
        scanf("%d", &width);
    }
    while ((width%2 == 0) || width > 19);
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