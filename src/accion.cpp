/*
 * accionMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "accion.h"

using namespace std;

Accion::Accion(accion::Tipo tipo, accion::Accion accion){

	this->tipo = tipo;
	this->accion = accion;
	this->parametros = NULL;
}

accion::Tipo Accion::obtenerTipo(){
	return this->tipo;
}

void Accion::cambiarParametros(string parametros){

	if(this->parametros != NULL){
		delete this->parametros;
	}

	this->parametros = new Lista<string>;
	int posicionRegex = parametros.find(" ");

	while(posicionRegex > 0){

		string elemento = parametros.substr(0, posicionRegex);
		this->parametros->agregar(elemento);

		parametros = parametros.substr(posicionRegex + 1);
		posicionRegex = parametros.find(" ");
	}

	if(parametros != ""){

		this->parametros->agregar(parametros);
	}
}

accion::Accion Accion::obtenerAccion(){
	return this->accion;
}

Lista<std::string>* Accion::obtenerParametros(){
	return this->parametros;
}

Accion::~Accion(){
	if(this->parametros != NULL){
		delete this->parametros;
	}
}
