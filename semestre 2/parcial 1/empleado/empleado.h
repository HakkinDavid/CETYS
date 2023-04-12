/*  nombre: Librería del empleado
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <string>
using namespace std;

// include guards
#ifndef CREATE_EMPLEADO_H
#define CREATE_EMPLEADO_H

// define class

class Empleado {
    public:
        // prototipos
        Empleado (string, float, int);
        ~Empleado ();

        void setName (string);
        void setSalary (float);
        void setID (int);

        string getName () const;
        float getSalary () const;
        int getID () const;

        float getAnnualSalary () const;
        void incrementSalary (float);
    private:
        string name = "David Emmanuel Santana Romero";
        float salary;
        int ID;
};

#include "empleado.cpp"
#endif