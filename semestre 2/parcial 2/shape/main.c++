/*  nombre: Herencia múltiple
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#include "shape.h"
#include <iostream>
using namespace std;

int main () {
    Rectangulo r;
    float a, b;

    cout << "Base [cm]: ";
    cin >> b;
    cout << "Altura [cm]: ";
    cin >> a;
    r.setBase(b);
    r.setAltura(a);

    cout << "El costo de " << r.getArea() << " cm ^ 2 de pintura es $" << r.getCost(r.getArea()) << endl;
}