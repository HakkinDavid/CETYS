/*  nombre: Alumno
    autor: David Emmanuel Santana Romero y Sebastian Soto
    versión: 1.0
    fecha: 15 de febrero de 2022
*/

#include <iostream>
#include <math.h>
using namespace std;

class Student {
    public:
    Student () {
        cout << "Sí, clarito." << endl;
        promedio = 0.0;
        nombre = "Santana";
    }
    ~Student () {
        cout << "He hecho honor al nombre de Ferlong." << endl;
        promedio = 0.0;
        nombre = "";
    }
    void setGrades (float x, int index) {
        if (x > 10 || x < 0) {
            cout << "Valor inválido. Las calificaciones parciales van de 0 a 10." << endl;
            return;
        }
        calificaciones[index] = x;
    }
    void setName (string n) {
        nombre = n;
    }
    float getGrades (int index) const {
        return calificaciones[index];
    }
    string getName () const {
        return nombre;
    }
    void promediar () {
        promedio = 0;
        promedio += (calificaciones[0] + calificaciones[1] + calificaciones[2]);
        promedio /= 3;
        if (promedio < 7 && promedio >= 6) promedio = 5.9;
    }
    void display (int mode) const {
        switch (mode) {
            case 1:
                cout << "Nombre: " << nombre << endl;
            break;
            case 2:
                cout << "Calificaciones: " << calificaciones[0] << ", " << calificaciones[1] << " y " << calificaciones[2] << endl;
            break;
            case 3:
                cout << "Promedio: " << promedio << endl;
            break;
            case 4:
                cout << "El promedio de " << calificaciones[0] << ", " << calificaciones[1] << " y " << calificaciones[2] << " es " << promedio << endl;
            break;
            default:
                cout << "Nombre: " << nombre << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Calificaciones: " << calificaciones[0] << ", " << calificaciones[1] << " y " << calificaciones[2] << endl;
            break;
        }
    }
    private:
        float promedio, calificaciones[3] = {0.0, 0.0, 0.0};
        string nombre = "Fernando Pulido Mendivil";
};

int main () {
    Student david;
    string nombre;
    float calificaciones[3] = {0.0, 0.0, 0.0};
    int modo = 0;
    cout << "Proporciona" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Calificaciones [3]:";
    cin >> calificaciones[0];
    cin >> calificaciones[1];
    cin >> calificaciones[2];

    david.setName(nombre);
    for (int i = 0; i < 3; i++) {
        david.setGrades(calificaciones[i], i);
    }
    david.promediar();

    cout << "¿Cómo quieres desplegar la información?\n[0] Todo\n[1] Solo nombre\n[2] Solo calificaciones\n[3] Solo promedio\n[4] Solo promedio y calificaciones";
    cin >> modo;
    david.display(modo);
}