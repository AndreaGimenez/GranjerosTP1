/*
 * tanque.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#ifndef TANQUE_H_
#define TANQUE_H_

/*
 * 'Tanque' es un espacio de almacenamiento de agua.
 * Las unidades de riego sobrantes de cada turno son almacenadas en el tanque hasta
 * que el mismo se llena.
 * El agua almacenada podra ser utilizada en las rondas posteriores para regar parcelas.
 */
class Tanque{

	private:

		unsigned int capacidad;
		unsigned int volumenOcupado;

	public:

		// Post: el tanque fue creado. Puede almacenar "capacidad" unidades de riego y esta vacio.
		Tanque(unsigned int capacidad);

		// Post: devuelve si el tanque esta o no lleno
		bool estaLLeno();

		// Post: devuelve si el tanque esta o no vacio
		bool estaVacio();

		// Post:devuelve cual es la capacidad utilizada del tanque
		unsigned int volumenUtilizado();

		// Post:devuelve cual es el volumen libre del tanque
		unsigned int volumenLibre();

		/*
		 * Post: Se almacena el agua en el tanque. Si no tiene suficiente espacio,
		 * 		 se almacena hasta que se llena y se descarta el excedente.
		 * 		 Si esta lleno, se descarta toda la nueva agua recibida.
		 */
		void almacenarAgua(unsigned int cantidadDeAgua);

		/*
		 * Post: Devuelve false si el agua alamcenada es menos que "aguaAUtilizar".
		 * 		 Cuando agua alamcenada es mayor o igual que "aguaAUtilizar",
		 * 		 el tanque queda con "aguaAUtilizar" menos unidades de riego almacenadas.
		 */
		bool usarAguaAlmacenada(unsigned int aguaAUtilizar);

		// Post: Imprime por pantalla los valores del tanque
		void imprimirEstado();

		/*
		 * Pre: "nuevaCapacidad" es un valor valido.
		 * Post: El tanque fue ampliado. La capacidad del tanque es ahora "nuevaCapacidad" mayor.
		 */
		void ampliarTanque(unsigned int nuevaCapacidad);
};



#endif /* TANQUE_H_ */
