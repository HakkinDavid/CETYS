/*  nombre: Paquete Express (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 24 de marzo de 2023
*/

#include "pack.h"
#ifndef EXPRESS_PACK_H
#define EXPRESS_PACK_H

class ExpressPack : public Pack {
    private:
        float ExpressCost;
    public:
        ExpressPack (float, float, float);
        virtual ~ExpressPack ();

        void setExpressCost (float);
        float getExpressCost () const;
        float calcExpressShippingCost () const;
};

#include "expresspack.cpp"
#endif