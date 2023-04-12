/*  nombre: Reverso
    autor: David Emmanuel Santana Romero y Sebastian Soto
    versión: 1.0
    fecha: 10 de febrero de 2023
*/

#include <iostream>
using namespace std;

class Number {
    public:
        Number () {
            num = 0, reverso = 0;
            cout << "Vamos a reversar un número reversible" << endl;
        }
        ~Number () {
            num = 0, reverso = 0;
            cout << "Me reversaron mi numerito" << endl;
        }
        void setNum (int x) {
            num = x;
        }
        int getNum () const {
            return num;
        }
        int reversar () {
            int numCopy = num;
            while (numCopy > 0) {
                reverso *= 10;
                reverso += (numCopy % 10);
                numCopy /= 10;
            }
            return reverso;
        }
    private:
        int num, reverso;
};

int main () {
    Number n;
    int numerito = 0;
    cout << "Proporciona un número" << endl;
    cin >> numerito;
    n.setNum(numerito);
    cout << "El reverso es " << n.reversar() << endl;
}