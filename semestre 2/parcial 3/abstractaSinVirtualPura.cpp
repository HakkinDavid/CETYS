#include <iostream>
using namespace std;

// definimos clase abstracta Car
class Car {
    public:
    // función virtual start no pura
    virtual void start () {
        cout << "El auto se ha encendido" << endl;
    }
};

// definimos clase de carro Cooper
class Cooper : public Car {
    public:
    // función que sobreescribe start de Car
    void start () override {
        cout << "Cooper se ha encendido" << endl;
    }
};

// definimos clase de carro TOYOTA COROLLA
class Corolla : public Car {
    public:
    // función que sobreescribe start de Car y culturiza al usuario con el mejor comercial de carros de la historia (TOYOTA COROLLA 1986)
    void start() override {
        cout << "Llegó el japonés\nTOYOTA COROLLA\nBonito como el Sol y jala como un campeón\nTracción delantera, independiente suspensión\nTOYOTA COROLLA\nTremendo motor de larga duración\n¡Cuatro cilindros! ¡Mil seiscientos!\nTOYOTA COROLLA\nPotencia sin restricción y suave su dirección\nEs grande en economía, pero camina millón\nTOYOTA COROLLA\nEl mejor carro del mundo entero ha llegado a Venezuela\nLa mejor tecnología obra de gran maestría\nLlegó el japonés\nTOYOTA COROLLA\nToyota Corolla, el milagro japonés\nTOYOTA COROLLA" << endl;
    }
};

int main () {
    // nuevo puntero tipo Car a un objeto tipo Cooper en memoria heap
    Car *cPtr = new Cooper();
    // arrancamos el carro
    cPtr -> start();
    delete [] cPtr; // eliminamos el objeto en memoria heap
    // redefinimos el puntero tipo Car para apuntar a un objeto tipo Corolla en memoria heap
    cPtr = new Corolla();
    // arrancamos el carro
    cPtr -> start();
    delete [] cPtr; // eliminamos el objeto en memoria heap
    return 0;
}