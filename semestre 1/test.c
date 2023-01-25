#include <stdio.h>
#define SIZE 1000000000000000
long double A [SIZE];

int main() {
    printf("A[%Ld] = %Lf", SIZE, A[SIZE]);
    return 0;
}