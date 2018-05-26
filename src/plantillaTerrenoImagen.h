#ifndef PLANTILLATERRENOIMAGEN_H_
#define PLANTILLATERRENOIMAGEN_H_

/*
 * Define las dimensiones de la imagen de un terreno.
 * Define las dimensiones qeu tienen las parcelas y las imagenes que se
 * utilizan para representar el terreno.
 */
class PlantillaTerrenoImagen {

private:

	static unsigned int distanciaHorizontalAlBorde;
	static unsigned int distanciaVerticalAlBorde;
	static unsigned int distanciaParcelaCoordenadaX;
	static unsigned int distanciaParcelaCoordenadaY;
	static unsigned int altoImagenNumeroCoordenada;
	static unsigned int anchoImagenNumeroCoordenada;
	static unsigned int espacioDigitosCoordenada;
	static unsigned int anchoParcela;
	static unsigned int largoParcela;
	static unsigned int anchoCultivo;
	static unsigned int separacionEntreCultivos;
	static unsigned int anchoImagenNombreCultivo;
	static unsigned int altoImagenNombreCultivo;
	static unsigned int anchoMarcaArado;
	static unsigned int separacionEntreMarcasArado;
	static unsigned int anchoPoste;
	static unsigned int largoPoste;
	static unsigned int anchoImagenRiego;
	static unsigned int altoImagenRiego;
	static unsigned int anchoImagenHoz;
	static unsigned int altoImagenHoz;

	/*
	 * El constructor es privado para que no se pueda instanciar,
	 * dado que no es necesario
	 */
	PlantillaTerrenoImagen();

public:

	/*
	 * Pos: Devuelve la distancia que hay entre el terreno y el borde
	 * 		izquierdo y derecho de la imagen.
	 */
	static unsigned int obtenerDistanciaHorizontalAlBorde();

	/*
	 * Pos: Devuelve la distancia que hay entre el terreno y el borde
	 * 		superior e inferior de la imagen.
	 */
	static unsigned int obtenerDistanciaVerticalAlBorde();

	/*
	 * Pos: Devuelve la distancia que hay entre los valores de las coordenadas
	 * 		X que se dibujan en la parte superior del terreno y la primera
	 * 		fila de parcelas.
	 */
	static unsigned int obtenerDistanciaParcelaCoordenadaX();

	/*
	 * Pos: Devuelve la distancia que hay entre los valores de las coordenadas
	 * 		Y que se dibujan a la izquierda del terreno y la primera
	 * 		columna de parcelas.
	 */
	static unsigned int obtenerDistanciaParcelaCoordenadaY();

	/*
	 * Pos: Devuelve el alto en pixeles que tienen las imagenes de los
	 * 		numeros de las coordenadas.
	 */
	static unsigned int obtenerAltoImagenNumeroCoordenada();

	/*
	 * Pos: Devuelve el ancho en pixeles que tienen las imagenes de los
	 * 		numeros de las coordenadas.
	 */
	static unsigned int obtenerAnchoImagenNumeroCoordenada();

	/*
	 * Pos: Devuelve el espacio que hay entre los digitos de una coordenada
	 */
	static unsigned int obtenerEspacioDigitosCoordenada();

	/*
	 * Pos: Devuelve el ancho en pixeles de una parcela
	 */
	static unsigned int obtenerAnchoParcela();

	/*
	 * Pos: Devuelve el alto en pixeles de una parcela
	 */
	static unsigned int obtenerLargoParcela();

	/*
	 * Pos: Devuelve el ancho en pixeles de la marca del cultivo
	 * 		en una parcela que se encuentra sembrada.
	 */
	static unsigned int obtenerAnchoCultivo();

	/*
	 * Pos: Devuelve la separacion entre las marcas de los cultivos
	 * 		de una parcela sembrada.
	 */
	static unsigned int obtenerSeparacionEntreCultivos();

	/*
	 * Pos: Devuelve el ancho en pixeles de las imagenes que tienen
	 * 		los nombres de los cultivos
	 */
	static unsigned int obtenerAnchoImagenNombreCultivo();

	/*
	 * Pos: Devuelve el alto en pixeles de las imagenes que tienen
	 * 		los nombres de los cultivos
	 */
	static unsigned int obtenerAltoImagenNombreCultivo();

	/*
	 * Pos: Devuelve el ancho en pixeles de la marca del arado
	 * 		en una parcela que se encuentra cosechada.
	 */
	static unsigned int obtenerAnchoMarcaArado();

	/*
	 * Pos: Devuelve la separacion entre las marcas del arado
	 * 		de una parcela cosechada.
	 */
	static unsigned int obtenerSeparacionEntreMarcasArado();

	/*
	 * Pos: Devuelve el ancho en pixeles de los postes de las parcelas.
	 */
	static unsigned int obtenerAnchoPoste();

	/*
	 * Pos: Devuelve el largo en pixeles de los postes de las parcelas.
	 */
	static unsigned int obtenerLargoPoste();

	/*
	 * Pos: Devuelve el ancho en pixeles de la imagen del riego
	 */
	static unsigned int obtenerAnchoImagenRiego();

	/*
	 * Pos: Devuelve el alto en pixeles de la imagen del riego
	 */
	static unsigned int obtenerAltoImagenRiego();

	/*
	 * Pos: Devuelve el ancho en pixeles de la imagen de la hoz
	 */
	static unsigned int obtenerAnchoImagenHoz();

	/*
	 * Pos: Devuelve el alto en pixeles de la imagen de la hoz
	 */
	static unsigned int obtenerAltoImagenHoz();

	/*
	 * Pos: Devuelve el ancho total del terreno teniendo en cuenta
	 * 		la cantidad de parcelas, el ancho de las parcelas y las
	 * 		distancias a los bordes de la imagen.
	 */
	static unsigned int obtenerAnchoTerreno();

	/*
	 * Pos: Devuelve el largo total del terreno teniendo en cuenta
	 * 		la cantidad de parcelas, el ancho de las parcelas y las
	 * 		distancias a los bordes de la imagen.
	 */
	static unsigned int obtenerLargoTerreno();
};

#endif /* PLANTILLATERRENOIMAGEN_H_ */
