/*  nombre: Librería de la factura (implementación)
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <iostream>

// user defined library header
#include "factura.h"

using namespace std;

// constructor and destructor declaration
Factura :: Factura (int providedID, string desc, int providedPrice) {
    this -> ID = providedID;
    this -> description = desc;

    if (providedPrice < 0) {
        providedPrice = 0;
        cout << "El precio no puede ser menor a cero." << endl;
    }
    this -> price = providedPrice;
    this -> amount = 0;
}

Factura :: ~Factura () {
    ID = 0;
    price = 0;
    amount = 0;
    description = "";
}

// setters implementation
void Factura :: setID (int x) {
    ID = x;
}
void Factura :: setDesc (string desc) {
    description = desc;
}
void Factura :: setPrice (int x) {
    price = x;
}
void Factura :: setAmount (int x) {
    amount = x;
    if (amount < 0) {
        amount = 0;
        cout << "La cantidad de elementos no puede ser negativa. ¿Acaso estás pidiendo un reembolso? Para eso necesitas la factura ... Misma que te impido generar. Qué ironías de la vida, ¿no?" << endl;
    }
}

// getters implementation
int Factura :: getID () const {
    return ID;
}
string Factura :: getDesc () const {
    return description;
}
int Factura :: getPrice () const {
    return price;
}
int Factura :: getAmount () const {
    return amount;
}

// other functions implementation
int Factura :: cobrar () {
    return price * amount;
}