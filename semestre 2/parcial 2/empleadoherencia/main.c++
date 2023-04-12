/*  nombre: Empleado con herencia
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#include "empleadoherencia.h"
#include <iostream>
using namespace std;

int main () {
    EmpleadoTiempoCompleto e ("David", 0, 19);
    EmpleadoMedioTiempo d ("Braulio", 2, 100000000);

    cout << "El salario del empleado " << e.getNombre() << " de tiempo completo con ID " << e.getID() << " es de " << e.getSalario() << endl;
    cout << "El salario del empleado " << d.getNombre() << " de medio tiempo con ID " << d.getID() << " es de " << d.getPago() << endl;
}