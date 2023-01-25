/*  nombre: Conjetura de Collatz
    autor: David Emmanuel Santana Romero
    fecha: 8 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<cstdlib>

// función que grafica el número como una barrita de tamaño n/10
void graphicate (int n) {
    if (n < 10) {
        printf("□");
    }
    for (int i = 10; i <= n; i+=10) {
        printf("■");
    }
}

int main () {
    int num = 1, pasos = 0, highest = 1;
    printf("Proporciona un número entero positivo: ");
    scanf("%d", &num);
    if (num < 1) {
        puts("Ese no es un entero positivo, joven.");
        exit(0);
    }
    printf("%d\t", num);
    graphicate(num);
    
    // Si este ciclo se repite indefinidamente, preocúpese o celébrelo, significaría que halló la respuesta a la conjetura.
    while (num > 1) {
        if (num % 2 == 0) {
            // si es par, dividir sobre dos y graficar un decremento (<, hacia abajo)
            num /= 2;
            printf("<");
        }
        else {
            // si es impar, multiplicar por 3 e incrementar en uno, graficar el incremento (>, hacia arriba)
            num *= 3;
            num++;
            printf(">");
        }
        // imprimir el nuevo valor
        printf("\n%d\t", num);
        graphicate(num);
        // verificar y/o establecer el valor más alto de la secuencia
        if (num > highest) highest = num;
        // sumar un paso
        pasos++;
    }
    printf("\nLa secuencia terminó en %d, tras %d iteraciones de la Conjetura de Collatz. El valor más alto fue %d.", num, pasos, highest);
    return 0;
}