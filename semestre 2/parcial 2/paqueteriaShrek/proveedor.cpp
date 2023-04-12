/*  nombre: Proveedor (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 17 de marzo de 2023
*/

#include "proveedor.h"
#include "pack.h"
#include "twodaypack.h"
#include "expresspack.h"
using namespace std;

int Proveedor::objectCount = 0;

Proveedor :: Proveedor () {
    setID(++objectCount);
}
Proveedor :: ~Proveedor () {
    serviceType = "";
    company = "";
}
void Proveedor :: setServiceType (string serviceType) {
    this -> serviceType = serviceType;
}
void Proveedor :: setCompany (string company) {
    this -> company = company;
}
string Proveedor :: getServiceType () const {
    return serviceType;
}
string Proveedor :: getCompany () const {
    return company;
}
void Proveedor :: configure () {
    string c, s;
    requestData ();
    cout << "Compañía: ";
    getline(cin, c);
    setCompany(c);
    cout << "Servicio: ";
    getline(cin, s);
    setServiceType(s);
}
void Proveedor :: display () const {
    cout << "PROVEEDOR" << endl;
    cout << "Nombre: " << getName() << endl;
    cout << "Dirección: " << getAddress() << endl;
    cout << "Teléfono: " << getPhone() << endl;
    cout << "Compañía: " << getCompany() << endl;
    cout << "Servicio: " << getServiceType() << endl;
}

int Proveedor :: shippingType () {
    int option;
    cout << "Tipo de entrega" << endl << "1. Entrega" << endl << "2. Express" << endl << "3. Two-day" << endl;
    do {
        cout << "Elige una opción" << endl;
        cin >> option;
    } while (option < 0 || option > 3);
    return option;
}

float Proveedor :: deliver (int option) {
    float weight, cost, extra;
    cout << "Peso [kg]: ";
    cin >> weight;
    cout << "Costo de envío base [$]: ";
    cin >> cost;
    if (option == 2) {
        cout << "Tarifa express [$]: ";
        cin >> extra;
        ExpressPack p (weight, cost, extra);
        return p.calcExpressShippingCost();
    }
    else if (option == 3) {
        cout << "Tarifa Two-Day [$]: ";
        cin >> extra;
        TwoDayPack p (weight, cost, extra);
        return p.calcTwoDayShippingCost();

    }
    else {
        if (option != 1) cout << "Se asume [1]" << endl;
        Pack p (weight, cost);
        return p.calcCost();
    }
}