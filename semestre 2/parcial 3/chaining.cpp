#include <iostream>

class Cadena {
    int eslabones;
    public:
        Cadena & addEslabones (int x) {
            eslabones += x;
            return *this;
        }
        Cadena & display () {
            for (int i = 0; i < eslabones; i++) {
                std::cout << "🔗";
            }
            std::cout << std::endl;
            return *this;
        }
};

int main () {
    Cadena c;
    c.addEslabones(1).display().addEslabones(99).addEslabones(-1).display();
}