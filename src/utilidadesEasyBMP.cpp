/*
 * utilidadesEasyBMP.cpp
 *
 *  Created on: 13/05/2018
 *      Author: ignacio
 */

#include "utilidadesEasyBMP.h"

void Herramientas::dibujarPerimetro(BMP* imagen, int ancho, int largo, int pixelAncho, int pixelLargo, RGBApixel* colorDelPerimetro){

	for(int i=0; i<ancho; i++){

		imagen->SetPixel(pixelAncho+i, pixelLargo, *colorDelPerimetro);

		imagen->SetPixel(pixelAncho+i, pixelLargo+largo, *colorDelPerimetro);

	}

	for(int i=0; i<largo; i++){

		imagen->SetPixel(pixelAncho, pixelLargo+i, *colorDelPerimetro);

		imagen->SetPixel(pixelAncho+ancho, pixelLargo+i, *colorDelPerimetro);

	}

}

void Herramientas::pintarZonaRandom(BMP* imagen, int ancho, int largo, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaZona1, RGBApixel* colorDeLaZona2){

	for(int i=0; i<ancho; i++){

		for(int j=0; j<largo; j++){

			if(rand()%11==5)

				imagen->SetPixel(pixelAncho+i, pixelLargo+j, *colorDeLaZona2);

			else

				imagen->SetPixel(pixelAncho+i, pixelLargo+j, *colorDeLaZona1);

		}

	}

}


void Herramientas::pintarZona(BMP* imagen, int ancho, int largo, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaZona){

	for(int i=0; i<ancho; i++){

		for(int j=0; j<largo; j++){

			imagen->SetPixel(pixelAncho+i, pixelLargo+j, *colorDeLaZona);

		}

	}

}

void Herramientas::cambiarColorPor(RGBApixel* colorPrevio, int rojo, int verde, int azul, int opacidad){

	colorPrevio->Alpha=opacidad;

	colorPrevio->Red=rojo;

	colorPrevio->Green=verde;

	colorPrevio->Blue=azul;

}

void Herramientas::dibujarLineaHorizontal(BMP* imagen, int longitud, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaLinea){

	for(int i=0; i<longitud; i++){

		imagen->SetPixel(pixelAncho+i, pixelLargo, *colorDeLaLinea);

	}

}

void Herramientas::dibujarLineaVertical(BMP* imagen, int longitud, int pixelAncho, int pixelLargo, RGBApixel* colorDeLaLinea){

	for(int i=0; i<longitud; i++){

		imagen->SetPixel(pixelAncho, pixelLargo+i, *colorDeLaLinea);

	}

}
