/*
 * VerticeAdyacente.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef VERTICEADYACENTE_H_
#define VERTICEADYACENTE_H_

#include "Vertice.h"

template <class T> class Vertice;

template<class T> class VerticeAdyacente {

private:

	Vertice<T>* vertice;
	unsigned int peso;

public:

	VerticeAdyacente(Vertice<T>* vertice, unsigned int peso);

	Vertice<T>* obtenerVertice();
	unsigned int obtenerPeso();
};

template<class T>
VerticeAdyacente<T>::VerticeAdyacente(Vertice<T>* vertice, unsigned int peso){

	this->vertice = vertice;
	this->peso = peso;
}

template<class T>
Vertice<T>* VerticeAdyacente<T>::obtenerVertice(){

	return this->vertice;
}

template<class T>
unsigned int VerticeAdyacente<T>::obtenerPeso(){

	return this->peso;
}

#endif /* VERTICEADYACENTE_H_ */
