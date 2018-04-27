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
 */
class Configuracion {

private:

	static Dificultad dificultad;
	static unsigned int cantidadJugadores;
	static unsigned int parametroN;
	static unsigned int parametroM;
	static unsigned int cantidadTurnos;
	static Lista<Cultivo*>* cultivos;
	static Lista<Destino*>* destinos;


	static void cargarCultivos();
	static void cargarDestinos();

	//Para evitar que sea instanciada el constructor es private, debe usarse de manera estatica.
	Configuracion();

	static unsigned int obtenerCoeficienteDificultad();

	//Pos: Libera memoria pedida para los cultivos
	static void destruirCultivos();

	//Pos: Libera memoria pedida para los destinos
	static void destruirDestinos();

public:

	//Pos: Inicializa la configuracion de acuerdo a los parametros del juego, archivos de configuracion, etc.
	static void inicializar(ParametroConfiguracion parametros);

	static Dificultad obtenerDificultad();

	static unsigned int obtenerCantidadJugadores();

	static unsigned int obtenerLargoTerreno();

	static unsigned int obtenerAnchoTerreno();

	static unsigned int obtenerCreditosIniciales();

	static unsigned int obtenerCapacidadInicialTanque();

	static unsigned int obtenerCantidadTurnos();

	static unsigned int obtenerCapacidadInicialAlmacen();

	//Pre: La configuracion debe haberse inicializado previamente llamando a 'inicializar'.
	static Lista<Cultivo*>* obtenerCultivos();

	//Pre: La configuracion debe haberse inicializado previamente llamando a 'inicializar'.
	static Lista<Destino*>* obtenerDestinos();

	~Configuracion();
};

#endif /* CONFIGURACION_H_ */
