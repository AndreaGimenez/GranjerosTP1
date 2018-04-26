/*
 * nodo.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef NODOJUGADOR_H_
#define NODOJUGADOR_H_

#include "jugador.h"

class Nodo{
	public:
		Jugador* dato ;		//puse dato como un puntero a jugador porque en este caso lo vamos a usar para eso
		Nodo* siguiente ;   //lo mas generico seria usar un void* pero no queria complicar mucho el codigo.
							// Despues si quieren lo podemos hacer con void*

	private:
		//Pre: -
		//Post:El nodo fue creado, su referencia a "siguiente" es NULL
		Nodo(Jugador* dato);

		//Pre:-
		Jugador* obtenerDato();

		//Pre: -
		//Post:Devuelve una referencia al siguiente nodo. Si es el ultimo devuelve NULL.
		Nodo* obtenerSiguiente();

		//Pre:-
		//Post: Se cambio la referencia al siguiente nodo por "nuevoSiguiente"
		void cambiarSiguiente(Nodo* nuevoNodo);

		~Nodo();
};



#endif /* NODOJUGADOR_H_ */
