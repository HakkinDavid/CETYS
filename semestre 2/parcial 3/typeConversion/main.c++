#include <iostream>
using namespace std;

class A {
    int value;
    public:
    A (int x) {
        value = x;
    }
    operator int () {
        return value;
    }
    A& operator = (int v) {
        value = v;
        return *this;
    }
};

class B {
    float fval;
    public:
    B (float x) {
        fval = x;
    }
    operator float () {
        return fval;
    }
    operator A () {
        return A(fval);
    }
    B& operator = (float v) {
        fval = v;
        return *this;
    }
};

int main () {
    A o(23);
    int e;
    B p(0);

    e = o;
    p = 0.9993;


    cout << e << endl;
    cout << o << endl;
    cout << p << endl;
}