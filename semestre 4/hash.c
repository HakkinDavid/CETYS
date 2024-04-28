#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define HASH_SIZE 64
#define HASH_BROWN 59.90 // por KG (ref. Central Detallista S.A. de C.V.)

const int primos[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

void hash_brown (char* input, char* output) { 
    srand(input[0]);
    const int prime_seed = primos[rand() % 12];
    int input_size = 0;
    bool input_terminated = false;
    for (int i = 0; i < HASH_SIZE - 1; i++) {
        if (input[i] != '\0' && !input_terminated) {
            output[i] = input[i] ^ prime_seed;
            input_size++;
        }
        else {
            input_terminated = true;
            output[i] = input[rand() % input_size] ^ prime_seed << 1;
        }
    }
    srand(HASH_BROWN + input_size);
    for (int i = HASH_SIZE - 1; i >= 0; i--) {
        output[i] = output[i] ^ primos[rand() % 12] >> 1;
        if (output[i] < 32) output[i] = 104; // en caso de generar un caracter no legible, establecer en 104 (h de hash brown)
        srand(output[i] + input_size);
    }
    output [HASH_SIZE - 1] = '\0';
}

int main () {
    char input [HASH_SIZE] = {0}; char output [HASH_SIZE] = {0};
    printf("🥔HASH BROWN FUNCTION🥔\nEntrada: ");
    fgets(input, HASH_SIZE, stdin);
    for (int i = 0; i < 64; i++) {
        char b = input[i];
        for (int j = 0; j < 8; j++) {
            printf("%d", !!((b << j) & 0x80));
        }
        printf(" ");
    }
    printf("\n");
    hash_brown(input, output);
    printf("\nSalida: %s\n", output);
    for (int i = 0; i < 64; i++) {
        char b = output[i];
        for (int j = 0; j < 8; j++) {
            printf("%d", !!((b << j) & 0x80));
        }
        printf(" ");
    }
    printf("\nPresiona cualquier tecla para salir.");
    _getch();
}