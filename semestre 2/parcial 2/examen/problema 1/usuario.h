/*	nombre: Usuario
	autor: David Emmanuel Santana Romero
	fecha: 31 de marzo de 2023
	descripción: Define un usuario
*/

#include <string>
using namespace std;

#ifndef USUARIO_EXAMEN_H
#define USUARIO_EXAMEN_H

class Usuario {
    private:
        string name;
        int id;
    public:
        Usuario (string);
        ~Usuario ();

        void setName (string);
        void setID (int);

        string getName () const;
        int getID () const;
};

#include "usuario.cpp"
#endif