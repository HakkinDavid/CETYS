/*  nombre: Programa que despliega una tabla con conversiones de decimal a binario, octal y hexadecimal
    autor: David Emmanuel Santana Romero
    fecha: 8 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<math.h>

// función para obtener los residuos de dividir un valor sobre una base
// hasta agotar sus dígitos
// y almacenarlos en un arreglo
void iterateAndConvert(int resultArray[9], int num, int base, int arraySize) {
    for (int i = (arraySize-1); i >= 0; i--) {
        resultArray[i] = (num%base);
        num /= base;
    }
}

// función para imprimir los elementos de un arreglo de números enteros
void arrayToPrintf(int integerArray[9], int arraySize) {
    int significant = 0;
    for (int i = 0; i < arraySize; i++) {
        if (integerArray[i] > 0) significant = 1; // omitiremos los 0 a la izquierda
        if (significant) printf("%d", integerArray[i]);
        else if (i < (arraySize-1)) printf(" "); // indentado muy rústico para la tabla
    }
    // si no hubo dígitos significativos, imprimir un 0
    if (!significant) printf("0");
}

int main () {
    // encabezados de la tabla
    printf("Decimal\t\tBinario\t\tOctal\t\tHexadecimal\n");
    for (int decimal = 0; decimal <= 256; decimal++) {
            // arreglo de los dígitos binarios,
            // podría hacerse con un simple número (y utilizar el método de las potencias de 10)
            // pero esto nos permite generalizar la función iterateAndConvert(),
            // dado que tenemos valores hexadecimales, procesables con un arreglo
        int bin[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0},
            binRemainder = decimal,

            // mismo caso, arreglo para los dígitos octales
            octal[3] = {0, 0, 0},
            octalRemainder = decimal,

            // mismo caso, arreglo para los dígitos hexadecimales
            temporalHex[3] = {0, 0, 0},
            hexRemainder = decimal;
        
        // cadena de texto que almacenará nuestro número hexadecimal convertido
        char hex [4] = "000";
        iterateAndConvert(bin, binRemainder, 2, 9);
        iterateAndConvert(octal, octalRemainder, 8, 3);
        iterateAndConvert(temporalHex, hexRemainder, 16, 3);

        // traducimos el valor hexadecimal a su cadena
        for (int i = 0; i < 3; i++) {
            if (temporalHex[i] < 10) hex[i] = (char) (48+temporalHex[i]);
            else {
                switch (temporalHex[i]) {
                case 10:
                    hex[i] = 'A';
                    break;
                case 11:
                    hex[i] = 'B';
                    break;
                case 12:
                    hex[i] = 'C';
                    break;
                case 13:
                    hex[i] = 'D';
                    break;
                case 14:
                    hex[i] = 'E';
                    break;
                case 15:
                    hex[i] = 'F';
                    break;
                default:
                    hex[i] = '0';
                    break;
                }
            }
        }

        // imprimir los valores en orden
        printf("%d\t\t", decimal);
        arrayToPrintf(bin, 9);
        printf("\t\t");
        arrayToPrintf(octal, 3);
        printf("\t\t");
        printf("%s\n", hex);
    }
}