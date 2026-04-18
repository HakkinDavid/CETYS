#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

class MaquinaChicles;

class ExcepcionRemota : public std::runtime_error
{
public:
    explicit ExcepcionRemota(const std::string &mensaje) : std::runtime_error(mensaje) {}
};

class ExcepcionRed : public ExcepcionRemota
{
public:
    explicit ExcepcionRed(const std::string &mensaje) : ExcepcionRemota(mensaje) {}
};

class IMaquinaChiclesRemota
{
public:
    virtual int getConteo() = 0;
    virtual std::string getEstadoTexto() = 0;
    virtual std::string getUbicacion() = 0;
    virtual ~IMaquinaChiclesRemota() {}
};

class ICanalTransporte
{
public:
    virtual std::string enviar(const std::string &mensaje) = 0;
    virtual ~ICanalTransporte() {}
};

class ProtocoloRPC
{
public:
    struct Solicitud
    {
        std::string tipo;
        std::string nombreMetodo;
        std::vector<std::string> argumentos;
    };

    struct Respuesta
    {
        std::string tipo;
        std::string valor;
    };

    static std::string serializarSolicitudMetodo(const std::string &nombreMetodo,
                                                 const std::vector<std::string> &argumentos)
    {
        if (nombreMetodo.empty())
            throw ExcepcionRemota("El nombre del metodo no puede estar vacio");
        return "METODO|" + nombreMetodo + "|" + unir(argumentos, ',');
    }

    static std::string serializarRespuestaOk(const std::string &valor)
    {
        return "OK|" + valor;
    }

    static std::string serializarRespuestaError(const std::string &mensaje)
    {
        return "ERROR|" + mensaje;
    }

    static Solicitud deserializarSolicitud(const std::string &texto)
    {
        std::vector<std::string> partes = separarExacto(texto, '|', 3);
        if (partes[0] != "METODO")
            throw ExcepcionRemota("Tipo de solicitud no soportado: " + partes[0]);
        if (partes[1].empty())
            throw ExcepcionRemota("La solicitud no incluye nombre de metodo");

        Solicitud solicitud;
        solicitud.tipo = partes[0];
        solicitud.nombreMetodo = partes[1];
        solicitud.argumentos = partes[2].empty() ? std::vector<std::string>() : separarLista(partes[2], ',');
        return solicitud;
    }

    static Respuesta deserializarRespuesta(const std::string &texto)
    {
        std::vector<std::string> partes = separarExacto(texto, '|', 2);
        if (partes[0] != "OK" && partes[0] != "ERROR")
            throw ExcepcionRemota("Tipo de respuesta no soportado: " + partes[0]);

        Respuesta respuesta;
        respuesta.tipo = partes[0];
        respuesta.valor = partes[1];
        return respuesta;
    }

private:
    static std::vector<std::string> separarExacto(const std::string &texto, char separador, std::size_t cantidadEsperada)
    {
        std::vector<std::string> partes;
        std::size_t inicio = 0;

        while (partes.size() + 1 < cantidadEsperada)
        {
            std::size_t posicion = texto.find(separador, inicio);
            if (posicion == std::string::npos)
                throw ExcepcionRemota("Estructura de mensaje invalida: " + texto);
            partes.push_back(texto.substr(inicio, posicion - inicio));
            inicio = posicion + 1;
        }

        partes.push_back(texto.substr(inicio));
        if (partes.size() != cantidadEsperada)
            throw ExcepcionRemota("Cantidad de campos invalida en mensaje: " + texto);
        return partes;
    }

    static std::vector<std::string> separarLista(const std::string &texto, char separador)
    {
        std::vector<std::string> partes;
        std::size_t inicio = 0;

        while (true)
        {
            std::size_t posicion = texto.find(separador, inicio);
            if (posicion == std::string::npos)
            {
                partes.push_back(texto.substr(inicio));
                break;
            }
            partes.push_back(texto.substr(inicio, posicion - inicio));
            inicio = posicion + 1;
        }

        return partes;
    }

    static std::string unir(const std::vector<std::string> &elementos, char separador)
    {
        std::string resultado;
        for (std::size_t i = 0; i < elementos.size(); ++i)
        {
            if (i > 0)
                resultado += separador;
            resultado += elementos[i];
        }
        return resultado;
    }
};

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
    explicit EstadoSinMoneda(MaquinaChicles *maquina) : maquina(maquina) {}
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
    explicit EstadoConMoneda(MaquinaChicles *maquina) : maquina(maquina) {}
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
    explicit EstadoVendido(MaquinaChicles *maquina) : maquina(maquina) {}
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
    explicit EstadoAgotado(MaquinaChicles *maquina) : maquina(maquina) {}
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
    explicit EstadoGanador(MaquinaChicles *maquina) : maquina(maquina) {}
    void insertarMoneda() override;
    void expulsarMoneda() override;
    void girarManivela() override;
    void dispensar() override;
};

class MaquinaChicles : public IMaquinaChiclesRemota
{
private:
    std::unique_ptr<Estado> sinMoneda;
    std::unique_ptr<Estado> conMoneda;
    std::unique_ptr<Estado> vendido;
    std::unique_ptr<Estado> agotado;
    std::unique_ptr<Estado> ganador;

    Estado *estadoActual;
    int conteo;
    std::string ubicacion;

    std::string obtenerEstadoTextoInterno() const
    {
        if (estadoActual == sinMoneda.get())
            return "esperando moneda";
        if (estadoActual == conMoneda.get())
            return "esperando giro";
        if (estadoActual == vendido.get())
            return "entregando chicle";
        if (estadoActual == ganador.get())
            return "entregando premio";
        return "agotada";
    }

public:
    MaquinaChicles(const std::string &ubicacion, int cantidad)
        : estadoActual(nullptr), conteo(cantidad), ubicacion(ubicacion)
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

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    void setEstado(Estado *estado) { estadoActual = estado; }
    Estado *getSinMoneda() { return sinMoneda.get(); }
    Estado *getConMoneda() { return conMoneda.get(); }
    Estado *getVendido() { return vendido.get(); }
    Estado *getAgotado() { return agotado.get(); }
    Estado *getGanador() { return ganador.get(); }

    int getConteo() override
    {
        if (conteo < 0)
            throw ExcepcionRemota("Conteo invalido en la maquina de chicles");
        return conteo;
    }

    std::string getEstadoTexto() override
    {
        return obtenerEstadoTextoInterno();
    }

    std::string getUbicacion() override
    {
        if (ubicacion.empty())
            throw ExcepcionRemota("Ubicacion no disponible");
        return ubicacion;
    }

    std::string toString()
    {
        return "\nMaquina de Chicles, S.A.\nInventario: " + std::to_string(conteo) +
               " chicles\nEstado: " + obtenerEstadoTextoInterno() + "\n";
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
        std::cout << "Maquina recargada con " << cantidad << " chicles" << std::endl;
        estadoActual = sinMoneda.get();
    }
};

class SkeletonMaquinaChicles
{
private:
    MaquinaChicles &maquina;
    std::unordered_map<std::string, std::function<std::string(const std::vector<std::string> &)>> despachadores;

public:
    explicit SkeletonMaquinaChicles(MaquinaChicles &maquina) : maquina(maquina)
    {
        despachadores["getConteo"] = [this](const std::vector<std::string> &argumentos)
        {
            validarCantidadArgumentos("getConteo", argumentos, 0);
            return std::to_string(this->maquina.getConteo());
        };
        despachadores["getEstadoTexto"] = [this](const std::vector<std::string> &argumentos)
        {
            validarCantidadArgumentos("getEstadoTexto", argumentos, 0);
            return this->maquina.getEstadoTexto();
        };
        despachadores["getUbicacion"] = [this](const std::vector<std::string> &argumentos)
        {
            validarCantidadArgumentos("getUbicacion", argumentos, 0);
            return this->maquina.getUbicacion();
        };
    }

    std::string despachar(const std::string &solicitudSerializada)
    {
        try
        {
            ProtocoloRPC::Solicitud solicitud = ProtocoloRPC::deserializarSolicitud(solicitudSerializada);
            return invocarMetodo(solicitud.nombreMetodo, solicitud.argumentos);
        }
        catch (const std::exception &excepcion)
        {
            return ProtocoloRPC::serializarRespuestaError(excepcion.what());
        }
    }

private:
    void validarCantidadArgumentos(const std::string &nombreMetodo,
                                   const std::vector<std::string> &argumentos,
                                   std::size_t cantidadEsperada)
    {
        if (argumentos.size() != cantidadEsperada)
        {
            throw ExcepcionRemota("Cantidad de argumentos invalida para " + nombreMetodo +
                                  ": se esperaban " + std::to_string(cantidadEsperada));
        }
    }

    std::string invocarMetodo(const std::string &nombreMetodo, const std::vector<std::string> &argumentos)
    {
        auto iterador = despachadores.find(nombreMetodo);
        if (iterador == despachadores.end())
            throw ExcepcionRemota("Metodo remoto no registrado: " + nombreMetodo);
        return ProtocoloRPC::serializarRespuestaOk(iterador->second(argumentos));
    }
};

class ServidorRPC : public ICanalTransporte
{
private:
    SkeletonMaquinaChicles &skeleton;
    std::mt19937 generador;
    std::uniform_int_distribution<int> distribucionPorcentaje;

public:
    explicit ServidorRPC(SkeletonMaquinaChicles &skeleton)
        : skeleton(skeleton),
          generador(static_cast<unsigned int>(std::time(nullptr))),
          distribucionPorcentaje(1, 100)
    {
    }

    std::string enviar(const std::string &mensaje) override
    {
        std::cout << "[ServidorRPC] Enviando mensaje por la red simulada: " << mensaje << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));

        if (distribucionPorcentaje(generador) <= 5)
            throw ExcepcionRed("Fallo de red");

        std::string respuesta = skeleton.despachar(mensaje);
        std::cout << "[ServidorRPC] Respuesta recibida desde el skeleton: " << respuesta << std::endl;
        return respuesta;
    }
};

class ProxyMaquinaChicles : public IMaquinaChiclesRemota
{
private:
    ICanalTransporte *canal;

public:
    explicit ProxyMaquinaChicles(ICanalTransporte *canal) : canal(canal)
    {
        if (canal == nullptr)
            throw ExcepcionRemota("El proxy no puede inicializarse sin canal de transporte");
    }

    int getConteo() override
    {
        std::string valor = invocarRemoto("getConteo", {});
        return convertirAEntero(valor);
    }

    std::string getEstadoTexto() override
    {
        return invocarRemoto("getEstadoTexto", {});
    }

    std::string getUbicacion() override
    {
        return invocarRemoto("getUbicacion", {});
    }

private:
    std::string invocarRemoto(const std::string &nombreMetodo, const std::vector<std::string> &argumentos)
    {
        std::string solicitud = ProtocoloRPC::serializarSolicitudMetodo(nombreMetodo, argumentos);

        std::string respuestaSerializada;
        try
        {
            respuestaSerializada = canal->enviar(solicitud);
        }
        catch (const ExcepcionRed &excepcion)
        {
            throw;
        }

        ProtocoloRPC::Respuesta respuesta = ProtocoloRPC::deserializarRespuesta(respuestaSerializada);

        if (respuesta.tipo == "ERROR")
            throw ExcepcionRemota(respuesta.valor);

        return respuesta.valor;
    }

    int convertirAEntero(const std::string &texto)
    {
        if (texto.empty())
            throw ExcepcionRemota("Respuesta numerica vacia");

        std::size_t indice = 0;
        long valor = 0;

        try
        {
            valor = std::stol(texto, &indice);
        }
        catch (const std::exception &)
        {
            throw ExcepcionRemota("No se pudo convertir a entero: " + texto);
        }

        if (indice != texto.size())
            throw ExcepcionRemota("Respuesta numerica invalida: " + texto);

        return static_cast<int>(valor);
    }
};

class RegistroServicios
{
private:
    std::unordered_map<std::string, ICanalTransporte *> servicios;

public:
    void registrar(const std::string &nombreServicio, ICanalTransporte *canal)
    {
        if (canal == nullptr)
            throw ExcepcionRemota("No se puede registrar un canal nulo");
        servicios[nombreServicio] = canal;
    }

    ICanalTransporte *obtenerCanal(const std::string &nombreServicio)
    {
        auto iterador = servicios.find(nombreServicio);
        if (iterador == servicios.end())
            throw ExcepcionRemota("Servicio no encontrado en el registro: " + nombreServicio);
        return iterador->second;
    }
};

class MonitorMaquinaChicles
{
private:
    IMaquinaChiclesRemota *maquina;

public:
    explicit MonitorMaquinaChicles(IMaquinaChiclesRemota *maquina) : maquina(maquina) {}

    void reportar()
    {
        std::string ubicacion = maquina->getUbicacion();
        int conteo = maquina->getConteo();
        std::string estado = maquina->getEstadoTexto();

        std::cout << "Maquina de chicles: " << ubicacion << std::endl;
        std::cout << "Inventario actual: " << conteo << " chicles" << std::endl;
        std::cout << "Estado actual: " << estado << std::endl;
    }
};

class NodoServidorMaquinaChicles
{
private:
    MaquinaChicles maquina;
    std::unique_ptr<SkeletonMaquinaChicles> skeleton;
    std::unique_ptr<ServidorRPC> servidor;

public:
    NodoServidorMaquinaChicles(const std::string &ubicacion, int cantidadInicial)
        : maquina(ubicacion, cantidadInicial)
    {
    }

    void simularActividadInterna()
    {
        std::cout << maquina.toString();
        maquina.insertarMoneda();
        maquina.girarManivela();
        maquina.insertarMoneda();
        maquina.expulsarMoneda();
        maquina.insertarMoneda();
        maquina.girarManivela();
    }

    void inicializarTransporte()
    {
        skeleton = std::make_unique<SkeletonMaquinaChicles>(maquina);
        servidor = std::make_unique<ServidorRPC>(*skeleton);
    }

    ICanalTransporte *obtenerCanalTransporte()
    {
        if (!servidor)
            throw ExcepcionRemota("El transporte del servidor aun no ha sido inicializado");
        return servidor.get();
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
        maquina->setEstado(maquina->getGanador());
    else
        maquina->setEstado(maquina->getVendido());
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
    std::cout << "No obtendras otro chicle" << std::endl;
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
    std::cout << "Maquina agotada" << std::endl;
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
            maquina->setEstado(maquina->getSinMoneda());
        else
            maquina->setEstado(maquina->getAgotado());
    }
}

int main()
{
    NodoServidorMaquinaChicles nodoServidor("Tecate", 5);
    nodoServidor.simularActividadInterna();
    nodoServidor.inicializarTransporte();

    RegistroServicios registro;
    registro.registrar("maquina-chicles-tecate", nodoServidor.obtenerCanalTransporte());

    ICanalTransporte *canal = registro.obtenerCanal("maquina-chicles-tecate");
    std::unique_ptr<IMaquinaChiclesRemota> maquinaRemota = std::make_unique<ProxyMaquinaChicles>(canal);
    MonitorMaquinaChicles monitor(maquinaRemota.get());

    for (int intento = 1; intento <= 3; ++intento)
    {
        try
        {
            monitor.reportar();
            return 0;
        }
        catch (const ExcepcionRed &excepcion)
        {
            std::cout << "Error de red en el intento " << intento << ": " << excepcion.what() << std::endl;
        }
        catch (const ExcepcionRemota &excepcion)
        {
            std::cout << "Error remoto: " << excepcion.what() << std::endl;
            return 1;
        }
    }

    std::cout << "No fue posible obtener el reporte tras varios intentos" << std::endl;
    return 1;
}
