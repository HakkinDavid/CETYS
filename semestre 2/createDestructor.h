#include <string>
using namespace std;

// include guards
#ifndef CREATE_H
#define CREATE_H

// define class

class DesAndCons {
    public:
        // prototipos de funciones miembro
        DesAndCons(int, string); // constructor
        ~DesAndCons(); // destructor
    private:
        int idObj;
        string message;
}; // end class

// include guards
#include "createDestructor.cpp"
#endif