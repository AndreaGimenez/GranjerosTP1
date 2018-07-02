/*
 * Trayecto.cpp
 *
 *  Created on: 1 jul. 2018
 *      Author: administrador
 */

#include "trayecto.h"

Trayecto::Trayecto(Lugar* origen, Lugar* destino, unsigned int costo, unsigned int distancia){

	this->origen = origen;
	this->destino = destino;
	this->costo = costo;
	this->distancia = distancia;
}

Lugar* Trayecto::obtenerOrigen(){
	return this->origen;
}

Lugar* Trayecto::obtenerDestino(){
	return this->destino;
}
unsigned int Trayecto::obtenerCosto(){
	return this->costo;
}
