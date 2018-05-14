#include "EasyBMP.h"
#include "configuracion.h" //incluye cultivo.h
#include "utilidadesEasyBMP.h"
#include "jugador.h" // incluye parcela.h terreno.h
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
	Jugador jugador;

	void dibujarTerrenoVacio(Herramientas utilidades);

	void asignarImagenAlCultivo(Cultivo* cultivoActual, BMP* imagenAsignada);

	void actualizarParcela(BMP* imagenAsignada, int coordenadasAncho, int coordenadasLargo);

	void obtenerSiguienteParcela();


	public:

		BmpCultivos(Jugador nombre);

		Jugador mostrarJugador();

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

		void actualizarTerreno(); //deberia devolver la imagen con los cambios efectuados en el turno correspondiente

		void actualizarTodosLosTerrenos(/*recibe la lista de terrenos*/);


};

#endif
