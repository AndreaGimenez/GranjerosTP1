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

bool Jugador::puedeGastarMonedas(unsigned int cantidadMonedas){

	return (cantidadMonedas <= this->monedas);
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

Terreno* Jugador::buscarTerreno(unsigned int numeroTerreno){

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

bool Jugador::puedeAlmacenar(Cultivo* cultivo){

	return (this->puedeAlmacenar(cultivo, 1));
}

bool Jugador::puedeAlmacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar){

	return (this->almacen->puedeAlmacenarCosecha(cultivo, cantidadAAlmacenar));
}

bool Jugador::almacenar(Cultivo* cultivo){

	return this->almacenar(cultivo, 1);
}

bool Jugador::almacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar){

	bool almacenar = puedeAlmacenar(cultivo, cantidadAAlmacenar);

	if(almacenar){
		this->almacen->almacenarCosecha(cultivo, cantidadAAlmacenar);
	}

	return almacenar;
}

bool Jugador::puedeSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo){

	bool puedeCosechar = false;

	Terreno* terreno = buscarTerreno(numeroTerreno);
	if(terreno != NULL){

		return (puedeGastarMonedas(cultivo->obtenerCosto())
				&& terreno->puedeSembrar(coordenadasParcela));
	}

	return puedeCosechar;
}

bool Jugador::sembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo){

	bool puedeSembrar = this->puedeSembrar(numeroTerreno,coordenadasParcela, cultivo);

	if(puedeSembrar){

		this->buscarTerreno(numeroTerreno)->sembrar(coordenadasParcela, cultivo);
		this->gastarMonedas(cultivo->obtenerCosto());
	}

	return puedeSembrar;
}

bool Jugador::puedeCosechar(unsigned int numeroTerreno, string coordenadasParcela){

	bool puedeCosechar = false;

	Terreno* terreno = buscarTerreno(numeroTerreno);
	if(terreno != NULL){
		terreno->puedeCosechar(coordenadasParcela);
	}

	return puedeCosechar;
}

bool Jugador::cosechar(unsigned int numeroTerreno, std::string coordenadasParcela){

	bool puedeCosechar = this->puedeCosechar(numeroTerreno, coordenadasParcela);

	if(puedeCosechar){

		Cultivo* cultivoCosechado = this->buscarTerreno(numeroTerreno)->cosechar(coordenadasParcela);
		almacenar(cultivoCosechado);
	}

	return puedeCosechar;
}

bool Jugador::puedeRegar(unsigned int numeroTerreno, std::string coordenadasParcela){

	bool puedeRegar = false;

	Terreno* terreno = this->buscarTerreno(numeroTerreno);
	if(terreno != NULL){

		Cultivo* cultivo = terreno->obtenerCultivo(coordenadasParcela);
		puedeRegar = (puedeConsumirUnidadesRiego(cultivo->obtenerConsumoAgua())
					  && terreno->puedeRegar(coordenadasParcela));
	}

	return puedeRegar;
}

bool Jugador::regar(unsigned int numeroTerreno, std::string coordenadasParcela){

	bool regar = puedeRegar(numeroTerreno, coordenadasParcela);

	if(regar){

		 int unidadesRiegoConsumidas = this->buscarTerreno(numeroTerreno)->regar(coordenadasParcela);
		 this->consumirUnidadesRiego(unidadesRiegoConsumidas);
	}

	return regar;
}

unsigned int Jugador::obtenerUnidadesRiego(){

	return this->unidadesRiego;
}

unsigned int Jugador::obtenerUnidadesRiegoTotales(){

	return this->unidadesRiego + this->tanque->volumenUtilizado();
}

bool Jugador::puedeConsumirUnidadesRiego(unsigned int unidadesRiego){

	return (unidadesRiego <= this->obtenerUnidadesRiegoTotales());
}

bool Jugador::consumirUnidadesRiego(unsigned int unidadesRiego){

	bool consumirUnidadesRiego = puedeConsumirUnidadesRiego(unidadesRiego);

	if(consumirUnidadesRiego){

		if(this->unidadesRiego < unidadesRiego){

			unsigned int unidadesAConsumirTanque = unidadesRiego - this->unidadesRiego;
			this->unidadesRiego = 0;
			this->tanque->usarAguaAlmacenada(unidadesAConsumirTanque);
		}else{
			this->unidadesRiego -= unidadesRiego;
		}
	}

	return consumirUnidadesRiego;
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
