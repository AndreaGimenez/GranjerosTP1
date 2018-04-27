/*
 * Cultivo.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef CULTIVO_H_
#define CULTIVO_H_

#include <string>

class Cultivo {

private:

	std::string nombre;
	unsigned int costo;
	unsigned int tiempoCrecimiento;
	unsigned int rentabilidad;
	unsigned int tiempoRecuperacion;
	unsigned int consumoAgua;

public:

	Cultivo(std::string nombre, unsigned int costo, unsigned int tiempoCrecimiento, unsigned int rentabilidad,
			unsigned int tiempoRecuperacion, unsigned int consumoAgua);

	unsigned int obtenerConsumoAgua();

	unsigned int obtenerCosto();

	std::string obtenerNombre();

	unsigned int obtenerRentabilidad();

	unsigned int obtenerTiempoCrecimiento();

	unsigned int obtenerTiempoRecuperacion();
};

#endif /* CULTIVO_H_ */
