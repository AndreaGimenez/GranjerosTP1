#ifndef CREADORIMAGEN_H_
#define CREADORIMAGEN_H_

#ifndef NULL
#define NULL 0
#endif

#include "lienzo.h"
#include "paletaColores.h"

/*
 * Herramienta que permite pegar imagenes, dibujar figuras y lineas sobre un lienzo.
 * Ofrece una paleta con colores predefinidos.
 * Una vez finalizado el dibujo se puede guardar la imagen en formato bmp.
 *
 * Para comenzar un nuevo dibujo es necesario llamar al metodo 'crearNuevaImagen'
 * esto descartara el lienzo previo y creara uno nuevo.
 */
class CreadorImagen {

private:

	Lienzo* lienzo;
	PaletaColores* paletaColores;

public:

	// Pos: Inicializa el creador con la paleta de colores y sin lienzo.
	CreadorImagen();

	// Pos: Inicializa el lienzo para poder comenzar a dibujar.
	void crearNuevaImagen(unsigned int alto, unsigned int ancho, unsigned int calidad);

	/*
	 * Pre: 'nombreImagen' es el directorio donde se guardara la imagen, debe contener el nombre del archivo.
	 * Pos: Guarda el dibujo del lienzo con formato BMP.
	 */
	void guardarImagen(std::string nombreImagen);

	//Pos: Devuelve color correspondiente al parametro.
	Color* obtenerColor(EColor color);

	/*
	 * Pos: Dibuja una linea horizontal sobre el lienzo. Se dibuja del color indicado en 'color'.
	 *		El largo de la linea sera el indicado en 'longitud'. Se dibuja a partir del punto
	 *		definido por 'coordenadaX' y 'coordenadaY'.
	 */
	void dibujarLineaHorizontal(Color* color, int longitud, int coordenadaX, int coordenadaY);

	/*
	 * Pos: Dibuja una linea vertical sobre el lienzo. Se dibuja del color indicado en 'color'.
	 *		El largo de la linea sera el indicado en 'longitud'. Se dibuja a partir del punto
	 *		definido por 'coordenadaX' y 'coordenadaY'.
	 */
	void dibujarLineaVertical(Color* color, int longitud, int coordenadaX, int coordenadaY);

	/*
	 * Pos: Dibuja un rectangulo sobre el lienzo. Se dibuja del color indicado en 'color'.
	 *		La base del rectangulo esta definida en 'ancho' y el alto en 'largo'.
	 *		El punto definido por 'coordenadaX' y 'coordenadaY' es el vertice superior izquierdo
	 *		del rectangulo.
	 */
	void dibujarRectangulo(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color);

	/*
	 * Pos: Dibuja un rectangulo con relleno sobre el lienzo. Tanto el borde como el relleno son del
	 * 		color indicado en 'color'. La base del rectangulo esta definida en 'ancho' y el alto en 'largo'.
	 *		El punto definido por 'coordenadaX' y 'coordenadaY' es el vertice superior izquierdo
	 *		del rectangulo.
	 */
	void dibujarRectanguloConRelleno(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color);

	/*
	 * Pos: Dibuja un rectangulo con relleno y textura sobre el lienzo. Tanto el borde como el relleno son del
	 * 		color indicado en 'color'. 'color2' indica el color de la textura. La textura son pixeles dibujados
	 * 		aleatoreamente sobre el relleno.
	 * 		La base del rectangulo esta definida en 'ancho' y el alto en 'largo'.
	 *		El punto definido por 'coordenadaX' y 'coordenadaY' es el vertice superior izquierdo
	 *		del rectangulo.
	 */
	void dibujarRectanguloConRelleno(int ancho, int largo, int coordenadaX, int coordenadaY, Color* color, Color* color2);

	/*
	 * Pos: Pega la imagen localizada en 'nombreImagen' sobre el lienzo. El punto determinado por 'coordenadaX'
	 * 		y 'coordenadaY' determina el punto superior izquierdo donde se pegará la imagen.
	 */
	void pegarImagen(std::string nombreImagen, int coordenadaX, int coordenadaY);

	/*
	 * Pos: Pega la imagen localizada en 'nombreImagen' sobre el lienzo.
	 * 		El parametro 'color' es un color de la imagen que debe ser tomado como transparente al momento de pegarla
	 * 		en el lienzo, por lo tanto no se vera ese color en la imagen pegada en el lienzo.
	 * 		El punto determinado por 'coordenadaX'
	 * 		y 'coordenadaY' determina el punto superior izquierdo donde se pegará la imagen.
	 */
	void pegarImagenConTransparencia(std::string nombreImagen, int coordenadaX, int coordenadaY, Color* color);

	// Pos: Libera los recursos reservados.
	~CreadorImagen();
};

#endif /* CREADORIMAGEN_H_ */
