/*
 * lienzo.h
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#ifndef LIENZO_H_
#define LIENZO_H_

#include "EasyBMP.h"
#include "color.h"

class Lienzo {

private:

	BMP* bmp;

public:

	Lienzo(unsigned int alto, unsigned int ancho, unsigned int calidad);

	RGBApixel obtenerRGBApixel(Color* color);
	void dibujarPunto(Color* lapiz, int coordenadaX, int coordenadaY);
	void pegarImagen(std::string nombreImagen, int coordenadaX, int coordenadaY);
	void guardar(std::string nombre);

	~Lienzo();
};

#endif /* LIENZO_H_ */
