/*  nombre: Paquete (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 22 de marzo de 2023
*/

#include <iostream>
#include "pack.h"

using namespace std;

int Pack::objectCount = 0;

Pack :: Pack (float weight, float shippingCost) {
    this -> weight = weight;
    this -> shippingCost = shippingCost;
    setID (++objectCount);
}
Pack :: Pack () {
    weight = 0.0;
    shippingCost = 0.0;
    packType = "";
    setID (++objectCount);
}
Pack :: ~Pack () {
    weight = 0.0;
    shippingCost = 0.0;
    packType = "";
}

void Pack :: setID (int id) {
    this -> id = id;
}
void Pack :: setWeight (float weight) {
    this -> weight = weight;
}
void Pack :: setShippingCost (float shippingCost) {
    this -> shippingCost = shippingCost;
}
void Pack :: setPackType (string packType) {
    this -> packType = packType;
}

int Pack :: getID () const {
    return id;
}
float Pack :: getWeight () const {
    return weight;
}
float Pack :: getShippingCost () const {
    return shippingCost;
}
string Pack :: getPackType () const {
    return packType;
}

float Pack :: calcCost() const {
    return getShippingCost () * getWeight ();
}