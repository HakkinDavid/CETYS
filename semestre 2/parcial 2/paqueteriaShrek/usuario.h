/*  nombre: Usuario (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 15 de marzo de 2023
*/

#include <string>
#include <iostream>
using namespace std;

#ifndef PAQUETERIA_USUARIO_H
#define PAQUETERIA_USUARIO_H

class Usuario {
    private:
        string name;
        string address;
        long phone;
        int id;
    public:
        Usuario ();
        virtual ~Usuario ();

        void setName (string);
        void setAddress (string);
        void setPhone (long long);
        void setID (int);

        string getName () const;
        string getAddress () const;
        long long getPhone () const;
        int getID () const;
    protected:
        void requestData ();
};

#include "usuario.cpp"
#endif