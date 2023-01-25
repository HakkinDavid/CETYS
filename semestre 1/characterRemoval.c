/*  nombre: Eliminar el primer caracter dado de una cadena
    autor: David Emmanuel Santana Romero
    fecha: 13 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<string.h>

#define SIZE 100

int main () {
    char str[SIZE] = {0}, resultStr[SIZE] = {0}, c = 0;
    int pos = 0, length = 0;
    printf("Escribe la cadena: ");
    gets(str);
    printf("Escribe el caracter a eliminar: ");
    scanf("%c", &c);

    length = strlen(str);
    pos = (length - strlen(strchr(str, c)));

    for (int i = 0; i < length; i++) {
        if (str[i] == '\0') break;
        if (i < pos) {
            resultStr[i] = str[i];            
        }
        else {
            resultStr[i] = str[i+1];
        }
    }

    printf("Cadena sin el caracter: ");
    puts(resultStr);
}