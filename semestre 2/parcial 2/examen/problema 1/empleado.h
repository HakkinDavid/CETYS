/*	nombre: Empleado (derivado de Usuario)
	autor: David Emmanuel Santana Romero
	fecha: 31 de marzo de 2023
	descripción: Define un empleado
*/

#include "usuario.h"
#include "cliente.h"
#include "proveedor.h"
#include <vector>

#ifndef EMPLEADO_EXAMEN_H
#define EMPLEADO_EXAMEN_H

class Empleado : public Usuario {
    private:
        static int objectCount;
        vector <pair<int, vector <pair <int, int>>>> requested;
    public:
        Empleado ();
        ~Empleado ();

        void requestBooks (int, int, int);
        void serveUser (int);

        void createUser ();
        void removeUser (Usuario &u);
};

#include "empleado.cpp"
#endif