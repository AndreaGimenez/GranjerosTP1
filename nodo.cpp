/*
 * nodo.cpp
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#include <iostream>

#include "nodo.h"


Nodo::Nodo(Jugador* dato){

	this->dato = dato ;
	this->siguiente = NULL ;

}

Jugador* Nodo::obtenerDato(){

	return this->dato;
}

Nodo* Nodo::obtenerSiguiente(){

	return this->siguiente;

}


void Nodo::cambiarSiguiente(Nodo* nuevoNodo){

	nuevoNodo->siguiente = this->obtenerSiguiente; //funciona tambien cuando se agrega al final
	this->siguiente = nuevoNodo;

}
