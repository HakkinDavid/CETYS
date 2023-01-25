#include<stdio.h>
#include<string.h>
#define SIZE 100
#define SIZE2 150
int main () {
    char str[SIZE];
    char str1[SIZE2];
    printf("Nombre completo: ");
    fgets(str, 100, stdin);

    printf("Dirección: ");
    gets(str1);

    printf("Tu nombre es %s y vives en %s\n", str, str1);
    printf("DOXXEADÍSIMO");
}