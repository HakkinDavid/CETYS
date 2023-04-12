/*  nombre: Calcular IMC, RCM y RCO de una persona
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <iostream>
#include "paciente.h" // user defined library header
using namespace std;

int main () {
    Paciente p;
    string nombre;
    int edad, rcm;
    float peso, altura, imc;
    bool esHombre;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Peso [kg]: ";
    cin >> peso;
    cout << "Altura [metros]: ";
    cin >> altura;
    cout << "Sexo [0 para mujer, 1 para hombre]: ";
    cin >> esHombre;

    p.setName(nombre);
    p.setAge(edad);
    p.setHeight(altura);
    p.setWeight(peso);
    p.setMale(esHombre);

    cout << "\n\n\nDatos del paciente" << endl;
    cout << "Nombre: " << p.getName() << endl;
    cout << "Edad: " << p.getAge() << endl;
    cout << "RCM: " << p.calcRCM() << endl;
    cout << "RCO: ";
    p.calcRCO();
    p.calcIMC();

    cout << "Si su IMC es menos de 18.5, se encuentra dentro del rango de peso insuficiente.\nSi su IMC es entre 18.5 y 24.9, se encuentra dentro del rango de peso normal o saludable.\nSi su IMC es entre 25.0 y 29.9, se encuentra dentro del rango de sobrepeso.\nSi su IMC es 30.0 o superior, se encuentra dentro del rango de obesidad." << endl;
}