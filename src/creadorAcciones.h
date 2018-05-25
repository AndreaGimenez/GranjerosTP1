/*
 * creadorAcciones.h
 *
 *  Created on: 2 may. 2018
 *      Author: administrador
 */

#ifndef CREADORACCIONES_H_
#define CREADORACCIONES_H_

#ifndef NULL
#define NULL 0
#endif

#include "accion.h"

/*
 * Clase que permite generar acciones a partir de "definiciones" hechas previamente.
 * La definicion consiste en la cantidad de parametros (si es que los requiere).
 */
class CreadorAcciones {

private:

	static unsigned int cantidadAcciones;
	static Accion** acciones;

	static void destruirAcciones();

	CreadorAcciones();

public:

	/*
	 * Pos: Inicializa las acciones disponibles para realizar.
	 */
	static void inicializar();

	/*
	 * Pos: Devuelve una copia de la accion solicitada, los parametros no se encuentran inicializados.
	 */
	static Accion* crearNuevaAccion(accion::Tipo tipoAccion);

	/*
	 * Pos: Libera los recursos reservados.
	 */
	~CreadorAcciones();
};

#endif /* CREADORACCIONES_H_ */
