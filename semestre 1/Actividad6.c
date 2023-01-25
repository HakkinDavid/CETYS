/* Fernando Pulido, David Santana, 30/08/22, Version: 1.0, Actividad 6: usar pow para encontrar la potencia de un numero entero */
#include <stdio.h>
#include <math.h>
int main()
{
    float res = 0;
    float base = 0;
    float exp = 0;
    printf("Dame la base : \n");
    scanf("%f", &base);
    printf("Dame el exponente: \n");
    scanf("%f", &exp);
    res = pow(base, exp);
    printf("%.2f", res);

    return 0;
}