/*
 * color.cpp
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#include "color.h"

Color::Color(unsigned char rojo, unsigned char verde, unsigned char azul, unsigned char opacidad){

	this->opacidad = opacidad;
	this->rojo = rojo;
	this->verde = verde;
	this->azul = azul;
}

unsigned char Color::obtenerRojo(){
	return this->rojo;
}

unsigned char Color::obtenerVerde(){
	return this->verde;
}

unsigned char Color::obtenerAzul(){
	return this->azul;
}

unsigned char Color::obtenerOpacidad(){
	return this->opacidad;
}
