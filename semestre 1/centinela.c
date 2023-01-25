/*  nombre: Promedio con centinela
    autor: David Emmanuel Santana Romero
    fecha: 30 de septiembre de 2022
    propósito: Obtener el promedio de n alumnos de Métodos de programación
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "es_MX");
    int suma = 0, cal = 0, alumnos = 0;
    float prom = 0.0;
    while (cal != -1) {
        suma += cal;
        alumnos++;
        printf("Calificación del alumno (-1 para salir): ");
        scanf("%d", &cal);
    }
    alumnos--;
    puts("[Centinela detectado]");
    prom = (float) suma / alumnos;
    printf("Promedio: %.2f\n", prom);
}