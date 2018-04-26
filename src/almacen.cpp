/*
 * almacen.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "almacen.h"

Almacen::Almacen(unsigned int capacidad){

	this->capacidad = capacidad;
	this->volumenUtilizado = 0;
}

unsigned int Almacen::getCapacidad(){

	return this->capacidad;
}

void Almacen::setCapacidad(unsigned int capacidad){

	this->capacidad = capacidad;
}

unsigned int Almacen::getVolumenUtilizado(){

	return this->volumenUtilizado;
}

void Almacen::setVolumenUtilizado(unsigned int volumenUtilizado){

	this->volumenUtilizado = volumenUtilizado;
}

bool Almacen::estaLleno(){

	return (this->volumenUtilizado == this->capacidad);
}

bool Almacen::estaVacio(){

	return (this->volumenUtilizado == 0);

}

void Almacen::almacenarCosechas(){

}

void Almacen::enviarCosechas(){

}
void Almacen::imprimirAlmacen(){

}
void Almacen::ampliarAlmacen(){

}


