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
	this->ronda = new Ronda();

	this->primerJugador = NULL;
	this->jugadorActual = NULL;
}

unsigned int Partida::obtenerDificultad(){

	return this->nivelDeDificultad ;

}

unsigned int Partida::getCantidadDeJugadores(){

	return this->cantidadDeJugadores ;

}

Jugador* Partida::verJugadorActual(){

	return NULL;
	//ronda->verJugadorActual();

}

Partida::~Partida(){
	delete[] this->ronda ;
}







#endif /* PARTIDA_CPP_ */
