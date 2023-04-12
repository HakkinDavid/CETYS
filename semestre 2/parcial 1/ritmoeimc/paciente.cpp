/*  nombre: Librería del paciente (implementación)
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <iostream>

// user defined library header
#include "paciente.h"

using namespace std;

// define corporal mass index levels
#define NORMAL 18.5
#define OVERWEIGHT 25
#define OBESITY 30

// constructor and destructor declaration
Paciente :: Paciente () {
    this -> name = "";
    this -> age = 0;
    this -> rcm = 0;
    this -> weight = 0.0;
    this -> height = 0.0;
    this -> imc = 0.0;
    this -> isMale = 0;

    cout << "Nuevo objeto tipo paciente inicializado." << endl;
}
Paciente :: ~Paciente() {
    name = "";
    age = 0;
    rcm = 0;
    weight = 0.0;
    height = 0.0;
    imc = 0.0;
    isMale = 0;
}

// setters implementation
void Paciente :: setName (string n) {
    name = n;
};
void Paciente :: setAge (int x) {
    age = x;
};
void Paciente :: setRCM (int x) {
    rcm = x;
};
void Paciente :: setWeight (float x) {
    weight = x;
};
void Paciente :: setHeight (float x) {
    height = x;
};
void Paciente :: setIMC (float x) {
    imc = x;
};
void Paciente :: setMale (bool gender) {
    isMale = gender;
};

// getters implementation
string Paciente :: getName () const {
    return name;
};
int Paciente :: getAge () const {
    return age;
};
int Paciente :: getRCM () const {
    return rcm;
};
float Paciente :: getWeight () const {
    return weight;
};
float Paciente :: getHeight () const {
    return height;
};
float Paciente :: getIMC () const {
    return imc;
};
bool Paciente :: getMale () const {
    return isMale;
};

// other functions implementation
int Paciente :: calcRCM () {
    isMale ? rcm = (220-age) : rcm = (227-age);
    return rcm;
};
void Paciente :: calcRCO () {
    cout << rcm*0.5 << " hasta " << rcm*0.85 << endl;
};
float Paciente :: calcIMC () {
    imc = weight / (height * height);

    cout << "Tu IMC es de " << imc << endl;

    if (imc < NORMAL) {
        cout << "Nivel: BAJO DE PESO" << endl;
    }
    else if (imc < OVERWEIGHT) {
        cout << "Nivel: NORMAL" << endl;
    }
    else if (imc < OBESITY) {
        cout << "Nivel: SOBREPESO" << endl;
    }
    else {
        cout << "Nivel: OBESIDAD" << endl;
    }
    return imc;
};