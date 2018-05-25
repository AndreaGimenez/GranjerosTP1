#ifndef COLOR_H_
#define COLOR_H_

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
