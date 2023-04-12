/*  nombre: Herencia múltiple
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    protected:
        float base, altura;
    public:
        Shape ();

        void setBase (float x);
        void setAltura (float x);

        float getBase () const;
        float getAltura () const;
};

class CostoPintura {
    public:
        float getCost (float area) const;
};

class Rectangulo : public Shape, public CostoPintura {
    public:
        float getArea () const;
};

#include "shape.cpp"
#endif