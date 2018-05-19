/*
 * dibujante.h
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#ifndef CREADORIMAGEN_H_
#define CREADORIMAGEN_H_

#ifndef NULL
#define NULL 0
#endif

#include "lienzo.h"
#include "paletaColores.h"

class CreadorImagen {

private:

	Lienzo* lienzo;
	PaletaColores* paletaColores;

public:
	CreadorImagen();
	void crearNuevaImagen(unsigned int alto, unsigned int ancho, unsigned int calidad);
	void guardarImagen(std::string nombreImagen);
	Color* obtenerColor(EColor color);
	void dibujarLineaHorizontal(Color* color, int longitud, int coordenadaX, int coordenadaY);
	void dibujarLineaVertical(Color* color, int longitud, int coordenadaX, int coordenadaY);
	void dibujarRectangulo(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color);
	void dibujarRectanguloConRelleno(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color);
	void dibujarRectanguloConRelleno(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color, Color* color2);
	void pegarImagen(std::string nombreImagen, int coordenadaX, int coordenadaY);
};

#endif /* CREADORIMAGEN_H_ */
