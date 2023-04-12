/*  nombre: Clase caja
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 3 de marzo de 2023
*/

#ifndef CAJA_H
#define CAJA_H

class Caja {
    private:
        int largo, ancho;
    public:
        Caja ();
        friend void printDimensions (Caja&);
};

#include "caja.cpp"
#endif