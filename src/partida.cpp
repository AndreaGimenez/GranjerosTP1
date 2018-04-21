/*
 * partida.cpp
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef PARTIDA_CPP_
#define PARTIDA_CPP_

#include <iostream>
#include <string>

#include "partida.h"

Partida::Partida(unsigned int dificultad, unsigned int jugadores){

	this->nivelDeDificultad = dificultad ;
	this->cantidadDeJugadores = jugadores ;
	this->ronda = new Ronda() ;

}

unsigned int Partida::obtenerDificultad(){

	return this->nivelDeDificultad ;

}

unsigned int Partida::cantidadDeJugadores(){

	return this->cantidadDeJugadores ;

}

Jugador* Partida::verJugadorActual(){

	return ronda->verActual();

}

Partida::~Partida(){
	delete[] this->ronda ;
}







#endif /* PARTIDA_CPP_ */
