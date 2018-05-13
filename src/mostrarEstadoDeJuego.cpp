#include "mostrarEstadoDeJuego.h"
#include <iostream>
using namespace std;


BmpCultivos::BmpCultivos(){


	distanciaAlBorde=10;
	anchoLargoParcela=10;
	imagenTerreno.SetSize(obtenerAnchoDelTerreno(), obtenerLargoDelTerreno());
	imagenTerreno.SetBitDepth(24);
	punteroImagenTerreno=&imagenTerreno;
	dibujarTerrenoVacio(utilidades);

	imagenActualCultivo.SetSize(obtenerAnchoLargoParcela(), obtenerAnchoLargoParcela());
	imagenActualCultivo.SetBitDepth(24);

}

void BmpCultivos::dibujarTerrenoVacio(Herramientas utilidades){

	RGBApixel verdeClaro, verdeOscuro, marron;
	RGBApixel* lapizVerdeClaro=&verdeClaro;
	RGBApixel* lapizVerdeOscuro=&verdeOscuro;
	RGBApixel* lapizMarron=&marron;

	utilidades.cambiarColorPor(lapizVerdeOscuro, 0, 100, 0, 0);

	utilidades.cambiarColorPor(lapizVerdeClaro, 0, 150, 0, 0);

	utilidades.cambiarColorPor(lapizMarron, 200, 160, 90, 0);

	utilidades.pintarZonaRandom(obtenerImagen(), obtenerImagen()->TellWidth(), obtenerImagen()->TellHeight(), 0, 0, lapizVerdeClaro, lapizVerdeOscuro);

	utilidades.dibujarPerimetro(obtenerImagen(), obtenerImagen()->TellWidth()-obtenerDistanciaAlBorde()*2, obtenerImagen()->TellHeight()-obtenerDistanciaAlBorde()*2,
			obtenerDistanciaAlBorde(), obtenerDistanciaAlBorde(), lapizMarron);

	int finDelTerrenoAncho=obtenerAnchoDelTerreno()-obtenerDistanciaAlBorde();
	int finDelTerrenoLargo=obtenerLargoDelTerreno()-obtenerDistanciaAlBorde();
	int inicioDelTerreno=obtenerDistanciaAlBorde()+obtenerAnchoLargoParcela();

	for(int i=inicioDelTerreno; i<finDelTerrenoAncho; i+=obtenerAnchoLargoParcela())

		utilidades.dibujarLineaVertical(obtenerImagen(), obtenerLargoDelTerreno()-obtenerDistanciaAlBorde()*2, i, obtenerDistanciaAlBorde(), lapizMarron);

	for(int j=inicioDelTerreno; j<finDelTerrenoLargo; j+=obtenerAnchoLargoParcela())

		utilidades.dibujarLineaHorizontal(obtenerImagen(), obtenerAnchoDelTerreno()-obtenerDistanciaAlBorde()*2, obtenerDistanciaAlBorde(), j, lapizMarron);

}

int BmpCultivos::obtenerColumnas(){

	return Configuracion::obtenerAnchoTerreno();

}

int BmpCultivos::obtenerFilas(){

	return Configuracion::obtenerLargoTerreno();

}


int BmpCultivos::obtenerAnchoDelTerreno(){

	return obtenerColumnas()*obtenerAnchoLargoParcela()+obtenerDistanciaAlBorde()*2;

}


int BmpCultivos::obtenerLargoDelTerreno(){

	return obtenerFilas()*obtenerAnchoLargoParcela()+obtenerDistanciaAlBorde()*2;

}

int BmpCultivos::obtenerAnchoLargoParcela(){

	return anchoLargoParcela;

}

int BmpCultivos::obtenerDistanciaAlBorde(){

	return distanciaAlBorde;

}

BMP* BmpCultivos::obtenerImagen(){

	return punteroImagenTerreno;

}

BMP BmpCultivos::obtenerImagenCultivo(){

	return imagenActualCultivo;

}



int BmpCultivos::obtenerPrincipioDelTerreno(){

	int coordenadasEnImagen[2];

	coordenadasEnImagen[0]=obtenerDistanciaAlBorde();

	coordenadasEnImagen[1]=coordenadasEnImagen[0];

	return coordenadasEnImagen;

}

bool BmpCultivos::finDelTerreno(int parcelaActualAncho, int parcelaActualLargo){

	return (parcelaActualAncho=obtenerAnchoDelTerreno()-obtenerDistanciaAlBorde()
			&& parcelaActualLargo=obtenerLargoDelTerreno()-obtenerDistanciaAlBorde());

}

void BmpCultivos::actualizarParcela(BMP* imagenAsignada, int coordenadasAncho, int coordenadasLargo){

	Herramientas color;
	RGBApixel transparente;
	RGBApixel* lapizTransparente=&transparente;

	color.cambiarColorPor(lapizTransparente, 255, 255, 255, 0);

	//PixelToPixelCopyTransparent(imagenAsignada, 0, 0, obtenerImagen(), coordenadasAncho, coordenadasLargo, lapizTransparente);

}

void BmpCultivos::asignarImagenAlCultivo(Cultivo* cultivoActual, BMP* imagenAsignada){

	string nombreCultivo=cultivoActual->obtenerNombre();

	imagenAsignada->ReadFromFile(nombreCultivo".bmp");

}


void BmpCultivos::actualizarTerreno(){

	int parcelaActual[2];

	Cultivo* cultivoActual; //aca tengo que asignarle el primer cultivo

	BMP* imagenAsignada=&obtenerImagenCultivo();

	parcelaActual=obtenerPrincipioDelTerreno();

	while(!finDelTerreno(parcelaActual[0], parcelaActual[1])){

		asignarImagenAlCultivo(cultivoActual, imagenAsignada);

		actualizarParcela(imagenAsignada, parcelaActual[0], parcelaActual[1]);

		//cultivoActual=obtenerSiguienteCultivo(); necesito pasar a la siguiente parcela

		parcelaActual=obtenerSiguienteParcela(); //recorre la imagen terreno

	}


}


void BmpCultivos::crearBitmap(){

	imagenTerreno.WriteToFile("Turno.bmp");

}

