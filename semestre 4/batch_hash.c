#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define HASH_SIZE 64
#define HASH_BROWN 59.90 // por KG (ref. Central Detallista S.A. de C.V.)
#define max_rand_word_size 1793

const int primos[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
char english_words[max_rand_word_size] = "hello\0world\0good\0morning\0afternoon\0evening\0night\0day\0time\0love\0hate\0friend\0enemy\0happy\0sad\0angry\0beautiful\0ugly\0kind\0cruel\0big\0small\0fast\0slow\0high\0low\0up\0down\0left\0right\0goodbye\0yes\0no\0please\0thank\0you\0welcome\0sorry\0excuse\0me\0apple\0banana\0orange\0grape\0strawberry\0melon\0watermelon\0kiwi\0pineapple\0pear\0dog\0cat\0bird\0fish\0horse\0cow\0sheep\0pig\0rabbit\0turtle\0car\0bus\0train\0bicycle\0motorcycle\0airplane\0boat\0ship\0rocket\0submarine\0school\0university\0teacher\0student\0book\0pen\0pencil\0desk\0chair\0board\0sun\0moon\0star\0sky\0earth\0planet\0space\0galaxy\0nebula\0universe\0tree\0flower\0grass\0leaf\0root\0branch\0trunk\0bark\0wood\0forest\0mountain\0hill\0valley\0plain\0plateau\0canyon\0river\0stream\0lake\0ocean\0house\0home\0room\0kitchen\0bathroom\0bedroom\0livingroom\0diningroom\0garage\0yard\0computer\0internet\0website\0email\0software\0hardware\0program\0code\0data\0file\0music\0song\0dance\0instrument\0guitar\0piano\0violin\0drum\0trumpet\0flute\0movie\0film\0actor\0actress\0director\0producer\0screenplay\0scene\0camera\0cinema\0art\0painting\0sculpture\0drawing\0artist\0gallery\0exhibition\0museum\0masterpiece\0creative\0sport\0football\0soccer\0basketball\0tennis\0volleyball\0swimming\0running\0cycling\0golf\0food\0meal\0breakfast\0lunch\0dinner\0snack\0drink\0water\0juice\0soda\0friendship\0family\0relationship\0marriage\0divorce\0parent\0child\0sibling\0brother\0sister\0job\0work\0career\0employer\0employee\0office\0company\0business\0meeting\0presentation\0money\0cash\0currency\0bank\0account\0credit\0debit\0loan\0investment\0wealth\0health\0fitness\0exercise\0nutrition\0diet\0doctor\0hospital\0medicine\0therapy\0wellness\0sleep\0dream\0awake\0tired\0rest\0energy\0effort\0success\0failure\0victory\0challenge\0problem\0solution\0question\0answer\0knowledge\0wisdom\0learning\0education\0school\0hope\0faith\0belief\0doubt\0fear\0courage\0strength\0weakness\0power\0control\0freedom\0justice\0equality\0rights\0law\0order\0chaos\0peace\0war\0conflict\0";

void hash_brown (char* input, char* output) { // tomar cadenas de 
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
    int offset = 0;
    while (offset < max_rand_word_size && english_words[offset] != '\0') {
        char input [HASH_SIZE] = {0};
        int j = 0;
        for (int i = offset; i < max_rand_word_size && j < HASH_SIZE; i++) {
            input[j++] = english_words[i];
            if (english_words[i] == '\0') {
                offset = ++i;
                break;
            }
        }
        char output [HASH_SIZE] = {0};
        printf("\nEntrada: %s", input);
        hash_brown(input, output);
        printf("\nSalida: %s", output);
    }
    _getch();
}