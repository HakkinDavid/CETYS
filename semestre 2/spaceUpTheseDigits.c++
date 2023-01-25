#include <iostream>

int main () {
    int num = 0, mun = 0;
    std::cout << "Indica un numerito" << std::endl;
    std::cin >> num;
    while (num > 0) {
        mun *= 10;
        mun += (num%10);
        num /= 10;
    }
    while (mun > 0) {
        std::cout << mun%10 << "   ";
        mun /= 10;
    }
    return 0;
}