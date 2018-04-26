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

	unsigned int getConsumoAgua();

	void setConsumoAgua(unsigned int consumoAgua);

	unsigned int getCosto();

	void setCosto(unsigned int costo);

	std::string getNombre();

	void setNombre(std::string nombre);

	unsigned int getRentabilidad();

	void setRentabilidad(unsigned int rentabilidad);

	unsigned int getTiempoCrecimiento();

	void setTiempoCrecimiento(unsigned int tiempoCrecimiento);

	unsigned int getTiempoRecuperacion();

	void setTiempoRecuperacion(unsigned int tiempoRecuperacion);
};

#endif /* CULTIVO_H_ */
