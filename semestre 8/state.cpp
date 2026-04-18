#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

class MaquinaChicles;

class Estado
{
public:
    virtual void insertarMoneda() = 0;
    virtual void expulsarMoneda() = 0;
    virtual void girarManivela() = 0;
    virtual void dispensar() = 0;
    virtual ~Estado() {}
};

class EstadoSinMoneda : public Estado
{
private:
    MaquinaChicles *maquina;

public:
    EstadoSinMoneda(MaquinaChicles *m) : maquina(m) {}
    void insertarMoneda() override;
    void expulsarMoneda() override;
    void girarManivela() override;
    void dispensar() override;
};

class EstadoConMoneda : public Estado
{
private:
    MaquinaChicles *maquina;

public:
    EstadoConMoneda(MaquinaChicles *m) : maquina(m) {}
    void insertarMoneda() override;
    void expulsarMoneda() override;
    void girarManivela() override;
    void dispensar() override;
};

class EstadoVendido : public Estado
{
private:
    MaquinaChicles *maquina;

public:
    EstadoVendido(MaquinaChicles *m) : maquina(m) {}
    void insertarMoneda() override;
    void expulsarMoneda() override;
    void girarManivela() override;
    void dispensar() override;
};

class EstadoAgotado : public Estado
{
private:
    MaquinaChicles *maquina;

public:
    EstadoAgotado(MaquinaChicles *m) : maquina(m) {}
    void insertarMoneda() override;
    void expulsarMoneda() override;
    void girarManivela() override;
    void dispensar() override;
};

class EstadoGanador : public Estado
{
private:
    MaquinaChicles *maquina;

public:
    EstadoGanador(MaquinaChicles *m) : maquina(m) {}
    void insertarMoneda() override;
    void expulsarMoneda() override;
    void girarManivela() override;
    void dispensar() override;
};

class MaquinaChicles
{
private:
    std::unique_ptr<Estado> sinMoneda;
    std::unique_ptr<Estado> conMoneda;
    std::unique_ptr<Estado> vendido;
    std::unique_ptr<Estado> agotado;
    std::unique_ptr<Estado> ganador;

    Estado *estadoActual;
    int conteo;

public:
    MaquinaChicles(int cantidad) : conteo(cantidad)
    {
        sinMoneda = std::make_unique<EstadoSinMoneda>(this);
        conMoneda = std::make_unique<EstadoConMoneda>(this);
        vendido = std::make_unique<EstadoVendido>(this);
        agotado = std::make_unique<EstadoAgotado>(this);
        ganador = std::make_unique<EstadoGanador>(this);

        if (cantidad > 0)
            estadoActual = sinMoneda.get();
        else
            estadoActual = agotado.get();

        std::srand(std::time(nullptr));
    }

    void setEstado(Estado *estado) { estadoActual = estado; }
    Estado *getSinMoneda() { return sinMoneda.get(); }
    Estado *getConMoneda() { return conMoneda.get(); }
    Estado *getVendido() { return vendido.get(); }
    Estado *getAgotado() { return agotado.get(); }
    Estado *getGanador() { return ganador.get(); }

    int getConteo() { return conteo; }

    std::string toString() {
        std::string estadoStr;
        if (estadoActual == sinMoneda.get()) estadoStr = "esperando moneda";
        else if (estadoActual == conMoneda.get()) estadoStr = "esperando giro";
        else if (estadoActual == vendido.get()) estadoStr = "entregando chicle";
        else if (estadoActual == ganador.get()) estadoStr = "entregando premio";
        else estadoStr = "agotada";

        return "\nMighty Gumball, Inc.\nInventario: " + std::to_string(conteo) +
               " chicles\nEstado: " + estadoStr + "\n";
    }

    void insertarMoneda() { estadoActual->insertarMoneda(); }
    void expulsarMoneda() { estadoActual->expulsarMoneda(); }

    void girarManivela()
    {
        estadoActual->girarManivela();
        estadoActual->dispensar();
    }

    void liberarChicle()
    {
        if (conteo > 0)
        {
            std::cout << "Un chicle sale por la ranura..." << std::endl;
            conteo--;
        }
    }

    void rellenar(int cantidad)
    {
        conteo += cantidad;
        std::cout << "Máquina recargada con " << cantidad << " chicles" << std::endl;
        estadoActual = sinMoneda.get();
    }
};

void EstadoSinMoneda::insertarMoneda()
{
    std::cout << "Has insertado una moneda" << std::endl;
    maquina->setEstado(maquina->getConMoneda());
}
void EstadoSinMoneda::expulsarMoneda()
{
    std::cout << "No has insertado moneda" << std::endl;
}
void EstadoSinMoneda::girarManivela()
{
    std::cout << "Giras, pero no hay moneda" << std::endl;
}
void EstadoSinMoneda::dispensar()
{
    std::cout << "Debes pagar primero" << std::endl;
}

void EstadoConMoneda::insertarMoneda()
{
    std::cout << "Ya hay una moneda insertada" << std::endl;
}
void EstadoConMoneda::expulsarMoneda()
{
    std::cout << "Moneda devuelta" << std::endl;
    maquina->setEstado(maquina->getSinMoneda());
}
void EstadoConMoneda::girarManivela()
{
    std::cout << "Giraste..." << std::endl;
    int ganador = std::rand() % 10;
    if (ganador == 0 && maquina->getConteo() > 1)
    {
        maquina->setEstado(maquina->getGanador());
    }
    else
    {
        maquina->setEstado(maquina->getVendido());
    }
}
void EstadoConMoneda::dispensar()
{
    std::cout << "No se ha dispensado nada" << std::endl;
}

void EstadoVendido::insertarMoneda()
{
    std::cout << "Espera, estamos entregando un chicle" << std::endl;
}
void EstadoVendido::expulsarMoneda()
{
    std::cout << "Ya giraste la manivela" << std::endl;
}
void EstadoVendido::girarManivela()
{
    std::cout << "No obtendrás otro chicle" << std::endl;
}
void EstadoVendido::dispensar()
{
    maquina->liberarChicle();
    if (maquina->getConteo() > 0)
    {
        maquina->setEstado(maquina->getSinMoneda());
    }
    else
    {
        std::cout << "Oops, se acabaron los chicles" << std::endl;
        maquina->setEstado(maquina->getAgotado());
    }
}

void EstadoAgotado::insertarMoneda()
{
    std::cout << "Máquina agotada" << std::endl;
}
void EstadoAgotado::expulsarMoneda()
{
    std::cout << "No hay moneda" << std::endl;
}
void EstadoAgotado::girarManivela()
{
    std::cout << "No hay chicles" << std::endl;
}
void EstadoAgotado::dispensar()
{
    std::cout << "Nada que dispensar" << std::endl;
}

void EstadoGanador::insertarMoneda()
{
    std::cout << "Espera, estamos entregando tus chicles" << std::endl;
}
void EstadoGanador::expulsarMoneda()
{
    std::cout << "Ya giraste la manivela" << std::endl;
}
void EstadoGanador::girarManivela()
{
    std::cout << "Girar otra vez no ayuda" << std::endl;
}
void EstadoGanador::dispensar()
{
    std::cout << "¡ERES GANADOR! Recibes dos chicles por tu moneda" << std::endl;
    maquina->liberarChicle();
    if (maquina->getConteo() == 0)
    {
        maquina->setEstado(maquina->getAgotado());
    }
    else
    {
        maquina->liberarChicle();
        if (maquina->getConteo() > 0)
        {
            maquina->setEstado(maquina->getSinMoneda());
        }
        else
        {
            maquina->setEstado(maquina->getAgotado());
        }
    }
}

int main()
{
    MaquinaChicles maquina(5);

    std::cout << maquina.toString();

    maquina.insertarMoneda();
    maquina.girarManivela();
    std::cout << maquina.toString();

    maquina.insertarMoneda();
    maquina.girarManivela();
    std::cout << maquina.toString();

    maquina.insertarMoneda();
    maquina.expulsarMoneda();
    std::cout << maquina.toString();

    maquina.insertarMoneda();
    maquina.girarManivela();
    std::cout << maquina.toString();

    maquina.rellenar(3);
    std::cout << maquina.toString();

    return 0;
}