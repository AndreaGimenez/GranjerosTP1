/*
 * accionMenu.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef ACCION_H_
#define ACCION_H_

#include <string>
#include "lista.h"

namespace accion{

	enum Tipo{

		CON_PARAMETROS_USUARIO,
		SIN_PARAMETROS_USUARIO
	};

	enum Accion{

		//ACCIONES DE CONFIGURACION
		CAMBIAR_CANTIDAD_JUGADORES,
		CAMBIAR_PARAMETRO_N,
		CAMBIAR_PARAMETRO_M,
		CAMBIAR_CANTIDAD_TURNOS,

		//ACCIONES DEL JUEGO
		SEMBRAR,
		REGAR,
		COSECHAR,
		ENVIAR_COSECHA,
		COMPRAR_TERRENO,
		VENDER_TERRENO,
		COMPRAR_CAPACIDAD_AGUA,
		COMPRAR_CAPACIDAD_ALMACEN,
		FINALIZAR_TURNO,

		//ACCIONES GENERALES
		JUGAR,
		SALIR
	};
}

class Accion {

private:

	accion::Tipo tipo;
	accion::Accion accion;
	Lista<std::string>* parametros;

public:

	Accion(accion::Tipo tipo, accion::Accion accion);

	accion::Tipo obtenerTipo();
	void cambiarParametros(std::string parametros);
	accion::Accion obtenerAccion();
	Lista<std::string>* obtenerParametros();

	~Accion();
};

#endif /* ACCIONMENU_H_ */
