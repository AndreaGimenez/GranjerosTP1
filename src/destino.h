/*
 * Destino.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef DESTINO_H_
#define DESTINO_H_

#include <string>

class Destino {

private:

	std::string nombre;
	unsigned int distancia;
	unsigned int precio;
	std::string nombreCultivo;

public:

	Destino(std::string nombre, unsigned int distacia, unsigned int precio, std::string nombreCultivo);

	unsigned int obtenerDistancia();

	std::string obtenerNombre();

	unsigned int obtenerPrecio();

	std::string obtenerNombreCultivo();
};

#endif /* DESTINO_H_ */
