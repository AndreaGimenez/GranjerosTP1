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
		unsigned int unidadesRiego;
		Lista<Terreno*> terrenos;
		Tanque* tanque;
		Almacen* almacen;

	public:

		/*
		 * Post: Inicializa un jugador con su cantidad de monedas, turnos y el nombre pasado por parametro.
		 *		 Por default la cantidad de terrenos inicial es uno (1).
		 */
		Jugador(std::string nombreJugador);

		//Post: Devuelve la cantidad de monedas que posee el jugador.
		unsigned int monedasDisponibles();

		//Pre: La cantidad de monedas recibida es mayor a cero.
		//Post: Incrementa la cantidad de monedas del jugador segun el monto de monedasASumar.
		void agregarMonedas(unsigned int monedasASumar);

		//Pre: la cantidad de monedas recibida es mayor a cero.
		//Post: Disminuye la cantidad de monedas del jugador segun el monto de monedasARestar.
		//		Si tuvo exito devuelve "true", sino "false".
		bool gastarMonedas(unsigned int monedasAGastar);

		//Post: Indica si el jugador puede gastar 'cantidadMonedas'.
		bool puedeGastarMonedas(unsigned int cantidadMonedas);

		//Post: devuelve la cantidad de terrenos que posee el jugador.
		unsigned int obtenerCantidadTerrenos();

		//Post: Asigna el nombre del jugador
		void asignarNombre(string nombre) ;

		//Post: Devuelve el nombre del jugador
		string obtenerNombre();

		//Post: Imprime el estado actual del jugador
		void imprimirJugador();

		/*
		 * Pre: 'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Devuelve el terreno asociado a 'numeroTerreno'. Los terrenos se numeran de 1 a 'cantidadDeTerrenos'.
		 * 		 En caso de no encontrarse el terreno indicado devuelve NULL.
		 */
		Terreno* buscarTerreno(unsigned int numeroTerreno);

		/*
		 * Post: Indica si hay espacio suficiente para almacenar 1 unidad de 'cultivo'.
		 */
		bool puedeAlmacenar(Cultivo* cultivo);

		/*
		 * Post: Indica si hay espacio suficiente para almacenar 'cantidadAAlmacenar' unidades de 'cultivo'.
		 */
		bool puedeAlmacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar);

		/*
		 * Pre: 'puedeAlmacenar' debe ser true.
		 * Post: Almacena 1 unidad de cosecha de 'cultivo'.
		 * 		 En caso de no poder almacenarse devuelve false.
		 */
		bool almacenar(Cultivo* cultivo);

		/*
		 * Pre: 'puedeAlmacenar' debe ser true.
		 * Post: Almacena 'cantidadAAlmacenar' unidades de cosecha de 'cultivo'.
		 * 		 En caso de no poder almacenarse devuelve false.
		 */
		bool almacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Indica si se puede realizar la siembra de 'cultivo' en la parcela indicada.
		 * 		 La siembra puede realizarse si:
		 * 		 		-El jugador cuenta con las monedas necesarias para comprar la semilla.
		 * 		 		-El terreno es apto para ser sembrado.
		 */
		bool puedeSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * 		'puedeSembrar' debe ser true.
		 * Post: Siembra la parcela indicada con 'cultivo'.
		 * 		 Consume la cantidad de monedas correspondientes al costo de la semilla del cultivo indicada en 'cultivos.txt'.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool sembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo);

		bool puedeCosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool cosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool puedeRegar(unsigned int numeroTerreno, std::string coordenadasParcela);

		bool regar(unsigned int numeroTerreno, std::string coordenadasParcela);

		//Post: Devuelve la cantidad de unidades de riego que tiene el jugador sin tener en cuenta las unidades del tanque.
		unsigned int obtenerUnidadesRiego();

		//Post: Devuelve la cantidad de unidades de riego que tiene el jugador teniendo en cuenta las unidades del tanque.
		unsigned int obtenerUnidadesRiegoTotales();

		//Post: Indica si el jugador puede consumir 'unidadesRiego'.
		//		Este metodo tiene en cuenta las unidades de riega almacenadas en el tanque.
		bool puedeConsumirUnidadesRiego(unsigned int unidadesRiego);

		bool consumirUnidadesRiego(unsigned int unidadesRiego);

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

		void actualizar();

		void actualizarUnidadesRiego();

		void actualizarTerrenos();

		~Jugador();
};



#endif /* JUGADOR_H_ */
