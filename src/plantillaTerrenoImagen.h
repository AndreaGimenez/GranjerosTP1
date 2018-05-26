#ifndef PLANTILLATERRENOIMAGEN_H_
#define PLANTILLATERRENOIMAGEN_H_

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

	PlantillaTerrenoImagen();

public:

	static unsigned int obtenerDistanciaHorizontalAlBorde();
	static unsigned int obtenerDistanciaVerticalAlBorde();
	static unsigned int obtenerDistanciaParcelaCoordenadaX();
	static unsigned int obtenerDistanciaParcelaCoordenadaY();
	static unsigned int obtenerAltoImagenNumeroCoordenada();
	static unsigned int obtenerAnchoImagenNumeroCoordenada();
	static unsigned int obtenerEspacioDigitosCoordenada();
	static unsigned int obtenerAnchoParcela();
	static unsigned int obtenerLargoParcela();
	static unsigned int obtenerAnchoCultivo();
	static unsigned int obtenerSeparacionEntreCultivos();
	static unsigned int obtenerAnchoImagenNombreCultivo();
	static unsigned int obtenerAltoImagenNombreCultivo();
	static unsigned int obtenerAnchoMarcaArado();
	static unsigned int obtenerSeparacionEntreMarcasArado();
	static unsigned int obtenerAnchoPoste();
	static unsigned int obtenerLargoPoste();
	static unsigned int obtenerAnchoImagenRiego();
	static unsigned int obtenerAltoImagenRiego();
	static unsigned int obtenerAnchoImagenHoz();
	static unsigned int obtenerAltoImagenHoz();
	static unsigned int obtenerAnchoTerreno();
	static unsigned int obtenerLargoTerreno();
};

#endif /* PLANTILLATERRENOIMAGEN_H_ */
