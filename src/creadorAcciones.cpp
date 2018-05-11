/*
 * creadorAcciones.cpp
 *
 *  Created on: 2 may. 2018
 *      Author: administrador
 */

#include "creadorAcciones.h"

unsigned int CreadorAcciones::cantidadAcciones = 17;
Accion** CreadorAcciones::acciones = NULL;

CreadorAcciones::CreadorAcciones() {
}

void CreadorAcciones::inicializar(){

	acciones = new Accion*[cantidadAcciones];

	acciones[accion::NINGUNA] = new Accion(accion::NINGUNA);
	acciones[accion::CAMBIAR_CANTIDAD_JUGADORES] = new Accion(accion::CAMBIAR_CANTIDAD_JUGADORES, 1);
	acciones[accion::CAMBIAR_PARAMETRO_N] = new Accion(accion::CAMBIAR_PARAMETRO_N, 1);
	acciones[accion::CAMBIAR_PARAMETRO_M] = new Accion(accion::CAMBIAR_PARAMETRO_M, 1);
	acciones[accion::CAMBIAR_CANTIDAD_TURNOS] = new Accion(accion::CAMBIAR_CANTIDAD_TURNOS, 1);
	acciones[accion::SEMBRAR] = new Accion(accion::SEMBRAR, 2);
	acciones[accion::REGAR] = new Accion(accion::REGAR, 1);
	acciones[accion::COSECHAR] = new Accion(accion::COSECHAR, 1);
	acciones[accion::ENVIAR_COSECHA] = new Accion(accion::ENVIAR_COSECHA, 1);
	acciones[accion::COMPRAR_TERRENO] = new Accion(accion::COMPRAR_TERRENO);
	acciones[accion::VENDER_TERRENO] = new Accion(accion::VENDER_TERRENO, 1);
	acciones[accion::COMPRAR_CAPACIDAD_AGUA] = new Accion(accion::COMPRAR_CAPACIDAD_AGUA);
	acciones[accion::COMPRAR_CAPACIDAD_ALMACEN] = new Accion(accion::COMPRAR_CAPACIDAD_ALMACEN);
	acciones[accion::FINALIZAR_TURNO] = new Accion(accion::FINALIZAR_TURNO);
	acciones[accion::FINALIZAR_PARTIDA] = new Accion(accion::FINALIZAR_PARTIDA);
	acciones[accion::JUGAR] = new Accion(accion::JUGAR);
	acciones[accion::SALIR] = new Accion(accion::SALIR);
}

Accion* CreadorAcciones::crearNuevaAccion(accion::EAccion accion){

	Accion* nuevaAccion = new Accion(acciones[accion]);
	return nuevaAccion;
}

void CreadorAcciones::destruirAcciones(){

	for(unsigned int iAccion = 0; iAccion < 16; iAccion++){
		delete acciones[iAccion];
	}
	delete[] acciones;
}


CreadorAcciones::~CreadorAcciones() {

	destruirAcciones();
}

