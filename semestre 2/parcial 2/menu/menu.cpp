/*  nombre: Menú
    autor: David Emmanuel Santana Romero
    fecha: 9 de marzo de 2023
*/

#include "menu.h"
#include <iostream>
#include <cstdio>
using namespace std;

Menu :: Menu (vector<pair<char, pair<string, function<void()>>>> options, string header = "") {
    this -> options = options;
    this -> header = header;
}

void Menu :: display (bool callPress = false, bool loop = false) {
    if (header.size() > 0) cout << header << endl;
    for (const auto &i : options) {
        cout << "[" << i.first << "] " << i.second.first << endl;
    }
    cout << "[-] Salir" << endl;
    if (callPress) press (loop);
}

void Menu :: press (bool loop = false) {
    char key = 0;
    bool found = false;
    cout << ">> ";
    cin >> key;
    system ("cls");
    if (key == 45) {
        return;
    }
    getchar();
    for (const auto &i : options) {
        if (i.first == key) {
            found = true;
            i.second.second();
            break;
        }
    }
    if (!found) {
        press (true);
    }
    else if (loop) {
        display();
        press(true);
    }
}