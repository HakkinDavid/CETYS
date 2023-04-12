/*  nombre: Animal
    autor: David Emmanuel Santana Romero
    fecha: 8 de marzo de 2023
*/

#include <iostream>
#include <string>
#include "animal.h"
using namespace std;

void configurar (Animal &p, string type) {
    string nombre, color;
    cout << "Nombre del " << type << ": ";
    cin >> nombre;
    cout << "Color: ";
    cin >> color;

    p.setNombre(nombre);
    p.setColor(color);
}

int main () {
    Perro canino;
    configurar(canino, "canino");

    Puppy chiquito;
    configurar(chiquito, "cachorro");
    
    cout << endl << endl;

    canino.display();
    canino.voz();

    cout << endl << endl;
    
    chiquito.display();
    chiquito.voz();
    chiquito.llorar();
}