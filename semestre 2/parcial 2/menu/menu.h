/*  nombre: Menú
    autor: David Emmanuel Santana Romero
    fecha: 9 de marzo de 2023
*/

#include <vector>
#include <string>
#include <functional>
using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu {
    private:
        vector<pair<char, pair<string, function<void()>>>> options;
        string header;
    public:
        Menu (vector<pair<char, pair<string, function<void()>>>>, string);

        void display(bool, bool);

        void press(bool);

};

#include "menu.cpp"
#endif