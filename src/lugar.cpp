/*
 * Lugar.cpp
 *
 *  Created on: 1 jul. 2018
 *      Author: administrador
 */

#include "lugar.h"

using namespace std;

Lugar::Lugar(string nombre) {
	this->nombre = nombre;
}

string Lugar::obtenerNombre(){
	return this->nombre;
}
