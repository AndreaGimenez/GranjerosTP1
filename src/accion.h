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

	enum EAccion{

		NINGUNA = 0,
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
	accion::EAccion accion;
	unsigned int cantidadParametros;
	std::string* parametros;

public:

	Accion();
	Accion(Accion* accion);
	Accion(accion::Tipo tipoAccion, accion::EAccion accion);
	Accion(accion::Tipo tipoAccion, accion::EAccion accion, unsigned int cantidadParametros);

	void cambiarTipo(accion::Tipo tipo);
	accion::Tipo obtenerTipo();
	void cambiarParametros(std::string* parametros);
	void cambiarParametros(std::string parametros);
	std::string* obtenerParametros();
	void cambiarAccion(accion::EAccion accion);
	accion::EAccion obtenerAccion();
	void cambiarCantidadParametros(unsigned int cantidadParametros);
	unsigned int obtenerCantidadParametros();

	~Accion();
};

#endif /* ACCIONMENU_H_ */
