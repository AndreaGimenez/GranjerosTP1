/*
 * jugador.cpp
 *
 *  Created on: 19 Apr 2018
 *      Author: Andrea
 */

#include <iostream>
#include <string>

#include "jugador.h"
#include "configuracion.h"

using namespace std ;

Jugador::Jugador(string nombre){

	this->nombre = nombre;
	this->monedas = Configuracion::obtenerCreditosIniciales();
	this->turnos = Configuracion::obtenerCantidadTurnos();
	this->tanque = new Tanque(Configuracion::obtenerCapacidadInicialTanque());
	this->almacen = new Almacen(Configuracion::obtenerCapacidadInicialAlmacen());

	for(unsigned int i = 1; i <= Configuracion::obtenerCantidadTerrenosIniciales(); i++){
		this->terrenos.agregar(new Terreno());
	}
}

unsigned int Jugador::monedasDisponibles(){

	return this->monedas;

}

void Jugador::agregarMonedas(unsigned int monedasASumar){

	if(monedasASumar < 0){
		throw string("Cantidad de monedas a sumar invalida \n");
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

	return this->terrenos.contarElementos();
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

Terreno* Jugador::obtenerTerreno(unsigned int numeroTerreno){

	if(numeroTerreno < 1 && numeroTerreno > this->terrenos.contarElementos() ){
		throw string("El numero de terreno no existe");
	}

	return this->terrenos.obtener(numeroTerreno);
}

bool Jugador::quedanTurnos(){

	bool turnos = false ;

	if (this->turnos > 1){
		turnos = true ;
	}

	return turnos;
}

bool Jugador::puedeSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo){

	return (cultivo->obtenerCosto() <= this->monedas
			&& this->obtenerTerreno(numeroTerreno)->puedeSembrar(coordenadasParcela));
}

bool Jugador::sembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo){

	bool puedeSembrar = this->puedeSembrar(numeroTerreno,coordenadasParcela, cultivo);

	if(puedeSembrar){

		this->obtenerTerreno(numeroTerreno)->sembrar(coordenadasParcela, cultivo);
		this->gastarMonedas(cultivo->obtenerCosto());
	}

	return puedeSembrar;
}

bool Jugador::cosechar(unsigned int numeroTerreno, std::string coordenadasParcela){
	return false;
}

bool Jugador::regar(unsigned int numeroTerreno, std::string coordenadasParcela){
	return false;
}

bool Jugador::enviar(Cultivo* cultivo){
	return false;
}

bool Jugador::comprarTerreno(){
	return false;
}

bool Jugador::venderTerreno(unsigned int numeroTerreno){
	return false;
}

bool Jugador::comprarCapacidadTanque(){
	return false;
}

bool Jugador::comprarCapacidadAlmacen(){
	return false;
}

Jugador::~Jugador(){

	delete this->tanque;

	this->terrenos.iniciarCursor();
	while(this->terrenos.avanzarCursor()){
		delete this->terrenos.obtenerCursor();
	}
}
