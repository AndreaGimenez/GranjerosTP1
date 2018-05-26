#ifndef CREADORACCIONES_H_
#define CREADORACCIONES_H_

#ifndef NULL
#define NULL 0
#endif

#include "accion.h"

/*
 * Clase que permite generar acciones a partir de definiciones hechas previamente.
 * Una accion esta definida por su tipo y la cantidad y tipos de parametros que utiliza.
 */
class CreadorAcciones {

private:

	static unsigned int cantidadAcciones;
	static Accion** acciones;

	//Para evitar que sea instanciada el constructor es private, debe usarse de manera estatica.
	CreadorAcciones();

	// Pos: Libera memoria pedida para los destinos
	static void destruirAcciones();

public:

	// Pos: Inicializa las acciones disponibles para realizar.
	static void inicializar();

	// Pos: Devuelve una copia de la accion solicitada, los parametros no se encuentran inicializados.
	static Accion* crearNuevaAccion(accion::Tipo tipoAccion);

	// Pos: Libera los recursos reservados.
	~CreadorAcciones();
};

#endif /* CREADORACCIONES_H_ */
