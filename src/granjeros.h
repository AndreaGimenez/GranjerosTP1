/*
 * granjeros.h
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#ifndef GRANJEROS_H_
#define GRANJEROS_H_

#include "interfazUsuario.h"
#include "partida.h"
#include "parametroConfiguracion.h"
#include "accion.h"

class Granjeros {

private:

	InterfazUsuario interfaz;
	ParametroConfiguracion parametros;
	//Partida partida;

	static unsigned int cantidadAcciones;
	static Accion** acciones;

	static void cargarAcciones();
	static void destruirAcciones();

public:
	Granjeros();

	bool jugar();
	void ejecutarAccionPartida(Accion* accion);

	//Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	//Pos: Devuelve el destino que corresponde al cultivo pasado por parametro 'cultivo'.
	//	   En caso que no haya ningun destino para el cultivo devuelve NULL.
	static Accion obtenerAccion(accion::EAccion accion);
	static Accion* crearNuevaAccion(accion::EAccion accion);
};

#endif /* GRANJEROS_H_ */
