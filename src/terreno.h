/*
 * terreno.h
 *
 *  Created on: 29 abr. 2018
 *      Author: jonathan
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "parametroConfiguracion.h"
#include "cultivo.h"

class Terreno{

	private:

		unsigned int cantidadColumnas;
		unsigned int cantidadFilas;
		unsigned int precio;
		Cultivo* terreno;

	public:

		// Constructor
		// Pre: Recibe la cantidad de columnas y filas, las cuales deben ser validas, mayores a 0
		// Post: Inicializa un terreno, con su cantidad de columnas, filas, precio y matriz dinamica
		Terreno(ParametroConfiguracion parametros);

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

		// Destructor
		// Libera la memoria solicitada
		~Terreno();

};




#endif /* TERRENO_H_ */
