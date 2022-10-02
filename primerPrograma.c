/*  nombre: Hola Mundo
    autor: David Emmanuel Santana Romero
    versión: 1.0
*/

#include <stdio.h>

char xyz[5][30] = {
        {'H','E','L','L','O',' ', 'W', 'O', 'R', 'L', 'D'},
        {'D', 'A', 'V', 'I', 'D', ' ', 'E', 'M', 'M', 'A', 'N', 'U', 'E', 'L', ' ', 'S', 'A', 'N', 'T', 'A', 'N', 'A', ' ', 'R', 'O', 'M', 'E', 'R', 'O'},
        {'d', 'e', ' ', 'T', 'E', 'C', 'A', 'T', 'E'},
        {'C', 'E', 'T', 'Y', 'S'},
        {'T', 'E', 'N', 'G', 'O', ' ', 'H', 'A', 'M', 'B', 'R', 'E'}
    };

int main () {
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 30; i++) {
            printf("%c", xyz[j][i]);
        }
        printf("%c", '\n');
    }
    return 0;
}