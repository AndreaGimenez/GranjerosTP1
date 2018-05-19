/*
 * lienzo.cpp
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#include "lienzo.h"

using namespace std;

Lienzo::Lienzo(unsigned int alto, unsigned int ancho, unsigned int calidad) {

	this->bmp = new BMP();
	bmp->SetSize(ancho, alto);
	bmp->SetBitDepth(calidad);
}

RGBApixel Lienzo::obtenerRGBApixel(Color* color){

	RGBApixel pixel;
	pixel.Red = color->obtenerRojo();
	pixel.Blue = color->obtenerAzul();
	pixel.Green = color->obtenerVerde();
	pixel.Alpha = color->obtenerOpacidad();

	return pixel;
}

void Lienzo::dibujarPunto(Color* color, int coordenadaX, int coordenadaY){

	this->bmp->SetPixel(coordenadaX, coordenadaY, obtenerRGBApixel(color));
}

void Lienzo::guardar(string nombre){

	this->bmp->WriteToFile(nombre.c_str());
}
