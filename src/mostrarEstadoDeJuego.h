#include "EasyBMP.h"
#include "configuracion.h"
#include "parcela.h"
#include "utilidadesEasyBMP.h"
#include <ctime>
#include <cstdlib>

#ifndef MOSTRARESTADODEJUEGO_H_
#define MOSTRARESTADODEJUEGO_H_

class BmpCultivos {

	private:

	//ancho: width
	//largo:height

	Herramientas utilidades;
	BMP imagenTerreno;
	BMP* punteroImagenTerreno;
	BMP imagenCultivo;
	BMP* punteroImagenCultivo;
	int anchoLargoParcela;
	int distanciaAlBorde;

	void dibujarTerrenoVacio(BMP* punteroImagenTerreno, Herramientas utilidades, int distanciaAlBorde);

	public:

		BmpCultivos();

		int obtenerAnchoDelTerreno();

		int obtenerLargoDelTerreno();

		void crearBitmap();

		// void actualizarTerreno() deberia devolver la imagen con los cambios efectuados en el turno correspondiente



};

#endif
