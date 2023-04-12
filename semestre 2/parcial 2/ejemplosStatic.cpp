#include <iostream>
#include <string>
using namespace std;
/*
class Miembro {
    private:
        string nombre, especie;
    public:
        Miembro (string nombre = "Tito", string especie = "gato") {
            this -> nombre = nombre;
            this -> especie = especie;

            cout << "Reclutando a " << nombre << ", es un " << especie << endl;
        }
        void setNombre (string n) {
            nombre = n;
        }
        string getNombre () const {
            return nombre;
        }
};

class PandillaAnimal {
    public:
        static Miembro gato;
};

Miembro PandillaAnimal::gato("Naranja");

int main () {
    PandillaAnimal p;
    p.gato.setNombre("Bolillo"); // Accedemos al gato miembro estático y le damos nombre

    PandillaAnimal b;
    cout << b.gato.getNombre();
}
*/

// Un gato miembro

class Gato {
    private:
        string nombre;
        static string owner;
    public:
        Gato (string nombre) {
            this -> nombre = nombre;
            cout << "Adoptaste a " << nombre << endl;
        }
        static void changeOwner (string o) {
            owner = o;
        }
        void display () const {
            cout << nombre << " es un gato(a) de " << owner << endl;
        }
};

string Gato::owner = "Emmanuel";

int main () {
    Gato gatito ("Dave"), gatita ("Sariah");
    gatita.display();
    gatito.display();
    gatito.changeOwner("David");
    gatita.display();
    gatito.display();
}