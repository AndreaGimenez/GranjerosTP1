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
#include "lista.h"
#include "jugador.h"
#include "configuracion.h"

using namespace std ;

Partida::Partida(Lista<string>* nombresJugadores){

	this->nivelDeDificultad = Configuracion::obtenerDificultad(); ;
	this->cantidadDeJugadores =  Configuracion::obtenerCantidadJugadores() ;
	Lista<Jugador*>* rondaJugadores = new Lista<Jugador*>();
	cargarJugadoresEnLaRonda(nombresJugadores);
	
}

Dificultad Partida::obtenerDificultad(){

	return this->nivelDeDificultad ;

}

unsigned int Partida::getCantidadDeJugadores(){

	return this->cantidadDeJugadores ;

}

Jugador* Partida::verJugadorActual(){

	return rondaJugadores->obtenerCursor();

}

void Partida::avanzarProximoJugador(){

	rondaJugadores->avanzarCursor();	//Si hacemos las modificaciones q propuse en las primitivas del cursor
									//de la lista, con esta linea de codigo creo q abarcamos todos los casos
}									//sino habria que contemplar los casos en que se este en el ultimo jugador,etc


Partida::~Partida(){

	rondaJugadores->iniciarCursor() ;
	for(unsigned int i = 0 ; i < this->cantidadDeJugadores ; i++ ){

		Jugador* jugadorObtenido = rondaJugadores->obtenerCursor() ;
		delete jugadorObtenido ;
		rondaJugadores->avanzarCursor() ;

	}

}

void Partida::cargarJugadoresEnLaRonda(Lista<string>* nombresJugadores){

	nombresJugadores->iniciarCursor() ;

	for(unsigned int i = 0 ; i < this->cantidadDeJugadores ; i++){

		Jugador* nuevoJugador = new Jugador();
		nuevoJugador->asignarNombre(nombresJugadores->obtenerCursor());
		this->rondaJugadores->agregar(nuevoJugador);
		nombresJugadores->avanzarCursor();

	}

}




#endif /* PARTIDA_CPP_ */
