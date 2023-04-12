/*  nombre: Comida
    autor: David Emmanuel Santana Romero
    fecha: 8 de marzo de 2023
*/

#include <vector>
#include <string>
using namespace std;

#ifndef HERENCIA_H
#define HERENCIA_H


class Tortilla {
    private:
        bool harina, enAceite;
        int tiempoEnCalor;
        string forma;
    public:
        Tortilla ();

        void setHarina (bool harina);
        void setEnAceite (bool enAceite);
        void setTiempoEnCalor (int tiempoEnCalor);
        void setForma (string forma);

        bool getHarina () const;
        bool getEnAceite () const;
        int getTiempoEnCalor () const;
        string getForma () const;
};

class AlimentoMexicano {
    private:
        string nombre;
        vector<string> ingredientes;
        float eatenPercentage;
    protected:
        Tortilla tortilla;
    public:
        AlimentoMexicano ();
        ~AlimentoMexicano ();

        void setNombre (string nombre);
        void setIngredientes (vector<string> ingredientes);
        void setIngredientes (string e);

        string getNombre() const;
        vector<string> getIngredientes () const;
        string getIngredientes (int index) const;

        void display () const;
        void eat (float percentage);
};

class Taco : public AlimentoMexicano {
    private:
        string tipoDeCarne;
        bool dorado;
    public:
        Taco (string tipoDeCarne);
};

class Burro : public AlimentoMexicano {
    private:
        string contenido;
    public:
        Burro (string contenido);
};

class Enchilada : public AlimentoMexicano {
    public:
        Enchilada ();
};

class Chilaquiles : public AlimentoMexicano {
    public:
        Chilaquiles ();
};

class Gordita : public AlimentoMexicano {
    public:
        Gordita ();
};

#include "comida.cpp"
#endif