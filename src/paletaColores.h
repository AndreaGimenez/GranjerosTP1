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

class PaletaColores {

private:

	Color** colores;
	unsigned int cantidadColores;

public:

	PaletaColores();
	Color* obtenerColor(EColor color);
	~PaletaColores();
};

#endif /* PALETACOLORES_H_ */
