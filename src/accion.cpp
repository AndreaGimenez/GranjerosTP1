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
		this->parametros = new Parametro[this->cantidadParametros];

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

Accion::Accion(accion::EAccion accion, unsigned int cantidadParametros, parametro::Tipo tiposParametros[]){

	this->accion = accion;
	this->cantidadParametros = cantidadParametros;

	if(cantidadParametros == 0){
		this->tipo = accion::SIN_PARAMETROS_USUARIO;
		this->parametros = NULL;
	}else{
		this->tipo = accion::CON_PARAMETROS_USUARIO;
		this->parametros = new Parametro;

		for(unsigned int i = 0; i < cantidadParametros; i++){
			this->parametros[i].cambiarTipo(tiposParametros[i]);
		}
	}
}

accion::Tipo Accion::obtenerTipo(){
	return this->tipo;
}

Parametro* Accion::obtenerParametros(){
	return this->parametros;
}

void Accion::cambiarParametros(Parametro* parametros){

	this->parametros = parametros;
}

bool Accion::cambiarParametros(string parametros){

	bool cambiarCantidadParametros = cambiarValoresParametros(parametros);
	cambiarCantidadParametros = cambiarCantidadParametros && validarTipoParametros();

	return cambiarCantidadParametros;
}

bool Accion::cambiarValoresParametros(std::string parametros){

	unsigned int cantidadEspacios = Utils::contarRepeticiones(parametros, " ");

	//Tiene que haber exactamente obtenercantidadParametros() - 1 espacios de lo contrario se pasaron mas o menos parametros
	bool cambiarCantidadParametros = cantidadEspacios == this->obtenerCantidadParametros() - 1;

	if(cambiarCantidadParametros){

		unsigned int tamanioCadenaSeparada = cantidadEspacios + 1;

		for(unsigned int i = 0; i < tamanioCadenaSeparada; i++){

			unsigned int posicionSubcadena = parametros.find(" ");

			string elemento = parametros.substr(0, posicionSubcadena);
			this->parametros[i].cambiarValor(elemento);

			parametros = parametros.substr(posicionSubcadena + 1);
		}
	}

	return cambiarCantidadParametros;
}

bool Accion::validarTipoParametros(){

	bool parametrosCorrectos = true;

	for(unsigned int i = 0; i < this->obtenerCantidadParametros() && parametrosCorrectos; i++){

		parametrosCorrectos = this->parametros[i].validarValor();
	}

	return parametrosCorrectos;
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
