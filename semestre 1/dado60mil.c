/*  nombre: Un loco tira 60 mil veces y necesita contabilizar su frecuencia
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 25 de octubre de 2022
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TIMES 60000
#define CARAS 6

int main () {
    short dado[TIMES] = {0};
    short frecuencia[CARAS] = {0};
    srand(time(NULL));
    for (int i = 0; i < TIMES; i++) {
        dado[i] = 1 + (rand() % 6);
    }
    for (int i = 0; i < TIMES; i++) {
        frecuencia[dado[i]-1]++;
    }
    for (int i = 0; i < CARAS; i++) {
        printf("La frecuencia de la cara %d fue %d / %d\n", i+1, frecuencia[i], TIMES);
    }
}