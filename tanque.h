/*
 * tanque.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef TANQUE_H_
#define TANQUE_H_

#include "partida.h"

class Tanque{
	private:
		unsigned int capacidad;
		unsigned int volumenOcupado;

	public:
		//constructor
		//Pre: -
		//Post: el tanque fue creado. Puede almacenar "capacidad" unidades de riego y está vacío.
		Tanque(unsigned int capacidad);

		//Pre: -
		//Post: devuelve si el tanque está o no lleno
		bool estaLLeno();

		//Pre:
		//Post: devuelve si el tanque está o no vacio
		bool estaVacio();

		//Pre:
		//Post:devuelve cual es la capacidad utilizada del tanque
		unsigned int volumenUtilizado();

		//Pre:
		//Post:devuelve cual es el volumen libre del tanque
		unsigned int volumenLibre();

		//Pre:
		//Post: Se almacena el agua en el tanque. Si no tiene suficiente espacio,
		//		se almacena hasta que se llena y se descarta el excedente.
		//		Si esta lleno, se descarta toda la nueva agua recibida.
		void almacenarAgua(unsigned int cantidadDeAgua);

		//Pre:
		//Post: Devuelve false si el agua alamcenada es menos que "aguaAUtilizar".
		//		Cuando agua alamcenada es mayor o igual que "aguaAUtilizar",
		//		el tanque queda con "aguaAUtilizar" menos unidades de riego almacenadas.
		bool usarAguaAlmacenada(unsigned int aguaAUtilizar);

		//Pre:
		//Post: Imprime por pantalla los valores del tanque
		void imprimirEstado();

	private:
		//Pre: "nuevaCapacidad" es un valor valido.
		//Post: El tanque fue ampliado. La capacidad del tanque es ahora "nuevaCapacidad" mayor.
		void ampliarTanque(unsigned int nuevaCapacidad);

		//Pre: La dificultad del juego es un entero que pertenece al intervalo [1;3]
		//Post: Se calcula la capacidad inicial del tanque
		unsigned int capacidadInicial(Partida partidaActual) ;
};



#endif /* TANQUE_H_ */
