/*
 * ElementoResultadoDijkstra.h
 *
 *  Created on: 25 jun. 2018
 *      Author: administrador
 */

#ifndef ELEMENTODIJKSTRA_H_
#define ELEMENTODIJKSTRA_H_

template <class T> class ElementoDijkstra {

private:
	T dato;
	unsigned int peso;

public:
	ElementoDijkstra(T dato, unsigned int peso);
	T obtenerDato();
	unsigned int obtenerPeso();
};

template <class T>
ElementoDijkstra<T>::ElementoDijkstra(T dato, unsigned int peso){

	this->dato = dato;
	this->peso = peso;
}

template <class T>
T ElementoDijkstra<T>::obtenerDato(){
	return this->dato;
}

template <class T>
unsigned int ElementoDijkstra<T>::obtenerPeso(){
	return this->peso;
}

#endif /* ELEMENTODIJKSTRA_H_ */
