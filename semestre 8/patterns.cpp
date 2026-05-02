#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class GraznadorObservable;

class Observador
{
public:
    virtual ~Observador() = default;
    virtual void actualizar(GraznadorObservable *pato) = 0;
};

class GraznadorObservable
{
public:
    virtual ~GraznadorObservable() = default;
    virtual void registrarObservador(Observador *observador) = 0;
    virtual void notificarObservadores() = 0;
    virtual string obtenerTipo() const = 0;
};

class Observable : public GraznadorObservable
{
private:
    vector<Observador *> observadores;
    GraznadorObservable *pato;

public:
    Observable(GraznadorObservable *pato) : pato(pato) {}

    void registrarObservador(Observador *observador) override
    {
        observadores.push_back(observador);
    }

    void notificarObservadores() override
    {
        for (auto *obs : observadores)
        {
            obs->actualizar(pato);
        }
    }

    string obtenerTipo() const override
    {
        return pato->obtenerTipo();
    }
};

class Graznador : public GraznadorObservable
{
public:
    virtual ~Graznador() = default;
    virtual void graznar() = 0;
};

class PatoMallard : public Graznador
{
private:
    Observable observable;

public:
    PatoMallard() : observable(this) {}

    void graznar() override
    {
        cout << "Cuac" << endl;
        notificarObservadores();
    }

    string obtenerTipo() const override
    {
        return "Pato Mallard";
    }

    void registrarObservador(Observador *observador) override
    {
        observable.registrarObservador(observador);
    }

    void notificarObservadores() override
    {
        observable.notificarObservadores();
    }
};

class PatoCabezaRoja : public Graznador
{
private:
    Observable observable;

public:
    PatoCabezaRoja() : observable(this) {}

    void graznar() override
    {
        cout << "Cuac" << endl;
        notificarObservadores();
    }

    string obtenerTipo() const override
    {
        return "Pato Cabeza Roja";
    }

    void registrarObservador(Observador *observador) override
    {
        observable.registrarObservador(observador);
    }

    void notificarObservadores() override
    {
        observable.notificarObservadores();
    }
};

class LlamadaDePato : public Graznador
{
private:
    Observable observable;

public:
    LlamadaDePato() : observable(this) {}

    void graznar() override
    {
        cout << "Kwak" << endl;
        notificarObservadores();
    }

    string obtenerTipo() const override
    {
        return "Llamada de Pato";
    }

    void registrarObservador(Observador *observador) override
    {
        observable.registrarObservador(observador);
    }

    void notificarObservadores() override
    {
        observable.notificarObservadores();
    }
};

class PatoDeGoma : public Graznador
{
private:
    Observable observable;

public:
    PatoDeGoma() : observable(this) {}

    void graznar() override
    {
        cout << "Squeak" << endl;
        notificarObservadores();
    }

    string obtenerTipo() const override
    {
        return "Pato de Goma";
    }

    void registrarObservador(Observador *observador) override
    {
        observable.registrarObservador(observador);
    }

    void notificarObservadores() override
    {
        observable.notificarObservadores();
    }
};

class Ganso
{
public:
    void graznar()
    {
        cout << "Honk" << endl;
    }
};

class AdaptadorGanso : public Graznador
{
private:
    Ganso ganso;
    Observable observable;

public:
    AdaptadorGanso(Ganso g) : ganso(g), observable(this) {}

    void graznar() override
    {
        ganso.graznar();
        notificarObservadores();
    }

    string obtenerTipo() const override
    {
        return "Ganso (adaptado)";
    }

    void registrarObservador(Observador *observador) override
    {
        observable.registrarObservador(observador);
    }

    void notificarObservadores() override
    {
        observable.notificarObservadores();
    }
};

class ContadorDeGraznidos : public Graznador
{
private:
    shared_ptr<Graznador> pato;
    static int numeroDeGraznidos;

public:
    ContadorDeGraznidos(shared_ptr<Graznador> pato) : pato(pato) {}

    void graznar() override
    {
        pato->graznar();
        numeroDeGraznidos++;
    }

    static int obtenerGraznidos()
    {
        return numeroDeGraznidos;
    }

    string obtenerTipo() const override
    {
        return pato->obtenerTipo();
    }

    void registrarObservador(Observador *observador) override
    {
        pato->registrarObservador(observador);
    }

    void notificarObservadores() override
    {
        pato->notificarObservadores();
    }
};

int ContadorDeGraznidos::numeroDeGraznidos = 0;

class FabricaAbstractaDePatos
{
public:
    virtual ~FabricaAbstractaDePatos() = default;
    virtual shared_ptr<Graznador> crearPatoMallard() = 0;
    virtual shared_ptr<Graznador> crearPatoCabezaRoja() = 0;
    virtual shared_ptr<Graznador> crearLlamadaDePato() = 0;
    virtual shared_ptr<Graznador> crearPatoDeGoma() = 0;
};

class FabricaDePatos : public FabricaAbstractaDePatos
{
public:
    shared_ptr<Graznador> crearPatoMallard() override
    {
        return make_shared<PatoMallard>();
    }

    shared_ptr<Graznador> crearPatoCabezaRoja() override
    {
        return make_shared<PatoCabezaRoja>();
    }

    shared_ptr<Graznador> crearLlamadaDePato() override
    {
        return make_shared<LlamadaDePato>();
    }

    shared_ptr<Graznador> crearPatoDeGoma() override
    {
        return make_shared<PatoDeGoma>();
    }
};

class FabricaDePatosContadores : public FabricaAbstractaDePatos
{
public:
    shared_ptr<Graznador> crearPatoMallard() override
    {
        return make_shared<ContadorDeGraznidos>(make_shared<PatoMallard>());
    }

    shared_ptr<Graznador> crearPatoCabezaRoja() override
    {
        return make_shared<ContadorDeGraznidos>(make_shared<PatoCabezaRoja>());
    }

    shared_ptr<Graznador> crearLlamadaDePato() override
    {
        return make_shared<ContadorDeGraznidos>(make_shared<LlamadaDePato>());
    }

    shared_ptr<Graznador> crearPatoDeGoma() override
    {
        return make_shared<ContadorDeGraznidos>(make_shared<PatoDeGoma>());
    }
};

class Bandada : public Graznador
{
private:
    vector<shared_ptr<Graznador>> graznareables;

public:
    void agregar(shared_ptr<Graznador> c)
    {
        graznareables.push_back(c);
    }

    void graznar() override
    {
        for (auto &c : graznareables)
        {
            c->graznar();
        }
    }

    string obtenerTipo() const override
    {
        return "Bandada";
    }

    void registrarObservador(Observador *observador) override
    {
        for (auto &c : graznareables)
        {
            c->registrarObservador(observador);
        }
    }

    void notificarObservadores() override {}
};

class Graznarologo : public Observador
{
public:
    void actualizar(GraznadorObservable *pato) override
    {
        cout << "Graznarólogo: " << pato->obtenerTipo() << " graznó." << endl;
    }
};

class SimuladorDePatos
{
public:
    void simular(FabricaAbstractaDePatos &fabrica)
    {

        auto mallard = fabrica.crearPatoMallard();
        auto cabezaRoja = fabrica.crearPatoCabezaRoja();
        auto llamada = fabrica.crearLlamadaDePato();
        auto goma = fabrica.crearPatoDeGoma();
        auto ganso = make_shared<AdaptadorGanso>(Ganso());

        Bandada bandada;

        bandada.agregar(mallard);
        bandada.agregar(cabezaRoja);
        bandada.agregar(llamada);
        bandada.agregar(goma);
        bandada.agregar(ganso);

        Bandada bandadaMallards;

        bandadaMallards.agregar(fabrica.crearPatoMallard());
        bandadaMallards.agregar(fabrica.crearPatoMallard());
        bandadaMallards.agregar(fabrica.crearPatoMallard());

        bandada.agregar(make_shared<Bandada>(bandadaMallards));

        cout << "Simulador de patos con observador" << endl;

        Graznarologo graznarologo;
        bandada.registrarObservador(&graznarologo);

        simular(bandada);

        cout << "Total de graznidos: " << ContadorDeGraznidos::obtenerGraznidos() << endl;
    }

    void simular(Graznador &pato)
    {
        pato.graznar();
    }
};

int main()
{
    SimuladorDePatos simulador;
    FabricaDePatosContadores fabrica;
    simulador.simular(fabrica);
    return 0;
}