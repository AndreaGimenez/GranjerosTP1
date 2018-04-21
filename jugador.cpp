/*
 * jugador.cpp
 *
 *  Created on: 19 Apr 2018
 *      Author: Usuario
 */

#include <iostream>
#include<string>

#include "jugador.h"
#include "utilidades.h"

using namespace std ;

Jugador::Jugador(unsigned int cantidadDeMonedas, unsigned int cantidadDeTurnos){

	if(cantidadDeMonedas < 0 || cantidadDeTurnos <0){
		throw string("Cantidades iniciales invalidas \n");
	}

	this->monedas = cantidadDeMonedas ;
	this->turnos = cantidadDeTurnos ;
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

	else{
		throw string("No quedan turnos \n") ;  //comentario para el grupo: hay que validar SIEMPRE
	}										  //que queden turnos antes de invocar este metodo
											 //usar quedanTurnos()
}

unsigned int Jugador::cantidadDeTerrenos(){

	return this->terrenos ;

}

void Jugador::imprimirJugador(){

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
