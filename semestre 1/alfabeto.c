/*  nombre: Programa que imprima el alfabeto
    autor: David Emmanuel Santana Romero
    fecha: 23 de septiembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "spanish");
    char letrita = 'a';
    for (; letrita <= 'z'; letrita++) {
        printf("%c%c", (letrita-32), letrita);
        if (letrita == 'n') printf("Ññ");
    }
    return 0;
}