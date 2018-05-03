/*
 * respuestaMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "resultadoOpcion.h"
#include "creadorAcciones.h"


ResultadoOpcion::ResultadoOpcion(Menu* subMenu){

	this->inicializar(resultadoOpcion::SUBMENU, subMenu, accion::NINGUNA);
}

ResultadoOpcion::ResultadoOpcion(accion::EAccion accion){

	this->inicializar(resultadoOpcion::ACCION, NULL, accion);
}

void ResultadoOpcion::inicializar(resultadoOpcion::Tipo tipo, Menu* subMenu, accion::EAccion accion){

	this->tipo = tipo;
	this->subMenu = subMenu;
	this->accion = NULL;

	if(accion != accion::NINGUNA){

		this->accion = CreadorAcciones::crearNuevaAccion(accion);
	}
}

resultadoOpcion::Tipo ResultadoOpcion::obtenerTipo(){
	return this->tipo;
}

Menu* ResultadoOpcion::obtenerSubMenu(){
	return this->subMenu;
}

Accion* ResultadoOpcion::obtenerAccion(){
	return this->accion;
}

ResultadoOpcion::~ResultadoOpcion(){

	if(this->accion != NULL){
		delete this->accion;
	}
}
