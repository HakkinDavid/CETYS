/*  nombre: Calculadora simple
    autor: David Emmanuel Santana Romero
    fecha: 8 de noviembre de 2022
    versión: 1.0
*/

#include <stdio.h>
#include "calculadora.h"

void menu();

int main () {
    char keypress;
    int num[2] = {0};

    do {
        menu();
        keypress = getchar();
        getchar();
        printf("Valor 1: ");
        scanf("%d", &num[0]);
        printf("Valor 2: ");
        scanf("%d", &num[1]);
        switch(keypress) {
            case 's':
                printf("El resultado es %d\n", suma(num[0], num[1]));
            break;
            case 'r':
                printf("El resultado es %d\n", resta(num[0], num[1]));
            break;
            case 'm':
                printf("El resultado es %d\n", multiplicar(num[0], num[1]));
            break;
            case 'd':
                printf("El resultado es %d\n", dividir(num[0], num[1]));
            break;
            default:
            break;
        }
        
    } while (keypress != 'q');
}

void menu() {
    puts("[S] Suma");
    puts("[R] Resta");
    puts("[M] Multiplicación");
    puts("[D] División");
    puts("[Q] Salir");
    printf("Selecciona una opción: ");
}