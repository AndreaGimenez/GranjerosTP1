/*
 * accionMenu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "accion.h"
#include <cstdlib>

using namespace std;

Accion::Accion(accion::Accion accion, unsigned int cantidadParametros, parametro::Tipo tiposParametros[]){

	this->tipo = accion::CON_PARAMETROS_USUARIO;
	this->accion = accion;
	this->parametros = new Lista<Parametro*>;
	this->parametrosConvertidos = new Lista<void*>;

	for(unsigned int iParametro = 0; iParametro < cantidadParametros; iParametro++){
		Parametro* parametro = new Parametro(tiposParametros[0], "");
		this->parametros->agregar(parametro);
	}
}

Accion::Accion(accion::Accion accion){

	this->tipo = accion::SIN_PARAMETROS_USUARIO;
	this->accion = accion;
	this->parametros = new Lista<Parametro*>;
	this->parametrosConvertidos = new Lista<void*>;
}

accion::Tipo Accion::obtenerTipo(){
	return this->tipo;
}

void Accion::cambiarParametros(string parametros){

	int posicionRegex = parametros.find(" ");
	unsigned int indiceParametros = 1;

	while(posicionRegex > 0){

		string strParametro = parametros.substr(0, posicionRegex);
		Parametro* parametro = this->parametros->obtener(indiceParametros);
		parametro->cambiarValor(strParametro);
		this->parametrosConvertidos->agregar(parametro->obtenerValorConvertido());

		parametros = parametros.substr(posicionRegex + 1);
		posicionRegex = parametros.find(" ");
		indiceParametros++;
	}

	if(parametros != ""){

		Parametro* parametro = this->parametros->obtener(indiceParametros);
		parametro->cambiarValor(parametros);
	}
}

accion::Accion Accion::obtenerAccion(){
	return this->accion;
}

Lista<Parametro*>* Accion::obtenerParametros(){
	return this->parametros;
}

Lista<void*>* Accion::obtenerParametrosConvertidos(){

	return this->parametrosConvertidos;
}

Accion::~Accion(){

	if(this->parametros != NULL){

		if(!this->parametros->estaVacia()){

				this->parametros->iniciarCursor();
				while(this->parametros->avanzarCursor()){
					delete this->parametros->obtenerCursor();
				}
			}
		delete this->parametros;
	}
	if(this->parametrosConvertidos != NULL){

		delete this->parametrosConvertidos;
	}
}
