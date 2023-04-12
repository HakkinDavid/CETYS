/*	nombre: Clase "Libro"
	autor: Vanessa Miranda
	fecha: 31 de marzo de 2023
	descripción: Define un libro
*/

#include <string>
#include <iostream>

class Libro {
private:
	std::string codigo;
	std::string tituloLibro;
	std::string proveedor;
	int anioPublicacion;
public:
	Libro(){
		codigo = "";
		tituloLibro = "";
		proveedor = "";
		anioPublicacion = 0;
	}

	Libro(std::string codigo, std::string tituloLibro, std::string proveedor, int añoPublicacion)
		: codigo(codigo), tituloLibro(tituloLibro), proveedor(proveedor), anioPublicacion(anioPublicacion){}

	~Libro(){}

	int getAnioPublicacion() const { return anioPublicacion; }

	void setAnioPublicacion(int añoPublicacion) {
		this->anioPublicacion = añoPublicacion;
	}

	const std::string getCodigo() const { return codigo; }

	void setCodigo(const std::string codigo) {
		this->codigo = codigo;
	}

	const std::string getTituloLibro() const { return tituloLibro; }

	void setTituloLibro(const std::string tituloLibro) {
		this->tituloLibro = tituloLibro;
	}

	const std::string getProveedor() const { return proveedor;	}

	void setProveedor(const std::string proveedor) {
		this->proveedor = proveedor;
	}

	void actualizarDatos(){
		int op;
		std::string titulo;
		std::string proveedor;
		int anio;
		std::cout << "Que datos se desea actualizar " << std::endl;
		std::cout << "1. Titulo" << std::endl;
		std::cout << "2. Proveedor" << std::endl;
		std::cout << "3. Año publicacion" << std::endl;
		do{
			std::cin >> op;
		}while(op < 1 && op > 3);
		switch(op){
		case 1:
			std::cout << "Nuevo Titulo.. " ; getline(std::cin, titulo);
			setTituloLibro(titulo);
			break;
		case 2:
			std::cout << "Nuevo Proveedor.. " ; getline(std::cin, proveedor);
			setProveedor(proveedor);
			break;
		case 3:
			std::cout << "Nuevo Año de publicacion.. "; std::cin >> anio;
			setAnioPublicacion(anio);
			break;
		default:
			std::cout << "Opcion no valida" << std::endl;
			break;
		}
	}

};
