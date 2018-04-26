/*
 * partida.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_

#include "jugador.h"
#include "ronda.h"

class Partida{
	private:

		unsigned int nivelDeDificultad ;
		unsigned int cantidadDeJugadores;
		Jugador* primerJugador ;
		Jugador* jugadorActual ;
		Ronda* ronda ;

	public:
		//Constructor
		//Pre:
		//Post:
		Partida(unsigned int dificultad, unsigned int jugadores);

		//Pre:
		//Post:
		unsigned int obtenerDificultad();

		//Pre:
		//Post:
		unsigned int getCantidadDeJugadores();

		//Pre:
		//Post:
		void cargarJugadoresEnLaRonda();
		//Pre:
		//Post: Devuelve un puntero con la referencia al jugador actual de la partida
		Jugador* verJugadorActual();

		//Pre:
		//Post: se avanz� un posicion en la ronda
		void avanzarProximoJugador();

		//Pre:
		//Post:
		~Partida();

};



#endif /* PARTIDA_H_ */
