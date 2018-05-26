#ifndef COLOR_H_
#define COLOR_H_

/*
 * Representa un color basado en el modelo RGB. Cada color es una mezcla de los 3 colores primarios de la luz
 * ROJO, VERDE y AZUL. Además se puede indicar la opacidad del color.
 */
class Color {

private:

	unsigned char opacidad;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:

	Color(unsigned char rojo, unsigned char verde, unsigned char azul, unsigned char opacidad);

	unsigned char obtenerRojo();
	unsigned char obtenerVerde();
	unsigned char obtenerAzul();
	unsigned char obtenerOpacidad();
};

#endif /* COLOR_H_ */
