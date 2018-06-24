/*
 * ComparadorDestino.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef COMPARADORDESTINO_H_
#define COMPARADORDESTINO_H_

#include "Comparador.h"
#include "destino.h"

class ComparadorDestino: public Comparador<Destino> {

public:

	bool sonIguales(Destino* destino1, Destino* destino2);
};

#endif /* COMPARADORDESTINO_H_ */
