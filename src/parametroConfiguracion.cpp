/*
 * parametroConfiguracion.cpp
 *
 *  Created on: 27 abr. 2018
 *      Author: administrador
 */

#include "parametroConfiguracion.h"
#include "configuracion.h"

ParametroConfiguracion::ParametroConfiguracion(){

	this->dificultad = FACIL;
	this->cantidadJugadores = 0;
	this->parametroN = 0;
	this->parametroM = 0;
	this->cantidadTurnos = 0;
}

void ParametroConfiguracion::cambiarDificultad(Dificultad dificultad){

	this->dificultad = dificultad;
}

Dificultad ParametroConfiguracion::obtenerDificultad(){

	return this->dificultad;
}

unsigned int ParametroConfiguracion::obtenerCantidadJugadores(){

	return this->cantidadJugadores;
}

void ParametroConfiguracion::cambiarCantidadJugadores(unsigned int cantidadJugadores){

	this->cantidadJugadores = cantidadJugadores;
}

unsigned int ParametroConfiguracion::obtenerParametroN(){

	return this->parametroN;
}

void ParametroConfiguracion::cambiarParametroN(unsigned int parametroN){

	this->parametroN = parametroN;
}

unsigned int ParametroConfiguracion::obtenerParametroM(){

	return this->parametroM;
}

void ParametroConfiguracion::cambiarParametroM(unsigned int parametroM){

	this->parametroM = parametroM;
}

unsigned int ParametroConfiguracion::obtenerCantidadTurnos(){

	return this->cantidadTurnos;
}

void ParametroConfiguracion::cambiarCantidadTurnos(unsigned int cantidadTurnos){

	this->cantidadTurnos = cantidadTurnos;
}
