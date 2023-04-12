/*  nombre: Suma, producto y promedio de tres números
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 25 de enero de 2023
*/

#include <iostream>
#include <iomanip>

int main () {
    int x = 0, y = 0, z = 0;
    std::cout << "Proporciona tres números" << std::endl;
    std::cin >> x >> y >> z; // leemos los datos
    std::cout << "Suma: " << x+y+z << std::endl; // desplegar suma
    std::cout << "Producto: " << x*y*z << std::endl; // desplegar producto
    std::cout << "Promedio: " << std::setprecision(3) << (float) (x+y+z)/3 << std::endl; // desplegar promedio con 2 decimales
    return 0;
}