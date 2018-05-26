#ifndef PALETACOLORES_H_
#define PALETACOLORES_H_

#include "color.h"

enum EColor{

	BLANCO,
	GRIS,
	GRIS_HIERRO,
	NEGRO,
	VERDE,
	VERDE_CLARO,
	VERDE_HIERBA,
	MARRON,
	MARRON_CLARO,
	MARRON_TIERRA,
	MARRON_CAOBA,
	AMARILLO_ARENA,
	AMARILLO_ORO,
	AMARILLO_MIEL,
	BEIGE,
	ROJO
};

/*
 * Define una gama de colores predefinidos.
 */
class PaletaColores {

private:

	Color** colores;
	unsigned int cantidadColores;

public:

	// Pos: Inicializa los colores de la paleta
	PaletaColores();

	// Pos: Devuelve el color correspondiente a 'color'
	Color* obtenerColor(EColor color);

	//Pos: Libera los recursos reservados
	~PaletaColores();
};

#endif /* PALETACOLORES_H_ */
