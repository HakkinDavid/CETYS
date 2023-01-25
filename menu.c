/*  nombre: Programa que despliega un menú
    autor: David Emmanuel Santana Romero
    fecha: 2 de octubre de 2022
    versión: 1.0
*/

#include<stdio.h>
#include<locale.h>

void menu ();
void triangle ();
void rectangle ();

int main() {
    setlocale(LC_ALL, "es_MX");
    char keypress;
    do {
        menu();
        scanf("%s", &keypress);
        switch (keypress) {
            case 's':
                puts("Programa para calcular áreas");
                break;
            case 't':
                triangle();
                break;
            case 'r':
                rectangle();
                break;
            case 'q':
                puts("Nos vemos luego.");
                break;
            default:
                printf("[%c] Opción no reconocida.\n", keypress);
                break;
        }
    }
    while (keypress != 'q');
    return 0;
}

void menu () {
    puts("M E N Ú");
    puts("[S] Start");
    puts("[T] Triángulo");
    puts("[R] Rectángulo");
    puts("[Q] Quit");
}

void triangle () {
    int base = 0, altura = 0;
    float area = 0.0;
    puts("-> Triángulo");
    printf("Valor de la base: ");
    scanf("%d", &base);
    printf("Valor de la altura: ");
    scanf("%d", &altura);
    area = (float) (base*altura)/2;
    printf("El área es %.2f unidades.\n", area);
}

void rectangle () {
    int base = 0, altura = 0;
    puts("-> Rectángulo");
    printf("Valor de la base: ");
    scanf("%d", &base);
    printf("Valor de la altura: ");
    scanf("%d", &altura);
    printf("El área es %d unidades.\n", (base*altura));
}