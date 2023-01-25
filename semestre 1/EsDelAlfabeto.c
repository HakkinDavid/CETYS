/*  nombre: ¿Es del alfabeto?
    autor: David Emmanuel Santana Romero
    fecha: 13 de septiembre de 2022
    versión: 1.0
*/

#include<stdio.h>

int main() {
    char c;
    printf("Indica un caracter a evaluar: ");
    scanf("%c", &c);
    (c >= 'a' && c<= 'z') || (c >= 'A' && c<= 'Z') ? printf("%c pertenece al alfabeto", c) : printf("%c no pertenece al alfabeto", c);
    return 0;
}