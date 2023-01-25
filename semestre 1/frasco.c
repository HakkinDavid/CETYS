/*  nombre: Adivina las canicas
    autor: David Emmanuel Santana Romero
    fecha: 4 de octubre de 2022
    descripción: Preguntar a 5 participantes sus estimaciones y dar un ganador
    versión: 1.0
*/

#include<stdio.h>

#define FRASCO 80
#define ADD 12

int main () {
    int id = -1, estimation = -1, dif = -1, frascoGanador = -1;
    for (int i = 0; i < 5; i++) {
        int frasquito = FRASCO + (i*ADD), idAct = 0, estAct = 0;
        printf("[%d]\n", frasquito);
        printf("ID: ");
        scanf("%d", &idAct);
        printf("\tEstimación: ");
        scanf("%d", &estAct);
        /*
        for (int j = 0; j < 2; j++) {
            char r = 'n';
            puts("\t\t¿Cambiar estimación? [s/n]");
            scanf("%s", &r);
            if (r != 's') break;
            printf("\t\t\tEstimación: ");
            scanf("%d", &estAct);
        }
        */

        if (estAct > frasquito) {
            continue;
        }
        else if ((frasquito - estAct) < dif || dif == -1) {
            dif = frasquito - estAct;
            estimation = estAct;
            id = idAct;
            frascoGanador = frasquito;
        }
        printf("<%d, %d, %d, %d>\n", id, estimation, frascoGanador, dif);
    }
    if (id == -1) {
        puts("Felicitaciones. No hubo ganador.");
    }
    else {
        printf("Felicidades, gana el jugador con ID %d, quien estimó %d para un frasco con %d canicas (diferencia de %d).", id, estimation, frascoGanador, dif);
    }
}