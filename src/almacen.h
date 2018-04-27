/*
 * Almacen.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

#ifndef NULL
#define NULL 0
#endif

#include "lista.h"
#include "unidadAlmacenamiento.h"
#include "destino.h"
#include "cultivo.h"

/*
 * 'Almacen' representa un espacio de almacenamiento de cosechas.
 * Se puede almacenar cualquier tipo de cultivo y cualquier cantidad de cada cultivo siempre y cuando la sumatoria de 'obtenerCantidadAlmacenada' de todos los cultivos no supere 'obtenerCapacidad'.
 * A medida que se almacenan cosechas se reduce la capacidad restante del almacen.
 */
class Almacen{

private:

	unsigned int capacidad;
	unsigned int volumenUtilizado;
	Lista<UnidadAlmacenamiento*> cosechasAlmacenadas;

	UnidadAlmacenamiento* buscarUnidadAlmacenamiento(Cultivo* cultivo);
	void inicializar(unsigned int capacidad);

public:

	//Pos: Crea el almacen con capacidad inicial determinada por la configuracion default del juego
	Almacen();

	//Pre: 'capacidad' es la capacidad maxima del almacen.
	//Pos: Crea el almacen con capacidad inicial igual a 'capacidad'. Inicialmente esta vacio, a plena capacidad de almacenamiento.
	Almacen(unsigned int capacidad);

	//Pos: Devuelve la capacidad maxima del almacen.
	unsigned int obtenerCapacidad();

	//Pos: Devuelve el volumen que se encuentra en uso de todas las cosechas. Es la sumatoria de todas las cantidades de las cosechas almacenadas.
	unsigned int obtenerVolumenUtilizado();

	//Pos: Devuelve el volumen que queda disponible para almacenaje de cualquier cosecha.
	unsigned int obtenerVolumenDisponible();

	//Pos: Indica si el almacen esta completamente ocupado.
	bool estaLleno();

	//Pos: Indica si el almacen esta completamente vacio.
	bool estaVacio();

	//Pos: Devuelve la cantidad almacenada de 'cultivo'.
	unsigned int obtenerCantidadAlmacenada(Cultivo* cultivo);

	//Pos: Incrementa en 1 la cantidad almacenada de 'cultivoAAlmacenar'.
	bool almacenarCosecha(Cultivo* cultivoAAlmacenar);

	//Pos: Incrementa en 'cantidadAAlmacenar' la cantidad almacenada de 'cultivoAAlmacenar'.
	bool almacenarCosecha(Cultivo* cultivoAAlmacenar, unsigned int cantidadAAlmacenar);

	//Pre: 'obtenerCantidadAlmacenada' de 'cultivoAEnviar' debe ser mayor o igual que 1.
	//Post: Envia toda la cantidad almacenada de 'cultivoAEnviar'. Si 'cultivoAEnviar' no se encuentra almacenado o la cantidad almacenada es 0 devuelve 'false'.
	bool enviarCosecha(Cultivo* cultivoAEnviar);

	//Pre: 'cantidadAEnviar' debe ser menor o igual que 'obtenerCantidadAlmacenada' de 'cultivoAEnviar'
	//Pos: Envia la cantidad almacenada el cultivo indicado. Si 'cultivoAEnviar' no se encuentra almacenado o la cantidad almacenada es menor a 'cantidadAEnviar' devuelve 'false'.
	bool enviarCosecha(Cultivo* cultivoAEnviar, unsigned int cantidadAEnviar);

	//Pre: 'cultivoAEnviar' debe encontrarse almacenado.
	//Pos: Obtiene el costo de enviar 'obtenerCantidadAlmacenada' de 'cultivoAEnviar' de acuerdo a los precios de los destinos definidos en 'destinos.txt'.
	//	   En caso que el cultivo no esté almacenado devuelve 0.
	unsigned int obtenerCostoEnvio(Cultivo* cultivoAEnviar);

	//Pre: 'cultivoAEnviar' debe encontrarse almacenado.
	//Pos: Obtiene el costo de enviar 'cantidadAEnviar' de 'cultivoAEnviar' de acuerdo a los precios de los destinos definidos en 'destinos.txt'.
	//	   En caso que el cultivo no esté almacenado devuelve 0.
	unsigned int obtenerCostoEnvio(Cultivo* cultivoAEnviar, unsigned int cantidadAEnviar);

	//Pos: Aumenta la capacidad maxima de almacenamiento en 'unidadesAmpliacion'. La nueva capacidad maxima va a ser 'obtenerCapacidad' + 'unidadesAmpliacion'.
	void ampliarAlmacen(unsigned int unidadesAmpliacion);

	~Almacen();
};

#endif /* ALMACEN_H_ */
