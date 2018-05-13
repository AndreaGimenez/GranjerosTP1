/*
 * parametro.cpp
 *
 *  Created on: 13 may. 2018
 *      Author: administrador
 */

#include "parametro.h"
#include "utils.h"

using namespace std;

Parametro::Parametro(){

	this->valor = "";
	this->tipo = parametro::STRING;
}

Parametro::Parametro(std::string valor, parametro::Tipo tipo){

	this->valor = valor;
	this->tipo = tipo;
}

Parametro::Parametro(parametro::Tipo tipo){

	this->valor = "";
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

bool Parametro::validarValor(){

	bool validacionOk = false;

	switch(this->tipo){

		case parametro::CHAR:
			validacionOk = Utils::esUnsignedInt(this->valor);
			break;

		case parametro::INT:
			validacionOk = Utils::esInt(this->valor);
			break;

		case parametro::UNSIGNED_INT:
			validacionOk = Utils::esChar(this->valor);
			break;

		default:
			validacionOk = true;
	}

	return validacionOk;
}
