/*  nombre: Contar vocales y consonantes
    autor: David Emmanuel Santana Romero
    fecha: 8 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>

int main () {
    int a = 0, e = 0, i = 0, o = 0, u = 0, consonantes = 0;
    char keypress = ' ';
    do {
        if (keypress == '\n') continue;
        printf("Ingresa el caracter de la palabra (# para terminar): ");
        keypress = getchar();

        // si es del abecedario
        if ((keypress >= 'a' && keypress <= 'z') || (keypress >= 'A' && keypress <= 'Z')) {
            switch (keypress) {
                // incrementar en uno la cuenta de la vocal correspondiente
                case 'a':
                case 'A':
                    a++;
                    break;
                case 'e':
                case 'E':
                    e++;
                    break;
                case 'i':
                case 'I':
                    i++;
                    break;
                case 'o':
                case 'O':
                    o++;
                    break;
                case 'u':
                case 'U':
                    u++;
                    break;
                // si no era ninguna de las vocales, es consonante, entonces incrementamos la variable en uno
                default:
                    consonantes++;
                    break;
            }
        }
    }
    // si el centinela es presionado, romper el ciclo
    while (keypress != '#');
    printf("Se contabilizaron %d vocales (a = %d, e = %d, i = %d, o = %d, u = %d) y %d consonantes.", (a+e+i+o+u), a, e, i, o, u, consonantes);
    return 0;
}