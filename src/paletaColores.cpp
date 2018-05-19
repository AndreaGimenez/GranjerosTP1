/*
 * paletaColores.cpp
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#include "paletaColores.h"

PaletaColores::PaletaColores() {

	this->cantidadColores = 15;
	this->colores = new Color*[this->cantidadColores];

	this->colores[BLANCO] = new Color(255, 255, 255, 0);
	this->colores[GRIS] = new Color(156, 156, 156, 0);
	this->colores[GRIS_HIERRO] = new Color(67, 75, 77, 0);
	this->colores[NEGRO] = new Color(0, 0, 0, 0);
	this->colores[VERDE] = new Color(0, 100, 0, 0);
	this->colores[VERDE_CLARO] = new Color(0, 150, 0, 0);
	this->colores[VERDE_HIERBA] = new Color(0, 125, 0, 0);
	this->colores[MARRON] = new Color(89, 53, 31, 0);
	this->colores[MARRON_CLARO] = new Color(200, 160, 90, 0);
	this->colores[MARRON_TIERRA] = new Color(78, 59, 49, 0);
	this->colores[MARRON_CAOBA] = new Color(76, 47, 39, 0);
	this->colores[AMARILLO_ARENA] = new Color(198, 166, 100, 0);
	this->colores[AMARILLO_ORO] = new Color(205, 164, 52, 0);
	this->colores[AMARILLO_MIEL] = new Color(169, 131, 7, 0);
	this->colores[BEIGE] = new Color(106, 93, 77, 0);
}

Color* PaletaColores::obtenerColor(EColor color){

	return this->colores[color];
}

PaletaColores::~PaletaColores() {

	for(unsigned int i = 0; i < this->cantidadColores; i ++){
		delete this->colores[i];
	}

	delete[] this->colores;
}
