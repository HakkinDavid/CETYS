#include <iostream>
using namespace std;

class invent1;
class invent2;

class invent2 {
    int code;
    float value;
public:
    invent2 (int x = 0, float y = 0) : code (x), value (y) {}

    void setCode (int code) { this -> code = code; }
    void setValue (float value) { this -> value = value; }

    void putData () {
        cout << "codigo " << code << endl;
        cout << "valor " << value << endl;
    }

    // conversion a tipo invent2
};

class invent1 {
    int code;
    int items;
    float price;
public:
    invent1 (int a, int b, int c) : code (a), items (b), price (c) {}

    void putData () {
        cout << "codigo " << code << endl;
        cout << "producto " << items << endl;
        cout << "valor " << price << endl;
    }

    int getCode () const { return code; }
    int getItems () const { return items; }
    float getPrice () const { return price; }

    // conversion a tipo float
    operator float () {
        return (items*price);
    }

    // conversion a invent2 usando funcion casting operator
    operator invent2 () {
        invent2 temp;
        temp.setCode(code);
        temp.setValue(price*items);
        return temp;
    }
};

int main () {
    invent1 s1 (100, 5, 140.5);
    invent2 d1;
    float valorTotal;

    // invent1 to float
    valorTotal = s1;

    // invent1 to invent2
    d1 = s1;

    cout << "detalles del producto - tipo invent1" << endl;
    s1.putData();

    cout << "Valor de stock " << endl;
    cout << "Valor " << valorTotal << endl;

    cout << "detalles del producto - tipo invent2" << endl;
    d1.putData();

    return 0;
}