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
	int comparar(T dato1, T dato2);
};

template<class T>
int Comparador<T>::comparar(T dato1, T dato2){

	int resultado = 0;

	if(dato1 > dato2){
		resultado = 1;
	}else if(dato1 < dato2){
		resultado = -1;
	}

	return resultado;
}

#endif /* COMPARADOR_H_ */
