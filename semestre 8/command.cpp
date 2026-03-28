#include <iostream>

class Comando
{
public:
    virtual void ejecutar() = 0;
    virtual void deshacer() = 0;
    virtual ~Comando() {}
};

class ComandoNulo : public Comando
{
public:
    void ejecutar() override {}
    void deshacer() override {}
};

class Light
{
public:
    void encendido() { std::cout << "[Light]: Nos prendieron la luz" << std::endl; }
    void apagado() { std::cout << "[Light]: Nos apagaron la luz" << std::endl; }
};
class CeilingLight
{
public:
    void encendido() { std::cout << "[CeilingLight]: Nos prendieron la luz de techo" << std::endl; }
    void apagado() { std::cout << "[CeilingLight]: Nos apagaron la luz de techo" << std::endl; }
    void atenuar() { std::cout << "[CeilingLight]: Atenuaron la luz de techo" << std::endl; }
};
class OutdoorLight
{
public:
    void encendido() { std::cout << "[OutdoorLight]: Nos prendieron la luz exterior" << std::endl; }
    void apagado() { std::cout << "[OutdoorLight]: Nos apagaron la luz exterior" << std::endl; }
};
class GardenLight
{
public:
    int dusk{18};
    int dawn{6};
    void setDuskTime(int t)
    {
        dusk = t;
        std::cout << "[GardenLight]: Configuran hora de anochecer a " << t << std::endl;
    }
    void setDawnTime(int t)
    {
        dawn = t;
        std::cout << "[GardenLight]: Configuran hora de amanecer a " << t << std::endl;
    }
    void manualOn() { std::cout << "[GardenLight]: Nos prendieron la luz del jardín" << std::endl; }
    void manualOff() { std::cout << "[GardenLight]: Nos apagaron la luz del jardín" << std::endl; }
};

class GarageDoor
{
public:
    void up() { std::cout << "[GarageDoor]: Nos abrieron la cochera" << std::endl; }
    void down() { std::cout << "[GarageDoor]: Nos cerraron la cochera" << std::endl; }
    void stop() { std::cout << "[GarageDoor]: Detuvieron la cochera" << std::endl; }
    void lightOn() { std::cout << "[GarageDoor]: Nos prendieron la luz de la cochera" << std::endl; }
    void lightOff() { std::cout << "[GarageDoor]: Nos apagaron la luz de la cochera" << std::endl; }
};
class Sprinkler
{
public:
    void waterOn() { std::cout << "[Sprinkler]: Nos prendieron el aspersor" << std::endl; }
    void waterOff() { std::cout << "[Sprinkler]: Nos apagaron el aspersor" << std::endl; }
};
class SecurityControl
{
public:
    void arm() { std::cout << "[SecurityControl]: Activaron la seguridad" << std::endl; }
    void disarm() { std::cout << "[SecurityControl]: Desactivaron la seguridad" << std::endl; }
};
class Thermostat
{
public:
    int temp{20};
    void setTemperature(int t)
    {
        temp = t;
        std::cout << "[Thermostat]: Ajustaron la temperatura a " << t << std::endl;
    }
};
class Hottub
{
public:
    int temp{30};
    void circulate() { std::cout << "[Hottub]: Activaron la circulación del jacuzzi" << std::endl; }
    void jetsOn() { std::cout << "[Hottub]: Encendieron los jets del jacuzzi" << std::endl; }
    void jetsOff() { std::cout << "[Hottub]: Apagaron los jets del jacuzzi" << std::endl; }
    void setTemperature(int t)
    {
        temp = t;
        std::cout << "[Hottub]: Ajustaron la temperatura del jacuzzi a " << t << std::endl;
    }
};
class FaucetControl
{
public:
    void openValue() { std::cout << "[FaucetControl]: Nos abrieron la llave" << std::endl; }
    void closeValue() { std::cout << "[FaucetControl]: Nos cerraron la llave" << std::endl; }
};
class ApplianceControl
{
public:
    void encendido() { std::cout << "[ApplianceControl]: Nos prendieron el aparato" << std::endl; }
    void apagado() { std::cout << "[ApplianceControl]: Nos apagaron el aparato" << std::endl; }
};
class TV
{
public:
    int volumen{10};
    int canal{1};
    void encendido() { std::cout << "[TV]: Nos prendieron la televisión" << std::endl; }
    void apagado() { std::cout << "[TV]: Nos apagaron la televisión" << std::endl; }
    void setInputChannel(int c)
    {
        canal = c;
        std::cout << "[TV]: Cambiaron el canal a " << c << std::endl;
    }
    void setVolume(int v)
    {
        volumen = v;
        std::cout << "[TV]: Ajustaron el volumen de la televisión a " << v << std::endl;
    }
};
class Stereo
{
public:
    int volumen{5};
    void encendido() { std::cout << "[Stereo]: Nos prendieron el estéreo" << std::endl; }
    void apagado() { std::cout << "[Stereo]: Nos apagaron el estéreo" << std::endl; }
    void setCD() { std::cout << "[Stereo]: Pusieron un CD" << std::endl; }
    void setVolume(int v)
    {
        volumen = v;
        std::cout << "[Stereo]: Ajustaron el volumen a " << v << std::endl;
    }
    void setDvd() { std::cout << "[Stereo]: Pusieron un DVD" << std::endl; }
    void setRadio() { std::cout << "[Stereo]: Pusieron la radio" << std::endl; }
};

class ComandoTVVolumenSubir : public Comando
{
    TV *tv;

public:
    ComandoTVVolumenSubir(TV *x) : tv(x) {}
    void ejecutar() override { tv->setVolume(tv->volumen + 1); }
    void deshacer() override { tv->setVolume(tv->volumen - 1); }
};

class ComandoTVVolumenBajar : public Comando
{
    TV *tv;

public:
    ComandoTVVolumenBajar(TV *x) : tv(x) {}
    void ejecutar() override { tv->setVolume(tv->volumen - 1); }
    void deshacer() override { tv->setVolume(tv->volumen + 1); }
};

class ComandoTVCanalSubir : public Comando
{
    TV *tv;

public:
    ComandoTVCanalSubir(TV *x) : tv(x) {}
    void ejecutar() override { tv->setInputChannel(tv->canal + 1); }
    void deshacer() override { tv->setInputChannel(tv->canal - 1); }
};

class ComandoTVCanalBajar : public Comando
{
    TV *tv;

public:
    ComandoTVCanalBajar(TV *x) : tv(x) {}
    void ejecutar() override { tv->setInputChannel(tv->canal - 1); }
    void deshacer() override { tv->setInputChannel(tv->canal + 1); }
};

class ComandoStereoVolumenSubir : public Comando
{
    Stereo *s;

public:
    ComandoStereoVolumenSubir(Stereo *x) : s(x) {}
    void ejecutar() override { s->setVolume(s->volumen + 1); }
    void deshacer() override { s->setVolume(s->volumen - 1); }
};

class ComandoStereoVolumenBajar : public Comando
{
    Stereo *s;

public:
    ComandoStereoVolumenBajar(Stereo *x) : s(x) {}
    void ejecutar() override { s->setVolume(s->volumen - 1); }
    void deshacer() override { s->setVolume(s->volumen + 1); }
};

class ComandoTemperaturaSubir : public Comando
{
    Thermostat *t;

public:
    ComandoTemperaturaSubir(Thermostat *x) : t(x) {}
    void ejecutar() override { t->setTemperature(t->temp + 1); }
    void deshacer() override { t->setTemperature(t->temp - 1); }
};

class ComandoTemperaturaBajar : public Comando
{
    Thermostat *t;

public:
    ComandoTemperaturaBajar(Thermostat *x) : t(x) {}
    void ejecutar() override { t->setTemperature(t->temp - 1); }
    void deshacer() override { t->setTemperature(t->temp + 1); }
};

class CeilingFan
{
public:
    enum Speed
    {
        OFF,
        LOW,
        MEDIUM,
        HIGH
    };
    Speed speed{OFF};
    void alto()
    {
        speed = HIGH;
        std::cout << "[CeilingFan]: Nos pusieron el ventilador en alto" << std::endl;
    }
    void medio()
    {
        speed = MEDIUM;
        std::cout << "[CeilingFan]: Nos pusieron el ventilador en medio" << std::endl;
    }
    void bajo()
    {
        speed = LOW;
        std::cout << "[CeilingFan]: Nos pusieron el ventilador en bajo" << std::endl;
    }
    void apagado()
    {
        speed = OFF;
        std::cout << "[CeilingFan]: Apagaron el ventilador" << std::endl;
    }
    void subir()
    {
        if (speed == LOW)
            medio();
        else if (speed == MEDIUM)
            alto();
        else if (speed == OFF)
            bajo();
    }
    void bajar()
    {
        if (speed == HIGH)
            medio();
        else if (speed == MEDIUM)
            bajo();
        else if (speed == LOW)
            apagado();
    }
    Speed obtenerVelocidad() { return speed; }
};

class ComandoLuzEncender : public Comando
{
    Light *l;

public:
    ComandoLuzEncender(Light *x) : l(x) {}
    void ejecutar() override { l->encendido(); }
    void deshacer() override { l->apagado(); }
};

class ComandoVentiladorAlto : public Comando
{
    CeilingFan *f;
    CeilingFan::Speed previo;

public:
    ComandoVentiladorAlto(CeilingFan *x) : f(x) {}
    void ejecutar() override
    {
        previo = f->speed;
        f->alto();
    }
    void deshacer() override
    {
        if (previo == CeilingFan::OFF)
            f->apagado();
        else if (previo == CeilingFan::MEDIUM)
            f->medio();
        else if (previo == CeilingFan::LOW)
            f->bajo();
        else if (previo == CeilingFan::HIGH)
            f->alto();
    }
};

class ComandoStereoEncender : public Comando
{
    Stereo *s;

public:
    ComandoStereoEncender(Stereo *x) : s(x) {}
    void ejecutar() override
    {
        s->encendido();
        s->setCD();
        s->setVolume(11);
    }
    void deshacer() override { s->apagado(); }
};

class ComandoLuzApagar : public Comando
{
    Light *l;

public:
    ComandoLuzApagar(Light *x) : l(x) {}
    void ejecutar() override { l->apagado(); }
    void deshacer() override { l->encendido(); }
};

class ComandoLuzTechoEncender : public Comando
{
    CeilingLight *l;

public:
    ComandoLuzTechoEncender(CeilingLight *x) : l(x) {}
    void ejecutar() override { l->encendido(); }
    void deshacer() override { l->apagado(); }
};

class ComandoLuzTechoApagar : public Comando
{
    CeilingLight *l;

public:
    ComandoLuzTechoApagar(CeilingLight *x) : l(x) {}
    void ejecutar() override { l->apagado(); }
    void deshacer() override { l->encendido(); }
};

class ComandoGarageAbrir : public Comando
{
    GarageDoor *g;

public:
    ComandoGarageAbrir(GarageDoor *x) : g(x) {}
    void ejecutar() override { g->up(); }
    void deshacer() override { g->down(); }
};

class ComandoGarageCerrar : public Comando
{
    GarageDoor *g;

public:
    ComandoGarageCerrar(GarageDoor *x) : g(x) {}
    void ejecutar() override { g->down(); }
    void deshacer() override { g->up(); }
};

class ComandoStereoApagar : public Comando
{
    Stereo *s;

public:
    ComandoStereoApagar(Stereo *x) : s(x) {}
    void ejecutar() override { s->apagado(); }
    void deshacer() override { s->encendido(); }
};

class ComandoVentiladorApagar : public Comando
{
    CeilingFan *f;
    CeilingFan::Speed previo;

public:
    ComandoVentiladorApagar(CeilingFan *x) : f(x) {}
    void ejecutar() override
    {
        previo = f->speed;
        f->apagado();
    }
    void deshacer() override
    {
        if (previo == CeilingFan::HIGH)
            f->alto();
        else if (previo == CeilingFan::MEDIUM)
            f->medio();
        else if (previo == CeilingFan::LOW)
            f->bajo();
    }
};

class ComandoVentiladorSubir : public Comando
{
    CeilingFan *f;

public:
    ComandoVentiladorSubir(CeilingFan *x) : f(x) {}
    void ejecutar() override { f->subir(); }
    void deshacer() override { f->bajar(); }
};

class ComandoVentiladorBajar : public Comando
{
    CeilingFan *f;

public:
    ComandoVentiladorBajar(CeilingFan *x) : f(x) {}
    void ejecutar() override { f->bajar(); }
    void deshacer() override { f->subir(); }
};

class ComandoLuzExteriorEncender : public Comando
{
    OutdoorLight *l;

public:
    ComandoLuzExteriorEncender(OutdoorLight *x) : l(x) {}
    void ejecutar() override { l->encendido(); }
    void deshacer() override { l->apagado(); }
};

class ComandoLuzExteriorApagar : public Comando
{
    OutdoorLight *l;

public:
    ComandoLuzExteriorApagar(OutdoorLight *x) : l(x) {}
    void ejecutar() override { l->apagado(); }
    void deshacer() override { l->encendido(); }
};

class ComandoJardinEncender : public Comando
{
    GardenLight *g;

public:
    ComandoJardinEncender(GardenLight *x) : g(x) {}
    void ejecutar() override { g->manualOn(); }
    void deshacer() override { g->manualOff(); }
};

class ComandoJardinApagar : public Comando
{
    GardenLight *g;

public:
    ComandoJardinApagar(GardenLight *x) : g(x) {}
    void ejecutar() override { g->manualOff(); }
    void deshacer() override { g->manualOn(); }
};

class ComandoAspersorEncender : public Comando
{
    Sprinkler *s;

public:
    ComandoAspersorEncender(Sprinkler *x) : s(x) {}
    void ejecutar() override { s->waterOn(); }
    void deshacer() override { s->waterOff(); }
};

class ComandoAspersorApagar : public Comando
{
    Sprinkler *s;

public:
    ComandoAspersorApagar(Sprinkler *x) : s(x) {}
    void ejecutar() override { s->waterOff(); }
    void deshacer() override { s->waterOn(); }
};

class ComandoTVEncender : public Comando
{
    TV *tv;

public:
    ComandoTVEncender(TV *x) : tv(x) {}
    void ejecutar() override { tv->encendido(); }
    void deshacer() override { tv->apagado(); }
};

class ComandoTVApagar : public Comando
{
    TV *tv;

public:
    ComandoTVApagar(TV *x) : tv(x) {}
    void ejecutar() override { tv->apagado(); }
    void deshacer() override { tv->encendido(); }
};

class ComandoJacuzziEncenderJets : public Comando
{
    Hottub *h;

public:
    ComandoJacuzziEncenderJets(Hottub *x) : h(x) {}
    void ejecutar() override { h->jetsOn(); }
    void deshacer() override { h->jetsOff(); }
};

class ComandoJacuzziApagarJets : public Comando
{
    Hottub *h;

public:
    ComandoJacuzziApagarJets(Hottub *x) : h(x) {}
    void ejecutar() override { h->jetsOff(); }
    void deshacer() override { h->jetsOn(); }
};

class ComandoLlaveAbrir : public Comando
{
    FaucetControl *f;

public:
    ComandoLlaveAbrir(FaucetControl *x) : f(x) {}
    void ejecutar() override { f->openValue(); }
    void deshacer() override { f->closeValue(); }
};

class ComandoLlaveCerrar : public Comando
{
    FaucetControl *f;

public:
    ComandoLlaveCerrar(FaucetControl *x) : f(x) {}
    void ejecutar() override { f->closeValue(); }
    void deshacer() override { f->openValue(); }
};

class ComandoMacro : public Comando
{
    Comando **comandos;
    int tamaño;

public:
    ComandoMacro(Comando **c, int t) : comandos(c), tamaño(t) {}
    void ejecutar() override
    {
        for (int i = 0; i < tamaño; i++)
            comandos[i]->ejecutar();
    }
    void deshacer() override
    {
        for (int i = tamaño - 1; i >= 0; i--)
            comandos[i]->deshacer();
    }
};

class ControlRemoto
{
    Comando *encendido[20];
    Comando *apagado[20];
    Comando *ultimo;

public:
    ControlRemoto()
    {
        Comando *no = new ComandoNulo();
        for (int i = 0; i < 20; i++)
        {
            encendido[i] = no;
            apagado[i] = no;
        }
        ultimo = no;
    }
    void establecerComando(int i, Comando *cEncendido, Comando *cApagado)
    {
        encendido[i] = cEncendido;
        apagado[i] = cApagado;
    }
    void botonEncendido(int i)
    {
        encendido[i]->ejecutar();
        ultimo = encendido[i];
    }
    void botonApagado(int i)
    {
        apagado[i]->ejecutar();
        ultimo = apagado[i];
    }
    void botonDeshacer() { ultimo->deshacer(); }
};

class ComandoLuzTechoAtenuar : public Comando
{
    CeilingLight *l;

public:
    ComandoLuzTechoAtenuar(CeilingLight *x) : l(x) {}
    void ejecutar() override { l->atenuar(); }
    void deshacer() override { l->encendido(); }
};

class ComandoGarageStop : public Comando
{
    GarageDoor *g;

public:
    ComandoGarageStop(GarageDoor *x) : g(x) {}
    void ejecutar() override { g->stop(); }
    void deshacer() override {}
};

class ComandoGarageLuzOn : public Comando
{
    GarageDoor *g;

public:
    ComandoGarageLuzOn(GarageDoor *x) : g(x) {}
    void ejecutar() override { g->lightOn(); }
    void deshacer() override { g->lightOff(); }
};

class ComandoGarageLuzOff : public Comando
{
    GarageDoor *g;

public:
    ComandoGarageLuzOff(GarageDoor *x) : g(x) {}
    void ejecutar() override { g->lightOff(); }
    void deshacer() override { g->lightOn(); }
};

class ComandoStereoDVD : public Comando
{
    Stereo *s;

public:
    ComandoStereoDVD(Stereo *x) : s(x) {}
    void ejecutar() override { s->setDvd(); }
    void deshacer() override {}
};

class ComandoStereoRadio : public Comando
{
    Stereo *s;

public:
    ComandoStereoRadio(Stereo *x) : s(x) {}
    void ejecutar() override { s->setRadio(); }
    void deshacer() override {}
};

class ComandoTVCanal : public Comando
{
    TV *tv;
    int canal;

public:
    ComandoTVCanal(TV *x, int c) : tv(x), canal(c) {}
    void ejecutar() override { tv->setInputChannel(canal); }
    void deshacer() override {}
};

class ComandoTVVolumen : public Comando
{
    TV *tv;
    int vol;

public:
    ComandoTVVolumen(TV *x, int v) : tv(x), vol(v) {}
    void ejecutar() override { tv->setVolume(vol); }
    void deshacer() override {}
};

class ComandoJacuzziCircular : public Comando
{
    Hottub *h;

public:
    ComandoJacuzziCircular(Hottub *x) : h(x) {}
    void ejecutar() override { h->circulate(); }
    void deshacer() override {}
};

class ComandoJacuzziTemperatura : public Comando
{
    Hottub *h;
    int t;

public:
    ComandoJacuzziTemperatura(Hottub *x, int temp) : h(x), t(temp) {}
    void ejecutar() override { h->setTemperature(t); }
    void deshacer() override {}
};

class ComandoJardinDusk : public Comando
{
    GardenLight *g;
    int t;

public:
    ComandoJardinDusk(GardenLight *x, int val) : g(x), t(val) {}
    void ejecutar() override { g->setDuskTime(t); }
    void deshacer() override {}
};

class ComandoJardinDawn : public Comando
{
    GardenLight *g;
    int t;

public:
    ComandoJardinDawn(GardenLight *x, int val) : g(x), t(val) {}
    void ejecutar() override { g->setDawnTime(t); }
    void deshacer() override {}
};

int main()
{
    ControlRemoto control;

    Light luzSala;
    CeilingLight luzTecho;
    CeilingFan ventilador;
    GarageDoor cochera;
    Sprinkler aspersor;
    TV tv;
    Stereo stereo;
    FaucetControl llave;
    Thermostat termo;
    OutdoorLight luzExterior;
    GardenLight jardin;
    Hottub jacuzzi;
    SecurityControl seguridad;
    ApplianceControl aparato;

    ComandoLuzEncender luzOn(&luzSala);
    ComandoLuzApagar luzOff(&luzSala);

    ComandoLuzTechoEncender techoOn(&luzTecho);
    ComandoLuzTechoApagar techoOff(&luzTecho);
    ComandoLuzTechoAtenuar techoDim(&luzTecho);

    ComandoVentiladorSubir fanUp(&ventilador);
    ComandoVentiladorBajar fanDown(&ventilador);

    ComandoGarageAbrir garageOpen(&cochera);
    ComandoGarageCerrar garageClose(&cochera);

    ComandoAspersorEncender aspOn(&aspersor);
    ComandoAspersorApagar aspOff(&aspersor);

    ComandoTVEncender tvOn(&tv);
    ComandoTVApagar tvOff(&tv);

    ComandoStereoEncender stereoOn(&stereo);
    ComandoStereoApagar stereoOff(&stereo);

    ComandoLlaveAbrir llaveOn(&llave);
    ComandoLlaveCerrar llaveOff(&llave);

    ComandoTVVolumenSubir tvVolUp(&tv);
    ComandoTVVolumenBajar tvVolDown(&tv);
    ComandoTVCanalSubir tvChanUp(&tv);
    ComandoTVCanalBajar tvChanDown(&tv);

    ComandoStereoVolumenSubir stereoVolUp(&stereo);
    ComandoStereoVolumenBajar stereoVolDown(&stereo);

    ComandoTemperaturaSubir tempUp(&termo);
    ComandoTemperaturaBajar tempDown(&termo);

    ComandoLuzExteriorEncender extOn(&luzExterior);
    ComandoLuzExteriorApagar extOff(&luzExterior);

    ComandoJardinEncender jardinOn(&jardin);
    ComandoJardinApagar jardinOff(&jardin);
    ComandoJardinDusk jardinDusk(&jardin, 19);
    ComandoJardinDawn jardinDawn(&jardin, 6);

    ComandoJacuzziEncenderJets jetsOn(&jacuzzi);
    ComandoJacuzziApagarJets jetsOff(&jacuzzi);
    ComandoJacuzziCircular jacuzziCirc(&jacuzzi);
    ComandoJacuzziTemperatura jacuzziTempUp(&jacuzzi, 36);

    class ComandoSeguridadArmar : public Comando
    {
        SecurityControl *s;

    public:
        ComandoSeguridadArmar(SecurityControl *x) : s(x) {}
        void ejecutar() override { s->arm(); }
        void deshacer() override { s->disarm(); }
    } segOn(&seguridad);

    class ComandoSeguridadDesarmar : public Comando
    {
        SecurityControl *s;

    public:
        ComandoSeguridadDesarmar(SecurityControl *x) : s(x) {}
        void ejecutar() override { s->disarm(); }
        void deshacer() override { s->arm(); }
    } segOff(&seguridad);

    class ComandoAparatoEncender : public Comando
    {
        ApplianceControl *a;

    public:
        ComandoAparatoEncender(ApplianceControl *x) : a(x) {}
        void ejecutar() override { a->encendido(); }
        void deshacer() override { a->apagado(); }
    } aparatoOn(&aparato);

    class ComandoAparatoApagar : public Comando
    {
        ApplianceControl *a;

    public:
        ComandoAparatoApagar(ApplianceControl *x) : a(x) {}
        void ejecutar() override { a->apagado(); }
        void deshacer() override { a->encendido(); }
    } aparatoOff(&aparato);

    control.establecerComando(0, &luzOn, &luzOff);
    control.establecerComando(1, &techoOn, &techoOff);
    control.establecerComando(2, &fanUp, &fanDown);
    control.establecerComando(3, &garageOpen, &garageClose);
    control.establecerComando(4, &aspOn, &aspOff);
    control.establecerComando(5, &tvOn, &tvOff);
    control.establecerComando(6, &stereoOn, &stereoOff);
    control.establecerComando(7, &llaveOn, &llaveOff);
    control.establecerComando(8, &tvVolUp, &tvVolDown);
    control.establecerComando(9, &tvChanUp, &tvChanDown);
    control.establecerComando(10, &stereoVolUp, &stereoVolDown);
    control.establecerComando(11, &tempUp, &tempDown);
    control.establecerComando(12, &techoDim, &techoOn);
    control.establecerComando(13, &extOn, &extOff);
    control.establecerComando(14, &jardinOn, &jardinOff);
    control.establecerComando(15, &jetsOn, &jetsOff);
    control.establecerComando(16, &segOn, &segOff);
    control.establecerComando(17, &aparatoOn, &aparatoOff);
    control.establecerComando(18, &jacuzziCirc, &jacuzziTempUp);
    control.establecerComando(19, &jardinDusk, &jardinDawn);

    Comando *macroOnArr[] = {&luzOn, &techoOn, &tvOn, &stereoOn, &extOn};
    Comando *macroOffArr[] = {&luzOff, &techoOff, &tvOff, &stereoOff, &extOff};
    ComandoMacro macroOn(macroOnArr, 5);
    ComandoMacro macroOff(macroOffArr, 5);

    control.establecerComando(0, &macroOn, &macroOff);

    control.botonEncendido(2);
    control.botonEncendido(2);
    control.botonEncendido(2);
    control.botonApagado(2);
    control.botonApagado(2);
    control.botonApagado(2);

    control.botonEncendido(5);
    for (int i = 0; i < 3; i++)
        control.botonEncendido(8);
    for (int i = 0; i < 2; i++)
        control.botonApagado(8);

    for (int i = 0; i < 3; i++)
        control.botonEncendido(9);
    for (int i = 0; i < 2; i++)
        control.botonApagado(9);

    control.botonEncendido(6);
    for (int i = 0; i < 3; i++)
        control.botonEncendido(10);
    for (int i = 0; i < 2; i++)
        control.botonApagado(10);

    for (int i = 0; i < 3; i++)
        control.botonEncendido(11);
    for (int i = 0; i < 2; i++)
        control.botonApagado(11);

    control.botonEncendido(8);
    control.botonEncendido(8);
    control.botonDeshacer();
    control.botonDeshacer();

    control.botonEncendido(0);
    control.botonApagado(0);
    control.botonEncendido(1);
    control.botonEncendido(12);
    control.botonApagado(1);

    for (int i = 0; i < 20; i++)
    {
        control.botonEncendido(i);
        control.botonApagado(i);
        control.botonDeshacer();
    }

    jardinDusk.ejecutar();
    jardinDawn.ejecutar();

    jacuzziCirc.ejecutar();
    jacuzziTempUp.ejecutar();
    control.botonDeshacer();

    control.botonEncendido(16);
    control.botonApagado(16);
    control.botonDeshacer();

    control.botonEncendido(17);
    control.botonApagado(17);
    control.botonDeshacer();

    control.botonEncendido(0);
    control.botonApagado(0);
    control.botonDeshacer();

    return 0;
}