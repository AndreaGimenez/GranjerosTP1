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
 * Se puede almacenar cualquier tipo de cultivo y cualquier cantidad de cada cultivo siempre y cuando la sumatoria
 * de 'obtenerCantidadAlmacenada' de todos los cultivos no supere 'obtenerCapacidad'.
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

	// Post: Crea el almacen con capacidad inicial determinada por la configuracion default del juego
	Almacen();

	/*
	 * Pre: 'capacidad' es la capacidad maxima del almacen.
	 * Post: Crea el almacen con capacidad inicial igual a 'capacidad'. Inicialmente esta vacio, a plena capacidad de almacenamiento.
	 */
	Almacen(unsigned int capacidad);

	// Post: Devuelve la capacidad maxima del almacen.
	unsigned int obtenerCapacidad();

	// Post: Devuelve el volumen que se encuentra en uso de todas las cosechas. Es la sumatoria de todas las cantidades de las cosechas almacenadas.
	unsigned int obtenerVolumenUtilizado();

	// Post: Devuelve el volumen que queda disponible para almacenaje de cualquier cosecha.
	unsigned int obtenerVolumenDisponible();

	// Post: Indica si el almacen esta completamente ocupado.
	bool estaLleno();

	// Post: Indica si el almacen esta completamente vacio.
	bool estaVacio();

	// Post: Devuelve la cantidad almacenada de 'cultivo'.
	unsigned int obtenerCantidadAlmacenada(Cultivo* cultivo);

	// Post: Indica si hay capacidad suficiente para almacenar 1 unidad de la cosecha.
	bool puedeAlmacenarCosecha(Cultivo* cultivoAAlmacenar);

	// Post: Indica si hay capacidad suficiente para almacenar 'cantidadAAlmacenar' unidades de cosecha.
	bool puedeAlmacenarCosecha(Cultivo* cultivoAAlmacenar, unsigned int cantidadAAlmacenar);

	// Post: Incrementa en 1 la cantidad almacenada de 'cultivoAAlmacenar'.
	bool almacenarCosecha(Cultivo* cultivoAAlmacenar);

	// Post: Incrementa en 'cantidadAAlmacenar' la cantidad almacenada de 'cultivoAAlmacenar'.
	bool almacenarCosecha(Cultivo* cultivoAAlmacenar, unsigned int cantidadAAlmacenar);

	/*
	 * Post: Envia toda la cantidad almacenada de 'cultivoAEnviar'. El valor devuelto es la rentabilidad obtenida
	 *		 del envio. Si 'cultivoAEnviar' no se encuentra almacenado o la cantidad almacenada es 0 devuelve 0.
	 */
	unsigned int enviarCosecha(Cultivo* cultivoAEnviar);

	/*
	 * Post: Envia 'cantidadAEnviar' unidades del cultivo indicado. El valor devuelto es la rentabilidad obtenida
	 *		 del envio. Si 'cultivoAEnviar' no se encuentra almacenado o la cantidad almacenada es menor a 'cantidadAEnviar' devuelve 0.
	 */
	unsigned int enviarCosecha(Cultivo* cultivoAEnviar, unsigned int cantidadAEnviar);

	/*
	 * Post: Envia toda la cantidad almacenada en 'unidadAlmacenamientoCosechaAEnviar'. El valor devuelto es la rentabilidad obtenida
	 *		 del envio. Si la cantidad almacenada es 0 devuelve 0.
	 */
	unsigned int enviarCosecha(UnidadAlmacenamiento* unidadAlmacenamientoCosechaAEnviar);

	/*
	 * Post: Envia 'cantidadAEnviar' unidades de 'unidadAlmacenamientoCosechaAEnviar'. El valor devuelto es la rentabilidad obtenida
	 *		 del envio. Si la cantidad almacenada es menor a 'cantidadAEnviar' devuelve 0.
	 */
	unsigned int enviarCosecha(UnidadAlmacenamiento* unidadAlmacenamientoCosechaAEnviar, unsigned int cantidadAEnviar);

	/*
	 * Post: Envia todas las cosechas almacenadas. El valor devuelto es la rentabilidad obtenida
	 *		 del envio. Si no hay ninguna cosecha almacenada o las cantidades son 0 devuelve 0.
	 */
	unsigned int enviarCosechas();

	/*
	 * Pre: 'cultivoAEnviar' debe encontrarse almacenado.
	 * Post: Obtiene el costo de enviar 'obtenerCantidadAlmacenada' de 'cultivoAEnviar' de acuerdo a los precios de los destinos definidos en 'destinos.txt'.
	 * 		 En caso que el cultivo no esté almacenado devuelve 0.
	 */
	unsigned int obtenerCostoEnvio(Cultivo* cultivoAEnviar);

	/*
	 * Pre: 'cultivoAEnviar' debe encontrarse almacenado.
	 * Post: Obtiene el costo de enviar 'cantidadAEnviar' de 'cultivoAEnviar' de acuerdo a los precios de los destinos definidos en 'destinos.txt'.
	 * 		En caso que el cultivo no esté almacenado devuelve 0.
	 */
	unsigned int obtenerCostoEnvio(Cultivo* cultivoAEnviar, unsigned int cantidadAEnviar);

	// Post: Aumenta la capacidad maxima de almacenamiento en 'unidadesAmpliacion'. La nueva capacidad maxima va a ser 'obtenerCapacidad' + 'unidadesAmpliacion'.
	void ampliarAlmacen(unsigned int unidadesAmpliacion);

	// Post: Libera los recursos reservados.
	~Almacen();
};

#endif /* ALMACEN_H_ */
