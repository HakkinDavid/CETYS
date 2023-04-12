/*  nombre: Caja con operadores
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de abril de 2023
*/

#ifndef CAJA_OPERADORES_H
#define CAJA_OPERADORES_H

class Caja {
    private:
        float x, y, z;
    public:
        Caja (float, float, float);
        ~Caja ();

        void setX (float);
        void setY (float);
        void setZ (float);

        float getX () const;
        float getY () const;
        float getZ () const;

        void display () const;

        Caja & operator + (const Caja &);
};

#include "caja.cpp"
#endif