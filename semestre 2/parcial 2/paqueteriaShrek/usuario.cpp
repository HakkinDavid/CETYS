/*  nombre: Usuario (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 15 de marzo de 2023
*/

#include "usuario.h"
#include <iostream>
#include <math.h>
using namespace std;

Usuario :: Usuario () {
    name = "";
    address = "";
    phone = 0;
}
Usuario :: ~Usuario () {
    name = "";
    address = "";
    phone = 0;
    cout << "Usuario con ID " << id << " eliminado" << endl;
    id = 0;
}

void Usuario :: setName (string name) {
    name.resize(20);
    this -> name = name;
}
void Usuario :: setAddress (string address) {
    address.resize(20);
    this -> address = address;
}
void Usuario :: setPhone (long long phone) {
    if ((log10(phone) + 1) > 10) {
        return;
    }
    this -> phone = phone;
}
void Usuario :: setID (int id) {
    this -> id = id;
}

string Usuario :: getName () const {
    return name;
}
string Usuario :: getAddress () const {
    return address;
}
long long Usuario :: getPhone () const {
    return phone;
}
int Usuario :: getID () const {
    return id;
}

void Usuario :: requestData () {
    string n, d;
    long long t;
    cout << "Nombre: ";
    getline(cin, n);
    setName (n);
    cout << "Dirección: ";
    getline(cin, d);
    setAddress (d);
    cout << "Teléfono: ";
    cin >> t;
    getchar();
    setPhone (t);
}