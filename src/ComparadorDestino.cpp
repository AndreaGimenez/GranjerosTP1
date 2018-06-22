/*
 * ComparadorDestino.cpp
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#include "ComparadorDestino.h"

bool ComparadorDestino::sonIguales(Destino* destino1, Destino* destino2){

	return (destino1->obtenerNombre() == destino2->obtenerNombre());
}
