#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

class MenuComponente
{
public:
    virtual ~MenuComponente() {}

    virtual void agregar(MenuComponente *componente) { throw runtime_error("Operación no soportada"); }
    virtual void eliminar(MenuComponente *componente) { throw runtime_error("Operación no soportada"); }
    virtual MenuComponente *obtenerHijo(int indice) { throw runtime_error("Operación no soportada"); }

    virtual string obtenerNombre() { throw runtime_error("Operación no soportada"); }
    virtual string obtenerDescripcion() { throw runtime_error("Operación no soportada"); }
    virtual double obtenerPrecio() { throw runtime_error("Operación no soportada"); }
    virtual bool esVegetariano() { throw runtime_error("Operación no soportada"); }

    virtual void imprimir() { throw runtime_error("Operación no soportada"); }
    virtual class Iterador *crearIterador() { throw runtime_error("Operación no soportada"); }
};

class Iterador
{
public:
    virtual ~Iterador() {}
    virtual bool tieneSiguiente() = 0;
    virtual MenuComponente *siguiente() = 0;
};

class IteradorNulo : public Iterador
{
public:
    bool tieneSiguiente() override { return false; }
    MenuComponente *siguiente() override { return nullptr; }
};

class IteradorCompuesto : public Iterador
{
private:
    stack<Iterador *> pila;

public:
    IteradorCompuesto(Iterador *iterador)
    {
        pila.push(iterador);
    }

    bool tieneSiguiente() override
    {
        while (!pila.empty())
        {
            Iterador *iterador = pila.top();
            if (iterador->tieneSiguiente())
            {
                return true;
            }
            pila.pop();
        }
        return false;
    }

    MenuComponente *siguiente() override
    {
        if (tieneSiguiente())
        {
            Iterador *iterador = pila.top();
            MenuComponente *componente = iterador->siguiente();
            Iterador *iter = componente->crearIterador();
            if (dynamic_cast<IteradorNulo *>(iter) == nullptr)
            {
                pila.push(iter);
            }
            return componente;
        }
        return nullptr;
    }
};

class ElementoMenu : public MenuComponente
{
private:
    string nombre;
    string descripcion;
    bool vegetariano;
    double precio;

public:
    ElementoMenu(string nombre, string descripcion, bool vegetariano, double precio)
        : nombre(nombre), descripcion(descripcion), vegetariano(vegetariano), precio(precio) {}

    string obtenerNombre() override { return nombre; }
    string obtenerDescripcion() override { return descripcion; }
    double obtenerPrecio() override { return precio; }
    bool esVegetariano() override { return vegetariano; }

    void imprimir() override
    {
        cout << "  " << obtenerNombre();
        if (esVegetariano())
            cout << " (v)";
        cout << ", " << obtenerPrecio() << endl;
        cout << "     -- " << obtenerDescripcion() << endl;
    }

    Iterador *crearIterador() override
    {
        return new IteradorNulo();
    }
};

class IteradorVector : public Iterador
{
private:
    vector<MenuComponente *> elementos;
    size_t posicion;

public:
    IteradorVector(vector<MenuComponente *> elementos)
        : elementos(elementos), posicion(0) {}

    bool tieneSiguiente() override
    {
        return posicion < elementos.size();
    }

    MenuComponente *siguiente() override
    {
        return elementos[posicion++];
    }
};

class MenuCompuesto : public MenuComponente
{
private:
    vector<MenuComponente *> componentes;
    string nombre;
    string descripcion;

public:
    MenuCompuesto(string nombre, string descripcion)
        : nombre(nombre), descripcion(descripcion) {}

    void agregar(MenuComponente *componente) override
    {
        componentes.push_back(componente);
    }

    void eliminar(MenuComponente *componente) override
    {
    }

    MenuComponente *obtenerHijo(int indice) override
    {
        return componentes[indice];
    }

    string obtenerNombre() override { return nombre; }
    string obtenerDescripcion() override { return descripcion; }

    void imprimir() override
    {
        cout << "\n"
             << obtenerNombre();
        cout << ", " << obtenerDescripcion() << endl;
        cout << "---------------------" << endl;

        for (auto componente : componentes)
        {
            componente->imprimir();
        }
    }

    Iterador *crearIterador() override
    {
        return new IteradorCompuesto(new IteradorVector(componentes));
    }
};

class Camarera
{
private:
    MenuComponente *todosLosMenus;

public:
    Camarera(MenuComponente *todosLosMenus)
        : todosLosMenus(todosLosMenus) {}

    void imprimirMenu()
    {
        todosLosMenus->imprimir();
    }

    void imprimirMenuVegetariano()
    {
        Iterador *iterador = todosLosMenus->crearIterador();
        cout << "\nMENÚ VEGETARIANO\n---------------------\n";

        while (iterador->tieneSiguiente())
        {
            MenuComponente *componente = iterador->siguiente();
            try
            {
                if (componente->esVegetariano())
                {
                    componente->imprimir();
                }
            }
            catch (...)
            {
            }
        }
    }
};

int main()
{
    MenuComponente *menuDesayuno = new MenuCompuesto("MENÚ DESAYUNO", "Desayuno");
    MenuComponente *menuComida = new MenuCompuesto("MENÚ COMIDA", "Comida");
    MenuComponente *menuCafe = new MenuCompuesto("MENÚ CAFÉ", "Cena");
    MenuComponente *menuPostres = new MenuCompuesto("MENÚ POSTRES", "Postres");

    MenuComponente *todos = new MenuCompuesto("MENÚS", "Todos los menús combinados");

    todos->agregar(menuDesayuno);
    todos->agregar(menuComida);
    todos->agregar(menuCafe);

    menuDesayuno->agregar(new ElementoMenu("K&B Panqueques", "Panqueques con huevos revueltos y tostadas", true, 2.99));
    menuDesayuno->agregar(new ElementoMenu("Panqueques Regulares", "Panqueques con huevos fritos y salchicha", false, 2.99));
    menuDesayuno->agregar(new ElementoMenu("Panqueques de Arándanos", "Con arándanos frescos", true, 3.49));
    menuDesayuno->agregar(new ElementoMenu("Wafles", "Con arándanos o fresas", true, 3.59));

    menuComida->agregar(new ElementoMenu("BLT Vegetariano", "Tocino vegetal con lechuga y tomate", true, 2.99));
    menuComida->agregar(new ElementoMenu("BLT", "Tocino con lechuga y tomate", false, 2.99));
    menuComida->agregar(new ElementoMenu("Sopa del día", "Con ensalada de papa", false, 3.29));
    menuComida->agregar(new ElementoMenu("Hot dog", "Con chucrut, relish y cebolla", false, 3.05));
    menuComida->agregar(new ElementoMenu("Verduras al vapor y arroz integral", "Verduras sobre arroz integral", true, 3.99));
    menuComida->agregar(new ElementoMenu("Pasta", "Espagueti con salsa marinara", true, 3.89));

    menuComida->agregar(menuPostres);

    menuPostres->agregar(new ElementoMenu("Pay de manzana", "Con corteza crujiente y helado", true, 1.59));
    menuPostres->agregar(new ElementoMenu("Cheesecake", "Pastel de queso cremoso", true, 1.99));
    menuPostres->agregar(new ElementoMenu("Sorbet", "Helado de frambuesa", true, 1.89));

    menuCafe->agregar(new ElementoMenu("Hamburguesa vegetariana", "Con papas fritas", true, 3.99));
    menuCafe->agregar(new ElementoMenu("Sopa del día", "Con ensalada", false, 3.69));
    menuCafe->agregar(new ElementoMenu("Burrito", "Grande con frijoles y salsa", true, 4.29));

    Camarera camarera(todos);

    camarera.imprimirMenu();
    camarera.imprimirMenuVegetariano();

    return 0;
}