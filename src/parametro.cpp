/*
 * parametro.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "parametro.h"
#include <cstdlib>

using namespace std;

Parametro::Parametro(parametro::Tipo tipo, string valor){

	this->tipo = tipo;
	this->valor = valor;
	this->valorConvertido = NULL;
}

void Parametro::cambiarValor(string valor){
	this->valor = valor;
	this->cambiarValorConvertido();
}

parametro::Tipo Parametro::obtenerTipo(){
	return this->tipo;
}

string Parametro::obtenerValor(){
	return this->valor;
}

void Parametro::cambiarValorConvertido(){

		void* valor = NULL;
		switch(this->obtenerTipo()){

		case parametro::CHAR:
			char* charValue;
			charValue = NULL;
			charValue = new char;
			*charValue = this->obtenerValor().c_str()[0];
			valor = charValue;
			break;

		case parametro::INT:
			int* intValue;
			intValue = NULL;
			intValue = new int;
			*intValue = atoi(this->obtenerValor().c_str());
			valor = intValue;
			break;

		case parametro::STRING:
			string* strValue;
			strValue = NULL;
			strValue = new string;
			*strValue = this->obtenerValor();
			valor = strValue;
			break;
		}
		this->valorConvertido = valor;
}

void* Parametro::obtenerValorConvertido(){
	return this->valorConvertido;
}

void Parametro::deleteValorConvertido(){

	switch(this->obtenerTipo()){

		case parametro::CHAR:
			delete (char*)this->valorConvertido;
			break;

		case parametro::INT:
			delete (int*)this->valorConvertido;
			break;

		case parametro::STRING:
			delete (string*)this->valorConvertido;
			break;
	}

}

Parametro::~Parametro(){

	if(this->valorConvertido != NULL){
		deleteValorConvertido();
	}
}
