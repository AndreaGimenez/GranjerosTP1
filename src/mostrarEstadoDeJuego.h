#include "EasyBMP.h"
#include "configuracion.h" //incluye cultivo.h
#include "terreno.h" //incluye parcela.h
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
	BMP imagenActualCultivo;
	int anchoLargoParcela; //depende de las imagenes que usemos para los cultivos
	int distanciaAlBorde;

	void dibujarTerrenoVacio(Herramientas utilidades);



	public:

		BmpCultivos();

		int obtenerFilas();

		int obtenerColumnas();

		int obtenerAnchoDelTerreno();

		int obtenerLargoDelTerreno();

		int obtenerDistanciaAlBorde();

		int obtenerAnchoLargoParcela();

		BMP* obtenerImagen();

		BMP obtenerImagenCultivo();

		void crearBitmap();

		//N filas, M columnas
		int obtenerPrincipioDelTerreno();

		bool finDelTerreno(int parcelaActualAncho, int parcelaActualLargo);

		void obtenerSiguienteParcela();

		void asignarImagenAlCultivo(Cultivo* cultivoActual, BMP* imagenAsignada)

		void actualizarParcela(BMP* imagenAsignada, int coordenadasAncho, int coordenadasLargo);

		void actualizarTerreno(); //deberia devolver la imagen con los cambios efectuados en el turno correspondiente



};

#endif
