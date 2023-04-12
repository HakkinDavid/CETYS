/*  nombre: Empleado con herencia
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#include "empleadoherencia.h"

// constructores
Empleado :: Empleado (string nombre = "Juan", int id = 0) {
    this -> nombre = nombre;
    this -> id = id;
}
EmpleadoTiempoCompleto :: EmpleadoTiempoCompleto (string nombre, int id, int salario) : Empleado (nombre, id) {
    this -> salario = salario;
}
EmpleadoMedioTiempo :: EmpleadoMedioTiempo (string nombre, int id, int pago) : Empleado (nombre, id) {
    this -> pago = pago;
}

// setters
void Empleado :: setNombre (string n) {
    nombre = n;
}
void Empleado :: setID (int x) {
    id = x;
}

void EmpleadoTiempoCompleto :: setSalario (int s) {
    salario = s;
}

void EmpleadoMedioTiempo :: setPago (int p) {
    pago = p;
}

// getters
string Empleado :: getNombre () const {
    return nombre;
}
int Empleado :: getID () const {
    return id;
}

int EmpleadoTiempoCompleto :: getSalario () const {
    return salario;
}

int EmpleadoMedioTiempo :: getPago () const {
    return pago;
}