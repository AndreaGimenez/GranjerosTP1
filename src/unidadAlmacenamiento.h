/*
 * unidadAlmacenamiento.h
 *
 *  Created on: 26 abr. 2018
 *      Author: administrador
 */

#ifndef UNIDADALMACENAMIENTO_H_
#define UNIDADALMACENAMIENTO_H_

#include "cultivo.h"

/*
 * 'UnidadAlmacenamiento' representa un subconjunto del almacenamiento total de un 'Almacen'. En ella se almacena la cantidad cosechada de una cosecha determinada.
 * Existe una 'UnidadAlmacenamiento' para cada cosecha.
 */
class UnidadAlmacenamiento {

private:

	Cultivo* cultivo;
	unsigned int cantidadAlmacenada;

public:

	//Pos: Crea una nueva unidad de almacenamiento para 'cultivo'. La cantidad inicial almacenada es 0.
	UnidadAlmacenamiento(Cultivo* cultivo);

	//Pos: Devuelve el cultivo que se encuentra almacenado en la unidad de almacenamiento.
	Cultivo* obtenerCultivo();

	//Pos: Aumenta en 'cantidadAAlmacenar' la cantidad almacenada de la cosecha.
	void almacenar(unsigned int cantidadAAlmacenar);

	//Pre: 'cantidadADesalmacenar' debe ser menor o igual a 'obtenerCantidadAlmacenada'.
	//Pos: Se reduce en 'cantidadADesalmacenar' la cantidad almacenada de la cosecha. Devuelve 'false' si 'cantidadADesalmacenar' es mayor que 'obtenerCantidadAlmacenada'.
	bool desalmacenar(unsigned int cantidadADesalmacenar);

	//Pos: Devuelve la cantidad almacenada.
	unsigned int obtenerCantidadAlmacenada();
};

#endif /* UNIDADALMACENAMIENTO_H_ */
