#include <iostream>
#include <string>
using namespace std;

// definir clase abstracta Animal
class Animal {
        string type; // tipo de animal
    public:
        // constructor que siempre define type como animal
        Animal () : type ("Animal") {}
        // función virtual para obtener el tipo de animal
        virtual string getType () { return type; }
};

// definir clase Dog derivada de Animal
class Dog : public Animal {
        string type; // tipo de animal
    public:
        // constructor que siempre define type como perro
        Dog () { type = "Dog"; }
        // método que sobreescribe getType en la clase Animal
        string getType () override { return type; }
};

// definir clase Cat derivada de Animal
class Cat : public Animal {
        string type; // tipo de animal
    public:
        // constructor que siempre define type como gato
        Cat () : type ("Cat") {}
        // método que sobreescribe getType en la clase Animal
        string getType () override { return type; }
};

// imprimir el animal
void print (Animal *ani) { cout << "Animal: " << ani -> getType() << endl; }

int main () {
    // apuntador Animal a objeto en memoria heap tipo Animal
    Animal *ani1 = new Animal ();
    // apuntador Animal a objeto en memoria heap tipo Dog
    Animal *dog1 = new Dog ();
    // objeto tipo Cat
    Cat cat;
    // apuntador Animal a objeto tipo Cat
    Animal *cat1 = &cat;

    // llamada a print() con el apuntador tipo Animal de 3 objetos distintos
    print (ani1);
    print (dog1);
    print (cat1);
}