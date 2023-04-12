/*	nombre: Empleado (derivado de Usuario)
	autor: David Emmanuel Santana Romero
	fecha: 31 de marzo de 2023
	descripción: Define un empleado
*/

Empleado :: Empleado () {
    setID (++objectCount);
}
Empleado :: ~Empleado () {
    requested = {};
}

void Empleado :: requestBooks (int userID, int proveedorID, int bookID) {
    for (auto &i : requested) {
        if (i.first == userID) {
            i.second.emplace_back(pair <int, int> {
                proveedorID, bookID
            });
            cout << "Se ha llenado la solicitud del libro con ID " << bookID << " para el proveedor con ID " << proveedorID;
            return;
        }
    }
    // if did not find an existent request ticket
    requested.emplace_back(
        pair <int, vector <pair <int, int>>> {userID, {
            { proveedorID, bookID }
        }}
    );
    cout << "Se ha llenado la solicitud del libro con ID " << bookID << " para el proveedor con ID " << proveedorID;
}
void Empleado :: serveUser (Cliente &c, vector <Proveedor> &p) {
    for (auto &i : requested) {
        if (i.first == c.getID()) {
            for (auto &j : i.second) {
                c.obtainBook(p[j.first - 1].sell(j.second - 1));
            }
            cout << "Se ha surtido al usuario con ID " << c.getID();
            return;
        }
    }
    cout << "El usuario con ID " << c.getID() << " no tiene solicitudes de libro pendientes";
}

template <typename tipoUsuario>
void Empleado :: createUser (vector <tipoUsuario> &usuarios) {
    string n = "";
    getline(cin, n);
    &usuarios.emplace_back(n);
}
void Empleado :: removeUser (Usuario &u) {
    cout << "Se ha eliminado al usuario con ID " << u.getID();
    u.~Usuario();
}