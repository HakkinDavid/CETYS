/*  nombre: Obtener el valor de y
    autor: David Emmanuel Santana Romero
    fecha: 7 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<math.h>

int main() {
    int x = 0, y = 0;
    printf("Proporciona un valor de x: ");
    scanf("%d", &x);
    // le damos a y el valor resultante de aplicar la función correspondiente
    switch (x) {
        case -1:
            y = pow(x, 2);
            break;
        case 0:
            y = x/2;
            break;
        case 1:
            y = x;
            break;
        case 2:
        case 3:
            y = 2*(x+1);
            break;
        default:
            y = 0;
            break;
    }
    printf("y = %d", y);
    return 0;
}