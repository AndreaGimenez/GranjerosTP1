/*
 * Configuracion.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include "cultivo.h"
#include "destino.h"
#include "lista.h"
#include "parametroConfiguracion.h"


/*
 * Clase que representa las configuraciones del juego.
 * Contiene los valores iniciales, dificultades, realiza todos los calculos que dependan de la dificultad del juego, contiene los recursos disponibles, constantes, etc.
 * La configuracion es comun a tode el juego por ende no debe instanciarse en cada lugar, debe inicializarse una unica vez y luego utilizarse de manera estatica.
 *
 * Los archivos de configuracion deben estar en resources/
 */
class Configuracion {

private:

	static Dificultad dificultad;
	static unsigned int cantidadTerrenosIniciales;
	static unsigned int cantidadJugadores;
	static unsigned int parametroN;
	static unsigned int parametroM;
	static unsigned int cantidadTurnos;
	static Lista<Cultivo*>* cultivos;
	static Lista<Destino*>* destinos;

	//Para evitar que sea instanciada el constructor es private, debe usarse de manera estatica.
	Configuracion();

	//Pre: En el archivo 'cultivos.txt' no puede haber mas de 1 linea con el mismo cultivo.
	//Pos: Carga los cultivos con la informacion del archivo 'cultivos.txt'.
	static void cargarCultivos();

	//Pre: En el archivo 'destinos.txt' no puede haber mas de 1 destino para cada cultivo.
	//Pos: Carga los destinos con la informacion del archivo 'destinos.txt'.
	static void cargarDestinos();

	//Pos: Devuelve el coeficiente que se utilizara para calcular:
	//			- Creditos iniciales
	//			- Capacidad inicial del tanque
	//			- Capacidad inicial del almacen
	static unsigned int obtenerCoeficienteDificultad();

	//Pos: Libera memoria pedida para los cultivos
	static void destruirCultivos();

	//Pos: Libera memoria pedida para los destinos
	static void destruirDestinos();


public:

	//Pos: Inicializa la configuracion de acuerdo a los parametros del juego y archivos de configuracion.
	static void inicializar(ParametroConfiguracion* parametros);

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la dificultad configurada.
	static Dificultad obtenerDificultad();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la cantidad de terrenos iniciales para un jugador.
	static unsigned int obtenerCantidadTerrenosIniciales();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la cantidad de jugadores de la partida
	static unsigned int obtenerCantidadJugadores();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve el largo del terreno, la dimension representada por las filas.
	static unsigned int obtenerLargoTerreno();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve el ancho del terreno, la dimension representada por las columnas.
	static unsigned int obtenerAnchoTerreno();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la cantidad de creditos iniciales de la partida.
	static unsigned int obtenerCreditosIniciales();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la capacidad inicial del tanque.
	static unsigned int obtenerCapacidadInicialTanque();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la cantidad de turnos.
	static unsigned int obtenerCantidadTurnos();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve la capacidad inicial del almacen.
	static unsigned int obtenerCapacidadInicialAlmacen();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//	   'numeroTerrenoAComprar' debe ser la cantidad de terrenos del jugador + 1.
	//Pos: Devuelve el costo de comprar el terreno.
	static unsigned int obtenerCostoTerreno(unsigned int numeroTerrenoAComprar);

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve los cultivos disponibles para que utilicen los jugadores.
	//	   Los mismos dependerán de la configuración del archivo 'cultivos.txt'.
	static Lista<Cultivo*>* obtenerCultivos();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve el cultivo que corresponde al nombre pasa por parametro 'nombreCultivo'.
	//	   En caso que 'nombreCultivo' no pertenezca a ningun cultivo disponible devuelve NULL.
	static Cultivo* obtenerCultivo(std::string nombreCultivo);

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve los destinos disponibles a los cuales se podrán enviar las cosechas almacenadas.
	//	   Los mismos dependerán de la configuración del archivo 'destinos.txt'.
	static Lista<Destino*>* obtenerDestinos();

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve el destino que corresponde al cultivo pasado por parametro 'cultivo'.
	//	   En caso que no haya ningun destino para el cultivo devuelve NULL.
	static Destino* obtenerDestino(Cultivo* cultivo);

	static unsigned int calcularRentabilidad(Cultivo* cultivo, unsigned int cantidad);

	//Pos: Libera la memoria reservada para los cultivos y destinos.
	~Configuracion();
};

#endif /* CONFIGURACION_H_ */
