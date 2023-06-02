/* nombre: Matrix (Librería de matrices)
*  fecha: 3 de mayo de 2023
*  versión: 4.0
*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "matrix.h"

Matrix::Matrix (int x, int y, string name = "") {
    m = x;
    n = y;
    this -> name = name;

    clear();
}
        
Matrix::Matrix (const Matrix &Y) {
    m = Y.m;
    n = Y.n;
    name = "";

    X = Y.X;
}

Matrix::~Matrix () {
    m = 0;
    n = 0;

    X.clear();
}

Matrix & Matrix::clear () {
    X.clear();
    X.resize(m);
    for (int i = 0; i < m; i++) {
        X.at(i).resize(n, 0);
    }
    return *this;
}

vector <float> & Matrix::operator [] (int index) {
    return X.at(index);
}

Matrix & Matrix::operator = (initializer_list<float> list) {
    if (list.size() != m*n) {
        throw invalid_argument("Initializer list has a different number of elements than matrix");
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            X.at(i).at(j) = *(list.begin() + i*n + j);
        }
    }

    return *this;
}

Matrix & Matrix::operator = (const Matrix &Y) {
    m = Y.m;
    n = Y.n;
    if (name.empty()) name = Y.name;

    X = Y.X;

    return *this;
}

Matrix & Matrix::operator = (string c) {
    name = c;
    return *this;
}

Matrix Matrix::operator * (Matrix & Y) {
    if (n != Y.m) {
        cout << "ERROR! Attempted to multiply matrices with dimensions " << m << " x <" << n << "> and <" << Y.m << "> x " << Y.n << endl;
        throw invalid_argument ("Number of columns in left operand must be the same as the number of rows in right operand");
    }
    Matrix Z (m, Y.n);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < Y.n; k++) {
            for (int j = 0; j < n; j++) {
                Z[i][k] += X[i][j] * Y[j][k];
            }                    
        }
    }
    return Z;
}

Matrix & Matrix::operator *= (Matrix & Y) {
    *this = Matrix::operator*(Y);
    return *this;
}

Matrix Matrix::operator * (float escalar) {
    Matrix Z (m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Z[i][j] = X[i][j] * escalar;
        }
    }
    return Z;
}

Matrix & Matrix::operator *= (float escalar) {
    *this = Matrix::operator*(escalar);
    return *this;
}

Matrix Matrix::operator / (float escalar) {
    Matrix Z (m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Z[i][j] = X[i][j] / escalar;
        }
    }
    return Z;
}

Matrix & Matrix::operator /= (float escalar) {
    *this = Matrix::operator/(escalar);
    return *this;
}

Matrix Matrix::operator + (Matrix & Y) {
    if (m != Y.m || n != Y.n) {
        cout << "ERROR! Attempted to add matrices with dimensions " << m << " x <" << n << "> and <" << Y.m << "> x " << Y.n << endl;
        throw invalid_argument ("Matrices are different dimensions, thus cannot add them");
    }
    Matrix Z (m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
    return Z;
}

Matrix & Matrix::operator += (Matrix & Y) {
    *this = Matrix::operator+(Y);
    return *this;
}

Matrix Matrix::operator - (Matrix & Y) {
    if (m != Y.m || n != Y.n) {
        cout << "ERROR! Attempted to substract matrices with dimensions " << m << " x <" << n << "> and <" << Y.m << "> x " << Y.n << endl;
        throw invalid_argument ("Matrices are different dimensions, thus cannot substract them");
    }
    Matrix Z (m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Z[i][j] = X[i][j] - Y[i][j];
        }
    }
    return Z;
}

Matrix & Matrix::operator -= (Matrix & Y) {
    *this = Matrix::operator-(Y);
    return *this;
}

Matrix & Matrix::add (Matrix & Y) {
    operator+=(Y);
    if (!name.empty()) name = "(" + name + "+" + Y.name + ")";
    return *this;
}
Matrix & Matrix::substract (Matrix & Y) {
    operator-=(Y);
    if (!name.empty()) name = "(" + name + "-" + Y.name + ")";
    return *this;
}
Matrix & Matrix::multiply (Matrix & Y) {
    operator*=(Y);
    if (!name.empty()) name = "(" + name + "*" + Y.name + ")";
    return *this;
}

Matrix & Matrix::transpose () {
    *this = T(*this);
    if (!name.empty()) name = "(" + name + "^T)";
    return *this;
}

Matrix T (Matrix & Y) {
    Matrix Z(Y.n, Y.m);
    if (!Y.name.empty()) Z.name = "(" + Y.name + "^T)";
    for (int j = 0; j < Y.n; j++) {
        for (int i = 0; i < Y.m; i++) {
            Z[j][i] = Y[i][j];
        }
    }
    return Z;
}

Matrix & Matrix::setName (string name = "") {
    this -> name = name;
    return *this;
}

Matrix::operator float () {
    return delta(*this);
}

float delta (Matrix & Y) {
    if (Y.m != Y.n) {
        throw invalid_argument("Matrix is not square, cannot get the determinant.");
    }
    float LRDiagonals, RLDiagonals;
    for (int d = 0; d < Y.n; d++) {
        float minidiagonal = 1;
        for (int i = 0, j = d; i < Y.m; i++, j++) {
            if (j == Y.n) j = 0;
            minidiagonal *= Y.X.at(i).at(j);
        }
        LRDiagonals += minidiagonal;
    }
    for (int d = (Y.n-1); d >= 0; d--) {
        float minidiagonal = 1;
        for (int i = 0, j = d; i < Y.m; i++, j--) {
            if (j == -1) j = (Y.n-1);
            minidiagonal *= Y.X.at(i).at(j);
        }
        RLDiagonals += minidiagonal;
    }
    return (LRDiagonals-RLDiagonals);
}

Identity::Identity (int m) : Matrix (m, m, "I[" + to_string(m) + "]") {
    for (int i = 0; i < m; i++) {
        X.at(i).at(i) = 1;
    }
}

Identity & Identity::resize (int s) {
    m = s; n = s;
    name = "I[" + to_string(m) + "]";
    clear();
    for (int i = 0; i < m; i++) {
        X.at(i).at(i) = 1;
    }
    return *this;
}

ostream & operator << (ostream & o, Matrix & M) {
    for (int i = 0; i < M.m; i++) {
        if (!M.name.empty()) {
            if (i == (M.m/2)) {
                o << M.name << " = ";
            }
            else {
                for (int spaces = 0; spaces < M.name.size(); spaces++) {
                    o << " ";
                }
                    o << "   ";
            }
        }
        o << "| ";
        for (int j = 0; j < M.n; j++) {
            o << M[i][j] << (j+1 < M.n ? "  " : " ");
        }
        o << "|" << endl;
    }
    return o;
}