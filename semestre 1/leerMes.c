/*  nombre: Leer un número entero y desplegar el mes
    autor: David Emmanuel Santana Romero
    fecha: 7 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>

int main() {
    int mes = 0;
    printf("Especifica el número del mes: ");
    scanf("%d", &mes); // asignamos el número del mes
    switch (mes) {
        case 1:
            puts("Enero");
            break;
        case 2:
            puts("Febrero");
            break;
        case 3:
            puts("Marzo");
            break;
        case 4:
            puts("Abril");
            break;
        case 5:
            puts("Mayo");
            break;
        case 6:
            puts("Junio");
            break;
        case 7:
            puts("Julio");
            break;
        case 8:
            puts("Agosto");
            break;
        case 9:
            puts("Septiembre");
            break;
        case 10:
            puts("Octubre");
            break;
        case 11:
            puts("Noviembre");
            break;
        case 12:
            puts("Diciembre");
            break;
        default:
            puts("No es un mes."); // si el valor es diferente a [1-12], no es un mes del año
            break;
    }
    return 0;
}