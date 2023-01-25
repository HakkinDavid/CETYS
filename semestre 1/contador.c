/*  nombre: Promedio
    autor: David Emmanuel Santana Romero
    fecha: 20 de septiembre de 2022
    propósito: Obtener el promedio de un grupo de Métodos de programación
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "es_MX");
    int suma = 0, cal = 0, alumnos = 0, passed = 0;
    float prom = 0.0;
    printf("Cantidad de alumnos: ");
    scanf("%d", &alumnos);
    for (int i = 0; i < alumnos; i++) {
        printf("Calificación del alumno %d: ", (i+1));
        scanf("%d", &cal);
        suma += cal;
        if (cal > 7) passed++;
    }
    prom = (float) suma / alumnos;
    printf("Promedio: %f\n", prom);
    (passed >= (alumnos / 2)) ? printf("¡Aprobaron %d de sus alumnos (%d%%)!", passed, (passed * 100 / alumnos)) : printf("¿Qué pasó ahí, profe?");
}