/* nombre: Matrix (Librería de matrices)
*  fecha: 3 de mayo de 2023
*  versión: 4.0
*/

#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
    protected:
        int m, n;
        vector <vector <float>> X;
        string name;
    public:
        Matrix (int, int, string);        
        Matrix (const Matrix &Y);
        ~Matrix ();

        friend ostream & operator << (ostream &, Matrix &);

        Matrix & clear ();

        vector <float> & operator [] (int);
        Matrix & operator = (initializer_list<float>);
        Matrix & operator = (const Matrix &);
        Matrix & operator = (string);
        Matrix operator * (Matrix &);
        Matrix & operator *= (Matrix &);
        Matrix operator * (float);
        Matrix & operator *= (float);
        Matrix operator / (float);
        Matrix & operator /= (float);
        Matrix operator + (Matrix &);
        Matrix & operator += (Matrix &);
        Matrix operator - (Matrix &);
        Matrix & operator -= (Matrix &);

        Matrix & add (Matrix &);
        Matrix & substract (Matrix &);
        Matrix & multiply (Matrix &);
        Matrix & transpose ();
        friend Matrix T (Matrix &);
        friend float delta (Matrix & Y);

        Matrix & setName(string);
        operator float ();
};

class Identity : public Matrix {
    public:
        Identity (int);
        Identity & resize (int);
};

Matrix T (Matrix &);
float delta (Matrix & Y);
ostream & operator << (ostream &, Matrix &);

#include "matrix.cpp"
#endif