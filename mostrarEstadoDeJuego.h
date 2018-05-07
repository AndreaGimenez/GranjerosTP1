#include "EasyBMP.h"
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

	public:

		BmpCultivos();

		void crearParcela();

		void rellenarTerreno();

};

#endif
