/*  nombre: Comida
    autor: David Emmanuel Santana Romero
    fecha: 8 de marzo de 2023
*/

#include "comida.h"
#include <iostream>
using namespace std;

// constructores
Tortilla :: Tortilla () {
    cout << "Se ha puesto una tortilla en el comal. Cuídala que se quema." << endl;
    tiempoEnCalor = 0;
    forma = "Redonda";
    enAceite = false;
}
AlimentoMexicano :: AlimentoMexicano () {
    cout << "¡A comer!" << endl;
    eatenPercentage = 100.0;
}
Taco :: Taco (string tipoDeCarne) {
    this -> tipoDeCarne = tipoDeCarne;
    setNombre ("Taco de " + tipoDeCarne);
    tortilla.setHarina(false);
    tortilla.setTiempoEnCalor(45);
    setIngredientes(tipoDeCarne);
}
Burro :: Burro (string contenido) {
    this -> contenido = contenido;
    setNombre ("Burro de " + contenido);
    tortilla.setHarina(true);
    tortilla.setTiempoEnCalor(30);
    setIngredientes(contenido);
}
Enchilada :: Enchilada () {
    setNombre ("Enchilada");
}
Chilaquiles :: Chilaquiles () {
    setNombre ("Chilaquiles");
}
Gordita :: Gordita () {
    setNombre ("Gordita");
}

// destructores
AlimentoMexicano :: ~AlimentoMexicano () {
    cout << "El alimento mexicano de tipo extendido " << nombre << " ha sido completamente consumido." << endl;
}

// Tortilla
void Tortilla :: setHarina (bool harina) {
    this -> harina = harina;
}
void Tortilla :: setEnAceite (bool enAceite) {
    this -> enAceite = enAceite;
}
void Tortilla :: setTiempoEnCalor (int tiempoEnCalor) {
    this -> tiempoEnCalor = tiempoEnCalor;
}
void Tortilla :: setForma (string forma) {
    this -> forma = forma;
}

bool Tortilla :: getHarina () const {
    return harina;
}
bool Tortilla :: getEnAceite () const {
    return enAceite;
}
int Tortilla :: getTiempoEnCalor () const {
    return tiempoEnCalor;
}
string Tortilla :: getForma () const {
    return forma;
}

// AlimentoMexicano
void AlimentoMexicano :: setNombre (string nombre) {
    this -> nombre = nombre;
}
void AlimentoMexicano :: setIngredientes (vector<string> ingredientes) {
    for (const auto &e : ingredientes) {
        (this -> ingredientes).push_back(e);
    }
}
void AlimentoMexicano :: setIngredientes (string e) {
    ingredientes.push_back(e);
}
string AlimentoMexicano :: getNombre () const {
    return nombre;
}
string AlimentoMexicano :: getIngredientes (int index) const {
    return ingredientes.at(index);
}
vector<string> AlimentoMexicano :: getIngredientes () const {
    return ingredientes;
}
void AlimentoMexicano :: display () const {
    cout << "[" << nombre << "]" << endl;
    cout << "\tTortilla de " << (tortilla.getHarina() ? "harina" : "maíz") << (tortilla.getEnAceite() ? " en aceite " : " ") << "calentada por " << tortilla.getTiempoEnCalor() << " segundos (forma: " << tortilla.getForma() << ")" << endl;
    cout << "\tIngredientes | ";
        for (const auto &e : ingredientes) {
            cout << e;
            if (&e != &ingredientes.back()) cout << ", ";
            else cout << endl;
        }
    
}
void AlimentoMexicano :: eat (float percentage = 10) {
    eatenPercentage -= percentage;
    if (eatenPercentage <= 0) AlimentoMexicano :: ~AlimentoMexicano ();
}
