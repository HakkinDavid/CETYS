#include <iostream>

int main () {
    char c = 0;
    std::cout << "Proporciona un carácter" << std::endl;
    std::cin >> c;
    std::cout << "Es " << (int) c;
    return 0;
}