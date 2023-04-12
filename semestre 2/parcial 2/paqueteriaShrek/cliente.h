/*  nombre: Cliente (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 22 de marzo de 2023
*/

#include "usuario.h"
#include <string>
#include <array>
using namespace std;
#ifndef CLIENTE_PAQUETERIA_H
#define CLIENTE_PAQUETERIA_H

class Cliente : public Usuario {
    private:
        array <string, 2> card; // where card[0] is name and card[1] is card number
        bool hasPurchased;
        static int objectCount;
    public:
        Cliente ();
        virtual ~Cliente ();

        void setCardName (string);
        void setCardNumber (string);
        void setHasPurchased (bool);

        string getCardName () const;
        string getCardNumber () const;
        bool getHasPurchased () const;

        void configure ();
        void display () const;
        void purchase ();
};

#include "cliente.cpp"
#endif