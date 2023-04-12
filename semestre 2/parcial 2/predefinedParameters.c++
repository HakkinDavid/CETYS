/*  nombre: Parámetros predeterminados
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 1 de marzo de 2023
*/

#include <iostream>
using namespace std;

class Console {
    public:
        void log (string mensaje, string origen = "main", int id = 0, bool error = false) {
            cout << (error ? "ERROR " : "") << "[" << id << "] at " << origen << " >> " << mensaje << endl;
        }
};

int main () {
    Console console;
    string command;
    console.log("Hola");
    cin >> command;
    if (command != "convivio.pedirPizza(5);") console.log("Ejecutado.");
    else {
        console.log("Error de referencia: No se puede llamar a la función pedirPizza (int rebanadas) del objeto \"convivio\" de tipo Evento. (No está definido).", "main", 404, true);
        console.log("\n8\tconvivio.pedirPizza(5);\n\t\t\t^^^");
    }
}