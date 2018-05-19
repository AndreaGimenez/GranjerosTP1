/*
 * dibujante.cpp
 *
 *  Created on: 18 may. 2018
 *      Author: administrador
 */

#include "creadorImagen.h"
#include <cstdlib>
#include <ctime>

using namespace std;

CreadorImagen::CreadorImagen() {

	this->lienzo = NULL;
	this->paletaColores = new PaletaColores;
}

void CreadorImagen::crearNuevaImagen(unsigned int alto, unsigned int ancho, unsigned int calidad){

	if(this->lienzo != NULL){
		delete this->lienzo;
	}

	this->lienzo = new Lienzo(alto, ancho, calidad);
}

void CreadorImagen::guardarImagen(string nombreImagen){

	this->lienzo->guardar(nombreImagen);
}

Color* CreadorImagen::obtenerColor(EColor color){
	return this->paletaColores->obtenerColor(color);
}

void CreadorImagen::dibujarLineaHorizontal(Color* color, int longitud, int coordenadaX, int coordenadaY){

	for(int i=0; i<longitud; i++){

		lienzo->dibujarPunto(color, coordenadaX + i, coordenadaY);
	}
}

void CreadorImagen::dibujarLineaVertical(Color* color, int longitud, int coordenadaX, int coordenadaY){

	for(int i=0; i<longitud; i++){

		lienzo->dibujarPunto(color, coordenadaX, coordenadaY + i);
	}
}

void CreadorImagen::dibujarRectangulo(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color){

	for(int i=0; i<ancho; i++){

		lienzo->dibujarPunto(color, coordenadaX + i, coordenadaY);
		lienzo->dibujarPunto(color, coordenadaX + i, coordenadaY + largo);
	}

	for(int i=0; i<largo; i++){

		lienzo->dibujarPunto(color, coordenadaX, coordenadaY + i);
		lienzo->dibujarPunto(color, coordenadaX + ancho, coordenadaY + i);
	}
}

void CreadorImagen::dibujarRectanguloConRelleno(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color){

	this->dibujarRectanguloConRelleno(ancho, largo, coordenadaX, coordenadaY, color, NULL);
}

void CreadorImagen::dibujarRectanguloConRelleno(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color, Color* color2){

	for(int i=0; i<ancho; i++){
		for(int j=0; j<largo; j++){

			if(color2 != NULL && rand()%11==5)
				lienzo->dibujarPunto(color2, coordenadaX + i, coordenadaY + j);

			else
				lienzo->dibujarPunto(color, coordenadaX + i, coordenadaY + j);
		}
	}
}

void CreadorImagen::pegarImagen(string nombreImagen, int coordenadaX, int coordenadaY){

	lienzo->pegarImagen(nombreImagen, coordenadaX, coordenadaY);
}


CreadorImagen::~CreadorImagen(){

	delete this->paletaColores;

	if(this->lienzo != NULL){
		delete this->lienzo;
	}
}
