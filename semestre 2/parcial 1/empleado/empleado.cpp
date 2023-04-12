/*  nombre: Librería del empleado (implementación)
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <iostream>

// user defined library header
#include "empleado.h"

using namespace std;

// constructor and destructor declaration
Empleado :: Empleado (string nombre, float salario, int providedID) {
    this -> name = nombre;
    this -> salary = salario;
    this -> ID = providedID;

    cout << "Se empleó a " << name << " con ID " << ID << " y salario mensual de $" << salary << endl;

    if (salary < 0.0) {
        cout << "El salario no puede ser menor a cero. De hecho, ni siquiera puede ser menor al salario mínimo establecido en la Ley Federal del Trabajo, eso es un delito y puedes ser penado." << endl;
        this -> salary = 0.0;
    }
    else if (salary < (312.41*7.0*54.0/12.0)) {
        cout << "Más te vale tener un buen abogado, has empleado a " << name << " por menos del salario mínimo establecido en la Ley Federal del Trabajo." << endl;
    }
}

Empleado :: ~Empleado () {
    name = "";
    salary = 0.0;
    ID = 0;
}

// setters implementation
void Empleado :: setName (string n) {
    name = n;
};
void Empleado :: setSalary (float x) {
    salary = x;
    if (salary < 0) {
        cout << "El salario no puede ser menor a cero. De hecho, ni siquiera puede ser menor al salario mínimo establecido en la Ley Federal del Trabajo, eso es un delito y puedes ser penado." << endl;
        salary = 0.0;
    }
};
void Empleado :: setID (int x) {
    ID = x;
};

// getters implementation
string Empleado :: getName () const {
    return name;
};
float Empleado :: getSalary () const {
    return salary;
};
int Empleado :: getID () const {
    return ID;
};

// other functions implementation
float Empleado :: getAnnualSalary () const {
    return salary * 12.0;
};
void Empleado :: incrementSalary (float percentage) {
    salary *= (1.0 + (percentage/100));
};