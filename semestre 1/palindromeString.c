/*  nombre: Cadena palíndromo
    autor: David Emmanuel Santana Romero
    fecha: 13 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 100

int main () {
    char str[SIZE];
    int length = 0;
    bool palindrome = true;
    printf("Escribe la cadena: ");
    gets(str);
    length = strlen(str);
    for (int i = 0, offsetLeft = 0, offsetRight = 0; (i+offsetLeft) < length && (length-i+offsetRight) > 0; i++) {
        if (str[(i+offsetLeft)] == ' ') offsetLeft++;
        if (str[length-1-(i+offsetRight)] == ' ') offsetRight++;
        if (str[(i+offsetLeft)] != str[length-1-(i+offsetRight)]) {
            palindrome = false;
            printf("El primer caracter diferente es %c comparado con %c, en las posiciones %d y %d, del total %d.\n", str[(i+offsetLeft)], str[length-1-(i+offsetRight)], (i+offsetLeft)+1, (length-(i+offsetRight)), length);
            break;
        }
    }
    palindrome ? puts("Es un palíndromo.") : puts("No es un palíndromo.");
}