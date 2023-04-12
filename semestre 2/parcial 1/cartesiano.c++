/*  nombre: Definir puntos cartesianos
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 5 de febrero de 2023
*/

#include <iostream>

class CartesianPoint {
    private:
        int x = 0, y = 0;
    public:
        void setX (int data) {
            x = data;
        }
        void setY (int data) {
            y = data;
        }
        int getX () const {
            return x;
        }
        int getY () const {
            return y;
        }
        void moveXY (int h, int k) {
            // sumar los valores de movimiento a la coordenada actual
            std::cout << "[X] " << x << " hacia " << x+h << std::endl;
            std::cout << "[Y] " << y << " hacia " << y+k << std::endl;
            x += h;
            y += k;
        }
        bool isAtOrigin () const {
            if (x == 0 && y == 0) return true;
            return false;
        }
        void getXY () const {
            std::cout << "[Posición] X: " << x << " Y: " << y << std::endl;
        }
};

int main () {
    CartesianPoint p;
    CartesianPoint pointsArray[5];
    std::cout << "<PUNTO INDIVIDUAL>" << std::endl;
    p.setX(1);
    p.setY(5);
    p.getXY();

    p.moveXY(-4, 2);

    std::cout << "\n<<<ARREGLO DE PUNTOS>>>" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "{PUNTO " << i+1 << "}" << std::endl;
        pointsArray[i].setX(rand() % 20);
        pointsArray[i].setY(rand() % 20);

        pointsArray[i].getXY();

        // decidir si se avanza o retrocede
        int signX = 0, signY = 0;

        rand() % 1 ? signX++ : signX--;
        rand() % 1 ? signY++ : signY--;

        pointsArray[i].moveXY(signX*(rand() % 20), signY*(rand() % 20));

        pointsArray[i].getXY();

        std::cout << "¿Está en el origen? " << (pointsArray[i].isAtOrigin() ? "Sí" : "No") << "\n\n";
    }
}