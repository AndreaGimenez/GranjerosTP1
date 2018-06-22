/*
 * Comparador.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef COMPARADOR_H_
#define COMPARADOR_H_

template<class T> class Comparador{

public:
	virtual bool sonIguales(T dato1, T dato2);
	virtual ~Comparador();
};

#endif /* COMPARADOR_H_ */
