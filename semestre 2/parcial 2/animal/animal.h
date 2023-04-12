/*  nombre: Animal
    autor: David Emmanuel Santana Romero
    fecha: 8 de marzo de 2023
*/

#include <string>
using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    protected:
        string nombre;
    public:
        int patas;
        string color;

        Animal ();
        void setNombre (string x);
        void setColor (string x);
        string getNombre ();
        string getColor ();
        int getPatas ();
        void display ();
};

class Perro : public Animal {
    public:
        void voz ();
};

class Puppy : public Perro {
    public:
        void llorar ();
};

#include "animal.cpp"
#endif