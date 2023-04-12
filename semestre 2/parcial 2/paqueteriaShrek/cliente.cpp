/*  nombre: Cliente (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 22 de marzo de 2023
*/

#include "cliente.h"
using namespace std;

int Cliente::objectCount = 0;

Cliente :: Cliente () {
    setID(++objectCount);
    hasPurchased = false;
}

Cliente :: ~Cliente () {
    card[0] = "";
    card[1] = "";
}

void Cliente :: setCardName (string n) {
    n.resize(20);
    this -> card[0] = n;
}

void Cliente :: setCardNumber (string n) {
    if (n.size() == 19) {
        // remove dashes
        n.erase (4, 1);
        n.erase (8, 1);
        n.erase (12, 1);
    }
    if (n.size() != 16) {
        cout << "No parece un número de tarjeta" << endl;
        return;
    } else {
        for (const auto &x : n) {
            if (!(&x >= "0" && &x <= "9")) {
                cout << "Hay caracteres que no son números en tu número de tarjeta" << endl;
                return;
            }
        }
    }
    this -> card[1] = n;
}

void Cliente :: setHasPurchased (bool p) {
    hasPurchased = p;
}

string Cliente :: getCardName () const {
    return card[0];
}

string Cliente :: getCardNumber () const {
    return card[1];
}

bool Cliente :: getHasPurchased () const {
    return hasPurchased;
}

void Cliente :: configure () {
    string cardName, cardNumber;
    requestData ();
    cout << "Nombre en la tarjeta: ";
    getline(cin, cardName);
    setCardName(cardName);
    cout << "Número de tarjeta: ";
    getline(cin, cardNumber);
    setCardNumber(cardNumber);
}

void Cliente :: display () const {
    cout << "CLIENTE" << endl;
    cout << "Nombre: " << getName() << endl;
    cout << "Dirección: " << getAddress() << endl;
    cout << "Teléfono: " << getPhone() << endl;
    cout << "Nombre en la tarjeta: " << getCardName() << endl;
    cout << "Número de tarjeta: " << getCardNumber() << endl;
}
        
void Cliente :: purchase () {
    int cvv;
    cout << "[Comprar] CVV: " << endl;
    cin >> cvv;
    if (cvv < 0 || cvv > 999 || (rand () % 100 + 1) < 20) {
        cout << "Tarjeta rechazada" << endl;
        return;
    }
    setHasPurchased(true);
    cout << "Compra exitosa" << endl;
}