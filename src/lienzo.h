#ifndef LIENZO_H_
#define LIENZO_H_

#include "EasyBMP.h"
#include "color.h"

/*
 * 'Lienzo' representa un espacio sobre el cual se pueden dibujar puntos sobre el mismo y crear formar
 * y lineas. Ademas permite pegar imagenes.
 * El dibujo puede ser almacenado en un archivo con formato bmp.
 *
 * El lienzo maneja 2 coordenadas X e Y. El origen de coordenadas esta en el punto superior izquierdo
 * del lienzo.
 * La coordenada X tiene direccion horizontal e incrementa hacia la derecha.
 * La coordenada Y tiene direccion vertical e incrementa hacia abajo.
 *
 * 		0,0 -------------------> coordenadas X
 * 		|   		-----------------------------------------------------------------------------
 * 		|   		|																			|
 * 		|   		|																			|
 * 		|			|				.(x,y)														|
 *		| 			|																			|
 * 		v			|																			|
 * coordenadas Y	|																			|
 * 					|																			|
 * 					|																			|
 * 					|																			|
 * 					|																			|
 * 					|																			|
 * 					|																			|
 * 					-----------------------------------------------------------------------------
 */
class Lienzo {

private:

	BMP* bmp;

	RGBApixel obtenerRGBApixel(Color* color);

public:


	// Pos: Inicializa el lienzo con los valores pasados por parametro
	Lienzo(unsigned int alto, unsigned int ancho, unsigned int calidad);

	/*
	 * Pre: 'coordenadaX' y 'coordenadaY' deben ser valores validos dentro del lienzo
	 * Pos: Dibuja un punto con 'color' en el punto definido por (coordendaX, coordenadaY)
	 */
	void dibujarPunto(Color* color, int coordenadaX, int coordenadaY);

	/*
	 * Pre: 'coordenadaX' y 'coordenadaY' deben ser valores validos dentro del lienzo
	 * 		'nombreImagen' debe ser un path relativo al entorno donde se ejecuta el programa
	 * 		o un path absoluto. Debe contener el nombre del archivo.
	 * Pos: Pega la imagen 'nombreImagen' en las coordendas X e Y. X e Y son las coordenadas del
	 * 		punto superior izquierdo de la imagen en el lienzo.
	 */
	void pegarImagen(std::string nombreImagen, int coordenadaX, int coordenadaY);

	/*
	 * Pre: 'coordenadaX' y 'coordenadaY' deben ser valores validos dentro del lienzo
	 * 		'nombreImagen' debe ser un path relativo al entorno donde se ejecuta el programa
	 * 		o un path absoluto. Debe contener el nombre del archivo.
	 * Pos: Pega la imagen 'nombreImagen' en las coordendas X e Y. X e Y son las coordenadas del
	 * 		punto superior izquierdo de la imagen en el lienzo. 'color' determina que color de la imagen
	 * 		debe ser considerado como transparente al momento de pegarla en el lienzo.
	 */
	void pegarImagenConTransparencia(std::string nombreImagen, int coordenadaX, int coordenadaY, Color* color);

	/*
	 * Pre: 'nombreImagen' debe ser un path relativo al entorno deonde se ejecuta el programa o un path absoluto
	 * 		valido y debe contener el nombre del archivo.
	 * Pos: Guarda el dibujo del lienzo en el path indicado en 'nombreImagen' con formato BMP.
	 */
	void guardar(std::string nombreImagen);

	// Pos: Libera los recursos reservados.
	~Lienzo();
};

#endif /* LIENZO_H_ */
