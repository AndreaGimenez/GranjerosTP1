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

void Lienzo::pegarImagen(std::string nombreImagen, int coordenadaX, int coordenadaY){

	BMP imagen;
	imagen.ReadFromFile(nombreImagen.c_str());
	RangedPixelToPixelCopy(imagen, 0, imagen.TellWidth(), 0, imagen.TellHeight(), *this->bmp, coordenadaX, coordenadaY);
}

void Lienzo::pegarImagenConTransparencia(std::string nombreImagen, int coordenadaX, int coordenadaY, Color* color){

	BMP imagen;
	imagen.ReadFromFile(nombreImagen.c_str());
	RGBApixel transparencia = obtenerRGBApixel(color);
	RangedPixelToPixelCopyTransparent(imagen, 0, imagen.TellWidth(), 0, imagen.TellHeight(), *this->bmp, coordenadaX, coordenadaY, transparencia);
}

void Lienzo::guardar(string nombre){

	this->bmp->WriteToFile(nombre.c_str());
}

Lienzo::~Lienzo(){

	delete this->bmp;
}
