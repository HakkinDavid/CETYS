#include<stdio.h>
#include<string.h>
#define SIZE 100
int main () {
    char str[SIZE];

    printf("Nombre completo: ");
    scanf_s("%[^\n]s", str);
    getchar();
    printf("Tu nombre es %s", str);
}