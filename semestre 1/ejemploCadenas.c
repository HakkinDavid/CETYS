#include<stdio.h>
#define SIZE 20
int main() {
    char str[SIZE] = "";
    char str1[] = "Que acabe el semestre";
    printf("Cadena de 19 o menos caracteres: ");
    scanf_s("%19s", str);

    printf("Cadena 1 es: %s\n", str);
    printf("Cadena 2 es: %s\n", str1);

    for (int i = 0; i < SIZE && str[i] != '\0'; i++) printf("%c ", str[i]);
    puts("");
}