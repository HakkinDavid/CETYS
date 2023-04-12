/*  nombre: Comida
    autor: David Emmanuel Santana Romero
    fecha: 8 de marzo de 2023
*/

#include "comida.h"
#include <iostream>

int main () {
    Taco taquito ("Birria"), tacoDeAdobada ("Adobada") , tacoDeLengua ("Lengua");
    Burro burrito ("Frijol");

    taquito.setIngredientes("Limón");

    taquito.display();
    tacoDeAdobada.display();
    tacoDeLengua.display();

    burrito.display();
}