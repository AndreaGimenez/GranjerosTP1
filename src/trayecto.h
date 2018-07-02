/*
 * Trayecto.h
 *
 *  Created on: 1 jul. 2018
 *      Author: administrador
 */

#ifndef TRAYECTO_H_
#define TRAYECTO_H_

#include "lugar.h"

class Trayecto {

private:

	Lugar* origen;
	Lugar* destino;
	unsigned int costo;
	unsigned int distancia;

public:

	Trayecto(Lugar* origen, Lugar* destino, unsigned int costo, unsigned int distancia);

	Lugar* obtenerOrigen();
	Lugar* obtenerDestino();
	unsigned int obtenerCosto();
};

#endif /* TRAYECTO_H_ */
