#include<stdio.h>
#include<math.h>
#define PI 3.141592

// declaración de funciones (prototipos)
double diameter(double radio);
double circumference(double radio);
double area(double radio);

int main() {
    float radio, d, circle, areaC;
    printf("Ingresa el radio: ");
    scanf("%f", &radio);
    d = diameter(radio);
    circle = circumference(radio);
    areaC = area(radio);

    printf("El círculo tiene un diámetro de %.2f, circunferencia de %.2f y área de %.2f", d, circle, areaC);
}

double diameter (double radio) {
    return (2 * radio);
}

double circumference(double radio) {
    return (2 * radio * PI);
}

double area(double radio) {
    return (PI * radio * radio);
}