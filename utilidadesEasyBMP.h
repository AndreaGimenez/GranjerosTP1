/*
 * utilidadesEasyBMP.h
 *
 *  Created on: 13/05/2018
 *      Author: ignacio
 */

#ifndef UTILIDADESEASYBMP_H_
#define UTILIDADESEASYBMP_H_

#include "EasyBMP.h"
#include <cstdlib>
#include <ctime>

class Herramientas{

	public:

		void dibujarPerimetro(BMP* imagen, int ancho, int largo, int pixelAncho, int pixelLargo, RGBApixel* colorDelPerimetro);

		void pintarZona(BMP* imagen, int ancho, int largo, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaZona);

		void cambiarColorPor(RGBApixel* colorPrevio, int rojo, int verde, int azul, int opacidad);

		void pintarZonaRandom(BMP* imagen, int ancho, int largo, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaZona1, RGBApixel* colorDeLaZona2);

		void dibujarLineaHorizontal(BMP* imagen, int longitud, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaLinea);

		void dibujarLineaVertical(BMP* imagen, int longitud, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaLinea);


};



#endif /* UTILIDADESEASYBMP_H_ */
