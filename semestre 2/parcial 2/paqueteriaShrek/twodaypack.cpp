/*  nombre: Paquete TwoDay (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 24 de marzo de 2023
*/

#include "twodaypack.h"

TwoDayPack :: TwoDayPack (float weight, float shippingCost, float TwoDayCost) : Pack (weight, shippingCost) {
    this -> TwoDayCost = TwoDayCost;
}
TwoDayPack :: ~TwoDayPack () {
    TwoDayCost = 0;
}
void TwoDayPack :: setTwoDayCost (float TwoDayCost) {
    this -> TwoDayCost = TwoDayCost;
}
float TwoDayPack :: getTwoDayCost () const {
    return TwoDayCost;
}
float TwoDayPack :: calcTwoDayShippingCost () const {
    return calcCost () + getTwoDayCost ();
}

using namespace std;