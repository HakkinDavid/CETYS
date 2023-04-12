/*  nombre: Empleado con herencia
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#include <string>
using namespace std;

#ifndef EMPLEADO_HERENCIA_H
#define EMPLEADO_HERENCIA_H

class Empleado {
    protected:
        string nombre;
        int id;
    public:
        Empleado (string nombre, int id);

        void setNombre (string n);
        void setID (int x);

        string getNombre () const;
        int getID () const;
};

class EmpleadoTiempoCompleto : public Empleado {
    private:
        int salario;
    public:
        EmpleadoTiempoCompleto (string nombre, int id, int salario);

        void setSalario (int s);
        int getSalario () const;
};

class EmpleadoMedioTiempo : public Empleado {
    private:
        int pago;
    public:
        EmpleadoMedioTiempo (string nombre, int id, int pago);

        void setPago (int p);
        int getPago () const;
};

#include "empleadoherencia.cpp"
#endif