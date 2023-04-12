/*	nombre: Usuario
	autor: David Emmanuel Santana Romero
	fecha: 31 de marzo de 2023
	descripción: Define un usuario
*/

#include <iostream>
#include "usuario.h"

Usuario :: Usuario (string name) {
    this -> name = name;
}
Usuario :: ~Usuario () {
    cout << "Usuario " << name << " con ID " << id << " eliminado";
    name = "";
    id = 0;
}

void Usuario :: setName (string name) {
    this -> name = name;
}
void Usuario :: setID (int id) {
    this -> id = id;
}

string Usuario :: getName () const {
    return name;
}
int Usuario :: getID () const {
    return id;
}