/*
 * ronda.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef RONDA_H_
#define RONDA_H_

#include "jugador.h"

class Ronda{
	private:
		unsigned int cantidadDeJugadores;
		Jugador* primerJugador;
		Jugador* jugadorActual;

	public:
		Ronda();
};



#endif /* RONDA_H_ */
