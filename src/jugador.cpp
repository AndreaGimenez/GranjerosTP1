/*
 * jugador.cpp
 *
 *  Created on: 19 Apr 2018
 *      Author: Andrea
 */

#include <iostream>
#include <string>

#include "jugador.h"
#include "utilidades.h"
#include "configuracion.h"

using namespace std ;

Jugador::Jugador(){

	this->monedas = Configuracion::obtenerCreditosIniciales() ;
	this->turnos = Configuracion::obtenerCantidadTurnos() ;
	this->terrenos = TERRENOS_INICIALES ;

}

unsigned int Jugador::monedasDisponibles(){

	return this->monedas;

}

void Jugador::agregarMonedas(unsigned int monedasASumar){

	if(monedasASumar < 0){
		throw string("Cantidad de monedas a sumar invalida \n") ;
	}

	this->monedas += monedasASumar ;
}


bool Jugador::gastarMonedas(unsigned int monedasAGastar){

	bool exito = false ;

	if(monedasAGastar < 0){
		throw string("Cantidad de monedas a gastar invalida \n");
	}

	if(monedasAGastar <= this->monedas){
		this->monedas -= monedasAGastar ;
		exito = true ;
	}

	return exito ;
}

unsigned int Jugador::turnosRestantes(){

	return (this-> turnos)-1 ; //para no contemplar el turno actual, solo los restantes

}

void Jugador::pasarProximoTurno(){

	if(this->quedanTurnos()){
		this->turnos -- ;
	}
}

unsigned int Jugador::cantidadDeTerrenos(){

	return this->terrenos ;

}

void Jugador::asignarNombre(string nombre) {

	this->nombre = nombre ;

}

string Jugador::obtenerNombre(){

	return this->nombre ;

}

void Jugador::imprimirJugador(){

	cout<<"Nombre del jugador: "<<obtenerNombre() ;
	cout<<"Cantidad de monedas: "<< monedasDisponibles() ;
	cout<<"Turnos Restantes: "<<turnosRestantes() ;
	cout<<"Cantidad de terrenos"<<cantidadDeTerrenos() ;

}

bool Jugador::quedanTurnos(){
	bool turnos = false ;

	if (this->turnos > 1){
		turnos = true ;
	}

	return turnos;

}

