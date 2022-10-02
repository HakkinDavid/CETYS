/*  nombre: Convertir los días en formato de años, semanas y días
    autor: David Emmanuel Santana Romero, en equipo con Fernando Pulido Mendivil
    fecha: 31 de agosto de 2022
    propósito: Dar formato de años, semanas y días a una cantidad de días cualesquiera
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "es_MX");
    int days, years, weeks;
    printf("Escribe el número de días: ");
    scanf("%d", &days);
    years = floor(days/365);
    days = days % 365;
    weeks = floor(days/7);
    days = days % 7;
    printf("%d años, %d semanas, %d días.", years, weeks, days);
    return 0;
}