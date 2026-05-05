#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pelicula
{
public:
    static const int REGULAR = 0;
    static const int NUEVO_ESTRENO = 1;
    static const int INFANTIL = 2;

private:
    string titulo;
    int codigoPrecio;

public:
    Pelicula(string titulo, int codigoPrecio)
    {
        this->titulo = titulo;
        this->codigoPrecio = codigoPrecio;
    }

    int obtenerCodigoPrecio()
    {
        return codigoPrecio;
    }

    void establecerCodigoPrecio(int arg)
    {
        codigoPrecio = arg;
    }

    string obtenerTitulo()
    {
        return titulo;
    }
};

class Renta
{
private:
    Pelicula *pelicula;
    int diasRentados;

public:
    Renta(Pelicula *pelicula, int diasRentados)
    {
        this->pelicula = pelicula;
        this->diasRentados = diasRentados;
    }

    int obtenerDiasRentados()
    {
        return diasRentados;
    }

    Pelicula *obtenerPelicula()
    {
        return pelicula;
    }
};

class Cliente
{
private:
    string nombre;
    vector<Renta> rentas;

public:
    Cliente(string nombre)
    {
        this->nombre = nombre;
    }

    void agregarRenta(Renta renta)
    {
        rentas.push_back(renta);
    }

    string obtenerNombre()
    {
        return nombre;
    }

    string statement()
    {
        double montoTotal = 0;
        int puntosFrecuentes = 0;
        string resultado = "Registro de renta para " + obtenerNombre() + "\n";

        for (size_t i = 0; i < rentas.size(); i++)
        {
            double montoActual = 0;
            Renta &each = rentas[i];

            switch (each.obtenerPelicula()->obtenerCodigoPrecio())
            {
            case Pelicula::REGULAR:
                montoActual += 2;
                if (each.obtenerDiasRentados() > 2)
                {
                    montoActual += (each.obtenerDiasRentados() - 2) * 1.5;
                }
                break;

            case Pelicula::NUEVO_ESTRENO:
                montoActual += each.obtenerDiasRentados() * 3;
                break;

            case Pelicula::INFANTIL:
                montoActual += 1.5;
                if (each.obtenerDiasRentados() > 3)
                {
                    montoActual += (each.obtenerDiasRentados() - 3) * 1.5;
                }
                break;
            }

            puntosFrecuentes++;

            if ((each.obtenerPelicula()->obtenerCodigoPrecio() == Pelicula::NUEVO_ESTRENO) &&
                each.obtenerDiasRentados() > 1)
            {
                puntosFrecuentes++;
            }

            resultado += "\t" + each.obtenerPelicula()->obtenerTitulo() + "\t" + to_string(montoActual) + "\n";
            montoTotal += montoActual;
        }

        resultado += "El monto total es " + to_string(montoTotal) + "\n";
        resultado += "Has acumulado " + to_string(puntosFrecuentes) + " puntos de cliente frecuente";

        return resultado;
    }
};

int main()
{
    Pelicula p1("La loca historia de las galaxias", Pelicula::REGULAR);
    Pelicula p2("Esrek", Pelicula::INFANTIL);
    Pelicula p3("A todo gas", Pelicula::NUEVO_ESTRENO);

    Cliente cliente("Guillermini");

    cliente.agregarRenta(Renta(&p1, 3));
    cliente.agregarRenta(Renta(&p2, 4));
    cliente.agregarRenta(Renta(&p3, 2));

    cout << cliente.statement() << endl;

    return 0;
}