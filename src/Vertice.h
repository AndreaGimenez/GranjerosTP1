/*
 * Vertice.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include "lista.h"
#include "VerticeAdyacente.h"
#include "Comparador.h"

template<class T> class Vertice {

private:

	Lista<VerticeAdyacente<T>*>* adyacencias;
	T dato;
	unsigned int numeroVertice;

public:

	Vertice(T dato);

	T obtenerDato();
	void agregarAdyacencia(Vertice<T>* verticeAdyacente, unsigned int peso);
	bool existeAdyacencia(T dato, Comparador<T>* comparador);
	bool tieneAlgunaAdyacencia();

	~Vertice();
};

template<class T>
Vertice<T>::Vertice(T dato, unsigned int numeroVertice){

	this->adyacencias = new Lista<VerticeAdyacente<T>*>;
	this->dato = dato;
}

template<class T>
T Vertice<T>::obtenerDato(){

	return this->dato;
}

template<class T>
void Vertice<T>::agregarAdyacencia(Vertice<T>* verticeAdyacente, unsigned int peso){

	VerticeAdyacente<T>* nuevaAdyacencia = new VerticeAdyacente<T>(verticeAdyacente, peso);
	this->adyacencias->agregar(nuevaAdyacencia);
}

template<class T>
bool Vertice<T>::existeAdyacencia(T dato, Comparador<T>* comparador){

	bool existeAdyacencia = false;

	this->adyacencias->iniciarCursor();
	while(this->adyacencias->avanzarCursor() && !existeAdyacencia){

		VerticeAdyacente<T>* verticeAdyacente = this->adyacencias->obtenerCursor();
		existeAdyacencia = comparador->sonIguales(verticeAdyacente->obtenerVertice()->obtenerDato(), dato);
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
	while(this->adyacencias->avanzarCursor()){

		delete this->adyacencias->obtenerCursor();
	}

	delete this->adyacencias;
}

#endif /* VERTICE_H_ */
