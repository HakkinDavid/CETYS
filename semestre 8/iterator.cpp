#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

class ElementoMenu
{
private:
    string nombre;
    string descripcion;
    bool esVegetarianoBandera;
    double precio;

public:
    ElementoMenu(string nombre, string descripcion, bool esVegetarianoBandera, double precio)
        : nombre(nombre), descripcion(descripcion), esVegetarianoBandera(esVegetarianoBandera), precio(precio) {}

    string obtenerNombre() const { return nombre; }
    string obtenerDescripcion() const { return descripcion; }
    double obtenerPrecio() const { return precio; }
    bool esVegetariano() const { return esVegetarianoBandera; }
};

class Iterador
{
public:
    virtual ~Iterador() {}
    virtual bool tieneSiguiente() = 0;
    virtual ElementoMenu *siguiente() = 0;
};

class MenuBase
{
public:
    virtual ~MenuBase() {}
    virtual Iterador *crearIterador() = 0;
};

class IteradorMenuDesayuno : public Iterador
{
private:
    vector<ElementoMenu *> elementos;
    size_t posicion;

public:
    IteradorMenuDesayuno(vector<ElementoMenu *> elementos)
        : elementos(elementos), posicion(0) {}

    bool tieneSiguiente() override
    {
        return posicion < elementos.size();
    }

    ElementoMenu *siguiente() override
    {
        return elementos[posicion++];
    }
};

class MenuDesayuno : public MenuBase
{
private:
    vector<ElementoMenu *> elementos;

public:
    MenuDesayuno()
    {
        agregarElemento("Desayuno de Panqueques K&B",
                        "Panqueques con huevos revueltos y tostadas",
                        true, 2.99);

        agregarElemento("Desayuno de Panqueques Regular",
                        "Panqueques con huevos fritos y salchicha",
                        false, 2.99);

        agregarElemento("Panqueques de Arándanos",
                        "Panqueques hechos con arándanos frescos",
                        true, 3.49);

        agregarElemento("Wafles",
                        "Wafles con arándanos o fresas",
                        true, 3.59);
    }

    void agregarElemento(string nombre, string descripcion, bool esVegetarianoBandera, double precio)
    {
        elementos.push_back(new ElementoMenu(nombre, descripcion, esVegetarianoBandera, precio));
    }

    Iterador *crearIterador() override
    {
        return new IteradorMenuDesayuno(elementos);
    }
};

class IteradorMenuComida : public Iterador
{
private:
    ElementoMenu **elementos;
    int posicion;
    int maxElementos;

public:
    IteradorMenuComida(ElementoMenu **elementos, int maxElementos)
        : elementos(elementos), posicion(0), maxElementos(maxElementos) {}

    bool tieneSiguiente() override
    {
        if (posicion >= maxElementos || elementos[posicion] == nullptr)
            return false;
        return true;
    }

    ElementoMenu *siguiente() override
    {
        return elementos[posicion++];
    }
};

class MenuComida : public MenuBase
{
private:
    static const int MAX_ELEMENTOS = 6;
    int numeroDeElementos;
    ElementoMenu *elementos[MAX_ELEMENTOS];

public:
    MenuComida() : numeroDeElementos(0)
    {
        agregarElemento("BLT Vegetariano",
                        "Tocino vegetal con lechuga y tomate en pan integral",
                        true, 2.99);

        agregarElemento("BLT",
                        "Tocino con lechuga y tomate en pan integral",
                        false, 2.99);

        agregarElemento("Sopa del día",
                        "Sopa con ensalada de papa",
                        false, 3.29);

        agregarElemento("Hot dog",
                        "Hot dog con chucrut, relish y cebolla",
                        false, 3.05);

        agregarElemento("Verduras al vapor con arroz integral",
                        "Verduras al vapor sobre arroz integral",
                        true, 3.99);

        agregarElemento("Pasta",
                        "Espagueti con salsa marinara y pan de masa madre",
                        true, 3.89);
    }

    void agregarElemento(string nombre, string descripcion, bool esVegetarianoBandera, double precio)
    {
        if (numeroDeElementos >= MAX_ELEMENTOS)
        {
            cout << "Menú lleno\n";
            return;
        }
        elementos[numeroDeElementos++] = new ElementoMenu(nombre, descripcion, esVegetarianoBandera, precio);
    }

    Iterador *crearIterador() override
    {
        return new IteradorMenuComida(elementos, MAX_ELEMENTOS);
    }
};

class IteradorMenuCafe : public Iterador
{
private:
    map<string, ElementoMenu *> elementos;
    map<string, ElementoMenu *>::iterator actual;
    map<string, ElementoMenu *>::iterator fin;

public:
    IteradorMenuCafe(map<string, ElementoMenu *> elementos)
        : elementos(elementos)
    {
        actual = this->elementos.begin();
        fin = this->elementos.end();
    }

    bool tieneSiguiente() override
    {
        return actual != fin;
    }

    ElementoMenu *siguiente() override
    {
        return (actual++)->second;
    }
};

class MenuCafe : public MenuBase
{
private:
    map<string, ElementoMenu *> elementos;

public:
    MenuCafe()
    {
        agregarElemento("Hamburguesa vegetariana con papas",
                        "Hamburguesa vegetariana en pan integral",
                        true, 3.99);

        agregarElemento("Sopa del día",
                        "Sopa con ensalada",
                        false, 3.69);

        agregarElemento("Burrito",
                        "Burrito grande con frijoles y salsa",
                        true, 4.29);
    }

    void agregarElemento(string nombre, string descripcion, bool esVegetarianoBandera, double precio)
    {
        elementos[nombre] = new ElementoMenu(nombre, descripcion, esVegetarianoBandera, precio);
    }

    Iterador *crearIterador() override
    {
        return new IteradorMenuCafe(elementos);
    }
};

class Camarera
{
private:
    vector<MenuBase *> menus;

    void imprimirMenu(Iterador *iterador)
    {
        while (iterador->tieneSiguiente())
        {
            ElementoMenu *elemento = iterador->siguiente();
            cout << elemento->obtenerNombre() << ", "
                 << elemento->obtenerPrecio() << " -- "
                 << elemento->obtenerDescripcion() << endl;
        }
    }

public:
    Camarera(vector<MenuBase *> menus) : menus(menus) {}

    void imprimirMenu()
    {
        cout << "MENÚ\n---------------------\n";

        const vector<string> titles = {"DESAYUNO", "COMIDA", "CENA"};

        for (size_t i = 0; i < menus.size(); ++i)
        {
            cout << "\n"
                 << titles[i] << "\n";

            Iterador *iterador = menus[i]->crearIterador();
            imprimirMenu(iterador);
            delete iterador;
        }
    }
};

int main()
{
    MenuBase *menuDesayuno = new MenuDesayuno();
    MenuBase *menuComida = new MenuComida();
    MenuBase *menuCafe = new MenuCafe();

    vector<MenuBase *> menus = {menuDesayuno, menuComida, menuCafe};

    Camarera camarera(menus);
    camarera.imprimirMenu();

    delete menuDesayuno;
    delete menuComida;
    delete menuCafe;

    return 0;
}