/*
 * respuestaMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "respuesta.h"
#include "granjeros.h"

Respuesta::Respuesta(){
	this->inicializar(respuesta::SUBMENU, NULL, accion::NINGUNA);
}

Respuesta::Respuesta(Menu* subMenu){

	this->inicializar(respuesta::SUBMENU, subMenu, accion::NINGUNA);
}

Respuesta::Respuesta(accion::EAccion accion){

	this->inicializar(respuesta::ACCION, NULL, accion);
}

void Respuesta::inicializar(respuesta::Tipo tipo, Menu* subMenu, accion::EAccion accion){

	this->tipo = tipo;
	this->subMenu = subMenu;
	this->accion = NULL;

	if(accion != accion::NINGUNA){

		this->accion = Granjeros::crearNuevaAccion(accion);
	}
}

respuesta::Tipo Respuesta::obtenerTipo(){
	return this->tipo;
}

Menu* Respuesta::obtenerSubMenu(){
	return this->subMenu;
}

Accion* Respuesta::obtenerAccion(){
	return this->accion;
}

Respuesta::~Respuesta(){

	if(this->accion != NULL){
		delete this->accion;
	}
}
