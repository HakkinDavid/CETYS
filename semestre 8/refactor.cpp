#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

class Precio
{
public:
    virtual ~Precio() {}
    virtual int obtenerCodigoPrecio() const = 0;
    virtual double obtenerCargo(int dias) const = 0;

    virtual int obtenerPuntosFrecuentes(int dias) const
    {
        return 1;
    }
};

class PrecioRegular : public Precio
{
public:
    int obtenerCodigoPrecio() const override { return 0; }

    double obtenerCargo(int dias) const override
    {
        double resultado = 2;
        if (dias > 2)
            resultado += (dias - 2) * 1.5;
        return resultado;
    }
};

class PrecioEstreno : public Precio
{
public:
    int obtenerCodigoPrecio() const override { return 1; }

    double obtenerCargo(int dias) const override
    {
        return dias * 3;
    }

    int obtenerPuntosFrecuentes(int dias) const override
    {
        return dias > 1 ? 2 : 1;
    }
};

class PrecioInfantil : public Precio
{
public:
    int obtenerCodigoPrecio() const override { return 2; }

    double obtenerCargo(int dias) const override
    {
        double resultado = 1.5;
        if (dias > 3)
            resultado += (dias - 3) * 1.5;
        return resultado;
    }
};

class Pelicula
{
public:
    static const int REGULAR = 0;
    static const int ESTRENO = 1;
    static const int INFANTIL = 2;

private:
    string titulo;
    unique_ptr<Precio> precio;

public:
    Pelicula(string titulo, int codigo) : titulo(titulo)
    {
        establecerCodigoPrecio(codigo);
    }

    void establecerCodigoPrecio(int codigo)
    {
        switch (codigo)
        {
        case REGULAR:
            precio = make_unique<PrecioRegular>();
            break;
        case ESTRENO:
            precio = make_unique<PrecioEstreno>();
            break;
        case INFANTIL:
            precio = make_unique<PrecioInfantil>();
            break;
        default:
            throw invalid_argument("Código inválido");
        }
    }

    int obtenerCodigoPrecio() const
    {
        return precio->obtenerCodigoPrecio();
    }

    string obtenerTitulo() const
    {
        return titulo;
    }

    double obtenerCargo(int dias) const
    {
        return precio->obtenerCargo(dias);
    }

    int obtenerPuntosFrecuentes(int dias) const
    {
        return precio->obtenerPuntosFrecuentes(dias);
    }
};

class Renta
{
private:
    Pelicula *pelicula;
    int dias;

public:
    Renta(Pelicula *pelicula, int dias) : pelicula(pelicula), dias(dias) {}

    int obtenerDias() const { return dias; }
    Pelicula *obtenerPelicula() const { return pelicula; }

    double obtenerCargo() const
    {
        return pelicula->obtenerCargo(dias);
    }

    int obtenerPuntosFrecuentes() const
    {
        return pelicula->obtenerPuntosFrecuentes(dias);
    }
};

class Cliente
{
private:
    string nombre;
    vector<Renta> rentas;

public:
    Cliente(string nombre) : nombre(nombre) {}

    void agregarRenta(const Renta &r)
    {
        rentas.push_back(r);
    }

    string obtenerNombre() const { return nombre; }

    vector<Renta> &obtenerRentas() { return rentas; }

    double obtenerTotalCargo() const
    {
        double resultado = 0;
        for (const auto &r : rentas)
            resultado += r.obtenerCargo();
        return resultado;
    }

    int obtenerTotalPuntos() const
    {
        int resultado = 0;
        for (const auto &r : rentas)
            resultado += r.obtenerPuntosFrecuentes();
        return resultado;
    }
};

class EstadoCuenta
{
public:
    virtual ~EstadoCuenta() {}

    string valor(Cliente &cliente)
    {
        string resultado = encabezado(cliente);
        for (auto &renta : cliente.obtenerRentas())
        {
            resultado += lineaRenta(renta);
        }
        resultado += pie(cliente);
        return resultado;
    }

protected:
    virtual string encabezado(Cliente &) = 0;
    virtual string lineaRenta(Renta &) = 0;
    virtual string pie(Cliente &) = 0;
};

class EstadoCuentaTexto : public EstadoCuenta
{
protected:
    string encabezado(Cliente &c) override
    {
        return "Registro de renta para " + c.obtenerNombre() + "\n";
    }

    string lineaRenta(Renta &r) override
    {
        return "\t" + r.obtenerPelicula()->obtenerTitulo() + "\t" +
               to_string(r.obtenerCargo()) + "\n";
    }

    string pie(Cliente &c) override
    {
        return "El monto total es " + to_string(c.obtenerTotalCargo()) + "\n" +
               "Has acumulado " + to_string(c.obtenerTotalPuntos()) +
               " puntos de cliente frecuente";
    }
};

class EstadoCuentaHTML : public EstadoCuenta
{
protected:
    string encabezado(Cliente &c) override
    {
        return "<H1>Rentas de <EM>" + c.obtenerNombre() + "</EM></H1><P>\n";
    }

    string lineaRenta(Renta &r) override
    {
        return r.obtenerPelicula()->obtenerTitulo() + ": " +
               to_string(r.obtenerCargo()) + "<BR>\n";
    }

    string pie(Cliente &c) override
    {
        return "<P>Total: <EM>" + to_string(c.obtenerTotalCargo()) +
               "</EM></P>\n<P>Puntos: <EM>" +
               to_string(c.obtenerTotalPuntos()) + "</EM></P>";
    }
};

int main()
{
    Pelicula p1("La loca historia de las galaxias", Pelicula::REGULAR);
    Pelicula p2("Esrek", Pelicula::INFANTIL);
    Pelicula p3("A todo gas", Pelicula::ESTRENO);

    Cliente cliente("Guillermini");

    cliente.agregarRenta(Renta(&p1, 3));
    cliente.agregarRenta(Renta(&p2, 4));
    cliente.agregarRenta(Renta(&p3, 2));

    EstadoCuentaTexto texto;
    EstadoCuentaHTML html;

    cout << texto.valor(cliente) << "\n\n";
    cout << html.valor(cliente) << endl;

    return 0;
}