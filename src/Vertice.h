/*
 * Vertice.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include "lista.h"

template<class T> class Vertice {

private:

	Lista<VerticeAdyacente<T>*>* adyacencias;
	T dato;

public:
	Vertice(T dato);

	T obtenerDato();
	void agregarAdyacencia(Arista<T>* arista);
	bool existeAdyacencia(Vertice<T>* vertice, Comparador<T>* comparador);
	bool tieneAlgunaAdyacencia();

	~Vertice();
};

template<class T>
Vertice<T>::Vertice(T dato){

	this->adyacencias = new Lista<VerticeAdyacente*>;
	this->dato = dato;
}

template<class T>
T Vertice<T>::obtenerDato(){

	return this->dato;
}

template<class T>
void Vertice<T>::agregarAdyacencia(Arista<T>* arista){

	VerticeAdyacente* nuevaAdyacencia = new VerticeAdyacente(arista->obtenerVerticeDestino(), arista->obtenerPeso());
	this->adyacencias->agregar(nuevaAdyacencia);
}

template<class T>
bool Vertice<T>::existeAdyacencia(Vertice<T>* vertice, Comparador<T>* comparador){

	bool existeAdyacencia = false;

	this->adyacencias->iniciarCursor();
	while(this->adyacencias->avanzarCursor() && !existeAdyacencia){

		VerticeAdyacente<T>* verticeAdyacente = this->adyacencias->obtenerCursor();
		existeAdyacencia = comparador->sonIguales(verticeAdyacente, vertice);
	}

	return existeAdyacencia;
}

template<class T>
bool Vertice<T>::tieneAlgunaAdyacencia(){

	return (!this->adyacencias->estaVacia());
}

template<class T>
Vertice<T>::~Vertice(){

	this->adyacencias->iniciarCursor();
	while(this->adyacencias->avanzarCursor() && !existeAdyacencia){

		delete this->adyacencias->obtenerCursor();
	}

	delete this->adyacencias;
}

#endif /* VERTICE_H_ */
