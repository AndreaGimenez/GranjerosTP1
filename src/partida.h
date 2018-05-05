/*
 * partida.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_

#include "jugador.h"
#include "lista.h"
#include "parametroConfiguracion.h"


using namespace std ;

class Partida{
	private:

		Dificultad nivelDeDificultad ;
		unsigned int cantidadDeJugadores;
		Lista<Jugador*>* rondaJugadores;

	public:
		//Constructor
		//Pre:
		//Post:
		Partida(Lista<string>*);

		//Pre:
		//Post:
		Dificultad obtenerDificultad();

		//Pre:
		//Post:
		unsigned int getCantidadDeJugadores();
		
		//Pre:
		//Post: Devuelve un puntero con la referencia al jugador actual de la partida
		Jugador* verJugadorActual();

		//Pre:
		//Post: se avanz� un posicion en la ronda
		void avanzarProximoJugador();

		//Pre:
		//Post:
		~Partida();

	private:
		//Pre:
		//Post:
		void cargarJugadoresEnLaRonda(Lista<string>* nombresJugadores);

};



#endif /* PARTIDA_H_ */
