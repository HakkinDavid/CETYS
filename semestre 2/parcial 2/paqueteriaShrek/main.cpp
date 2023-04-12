/*  nombre: Main (de Paquetería)
    autor: David Emmanuel Santana Romero
    fecha: 24 de marzo de 2023
*/

#include "proveedor.h"
#include "cliente.h"
#include "twodaypack.h"
#include "pack.h"
#include "expresspack.h"
#include "../menu/menu.h"
using namespace std;

vector <Cliente> clientes = {};
vector <Proveedor> proveedores = {};

template <typename usuario>
usuario * selectFrom (vector<usuario> &v) {
    int id = 0;
    cout << "ID: ";
    cin >> id;
    if (v.empty() || id < 1 || id > (int) v.size()) {
        cout << "ID inexistente" << endl;
    }
    return &v.at(id-1);
}

Menu menuCliente ({

}, "MENÚ DEL CLIENTE");
Menu menuProveedor ({
    {'1', {"Crear proveedor", [] () {
        proveedores.emplace_back();
        proveedores.back().configure();
    }}},
    {'2', {"Obtener datos de proveedor", [] () {
        selectFrom(proveedores)->display();
    }}},
    {'3', {"Enviar paquete", [] () {
        selectFrom(proveedores)->deliver(selectFrom(proveedores)->shippingType());
    }}}
}, "MENÚ DEL PROVEEDOR");
Menu mainMenu ({
    {'1', {"Proveedor", [] () { menuProveedor.display(true, true); }}},
    {'2', {"Cliente", [] () { menuCliente.display(true, true); }}}
}, "MENÚ PRINCIPAL");

int main () {
    mainMenu.display(true, true);
}