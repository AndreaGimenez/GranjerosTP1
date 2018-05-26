#include "plantillaTerrenoImagen.h"
#include "configuracion.h"

unsigned int PlantillaTerrenoImagen::distanciaHorizontalAlBorde = 50;
unsigned int PlantillaTerrenoImagen::distanciaVerticalAlBorde = 50;
unsigned int PlantillaTerrenoImagen::distanciaParcelaCoordenadaX = 10;
unsigned int PlantillaTerrenoImagen::distanciaParcelaCoordenadaY = 10;
unsigned int PlantillaTerrenoImagen::altoImagenNumeroCoordenada = 19;
unsigned int PlantillaTerrenoImagen::anchoImagenNumeroCoordenada = 14;
unsigned int PlantillaTerrenoImagen::espacioDigitosCoordenada = 2;
unsigned int PlantillaTerrenoImagen::anchoParcela = 100;
unsigned int PlantillaTerrenoImagen::largoParcela = 100;
unsigned int PlantillaTerrenoImagen::anchoCultivo = 5;
unsigned int PlantillaTerrenoImagen::separacionEntreCultivos = 10;
unsigned int PlantillaTerrenoImagen::anchoImagenNombreCultivo = 24;
unsigned int PlantillaTerrenoImagen::altoImagenNombreCultivo = 24;
unsigned int PlantillaTerrenoImagen::anchoMarcaArado = 5;
unsigned int PlantillaTerrenoImagen::separacionEntreMarcasArado = 10;
unsigned int PlantillaTerrenoImagen::anchoPoste = 6;
unsigned int PlantillaTerrenoImagen::largoPoste = 6;
unsigned int PlantillaTerrenoImagen::anchoImagenRiego = 10;
unsigned int PlantillaTerrenoImagen::altoImagenRiego = 30;
unsigned int PlantillaTerrenoImagen::anchoImagenHoz = 50;
unsigned int PlantillaTerrenoImagen::altoImagenHoz = 50;

PlantillaTerrenoImagen::PlantillaTerrenoImagen() {
	// TODO Auto-generated constructor stub

}

unsigned int PlantillaTerrenoImagen::obtenerDistanciaHorizontalAlBorde(){
	return distanciaHorizontalAlBorde;
}

unsigned int PlantillaTerrenoImagen::obtenerDistanciaVerticalAlBorde(){
	return distanciaVerticalAlBorde;
}

unsigned int PlantillaTerrenoImagen::obtenerDistanciaParcelaCoordenadaX(){
	return distanciaParcelaCoordenadaX;
}

unsigned int PlantillaTerrenoImagen::obtenerDistanciaParcelaCoordenadaY(){
	return distanciaParcelaCoordenadaY;
}

unsigned int PlantillaTerrenoImagen::obtenerAltoImagenNumeroCoordenada(){
	return altoImagenNumeroCoordenada;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoImagenNumeroCoordenada(){
	return anchoImagenNumeroCoordenada;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoParcela(){
	return anchoParcela;
}

unsigned int PlantillaTerrenoImagen::obtenerLargoParcela(){
	return largoParcela;
}

unsigned int PlantillaTerrenoImagen::obtenerEspacioDigitosCoordenada(){
	return espacioDigitosCoordenada;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoCultivo(){
	return anchoCultivo;
}

unsigned int PlantillaTerrenoImagen::obtenerSeparacionEntreCultivos(){
	return separacionEntreCultivos;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoImagenNombreCultivo(){
	return anchoImagenNombreCultivo;
}
unsigned int PlantillaTerrenoImagen::obtenerAltoImagenNombreCultivo(){
	return altoImagenNombreCultivo;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoMarcaArado(){
	return anchoMarcaArado;
}

unsigned int PlantillaTerrenoImagen::obtenerSeparacionEntreMarcasArado(){
	return separacionEntreMarcasArado;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoPoste(){
	return anchoPoste;
}

unsigned int PlantillaTerrenoImagen::obtenerLargoPoste(){
	return largoPoste;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoImagenRiego(){
	return anchoImagenRiego;
}

unsigned int PlantillaTerrenoImagen::obtenerAltoImagenRiego(){
	return altoImagenRiego;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoImagenHoz(){
	return anchoImagenHoz;
}

unsigned int PlantillaTerrenoImagen::obtenerAltoImagenHoz(){
	return altoImagenHoz;
}

unsigned int PlantillaTerrenoImagen::obtenerAnchoTerreno(){

	return Configuracion::obtenerAnchoTerreno() * PlantillaTerrenoImagen::obtenerAnchoParcela()
		 + PlantillaTerrenoImagen::obtenerDistanciaHorizontalAlBorde() * 2;
}

unsigned int PlantillaTerrenoImagen::obtenerLargoTerreno(){

	return Configuracion::obtenerLargoTerreno() * PlantillaTerrenoImagen::obtenerLargoParcela()
		 + PlantillaTerrenoImagen::obtenerDistanciaHorizontalAlBorde() * 2;
}
