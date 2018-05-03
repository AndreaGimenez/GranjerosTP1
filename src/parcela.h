/*
 * parcela.h
 *
 *  Created on: 2 may. 2018
 *      Author: administrador
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "cultivo.h"

namespace parcela{

	enum Estado{

		LIMPIA = 0,
		SEMBRADA,
		COSECHADA,
		PODRIDA,
		SECA
	};
}
class Parcela {

private:

	Cultivo* cultivo;
	parcela::Estado estado;
	bool regada;
	unsigned int tiempoCosechada;
	unsigned int tiempoSembrada;

public:

	Parcela();
};

#endif /* PARCELA_H_ */
