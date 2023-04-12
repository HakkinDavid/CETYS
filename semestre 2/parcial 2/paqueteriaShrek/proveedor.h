/*  nombre: Proveedor (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 17 de marzo de 2023
*/

#include <string>
#include "usuario.h"
using namespace std;
#ifndef PROVEEDOR_H
#define PROVEEDOR_H

class Proveedor : public Usuario {
    private:
        string serviceType;
        string company;
        static int objectCount;
    public:
        Proveedor ();
        virtual ~Proveedor ();

        void setServiceType (string);
        void setCompany (string);

        string getServiceType () const;
        string getCompany () const;

        float deliver (int);
        int shippingType ();
        void configure ();
        void display () const; // id, nombre, dirección, teléfono, compañía y servicio
};

#include "proveedor.cpp"
#endif