#include <iostream>
#include <iomanip>

int main () {
    int x = 0, y = 0, z = 0;
    std::cout << "Proporciona tres números" << std::endl;
    std::cin >> x >> y >> z;
    std::cout << "Suma: " << x+y+z << "\nProducto: " << x*y*z << "\nPromedio: " << std::setprecision(3) << (float) (x+y+z)/3 << std::endl;
    return 0;
}