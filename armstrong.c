/*  nombre: Números Armstrong
    autor: David Emmanuel Santana Romero
    fecha: 11 de noviembre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<stdbool.h>

#define RANGO 1000

bool isArmstrong(int num);
int digits(int num);
int powerAde(int num, int power);

int main() {
    int armstrongN = 0;
    for (int i = 1; i <= RANGO; i++) {
        if (isArmstrong(i)) armstrongN++;
    }

    printf("Del 1 al %d hay %d números Armstrong.", RANGO, armstrongN);
}

bool isArmstrong(int num) {
    int potencia = digits(num),
        n = num,
        suma = 0;
    while (n > 0) {
        suma += powerAde((n%10), potencia);
        n /= 10;
    }
    if (suma == num) {
        printf("%d 💪\n", num);
        return true;
    }
    else return false;
}

int digits(int num) {
    int digitN = 0;
    while (num > 0) {
        digitN++;
        num /= 10;
    }
    return digitN;
}

int powerAde(int num, int power) {
    if (power == 0) return 0;
    int resultado = num;
    for (int i = 0; i < power; i++) {
        resultado *= num;
    }
    return resultado;
}