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
	std::string nombreCultivo;

public:

	Destino(std::string nombre, unsigned int distacia, std::string nombreCultivo);

	unsigned int getDistancia();

	void setDistancia(unsigned int distancia);

	std::string getNombre();

	void setNombre(std::string nombre);

	std::string getNombreCultivo();

	void setNombreCultivo(std::string nombreCultivo);
};

#endif /* DESTINO_H_ */
