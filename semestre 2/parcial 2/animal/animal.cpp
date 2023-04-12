/*  nombre: Animal
    autor: David Emmanuel Santana Romero
    fecha: 8 de marzo de 2023
*/

#include <iostream>
#include "animal.h"

using namespace std;

Animal :: Animal () {
    cout << "Se ha creado un animal cuadrúpedo" << endl;
    patas = 4;
}

// setters
void Animal :: setNombre (string x) {
    nombre = x;
}
void Animal :: setColor (string x) {
    color = x;
}

// getters
string Animal :: getNombre () {
    return nombre;
}
string Animal :: getColor () {
    return color;
}
int Animal :: getPatas () {
    return patas;
}

// Animal
void Animal :: display () {
    cout << nombre << " tiene " << patas << " patas y es de color " << color << endl;
}

// Perro
void Perro :: voz () {
    cout << "Woof Woof" << endl;
}

// Puppy
void Puppy :: llorar () {
    cout << "*llora porque es chiquito*" << endl;
}