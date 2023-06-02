/* nombre: Matrix (Librería de matrices) [Ejemplo de uso]
*  fecha: 3 de mayo de 2023
*  versión: 4.0
*/

#include "matrix.h"
#include <iostream>
using namespace std;

int main () {
    Matrix A (3, 3, "A"), B (3, 3, "B"), V (3, 1, "V"), W (1, 3, "W");
    A[0] = {1, 2, 3};
    A[1] = {4, 5, 6};
    A[2] = {7, 8, 9};
    cout << A;

    cout << "DETERMINANTE DE A: " << delta(A);

    Matrix AL = A;
    AL = "A";

    cout << endl;

    B = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };
    cout << B;


    cout << endl;

    Identity I(8);
    I.resize(10);

    cout << I;

    cout << endl;

    V = {
        1,
        2,
        3
    };

    cout << V;

    cout << endl;

    W = {
        2,
        4,
        6
    };

    cout << W;

    cout << endl;

    Matrix C = B-A;
    C = "C";

    C += A;
    
    cout << C;

    cout << endl;
    
    C = W*V;
    C = C*C*C*C*C;
    cout << C;
    cout << endl;

    A /= 2;
    cout << A;

    A *= 4;
    cout << A;

    AL.add(B).substract(A).multiply(V);

    cout << AL;

    A.transpose();
    cout << A;

    A.transpose();
    cout << A;

    Identity I3(3);

    A.clear().add(I3);
    A.setName();
    cout << A << endl;

    I.add(I);
    cout << I;
}