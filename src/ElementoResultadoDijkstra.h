/*
 * ElementoResultadoDijkstra.h
 *
 *  Created on: 25 jun. 2018
 *      Author: administrador
 */

#ifndef ELEMENTORESULTADODIJKSTRA_H_
#define ELEMENTORESULTADODIJKSTRA_H_

template <class T> class ElementoResultadoDijkstra {

private:
	T dato;
	unsigned int peso;

public:
	ElementoResultadoDijkstra(T dato, unsigned int peso);
	T obtenerDato();
	unsigned int obtenerPeso();
};

template <class T>
ElementoResultadoDijkstra<T>::ElementoResultadoDijkstra(T dato, unsigned int peso){

	this->dato = dato;
	this->peso = peso;
}

template <class T>
T ElementoResultadoDijkstra<T>::obtenerDato(){
	return this->dato;
}

template <class T>
unsigned int ElementoResultadoDijkstra<T>::obtenerPeso(){
	return this->peso;
}

#endif /* ELEMENTORESULTADODIJKSTRA_H_ */
