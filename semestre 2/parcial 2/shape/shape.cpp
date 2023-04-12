/*  nombre: Herencia múltiple
    autor: David Emmanuel Santana Romero
    fecha: 10 de marzo de 2023
*/

#include "shape.h"

Shape :: Shape () {
    base = 0;
    altura = 0;
}

// setters
void Shape :: setBase (float x){
    base = x;
}
void Shape :: setAltura (float x){
    altura = x;
}

// getters
float Shape :: getBase () const {
    return base;
}
float Shape :: getAltura () const {
    return altura;
}
float CostoPintura :: getCost (float area) const {
    return 100.0 * area;
}
float Rectangulo :: getArea () const {
    return base * altura;
}