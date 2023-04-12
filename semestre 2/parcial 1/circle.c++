/*  nombre: Calcular el área de un círculo
    autor: David Emmanuel Santana Romero
    versión: 2.0
    fecha: 3 de febrero de 2023
*/

#include <iostream>
#include <math.h>

#define PI 3.141592

class Circle {
    private:
        float radius = 0, diameter = 0, circumference = 0, area = 0;
        void updateProps (int mode) {
            switch (mode)
            {
            case 1:
                radius = diameter/2;
                break;
            case 2:
                radius = circumference / PI / 2;
                break;
            case 3:
                radius = sqrt(abs(area / PI));
                break;
            default:
                break;
            }
            diameter = radius * 2;
            circumference = PI * diameter;
            area = radius * radius * PI;
        }
    public:
        void setRadius (float r) {
            radius = r;
            updateProps(0);
        }
        void setDiameter (float d) {
            diameter = d;
            updateProps(1);
        }
        void setCircumference (float c) {
            circumference = c;
            updateProps(2);
        }
        void setArea (float a) {
            area = a;
            updateProps(3);
        }
        float getRadius () const {
            return radius;
        }
        float getDiameter () const {
            return diameter;
        }
        float getCircumference () const {
            return circumference;
        }        
        float getArea () const {
            return area;
        }
        void display () const {
            std::cout << "[Datos del círculo]" << std::endl;
            std::cout << "Radio: " << getRadius() << std::endl;
            std::cout << "Diámetro: " << getDiameter() << std::endl;
            std::cout << "Circunferencia: " << getCircumference() << std::endl;
            std::cout << "Área: " << getArea() << std::endl;
        }
};

int main () {
    Circle circle;
    char k = 0; // variable para el menú
    do {
        float data = 1; // variable para el dato ingresado
        // menú
        std::cout << "Definir mediante\n[r] Radio\n[d] Diámetro\n[c] Circunferencia\n[a] Área\n[s] Solo desplegar datos\n[q] Salir" << std::endl;
        std::cin >> k;
        switch (k)
        {
        case 'r':
            std::cout << "Proporciona un radio: ";
            std::cin >> data;
            circle.setRadius(data);
            break;
        case 'd':
            std::cout << "Proporciona un diámetro: ";
            std::cin >> data;
            circle.setDiameter(data);
        break;
        case 'c':
            std::cout << "Proporciona una circunferencia: ";
            std::cin >> data;
            circle.setCircumference(data);
        break;
        case 'a':
            std::cout << "Proporciona un área: ";
            std::cin >> data;
            circle.setArea(data);
        break;
        case 's':
            circle.display();
            std::cout << "\n\n\n\n";
            continue;
        break;
        default:
            continue;
        break;
        }

        std::cout << "\n\nDatos actuales" << std::endl;
        std::cout << "Radio: " << circle.getRadius() << std::endl;
        std::cout << "Diámetro: " << circle.getDiameter() << std::endl;
        std::cout << "Circunferencia: " << circle.getCircumference() << std::endl;
        std::cout << "Área: " << circle.getArea() << std::endl;

        std::cout << "\n\n\n\n";
    } while (k != 'q'); // mientras el usuario no presione la tecla q, continuar el programa
}