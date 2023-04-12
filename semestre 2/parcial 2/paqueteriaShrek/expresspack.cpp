/*  nombre: Paquete Express (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 24 de marzo de 2023
*/

#include "expresspack.h"

ExpressPack :: ExpressPack (float weight, float shippingCost, float ExpressCost) : Pack (weight, shippingCost) {
    this -> ExpressCost = ExpressCost;
}
ExpressPack :: ~ExpressPack () {
    ExpressCost = 0;
}
void ExpressPack :: setExpressCost (float ExpressCost) {
    this -> ExpressCost = ExpressCost;
}
float ExpressPack :: getExpressCost () const {
    return ExpressCost;
}
float ExpressPack :: calcExpressShippingCost () const {
    return calcCost () + getExpressCost ();
}

using namespace std;