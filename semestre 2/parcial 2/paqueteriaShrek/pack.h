/*  nombre: Paquete (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 22 de marzo de 2023
*/

#include <string>
#ifndef PACK_H
#define PACK_H

class Pack {
    private:
        int id;
        static int objectCount;
        float weight, shippingCost;
        string packType;
    public:
        Pack ();
        Pack (float, float);
        virtual ~Pack ();

        void setID (int);
        void setWeight (float);
        void setShippingCost (float);
        void setPackType (string);

        int getID () const;
        float getWeight () const;
        float getShippingCost () const;
        string getPackType () const;

        float calcCost() const;
};

#include "pack.cpp"
#endif