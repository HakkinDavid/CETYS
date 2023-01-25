/*  nombre: Centinela con pregunta
    autor: David Emmanuel Santana Romero
    fecha: 30 de septiembre de 2022
    propósito: Preguntar hasta que se obtenga la respuesta correcta
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

#define PREGUNTA "¿Cuánto es 8-3?"
#define RESPUESTA 5

int main() {
    setlocale(LC_ALL, "es_MX");
    int resultado = 0;
    int i = 0;

    do {
        printf("%s", PREGUNTA);
        scanf("%d", &resultado);
        i++;
    }
    while (resultado != RESPUESTA);

    (i > 1) ? printf("Termina tu primaria.") : printf("¡Bien hecho!");
    return 0;
}