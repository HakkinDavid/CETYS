#include <chrono>
#include <iostream>

using namespace std::chrono;
using std::cout;
using std::endl;

int suma (int a, int b) {
    return (a + b);
}

inline int sumaInsertada (int a, int b) {
    return (a + b);
}

int main () {
    auto inicio = high_resolution_clock::now();
    suma(1, 2);
    suma(2, 3);
    suma(3, 4);
    suma(4, 5);
    auto fin = high_resolution_clock::now();

    auto inicioInsertado = high_resolution_clock::now();
    sumaInsertada(1, 2);
    sumaInsertada(2, 3);
    sumaInsertada(3, 4);
    sumaInsertada(4, 5);
    auto finInsertado = high_resolution_clock::now();

    cout << "No inline (ns): " << (duration_cast<nanoseconds>(fin - inicio)).count() << endl;
    cout << "Inline (ns): " << (duration_cast<nanoseconds>(finInsertado - inicioInsertado)).count() << endl;
}