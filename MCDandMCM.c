/*  nombre: Programa que despliega un menú para determinar primos y coprimos
    autor: David Emmanuel Santana Romero
    fecha: 8 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main() {
    setlocale(LC_ALL, "es_MX");
    int num1 = 0, num2 = 0, i = 0, j = 0;
    printf("Proporciona un número: ");
    scanf("%d", &num1);
    printf("Proporciona otro número: ");
    scanf("%d", &num2);
    // buscamos el número menor (i) y el mayor (j)
    if (num1 < num2) {
        i = num1;
        j = num2;
    }
    else {
        i = num2;
        j = num1;
    }
    // decrementamos i hasta que divida enteramente ambos valores
    for (; i > 0; i--) {
        if (num1%i == 0 && num2%i == 0) {
            printf("MCD para %d y %d es %d\n", num1, num2, i);
            break;
        }
    }
    // incrementamos j hasta que ambos valores le dividan enteramente o sea igual al producto de ambos
    for (; j <= (num1*num2); j++) {
        if (j%num1 == 0 && j%num2 == 0) {
            printf("MCM para %d y %d es %d", num1, num2, j);
            if (j == (num1*num2)) {
                printf(", que además es producto de ambos números");
            }
            break;
        }
    }
    return 0;
}