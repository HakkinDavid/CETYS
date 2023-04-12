/*  nombre: Menú
    autor: David Emmanuel Santana Romero
    fecha: 9 de marzo de 2023
*/

#include <iostream>
#include <string>
#include <vector>
#include "menu.h"

using namespace std;

void A () {
    cout << "Una A" << endl;
}

void B () {
    cout << "Una B" << endl;
}
/*
vector<pair<char, pair<string, function<void()>>>> options = {
    {'a', {"Desplegar A", A}},
    {'b', {"Desplegar B", B}}
};
*/
int main () {
    Menu menu ({
        {'a', {"Desplegar A", A}},
        {'b', {"Desplegar B", B}}
    });
    menu.display();
    menu.press(true);
}