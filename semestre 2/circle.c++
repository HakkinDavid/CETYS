#include <iostream>

#define PI 3.141592

int main () {
    int radius = 0;
    std::cout << "Proporcionar radio" << std::endl;
    std::cin >> radius;
    std::cout << "Diámetro: " << radius*2 << "\nCircunferencia: " << radius*2*PI << "\nÁrea: " << radius*radius*PI << std::endl;
    return 0;
}