/*
 * Destino.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef DESTINO_H_
#define DESTINO_H_

#include <string>

/*
 * 'Destino' representa cada uno de lso lugares a los que se puede enviar una cosecha que se encuentra almacenada.
 * Cada destino esta asociado a un cultivo. Tiene el precio que acarrea el envio una unidad del cultivo
 * y la distancia que es necesario recorrer.
 */
class Destino {

private:

	std::string nombre;
	unsigned int distancia;
	unsigned int precio;
	std::string nombreCultivo;

public:

	//Pre: 'nombre' y 'cultivo' no pueden estar vacios.
	//Pos: Crea un nuevo destino con los parametros indicados.
	Destino(std::string nombre, unsigned int distacia, unsigned int precio, std::string nombreCultivo);

	//Pos: Devuelve la distancia en KM.
	unsigned int obtenerDistancia();

	//Pos: Devuelve el nombre del destino.
	std::string obtenerNombre();

	//Pos: Devuelve la cantidad de monedas por unidad a enviar al destino que costara el envio.
	unsigned int obtenerPrecio();

	//Pos: Devuelve el nombre del cultivo asociado al destino.
	std::string obtenerNombreCultivo();
};

#endif /* DESTINO_H_ */
