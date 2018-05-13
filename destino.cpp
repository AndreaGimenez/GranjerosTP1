/*
 * Destino.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "destino.h"

using namespace std;

Destino::Destino(string nombre, unsigned int distacia, unsigned int precio, string nombreCultivo){

	this->nombre = nombre;
	this->distancia = distancia;
	this->precio = precio;
	this->nombreCultivo = nombreCultivo;
}

unsigned int Destino::obtenerDistancia() {
	return distancia;
}

string Destino::obtenerNombre() {
	return nombre;
}

unsigned int Destino::obtenerPrecio(){
	return this->precio;
}

string Destino::obtenerNombreCultivo() {
	return nombreCultivo;
}
