/*
 * accionMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "accion.h"
#include <cstdlib>
#include "utils.h"


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

bool Accion::cambiarParametros(string parametros){

	unsigned int cantidadEspacios = Utils::contarRepeticiones(parametros, " ");

	//Tiene que haber exactamente obtenercantidadParametros() - 1 espacios de lo contrario se pasaron mas o menos parametros
	bool cambiarCantidadParametros = cantidadEspacios == this->obtenerCantidadParametros() - 1;

	if(cambiarCantidadParametros){

		Utils::splitString(parametros, " ", this->parametros);
		cambiarCantidadParametros = validarTipoParametros();
	}

	return cambiarCantidadParametros;
}

bool Accion::validarTipoParametros(){

	/*
	bool parametrosCorrectos = true;

	for(unsigned int i = 0; i < this->obtenerCantidadParametros() && parametrosCorrectos; i++){

		parametrosCorrectos = this->parametros->validarValor();
	}

	return parametrosCorrectos;*/

	return true;
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
