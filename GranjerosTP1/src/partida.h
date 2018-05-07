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

		Dificultad nivelDeDificultad;
		unsigned int cantidadTurnos;
		unsigned int cantidadTurnosJugados;
		Lista<Jugador*>* jugadores;

		void cargarJugadores(Lista<string>* nombresJugadores);

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
		//Post: se avanza un posicion en la ronda. Devuelve false si el jugador actual es el ultimo jugador.
		bool avanzarProximoJugador();

		//Pre:
		//Post: Posiciona el jugador actual en el primer jugador.
		void irAPrimerJugador();

		//Pre:
		//Post:
		bool ejecutarAccionComprarCapacidadAgua();

		bool ejecutarAccionComprarCapacidadAlmacen();

		bool ejecutarAccionComprarTerreno();

		bool ejecutarAccionCosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool ejecutarAccionEnviarCosecha(std::string nombreCultivo);

		bool ejecutarAccionRegar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool ejecutarAccionSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, std::string nombreCultivo);

		bool ejecutarAccionVenderTerreno(unsigned int numeroTerreno);

		bool avanzarTurno();

		//Pre:
		//Post:
		~Partida();
};



#endif /* PARTIDA_H_ */
