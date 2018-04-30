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
	ParametroConfiguracion parametrosConfiguracion;
	//Partida partida;

	static unsigned int cantidadAcciones;
	static Accion** acciones;

	static void cargarAcciones();
	static void destruirAcciones();

public:

	Granjeros();

	bool iniciarJuego();
	void ejecutarAccion(Accion* accion);
	bool ejecutarAccionConfiguracion(Accion* accion);
	bool ejecutarAccionPartida(Accion* accion);
	void comenzarPartida();
	bool avanzarTurno();
	static Accion* crearNuevaAccion(accion::EAccion accion);

	~Granjeros();
};

#endif /* GRANJEROS_H_ */
