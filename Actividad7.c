/* Fernando Pulido, David Santana, 31/08/22, Version: 1.0, Actividad 7: Convertir Celsius a Fahrenheit */
#include <stdio.h>
#include <math.h>

int main()
{
    float grados = 0;
    float res = 0;
    printf("Dame Celsius: \n");
    scanf("%f", &grados);
    res = (grados * 1.8) + 32.0;
    printf("Fahrenheit: %.1f", res);
    return 0;
}