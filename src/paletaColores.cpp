/*
 * paletaColores.cpp
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#include "paletaColores.h"

PaletaColores::PaletaColores() {

	this->cantidadColores = 7;
	this->colores = new Color*[this->cantidadColores];

	this->colores[BLANCO] = new Color(255, 255, 255, 0);
	this->colores[GRIS] = new Color(156, 156, 156, 0);
	this->colores[NEGRO] = new Color(0, 0, 0, 0);
	this->colores[VERDE] = new Color(0, 100, 0, 0);
	this->colores[VERDE_CLARO] = new Color(0, 150, 0, 0);
	this->colores[MARRON] = new Color(89, 53, 31, 0);
	this->colores[MARRON_CLARO] = new Color(200, 160, 90, 0);
}

Color* PaletaColores::obtenerColor(EColor color){

	return this->colores[color];
}
