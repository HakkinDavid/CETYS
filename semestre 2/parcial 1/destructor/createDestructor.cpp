#include <iostream>

// user defined library header
#include "createDestructor.h"

using namespace std;

// constructor declaration
DesAndCons :: DesAndCons (int ID, string menString) {
    this -> idObj = ID;
    this -> message = menString;
    cout << "Constructor del objeto ID: " << idObj << " -- " << message << endl;
}

// destructor declaration
DesAndCons :: ~DesAndCons () {
    cout << (idObj == 1 || idObj == 6 ? "\n" : ""); // ternary conditional
    cout << "Destructor del objeto ID: " << idObj << " -- " << message << endl;
}
