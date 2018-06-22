/*
 * Arista.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef ARISTA_H_
#define ARISTA_H_

template<class T> class Arista {

private:

	Vertice<T>* origen;
	Vertice<T>* destino;
	unsigned int peso;

public:

	Arista(T origen, T destino, unsigned int peso);

	Vertice<T>* obtenerVerticeOrigen();
	Vertice<T>* obtenerVerticeDestino();
	unsigned int obtenerPeso();
};

template<class T>
Arista<T>::Arista(T origen, T destino, unsigned int peso){

	this->origen = origen;
	this->destino = destino;
	this->peso = peso;
}

template<class T>
Vertice<T>* Arista<T>::obtenerVerticeOrigen(){

	return this->origen;
}

template<class T>
Vertice<T>* Arista<T>::obtenerVerticeDestino(){

	return this->destino;
}

template<class T>
unsigned int Arista<T>::obtenerPeso(){

	return this->peso;
}

#endif /* ARISTA_H_ */
