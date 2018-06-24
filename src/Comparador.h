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
	bool sonIguales(T dato1, T dato2);
};

template<class T>
bool Comparador<T>::sonIguales(T dato1, T dato2){

	return (dato1 == dato2);
}

#endif /* COMPARADOR_H_ */
