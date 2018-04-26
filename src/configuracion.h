/*
 * Configuracion.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include "cultivo.h"
#include "destino.h"
#include "lista.h"

class Configuracion {

private:

	static Lista<Cultivo*>* cultivos;
	static Lista<Destino*>* destinos;


	static void cargarCultivos();
	static void cargarDestinos();

	//Para evitar que la instancien
	Configuracion();

public:

	static void inicializar();

	static Lista<Cultivo*>* getCultivos();

	static Lista<Destino*>* getDestinos();

	static void destruirCultivos();

	static void destruirDestinos();

	~Configuracion();
};

#endif /* CONFIGURACION_H_ */
