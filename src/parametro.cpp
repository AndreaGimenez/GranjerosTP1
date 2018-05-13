/*
 * parametro.cpp
 *
 *  Created on: 13 may. 2018
 *      Author: administrador
 */

#include "parametro.h"

using namespace std;

Parametro::Parametro(std::string valor, parametro::Tipo tipo){

	this->valor = valor;
	this->tipo = tipo;
}

std::string Parametro::obtenerValor(){

	return this->valor;
}

void Parametro::cambiarValor(std::string valor){

	this->valor = valor;
}

parametro::Tipo Parametro::obtenerTipo(){

	return this->tipo;
}

void Parametro::cambiarTipo(parametro::Tipo tipo){

	this->tipo = tipo;
}
