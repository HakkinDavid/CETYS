/*  nombre: Llevar un récord de calificaciones
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 1 de febrero de 2023
*/

#include <iostream>
#include <string>
using namespace std;

class Calificaciones {
    private:
        string nombreCurso;
    public:
        void setNombreCurso(string curso) {
            nombreCurso = curso;
        }
        string getNombreCurso () const {
            return nombreCurso;
        }
        void display() const {
            cout << "Nombre de la materia: " << nombreCurso << endl;
        }
    public:
};

int main () {
    Calificaciones record;
    string materia;

    cout << "Proporciona el nombre de la materia" << endl;
    getline(cin, materia);

    record.setNombreCurso(materia);
    record.display();
}