/*
 * Almacen.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

class Almacen{

private:

	unsigned int capacidad;
	unsigned int volumenUtilizado;

public:

	//Pre: 'capacidad' es la capacidad maxima del almacen, medida en ?
	//Pos: Crea el amlacen con la capacidad maxima indica. Inicialmente esta vacio, a plena capacidad.
	Almacen(unsigned int capacidad);

	//Pos: devuelve la capacidad maxima del almacen
	unsigned int getCapacidad();

	//Pre: recibe la nueva capacidad maxima del almacen
	//Pos: cambia la capacidad maxima del almacen al nuevo valor
	void setCapacidad(unsigned int capacidad);

	//Pos: devuelve el volumen que se encuentra en uso
	unsigned int getVolumenUtilizado();

	//Pre: recibe el nuevo volumen utilizado
	//Pos: cambia el volumen que se encuentra en uso al valor indicado
	void setVolumenUtilizado(unsigned int volumenUtilizado);

	//Pos: indica si el almacen esta completamente ocupado
	bool estaLleno();

	//Pos: indica si el almacen esta completamente vacio
	bool estaVacio();

	void almacenarCosechas();

	void enviarCosechas();

	void imprimirAlmacen();

	void ampliarAlmacen();
};

#endif /* ALMACEN_H_ */
