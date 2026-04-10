#include <iostream>
#include <string>

using namespace std;

class BebidaConCafeina
{
public:
    void prepararReceta()
    {
        hervirAgua();
        preparar();
        verterEnTaza();
        agregarCondimentos();
    }

    virtual ~BebidaConCafeina() {}

protected:
    virtual void preparar() = 0;
    virtual void agregarCondimentos() = 0;

    void hervirAgua()
    {
        cout << "Hirviendo agua" << endl;
    }

    void verterEnTaza()
    {
        cout << "Vertiendo en la taza" << endl;
    }
};

class Cafe : public BebidaConCafeina
{
protected:
    void preparar() override
    {
        cout << "Filtrando café molido" << endl;
    }

    void agregarCondimentos() override
    {
        cout << "Agregando azúcar y leche" << endl;
    }
};

class Te : public BebidaConCafeina
{
protected:
    void preparar() override
    {
        cout << "Infusionando la bolsa de té" << endl;
    }

    void agregarCondimentos() override
    {
        cout << "Agregando limón" << endl;
    }
};

class Chocolate : public BebidaConCafeina
{
protected:
    void preparar() override
    {
        cout << "Disolviendo chocolate en polvo en agua caliente" << endl;
    }

    void agregarCondimentos() override
    {
        cout << "Agregando crema batida y malvaviscos" << endl;
    }
};

int main()
{
    cout << "Bienvenido a 🐱 ᴛᴏᴛᴇ ᴇᴛ ᴛᴏᴜᴛ ʟᴇ ᴛʜé ☕️" << endl
         << endl;

    BebidaConCafeina *bebida1 = new Cafe();
    cout << "Preparando café..." << endl;
    bebida1->prepararReceta();
    cout << endl;

    BebidaConCafeina *bebida2 = new Te();
    cout << "Preparando té..." << endl;
    bebida2->prepararReceta();
    cout << endl;

    BebidaConCafeina *bebida3 = new Chocolate();
    cout << "Preparando chocolate..." << endl;
    bebida3->prepararReceta();
    cout << endl;

    delete bebida1;
    delete bebida2;
    delete bebida3;

    return 0;
}