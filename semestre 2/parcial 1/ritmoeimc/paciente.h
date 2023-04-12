/*  nombre: Librería del paciente
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <string>
using namespace std;

// include guards
#ifndef CREATE_PACIENTE_H
#define CREATE_PACIENTE_H

// define class

class Paciente {
    public:
        Paciente ();
        ~Paciente();

        void setName (string);
        void setAge (int);
        void setRCM (int);
        void setWeight (float);
        void setHeight (float);
        void setIMC (float);
        void setMale(bool);

        string getName () const;
        int getAge () const;
        int getRCM () const;
        float getWeight () const;
        float getHeight () const;
        float getIMC () const;
        bool getMale () const;

        int calcRCM ();
        void calcRCO ();
        float calcIMC ();
    private:
        string name = "David Emmanuel Santana Romero";
        int age, rcm;
        float weight, height, imc;
        bool isMale;
};

#include "paciente.cpp"
#endif