/*  nombre: Cadenas concatenadas
    autor: David Emmanuel Santana Romero
    fecha: 13 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<string.h>

#define SIZE 100

int main () {
    char str[SIZE], str2[SIZE];
    printf("Escribe la primera cadena: ");
    gets(str);
    printf("Escribe la segunda cadena: ");
    gets(str2);

    strcat(str, str2);

    puts("\nCadena concatenada:");
    puts(str);
}