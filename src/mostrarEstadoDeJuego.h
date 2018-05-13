#include "EasyBMP.h"
#include "configuracion.h"
#include <ctime>
#include <cstdlib>

#ifndef MOSTRARESTADODEJUEGO_H_
#define MOSTRARESTADODEJUEGO_H_

class BmpCultivos {

	private:

	//ancho: width
	//largo:height

		BMP imagen;
		BMP* punteroImagen;
		RGBApixel lapizVerdeClaro;
		RGBApixel lapizVerdeOscuro;
		RGBApixel lapizMarron;
		int ladoCultivo;
		int espacioEntreCultivos;
		int espacioLateral;
		int espacioEntreLateralYCultivos;
		int coordenadaAncho;
		int coordenadaLargo;
		int salto;

		int asignarDimension(int dimensionActual);


		void rellenarTerreno(BMP* punteroImagen, RGBApixel lapizVerdeClaro, RGBApixel lapizVerdeOscuro);

		void crearEnmarcado(BMP* punteroImagen, RGBApixel lapizMarron);

		void crearParcelas(BMP* punteroImagen, int i, int j, RGBApixel lapizMarron);

		void asignarParcelas(BMP* punteroImagen, int salto, RGBApixel lapizMarron);


	public:


		BmpCultivos();

		int mostrarEspacioEntreLateralYCultivos();

		int mostrarEspacioEntreCultivos();

		int mostrarEspacioLateral();

		int mostrarLadoCultivo();

		int obtenerPixelActualAncho();

		int obtenerPixelActualLargo();

		int obtenerTopeDeCoordenadas();

		void crearImagen();


};

#endif
