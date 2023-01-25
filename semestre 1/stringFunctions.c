/*  nombre: Funciones de cadenas de texto
    autor: David Emmanuel Santana Romero
    fecha: 8 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<string.h>

int main () {
    char nombre[50] = "David", ciudad[] = "Tecate", escuela[] = "CETYS Universidad", juego[] = "Doom";

    // strlen
    printf_s("La longitud de la cadena de texto %s es %d\n", escuela, strlen(escuela));

    //strcat
    strcat(nombre, " Emmanuel Santana Romero");
    printf_s("Mi nombre es %s\n", nombre);

    //strcpy
    strcpy(nombre, "Ajax");
    printf_s("El nuevo valor de \"nombre\" es %s\n", nombre);

    //strcmp
    strcmp(nombre, "David") == 0 ? printf("Me llamo David.") : printf("Wade Wilson, ¿cómo me llamo?");

    //strlwr
    strlwr(juego);
    printf_s("\nNo se dice %s, ", juego);

    //strupr
    strupr(juego);
    printf_s("se dice %s\n", juego);

    //strchr
    printf_s("%s\n", strchr(ciudad, 'e'));

    //strrchr
    printf_s("%s\n", strrchr(ciudad, 'e'));

    //strstr
    printf_s("%s\n", strstr(escuela, "Uni"));
}