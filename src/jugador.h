/*
 * jugador.h
 *
 *  Created on: 19 Apr 2018
 *      Author: Andrea
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include<string>
#include "terreno.h"
#include "tanque.h"
#include "lista.h"
#include "almacen.h"

using namespace std ;

class Jugador{

	private:

		string nombre;
		unsigned int monedas;
		unsigned int turnos;
		Lista<Terreno*> terrenos;
		Tanque* tanque;
		Almacen* almacen;

	public:
		//Constructor
	    //Pre: -
		//Post: Inicializa un jugador con su cantidad de monedas, turnos y el nombre pasado por parametro.
		//		Por default la cantidad de terrenos inicial es uno (1).
		Jugador(std::string nombreJugador);

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
		//Post: se utiliza un turno.
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

		Terreno* obtenerTerreno(unsigned int numeroTerreno);

		bool puedeSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo);

		bool sembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo);

		bool puedeCosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool cosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool puedeRegar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool regar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool puedeEnviar(Cultivo* cultivo);

		bool enviar(Cultivo* cultivo);

		bool puedeComprarTerreno();

		bool comprarTerreno();

		bool puedeVenderTerreno(unsigned int numeroTerreno);

		bool venderTerreno(unsigned int numeroTerreno);

		bool puedeComprarCapacidadTanque();

		bool comprarCapacidadTanque();

		bool puedeComprarCapacidadAlmacen();

		bool comprarCapacidadAlmacen();

		~Jugador();


	private:
		//Post: devuelve "true" si el jugador tiene turnos disponibles,"false" caso contrario.
		bool quedanTurnos();
};



#endif /* JUGADOR_H_ */
