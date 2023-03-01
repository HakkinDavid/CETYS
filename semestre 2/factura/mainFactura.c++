/*  nombre: Facturar una compra
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <iostream>
#include "factura.h" // user defined library header
using namespace std;

int main () {
    Factura capacitor (100, "Capacitor electrolítico radial, de 100 uF (micro Faradios) a 25 Volts", 3);
    int cantidad = 0, total = 0;
    cout << capacitor.getDesc() << endl;
    cout << "ID: " << capacitor.getID() << endl;
    cout << "Precio: $" << capacitor.getPrice() << endl;
    cout << "[Cantidad a comprar]: ";
    cin >> cantidad;
    capacitor.setAmount(cantidad);

    total += capacitor.cobrar();

    cout << "Subtotal: $" << total << endl;

    cout << endl;

    Factura opAmp (741, "Amplificador Operacional Sencillo", 9);
    cantidad = 0;
    cout << opAmp.getDesc() << endl;
    cout << "ID: " << opAmp.getID() << endl;
    cout << "Precio: $" << opAmp.getPrice() << endl;
    cout << "[Cantidad a comprar]: ";
    cin >> cantidad;
    opAmp.setAmount(cantidad);

    total += opAmp.cobrar();

    cout << "Total: $" << total << endl;
}