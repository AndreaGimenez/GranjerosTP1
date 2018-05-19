/*
 * parametrosDibujo.h
 *
 *  Created on: 19 may. 2018
 *      Author: administrador
 */

#ifndef PARAMETROSDIBUJO_H_
#define PARAMETROSDIBUJO_H_

class ParametrosDibujo {

private:

	unsigned int anchoParcela;
	unsigned int largoParcela;
	unsigned int distanciaAlBorde;

public:
	ParametrosDibujo(unsigned int anchoParcela, unsigned int largoParcela, unsigned int distanciaAlBorde);
};

#endif /* PARAMETROSDIBUJO_H_ */
