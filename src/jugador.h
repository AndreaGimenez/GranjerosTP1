/*
 * jugador.h
 *
 *  Created on: 19 Apr 2018
 *      Author: Andrea
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include<string>

using namespace std ;

class Jugador{

	private:
		unsigned int monedas;
		unsigned int turnos;
		unsigned int terrenos;
		string nombre ;

	public:
		//Constructor
	    //Pre: -
		//Post: Inicializa un jugador con su cantidad de monedas y turnos. 
		//		Por default la cantidad de terrenos inicial es uno (1).
		//		La referencia al siguiente jugador es NULL.
		Jugador ();

		//Post: devuelve la cantidad de monedas que posee el jugador.
		unsigned int monedasDisponibles();

		//Pre: la cantidad de monedas recibida es mayor a cero.
		//Post: incrementa la cantidad de monedas del jugador segun el monto de monedasASumar.
		void agregarMonedas(unsigned int monedasASumar);

		//Pre: la cantidad de monedas recibida es mayor a cero.
		//Post: disminuye la cantidad de monedas del jugador segun el monto de monedasARestar.
		//		Si tuvo exito devuelve "true", sino "false".
		bool gastarMonedas(unsigned int monedasAGastar);

		//Post: devuelve la cantidad de turnos que le quedan al jugador
		unsigned int turnosRestantes();

		//Pre: quedan turnos disponibles
		//Post: se utilizó un turno.
		void pasarProximoTurno();

		//Post: devuelve la cantidad de terrenos que posee el jugador.
		unsigned int cantidadDeTerrenos();

		//Pre:
		//Post: Asigna el nombre del jugador
		void asignarNombre(string nombre) ;

		//Pre:
		//Post: Devuelve el nombre del jugador
		string obtenerNombre();

		//Post: imprime el estado actual del jugador
		void imprimirJugador();

	private:
		//Post: devuelve "true" si el jugador tiene turnos disponibles,"false" caso contrario.
		bool quedanTurnos();
};



#endif /* JUGADOR_H_ */
