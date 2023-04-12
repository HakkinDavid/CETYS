/*  nombre: Librería de la factura
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <string>
using namespace std;

// include guards
#ifndef CREATE_FACTURA_H
#define CREATE_FACTURA_H

// define class

class Factura {
    public:
        // prototipos
        Factura(int, string, int);
        ~Factura();

        void setID(int);
        void setDesc(string);
        void setPrice(int);
        void setAmount(int);

        int getID() const;
        string getDesc() const;
        int getPrice() const;
        int getAmount() const;

        int cobrar();
    private:
        int ID, price, amount;
        string description = "No compren en la Walmart, larga vida a Calimax. Tampoco compren en Coppel, les sale muy caro. No desperdicien en bolsas de plástico.";
};

#include "factura.cpp"
#endif