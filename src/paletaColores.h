/*
 * paletaColores.h
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#ifndef PALETACOLORES_H_
#define PALETACOLORES_H_

#include "color.h"

enum EColor{

	BLANCO,
	GRIS,
	NEGRO,
	VERDE,
	VERDE_CLARO,
	MARRON,
	MARRON_CLARO
};

class PaletaColores {

private:

	Color** colores;
	unsigned int cantidadColores;

public:
	PaletaColores();
	Color* obtenerColor(EColor color);
};

#endif /* PALETACOLORES_H_ */
