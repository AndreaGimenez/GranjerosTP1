/*
 * accionMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "accion.h"
#include <cstdlib>


using namespace std;

Accion::Accion(){

	this->tipo = accion::SIN_PARAMETROS_USUARIO;
	this->accion = accion::NINGUNA;
	this->cantidadParametros = 0;
	this->parametros = NULL;
}

Accion::Accion(Accion* accion){

	this->tipo = accion->obtenerTipo();
	this->accion = accion->obtenerAccion();
	this->cantidadParametros = accion->obtenerCantidadParametros();

	if(accion->obtenerParametros() != NULL){
		this->parametros = new string[this->cantidadParametros];

		for(unsigned int iParametro = 0; iParametro < this->cantidadParametros; iParametro++){
			this->parametros[iParametro] = accion->obtenerParametros()[iParametro];
		}
	}else{
		this->parametros = NULL;
	}
}

Accion::Accion(accion::EAccion accion){

	this->tipo = accion::SIN_PARAMETROS_USUARIO;
	this->accion = accion;
	this->cantidadParametros = 0;
	this->parametros = NULL;
}

Accion::Accion(accion::EAccion accion, unsigned int cantidadParametros){

	this->accion = accion;
	this->cantidadParametros = cantidadParametros;

	if(cantidadParametros == 0){
		this->tipo = accion::SIN_PARAMETROS_USUARIO;
		this->parametros = NULL;
	}else{
		this->tipo = accion::CON_PARAMETROS_USUARIO;
		this->parametros = new string[this->cantidadParametros];
	}
}

accion::Tipo Accion::obtenerTipo(){
	return this->tipo;
}

std::string* Accion::obtenerParametros(){
	return this->parametros;
}

void Accion::cambiarParametros(string* parametros){

	this->parametros = parametros;
}

void Accion::cambiarParametros(string parametros){

	int posicionRegex = parametros.find(" ");
	unsigned int indiceParametro = 0;

	while(posicionRegex > 0){

		string strParametro = parametros.substr(0, posicionRegex);
		this->parametros[indiceParametro] = strParametro;

		parametros = parametros.substr(posicionRegex + 1);
		posicionRegex = parametros.find(" ");
		indiceParametro++;
	}

	if(parametros != ""){

		this->parametros[indiceParametro] = parametros;
	}
}

accion::EAccion Accion::obtenerAccion(){
	return this->accion;
}

unsigned int Accion::obtenerCantidadParametros(){
	return this->cantidadParametros;
}

Accion::~Accion(){

	if(this->parametros != NULL){
		delete[] this->parametros;
	}
}
