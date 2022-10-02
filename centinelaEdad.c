/*  nombre: Centinela con edad
    autor: David Emmanuel Santana Romero
    fecha: 30 de septiembre de 2022
    propósito: Preguntar la edad hasta que se obtenga una válida
    versión: 1.0
*/

#include <stdio.h>
#define MINEDAD 18

int main () {
    int attempts = 0, edad = 0;
    puts("  ____   __   __ __   __   ____\n / __ \\  \\ \\ / / \\ \\ / /  / __ \\\n| |  | |  \\ V /   \\ V /  | |  | |\n| |  | |   > <     > <   | |  | |\n| |__| |  / . \\   / . \\  | |__| |\n \\____/  /_/ \\_\\ /_/ \\_\\  \\____/ ");
    puts("¡Estamos contratando!");
    do {
        if (attempts > 0) printf("No aceptamos menores de edad. [Intentos: %d]\n", attempts);
        printf("Proporciona tu edad: ");
        scanf("%d", &edad);
        attempts++;
    } while (edad < MINEDAD && attempts < 5);
    if (edad >= MINEDAD) {
        puts("Excelente. Lamentablemente, ahora que vemos su currículo, no lo podemos contratar. Necesita un doctorado en administración de negocios internacionales.");
    }
    else {
        puts("Estás muy chavo.");
    }
    return 0;
}