/*
 * terreno.h
 *
 *  Created on: 29 abr. 2018
 *      Author: jonathan
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "parcela.h"

class Terreno{

	private:

		unsigned int cantidadColumnas;
		unsigned int cantidadFilas;
		//unsigned int precio;
		Parcela** parcelas;

	public:

		// Constructor
		// Pre: Recibe la cantidad de columnas y filas, las cuales deben ser validas, mayores a 0
		// Post: Inicializa un terreno, con su cantidad de columnas, filas, precio y matriz dinamica
		Terreno();

		// Post: Devuelve la cantidad de columnas
		unsigned int obtenerCantidadColumnas();

		// Post: Devuelve la cantidad de filas
		unsigned int obtenerCantidadFilas();

		// Post: Devuelve el precio actual del terreno
		unsigned int obtenerPrecio();

		// Post: Devuelve la cantidad de Parcelas que tiene el terreno
		unsigned int obtenerCantidadParcelas();

		// Post: Devuelve la cantidad de cultivos que se encuentran actualemnte en el terreno
		unsigned int obtenerCantidadCultivos();

		// Pre: Coordenadas debe tener el formato "x,y", donde x es la fila e y la columna
		//		x no puede ser mayor que 'obtenerCantidadFilas' e 'y' no puede ser mayor que 'obtenerCantidadColumnas'
		// Post: Devuelve la parcela con coordenadas 'coordenadas'. Si la parcela no existe devuelve NULL.
		Parcela* buscarParcela(std::string coordenadas);

		// Destructor
		// Libera la memoria solicitada
		~Terreno();
};




#endif /* TERRENO_H_ */
