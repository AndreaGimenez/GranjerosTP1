/*
 * Lugar.h
 *
 *  Created on: 1 jul. 2018
 *      Author: administrador
 */

#ifndef LUGAR_H_
#define LUGAR_H_

#include <string>

class Lugar {

private:
	std::string nombre;

public:
	Lugar(std::string nombre);
	std::string obtenerNombre();
};

#endif /* LUGAR_H_ */
