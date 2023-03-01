/*  nombre: Incrementar el sueldo de dos empleados
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 22 de febrero de 2023
*/

#include <iostream>
#include "empleado.h" // user defined library header
using namespace std;

int main () {
    Empleado david ("David Emmanuel Santana Romero", 100.00, 0), braulio ("Braulio 👍", 32982.99, 1);

    cout << "Salario anual de " << david.getName() << ": $" << david.getAnnualSalary() << endl;
    cout << "Salario anual de " << braulio.getName() << ": $" << braulio.getAnnualSalary() << endl;

    david.incrementSalary(10.0);
    braulio.incrementSalary(10.0);

    cout << "\nA ambos empleados se les otorgará un incremento proporcional al 10% de su salario\n" << endl;

    cout << "Salario anual [+10%] de " << david.getName() << ": $" << david.getAnnualSalary() << endl;
    cout << "Salario anual [+10%] de " << braulio.getName() << ": $" << braulio.getAnnualSalary() << endl;
}