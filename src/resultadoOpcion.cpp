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

ResultadoOpcion::ResultadoOpcion(accion::Tipo tipoAccion){

	this->inicializar(resultadoOpcion::ACCION, NULL, tipoAccion);
}

void ResultadoOpcion::inicializar(resultadoOpcion::Tipo tipo, Menu* subMenu, accion::Tipo tipoAccion){

	this->tipo = tipo;
	this->subMenu = subMenu;
	this->accion = NULL;

	if(tipoAccion != accion::NINGUNA){

		this->accion = CreadorAcciones::crearNuevaAccion(tipoAccion);
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
