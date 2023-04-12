/*  nombre: Paquete Two-Day (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 24 de marzo de 2023
*/

#include "pack.h"
#ifndef TWODAY_PACK_H
#define TWODAY_PACK_H

class TwoDayPack : public Pack {
    private:
        float TwoDayCost;
    public:
        TwoDayPack (float, float, float);
        virtual ~TwoDayPack ();

        void setTwoDayCost (float);
        float getTwoDayCost () const;
        float calcTwoDayShippingCost () const;
};

#include "twodaypack.cpp"
#endif