#include <iostream>
#include "createDestructor.h" // user defined library header
using namespace std;

void create ();

// object 1 creation
DesAndCons first(1, "global object defined before main()");

int main () {
    cout << "\n**** main() starts ****" << endl;
    DesAndCons second(2, "local object defined inside main()"); // object 2 creation
    create(); // call create()
    cout << "\n*** returns to main() ***" << endl;
    DesAndCons third(3, "local object defined inside main()"); // object 3 creation
    cout << "\n**** main() ends ****" << endl;
    return 0;
}

// create() declaration
void create () {
    cout << "\n**** create() starts ****" << endl;
    DesAndCons fourth(4, "local object defined inside create()"); // object 4 creation
    cout << "\n**** create() ends ****" << endl;
}