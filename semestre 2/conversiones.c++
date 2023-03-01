/*  nombre: Convertir decimal desde o hacia binario
    autor: David Emmanuel Santana Romero y Sebastian Soto
    versión: 1.0
    fecha: 15 de febrero de 2022
*/

#include <iostream>
#include <math.h>
using namespace std;

class Number {
    public:
        Number () {
            cout << "Empezaremos a convertir números convertibles" << endl;
            decimal = 0;
            binario = 0;
        }
        ~Number () {
            cout << "Me convirtieron en algo que yo no era. Yo no pedí ser esta cosa." << endl;
        }
        void setDecimal (int x) {
            decimal = x;
            binario = 0;
        }
        void setBinary (int x) {
            binario = x;
            decimal = 0;
        }
        int getDecimal () const {
            return decimal;
        }
        int getBinary () const {
            return binario;
        }
        void convert (int base) {
            int copia;
            switch (base) {
                case 2:
                    copia = decimal;
                    for (int exp = 0; copia > 0; exp++) {
                        binario += (pow(10, exp) * (copia%2));
                        copia /= 2;
                    }
                break;
                case 10:
                    copia = binario;
                    for (int exp = 0; copia > 0; exp++) {
                        decimal += (copia%2 ? pow(2, exp) : 0);
                        copia /= 10;
                    }
                break;
                default:
                    cout << "Proporciona una base" << endl;
                    return;
                break;
            }
        }
    private:
        int decimal, binario;
};

int main () {
    Number n;
    char keypress = 0;
    int num = 0;
    cout << "Convertir a\n[d] Decimal\n[b] Binario" << endl;
    cin >> keypress;
    cout << "Proporciona el número:" << endl;
    cin >> num;
    switch (keypress) {
        case 'd':
            n.setBinary(num);
            n.convert(10);
        break;
        case 'b':
            n.setDecimal(num);
            n.convert(2);
        break;
        default:
        break;
    }
    cout << "\n\nRESULTADO\n[Decimal]\t[Binario]\n" << n.getDecimal() << "\t  =\t" << n.getBinary() << endl;
}