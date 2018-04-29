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

class Granjeros {

private:

	InterfazUsuario interfaz;
	ParametroConfiguracion parametros;
	//Partida partida;
public:
	Granjeros();

	bool jugar();
	void ejecutarAccionPartida(Accion* accion);
};

#endif /* GRANJEROS_H_ */
