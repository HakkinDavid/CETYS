/*  nombre: Calcular el área de un rectángulo
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 3 de febrero de 2023
*/

#include <iostream>
#include <math.h>

class Rectangle {
    private:
        float sideA = 0, sideB = 0, perimeter = 0, area = 0;
        void updateProps () {
            perimeter = sideA * 2 + sideB * 2;
            area = sideA * sideB;
        }
    public:
        void setSideA (float s) {
            sideA = s;
            updateProps();
        }
        void setSideB (float s) {
            sideB = s;
            updateProps();
        }
        float getSideA () const {
            return sideA;
        }
        float getSideB () const {
            return sideB;
        }
        float getPerimeter () const {
            return perimeter;
        }        
        float getArea () const {
            return area;
        }
        void display () const {
            std::cout << "[Datos del rectángulo]" << std::endl;
            std::cout << "Lado A: " << getSideA() << std::endl;
            std::cout << "Lado B: " << getSideB() << std::endl;
            std::cout << "Perímetro: " << getPerimeter() << std::endl;
            std::cout << "Área: " << getArea() << std::endl;
        }
};

int main () {
    Rectangle rectangle1, rectangle2;
    float ladoA1 = 0.0, ladoB1 = 0.0, ladoA2 = 0.0, ladoB2 = 0.0;
    std::cout << "<RECTÁNGULO UNO>" << std::endl << "Lado A: ";
    std::cin >> ladoA1;
    std::cout << "Lado B: ";
    std::cin >> ladoB1;

    rectangle1.setSideA(ladoA1);
    rectangle1.setSideB(ladoB1);

    std::cout << "\nÁrea: " << rectangle1.getArea() << "\n\n" << std::endl;

    std::cout << "<RECTÁNGULO DOS>" << std::endl << "Lado A: ";
    std::cin >> ladoA2;
    std::cout << "Lado B: ";
    std::cin >> ladoB2;

    rectangle2.setSideA(ladoA2);
    rectangle2.setSideB(ladoB2);

    std::cout << "\n";

    rectangle2.display();
}