/*  nombre: Potencia dada hasta cierto número
    autor: David Emmanuel Santana Romero y Sebastian Soto
    versión: 1.0
    fecha: 10 de febrero de 2023
*/

#include <iostream>
#include <math.h>
using namespace std;

class Potencia {
    public:
        Potencia () {
            baseMax = 0;
            exp = 0;
            cout << "Vamos a calcular una calculación" << endl;
        }
        ~Potencia () {
            baseMax = 0;
            exp = 0;
            cout << "Me han encontrado un cálculo y no precisamente matemático. *muere*" << endl;
        }
        void setBaseMax (int x) {
            baseMax = x;
        }
        int getBaseMax () const {
            return baseMax;
        }
        void setExp (int x) {
            if (x < 0) {
                cout << "Solo exponentes positivos." << endl;
                return;
            }
            exp = x;
        }
        int getExp () const {
            return exp;
        }
        void calcular () const {
            for (int i = 1; i <= baseMax; i++) {
                cout << i << " elevado a la " << exp << " es " << pow(i, exp) << endl;
            }
        }
    private:
        int baseMax, exp;
};

int main () {
    Potencia p;
    int baseMax = 0, exp = 0;
    cout << "Base máxima: " << endl;
    cin >> baseMax;
    p.setBaseMax(baseMax);
    cout << "Potencia: " << endl;
    cin >> exp;
    p.setExp(exp);

    p.calcular();
}