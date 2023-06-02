#include <string>
#include <iostream>
using namespace std;

// se define la clase Libro
class Libro {
    private:
        // codigo y precio
        int code; float price;
    public:
        Libro () {}
        // establecer el valor del codigo y del precio
        void getData (int code, int price) {
            this -> code = code;
            this -> price = price;
        }
        // mostrar los valores de codigo y precio
        void show () {
            cout << "Code " << code << endl;
            cout << "Price " << price << endl;
        }
};
// tamaño del arreglo de libros
const int size = 2;
int main () {
    // declarar un puntero con nombre p hacia un arreglo en memoria heap de tipo Libro
    Libro *p = new Libro [2];
    // copiamos el puntero
    Libro *d = p;
    int x, i; float y;
    // establecemos los valores de cada libro
    for (i = 0; i < 2; i++) {
        cout << "codigo y precio " << i + 1 << endl;
        cin >> x >> y;
        p -> getData (x, y);
        p++;
    }
    // desplegamos los datos de los libros
    for (i = 0; i < 2; i++) {
        cout << "libro " << i + 1 << endl;
        d -> show ();
        d++;
    }
}