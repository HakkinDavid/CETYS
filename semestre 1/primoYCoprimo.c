/*  nombre: Programa que despliega un menú para determinar primos y coprimos
    autor: David Emmanuel Santana Romero
    fecha: 8 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

void menu ();
void primo ();
void coprimos ();

int main() {
    setlocale(LC_ALL, "es_MX");
    char keypress;
    do {
        menu();
        scanf("%s", &keypress);
        switch (keypress) {
            case '1':
                primo();
                break;
            case '2':
                coprimos();
                break;
            case 'q':
                puts("Nos vemos luego.");
                break;
            default:
                printf("[%c] Opción no reconocida.\n", keypress);
                break;
        }
    }
    while (keypress != 'q');
    return 0;
}

void menu () {
    puts("M E N Ú");
    puts("[1] Saber si un número es primo");
    puts("[2] Saber si dos números son coprimos");
    puts("[Q] Quit");
}

void primo () {
    int n = 0;
    printf("Proporciona un número: ");
    scanf("%d", &n);
    // ciclo para averiguar por fuerza bruta qué números del 2 a (n-1) dividen enteramente a n
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {
            printf("☑ %d ÷ %d ∴ No es primo.\n", n, i); // si n%i == 0, es porque hay un número diferente a n y 1 que puede dividir n enteramente
            return;
        }
        printf("☒ %d ÷ %d\n", n, i);
    }
    puts("Es primo."); // si no encontramos i, tal que n%i == 0, n es primo
}

void coprimos () {
    int num1 = 0, num2 = 0;
    printf("Proporciona un número: ");
    scanf("%d", &num1);
    printf("Proporciona otro número: ");
    scanf("%d", &num2);
    for (int i = 2; i < num1 && i < num2; i++) {
        if (abs(num1 - num2) == 1) {
            printf("La diferencia entre %d y %d es 1 ∴ ", num1, num2);
            break;
        }
        if (num1%i == 0 && num2%i == 0) {
            // si i puede dividir ambos números de manera entera, no son coprimos
            printf("☑ [%d, %d] ÷ %d ∴ No son coprimos.\n", num1, num2, i);
            return;
        }
        printf("☒ [%d, %d] ÷ %d\n", num1, num2, i);
    }
    // si no encontramos i, tal que divida ambos números de manera entera, son coprimos
    puts("Son coprimos.");
}