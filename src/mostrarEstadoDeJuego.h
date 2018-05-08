#include "EasyBMP.h"
#include "configuracion.h"
#include <ctime>
#include <cstdlib>

#ifndef MOSTRARESTADODEJUEGO_H_
#define MOSTRARESTADODEJUEGO_H_

class BmpCultivos {

	private:

		BMP imagen;
		RGBApixel lapizVerdeClaro;
		RGBApixel lapizVerdeOscuro;
		RGBApixel lapizMarron;
		//Configuracion dimensiones;
		unsigned int perimetroCultivo;
		unsigned int espacioEntreCultivos;
		unsigned int espacioLateral;
		unsigned int ancho;
		unsigned int largo;
		int coordenadaAncho;
		int coordenadaLargo;

		unsigned int asignarDimension(int dimensiones, unsigned int perimetroCultivo, unsigned int espacioEntreCultivos, unsigned int espacioLateral);
		void rellenarTerreno(BMP imagen, unsigned int ancho, unsigned int largo);
		void crearEnmarcado(BMP imagen, unsigned int ancho, unsigned int largo, unsigned int espacioLateral, RGBApixel lapizMarron);
		void crearMaceta(BMP imagen, int coordenadaAncho, int coordenadaLargo, unsigned int perimetroCultivo, RGBApixel lapizMarron);

	public:

		BmpCultivos();

		void crearParcela();

};

#endif
