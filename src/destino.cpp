/*
 * Destino.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "destino.h"

using namespace std;

Destino::Destino(string nombre, unsigned int distacia, string nombreCultivo){

	this->nombre = nombre;
	this->distancia = distancia;
	this->nombreCultivo = nombreCultivo;
}

unsigned int Destino::getDistancia() {
	return distancia;
}

void Destino::setDistancia(unsigned int distancia) {
	this->distancia = distancia;
}

string Destino::getNombre() {
	return nombre;
}

void Destino::setNombre(string nombre) {
	this->nombre = nombre;
}

string Destino::getNombreCultivo() {
	return nombreCultivo;
}

void Destino::setNombreCultivo(string nombreCultivo) {
	this->nombreCultivo = nombreCultivo;
}

