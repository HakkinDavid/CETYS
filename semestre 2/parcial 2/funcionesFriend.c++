#include <iostream>

class B; // anunciar la existencia de B

class A {
    private:
        int x;
    public:
        A (int i = 0) { x = i; }
        friend void max (A, B);
};

class B {
    private:
        int y;
    public:
        B (int i = 0) { y = i; }
        friend void max (A, B);

};

void max (A a, B b) {
    if (a.x >= b.y) std::cout << a.x << " es mayor" << std::endl;
    else std::cout << b.y << " es mayor" << std::endl;
}

int main () {
    A a (10);
    B b (5);
    max (a, b);
}