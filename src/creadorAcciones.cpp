/*
 * creadorAcciones.cpp
 *
 *  Created on: 2 may. 2018
 *      Author: administrador
 */

#include "creadorAcciones.h"

unsigned int CreadorAcciones::cantidadAcciones = 16;
Accion** CreadorAcciones::acciones = NULL;

CreadorAcciones::CreadorAcciones() {
}

void CreadorAcciones::inicializar(){

	acciones = new Accion*[cantidadAcciones];

	acciones[0] = new Accion(accion::NINGUNA);
	acciones[1] = new Accion(accion::CAMBIAR_CANTIDAD_JUGADORES, 1);
	acciones[2] = new Accion(accion::CAMBIAR_PARAMETRO_N, 1);
	acciones[3] = new Accion(accion::CAMBIAR_PARAMETRO_M, 1);
	acciones[4] = new Accion(accion::CAMBIAR_CANTIDAD_TURNOS, 1);
	acciones[5] = new Accion(accion::SEMBRAR, 2);
	acciones[6] = new Accion(accion::REGAR, 1);
	acciones[7] = new Accion(accion::COSECHAR, 1);
	acciones[8] = new Accion(accion::ENVIAR_COSECHA, 1);
	acciones[9] = new Accion(accion::COMPRAR_TERRENO);
	acciones[10] = new Accion(accion::VENDER_TERRENO, 1);
	acciones[11] = new Accion(accion::COMPRAR_CAPACIDAD_AGUA);
	acciones[12] = new Accion(accion::COMPRAR_CAPACIDAD_ALMACEN);
	acciones[13] = new Accion(accion::FINALIZAR_TURNO);
	acciones[14] = new Accion(accion::JUGAR);
	acciones[15] = new Accion(accion::SALIR);
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

