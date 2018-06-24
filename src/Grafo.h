/*
 * Grafo.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "Comparador.h"

template<class T> class Grafo {

private:

	Lista<Vertice<T>*>* vertices;

	Comparador<T>* comparador;
	Comparador<T>* comparadorDefault;

public:

	Grafo();
	Grafo(Comparador<T> comparador);

	bool existeNodo(T dato);
	void insertarNodo(T dato);
	bool existeArista(T datoOrigen, T datoDestino);
	void insertarArista(T datoOrigen, T datoDestino, unsigned int peso);
	void borrarNodo(T dato);
	void borrarArista(T datoOrigen, T datoDestino);

	~Grafo();

private:

	/*
	 * pos: devuelve el vertice del grafo que coincida con los datos de vertice, de acuerdo al comparador
	 */
	Vertice<T>* obtenerNodo(T dato);
	bool sonIguales(T dato1, T dato2);
	Comparador<T>* getComparador();
};

template<class T>
Grafo<T>::Grafo(){

	this->vertices = new Lista<Vertice<T>*>;
	this->comparador = NULL;
	this->comparadorDefault = new Comparador<T>;
}

template<class T>
Grafo<T>::Grafo(Comparador<T> comparador){

	this->vertices = new Lista<Vertice<T>*>;
	this->comparador = comparador;
	this->comparadorDefault = new Comparador<T>;
}

template<class T>
Comparador<T>* Grafo<T>::getComparador(){

	return (this->comparador == NULL)?this->comparadorDefault:this->comparador;
}

template<class T>
bool Grafo<T>::existeNodo(T dato){

	bool existeNodo = false;
	this->vertices->iniciarCursor();

	while(this->vertices->avanzarCursor() && !existeNodo){

		Vertice<T>* verticeAAnalizar = this->vertices->obtenerCursor();
		existeNodo = this->getComparador()->sonIguales(verticeAAnalizar->obtenerDato(), dato);
	}

	return existeNodo;
}

template<class T>
void Grafo<T>::insertarNodo(T dato){

	if(!this->existeNodo(dato)){

		Vertice<T>* nuevoVertice = new Vertice<T>(dato);
		this->vertices->agregar(nuevoVertice);
	}
}

template<class T>
bool Grafo<T>::existeArista(T datoOrigen, T datoDestino){

	bool existeArista = false;

	Vertice<T>* verticeDelGrafo = this->obtenerNodo(datoOrigen);
	if(verticeDelGrafo != NULL){
		existeArista = verticeDelGrafo->existeAdyacencia(datoDestino, this->getComparador());
	}

	return existeArista;
}

template<class T>
void Grafo<T>::insertarArista(T datoOrigen, T datoDestino, unsigned int peso){

	if(!this->existeArista(datoOrigen, datoDestino)){

		Vertice<T>* verticeDelGrafoOrigen = this->obtenerNodo(datoOrigen);
		Vertice<T>* verticeDelGrafoDestino = this->obtenerNodo(datoDestino);

		verticeDelGrafoOrigen->agregarAdyacencia(verticeDelGrafoDestino, peso);
	}
}

template<class T>
void Grafo<T>::borrarNodo(T dato){

	unsigned int indice = 0;
	bool verticeEncontrado = false;

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor() && !verticeEncontrado){

		indice++;
		Vertice<T>* verticeActual = this->vertices->obtenerCursor();

		if(this->getComparador().sonIguales(verticeActual->obtenerDato(), dato)){

			verticeEncontrado = true;
			if(!verticeActual->tieneAlgunaAdyacencia()){

				this->vertices->remover(indice);
			}
		}
	}
}

template<class T>
void Grafo<T>::borrarArista(T datoOrigen, T datoDestino){

	bool verticeEncontrado = false;

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor() && !verticeEncontrado){
		Vertice<T>* verticeActual = this->vertices->obtenerCursor();

		if(this->getComparador().sonIguales(verticeActual->obtenerDato(), datoOrigen)){

			verticeActual->borrarAdyacencia(datoDestino);
		}
	}
}

template<class T>
Vertice<T>* Grafo<T>::obtenerNodo(T dato){

	Vertice<T>* verticeDelGrafo = NULL;

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor() && verticeDelGrafo == NULL){

		Vertice<T>* verticeActual = this->vertices->obtenerCursor();
		if(this->getComparador()->sonIguales(verticeActual->obtenerDato(), dato)){

			verticeDelGrafo = verticeActual;
		}
	}

	return verticeDelGrafo;
}

template<class T>
Grafo<T>::~Grafo(){

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()){
		delete this->vertices->obtenerCursor();
	}

	delete this->vertices;
}

#endif /* GRAFO_H_ */
