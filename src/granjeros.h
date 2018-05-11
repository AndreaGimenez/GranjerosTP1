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

/*
 * Clase principal del juego. Se encarga de gestionar el juego.
 * Utiliza 'InterfazUsuario' para interactuar con el usuario y enviar a la partida los datos que ingresan los usuarios.
 * Contiene la configuracion de los parametros que elige el usuario.
 */
class Granjeros {

private:

	ParametroConfiguracion* parametrosConfiguracion;
	InterfazUsuario* interfaz;
	Partida* partida;

	void ejecutarAccion(Accion* accion);
	void ejecutarAccionConfiguracion(Accion* accion);
	void ejecutarAccionPartida(Accion* accion);
	void comenzarPartida();
	bool avanzarTurno();
	void finalizarPartida();

public:

	Granjeros();

	// Post: Comienza la ejecucion del juego.
	void iniciarJuego();

	// Post: Libera los recursos reservados.
	~Granjeros();
};

#endif /* GRANJEROS_H_ */
