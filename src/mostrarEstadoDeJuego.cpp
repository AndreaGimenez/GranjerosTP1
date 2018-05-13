#include "mostrarEstadoDeJuego.h"
#include <iostream>
using namespace std;


BmpCultivos::BmpCultivos(){

	distanciaAlBorde=10;
	anchoLargoParcela=10;
	imagenTerreno.SetSize(obtenerAnchoDelTerreno(), obtenerLargoDelTerreno());
	imagenTerreno.SetBitDepth(24);
	punteroImagenTerreno=&imagenTerreno;
	dibujarTerrenoVacio(punteroImagenTerreno, utilidades, distanciaAlBorde);


}

void BmpCultivos::dibujarTerrenoVacio(BMP* punteroImagenTerreno, Herramientas utilidades, int distanciaAlBorde){

	RGBApixel verdeClaro, verdeOscuro, marron;
	RGBApixel* lapizVerdeClaro=&verdeClaro;
	RGBApixel* lapizVerdeOscuro=&verdeOscuro;
	RGBApixel* lapizMarron=&marron;

	utilidades.cambiarColorPor(lapizVerdeOscuro, 0, 100, 0, 0);

	utilidades.cambiarColorPor(lapizVerdeClaro, 0, 150, 0, 0);

	utilidades.cambiarColorPor(lapizMarron, 200, 160, 90, 0);

	utilidades.pintarZonaRandom(punteroImagenTerreno, punteroImagenTerreno->TellWidth(), punteroImagenTerreno->TellHeight(), 0, 0, lapizVerdeClaro, lapizVerdeOscuro);

	utilidades.dibujarPerimetro(punteroImagenTerreno, punteroImagenTerreno->TellWidth()-distanciaAlBorde*2, punteroImagenTerreno->TellHeight()-distanciaAlBorde*2,
								 distanciaAlBorde, distanciaAlBorde, lapizMarron);

	int finDelTerrenoAncho=obtenerAnchoDelTerreno()-distanciaAlBorde;
	int finDelTerrenoLargo=obtenerLargoDelTerreno()-distanciaAlBorde;
	int inicioDelTerreno=distanciaAlBorde+anchoLargoParcela;

	for(int i=inicioDelTerreno; i<finDelTerrenoAncho; i+=anchoLargoParcela)

		utilidades.dibujarLineaVertical(punteroImagenTerreno, obtenerLargoDelTerreno()-distanciaAlBorde*2, i, distanciaAlBorde, lapizMarron);

	for(int j=inicioDelTerreno; j<finDelTerrenoLargo; j+=anchoLargoParcela)

		utilidades.dibujarLineaHorizontal(punteroImagenTerreno, obtenerAnchoDelTerreno()-distanciaAlBorde*2, distanciaAlBorde, j, lapizMarron);

}


int BmpCultivos::obtenerAnchoDelTerreno(){

	return Configuracion::obtenerAnchoTerreno()*anchoLargoParcela+distanciaAlBorde*2;

}


int BmpCultivos::obtenerLargoDelTerreno(){

	return Configuracion::obtenerLargoTerreno()*anchoLargoParcela+distanciaAlBorde*2;

}

void BmpCultivos::crearBitmap(){

	imagenTerreno.WriteToFile("Turno.bmp");

}

