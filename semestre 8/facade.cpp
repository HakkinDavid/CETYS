#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Amplificador;

class Sintonizador
{
    Amplificador *amplificador;

public:
    void encender() { cout << "Sintonizador encendido" << endl; }
    void apagar() { cout << "Sintonizador apagado" << endl; }
    void establecerFrecuencia(double freq) { cout << "Sintonizador ajustando frecuencia a " << freq << endl; }
    void setAM() { cout << "Sintonizador en AM" << endl; }
    void setFM() { cout << "Sintonizador en FM" << endl; }
};

class ReproductorDVD
{
    Amplificador *amplificador;
    string pelicula;

public:
    void encender() { cout << "Reproductor DVD encendido" << endl; }
    void apagar() { cout << "Reproductor DVD apagado" << endl; }
    void reproducir(const string &m)
    {
        pelicula = m;
        cout << "Reproductor DVD reproduciendo \"" << pelicula << "\"" << endl;
    }
    void detener() { cout << "Reproductor DVD detenido \"" << pelicula << "\"" << endl; }
    void expulsar() { cout << "Reproductor DVD expulsar" << endl; }
    void pausar() { cout << "Reproductor DVD pausado \"" << pelicula << "\"" << endl; }
    void reproducir(int pista) { cout << "Reproductor DVD reproduciendo pista " << pista << endl; }
    void audioEnvolvente() { cout << "Reproductor DVD audio envolvente activado" << endl; }
    void audioDosCanales() { cout << "Reproductor DVD audio de dos canales" << endl; }
};

class ReproductorCD
{
    Amplificador *amplificador;

public:
    void encender() { cout << "Reproductor CD encendido" << endl; }
    void apagar() { cout << "Reproductor CD apagado" << endl; }
    void expulsar() { cout << "Reproductor CD expulsar" << endl; }
    void reproducir(const string &titulo) { cout << "Reproductor CD reproduciendo \"" << titulo << "\"" << endl; }
    void reproducir(int pista) { cout << "Reproductor CD reproduciendo pista " << pista << endl; }
    void pausar() { cout << "Reproductor CD pausado" << endl; }
    void detener() { cout << "Reproductor CD detenido" << endl; }
};

class Amplificador
{
    Sintonizador *sintonizador;
    ReproductorDVD *dvd;
    ReproductorCD *cd;

public:
    void encender() { cout << "Amplificador encendido" << endl; }
    void apagar() { cout << "Amplificador apagado" << endl; }
    void configurarDVD(ReproductorDVD *d)
    {
        dvd = d;
        cout << "Amplificador configurando reproductor DVD" << endl;
    }
    void sonidoEnvolvente() { cout << "Amplificador sonido envolvente activado" << endl; }
    void establecerVolumen(int nivel) { cout << "Amplificador ajustando volumen a " << nivel << endl; }
    void configurarCD(ReproductorCD *c)
    {
        cd = c;
        cout << "Amplificador configurando reproductor CD" << endl;
    }
    void sonidoEstereo() { cout << "Amplificador sonido estéreo activado" << endl; }
    void configurarSintonizador(Sintonizador *t)
    {
        sintonizador = t;
        cout << "Amplificador configurando sintonizador" << endl; }
};

class Proyector
{
    ReproductorDVD *dvd;

public:
    void encender() { cout << "Proyector encendido" << endl; }
    void apagar() { cout << "Proyector apagado" << endl; }
    void modoPanoramico() { cout << "Proyector en modo panorámico (16x9)" << endl; }
    void modoTV() { cout << "Proyector en modo TV (4x3)" << endl; }
};

class Pantalla
{
public:
    void subir() { cout << "Pantalla subiendo" << endl; }
    void bajar() { cout << "Pantalla bajando" << endl; }
};

class LucesTeatro
{
public:
    void encender() { cout << "Luces del teatro encendidas" << endl; }
    void apagar() { cout << "Luces del teatro apagadas" << endl; }
    void atenuar(int nivel) { cout << "Luces del teatro atenuando a " << nivel << "%" << endl; }
};

class MaquinaPalomitas
{
public:
    void encender() { cout << "Máquina de palomitas encendida" << endl; }
    void apagar() { cout << "Máquina de palomitas apagada" << endl; }
    void preparar() { cout << "Máquina de palomitas preparando palomitas" << endl; }
};

class FachadaCineCasa
{
    Amplificador *amp;
    Sintonizador *sintonizador;
    ReproductorDVD *dvd;
    ReproductorCD *cd;
    Proyector *proyector;
    LucesTeatro *luces;
    Pantalla *pantalla;
    MaquinaPalomitas *palomitas;

public:
    FachadaCineCasa(Amplificador *a, Sintonizador *t, ReproductorDVD *d, ReproductorCD *c,
                    Proyector *p, Pantalla *s, LucesTeatro *l, MaquinaPalomitas *pop)
        : amp(a), sintonizador(t), dvd(d), cd(c), proyector(p), luces(l), pantalla(s), palomitas(pop) {}

    void verPelicula(const string &pelicula)
    {
        cout << "Preparándose para ver una película..." << endl;
        palomitas->encender();
        palomitas->preparar();
        luces->atenuar(10);
        pantalla->bajar();
        proyector->encender();
        proyector->modoPanoramico();
        amp->encender();
        amp->configurarDVD(dvd);
        amp->sonidoEnvolvente();
        amp->establecerVolumen(5);
        dvd->encender();
        dvd->reproducir(pelicula);
    }

    void terminarPelicula()
    {
        cout << "Apagando el cine en casa..." << endl;
        palomitas->apagar();
        luces->encender();
        pantalla->subir();
        proyector->apagar();
        amp->apagar();
        dvd->detener();
        dvd->expulsar();
        dvd->apagar();
    }
};

int main()
{
    Amplificador amp;
    Sintonizador sintonizador;
    ReproductorDVD dvd;
    ReproductorCD cd;
    Proyector proyector;
    Pantalla pantalla;
    LucesTeatro luces;
    MaquinaPalomitas palomitas;

    FachadaCineCasa cine(&amp, &sintonizador, &dvd, &cd, &proyector, &pantalla, &luces, &palomitas);

    cine.verPelicula("Adán y los Hirales: Búsqueda binaria");
    cine.terminarPelicula();

    cine.verPelicula("Kalusha versus el Portero Fantasma");
    cine.terminarPelicula();

    return 0;
}