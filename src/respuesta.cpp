/*
 * respuestaMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "respuesta.h"

Respuesta::Respuesta(){
	this->inicializar(respuesta::SUBMENU, NULL, NULL);
}

Respuesta::Respuesta(Menu* subMenu){

	this->inicializar(respuesta::SUBMENU, subMenu, NULL);
}

Respuesta::Respuesta(Accion* accion){

	this->inicializar(respuesta::ACCION, NULL, accion);
}

void Respuesta::inicializar(respuesta::Tipo tipo, Menu* subMenu, Accion* accion){

	this->tipo = tipo;
	this->subMenu = subMenu;
	this->accion = accion;
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
