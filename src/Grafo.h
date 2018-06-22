/*
 * Grafo.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "Arista.h"

template<class T> class Grafo {

private:

	Lista<Vertice<T>*>* vertices;
	unsigned int tamanio;

	Comparador<T> comparador;

public:

	Grafo();

	void cambiarComparador(Comparador<T> comparador);
	bool existeVertice(Vertice<T>* vertice);
	void insertarVertice(Vertice<T>* vertice);
	bool existeArista(Arista<T>* arista);
	void insertarArista(Arista<T>* arista);
	void borrarVertice(Vertice<T>* vertice);
	void borrarArista(Arista<T>* arista);

	~Grafo();

private:

	/*
	 * pos: devuelve el vertice del grafo que coincida con los datos de vertice, de acuerdo al comparador
	 */
	Vertice<T>* obtenerVertice(Vertice<T>* vertice);
};

template<class T>
Grafo<T>::Grafo(){

	this->vertices = new Lista<Vertice<T>*>;
	tamanio = 0;
}

template<class T>
void Grafo<T>::cambiarComparador(Comparador<T> comparador){

	this->comparador = comparador;
}

template<class T>
bool Grafo<T>::existeVertice(Vertice<T>* vertice){

	bool existeVertice = false;
	this->vertices->iniciarCursor();

	while(this->vertices->avanzarCursor() && !existeVertice){

		Vertice<T>* verticeAAnalizar = this->vertices->obtenerCursor();
		existeVertice = this->comparador.sonIguales(verticeAAnalizar->obtenerDato(), vertice->obtenerDato());
	}

	return existeVertice;
}

template<class T>
void Grafo<T>::insertarVertice(Vertice<T>* vertice){

	if(!this->existeVertice(vertice)){

		this->vertices->agregar(vertice);
	}
}

template<class T>
bool Grafo<T>::existeArista(Arista<T>* arista){

	bool existeArista = false;

	Vertice<T>* verticeDelGrafo = this->obtenerVertice(arista->obtenerVerticeOrigen());
	if(verticeDelGrafo != NULL){
		existeArista = verticeDelGrafo->existeAdyacencia(arista->obtenerVerticeDestino(), this->comparador);
	}

	return existeArista;
}

template<class T>
void Grafo<T>::insertarArista(Arista<T>* arista){

	if(!this->existeArista(arista)){

		Vertice<T>* verticeDelGrafo = this->obtenerVertice(arista->obtenerVerticeOrigen());
		verticeDelGrafo->agregarAdyacencia(arista);
	}
}

template<class T>
void Grafo<T>::borrarVertice(Vertice<T>* vertice){

	unsigned int indice = 0;
	bool verticeEncontrado = false;

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor() && !verticeEncontrado){

		indice++;
		Vertice<T>* verticeActual = this->vertices->obtenerCursor();

		if(this->comparador.comparar(verticeActual->obtenerDato(), vertice->obtenerDato())){

			verticeEncontrado = true;
			if(!verticeActual->tieneAlgunaAdyacencia()){

				this->vertices->remover(indice);
			}
		}
	}
}

template<class T>
void Grafo<T>::borrarArista(Arista<T>* arista){

	bool verticeEncontrado = false;

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor() && !verticeEncontrado){
		Vertice<T>* verticeActual = this->vertices->obtenerCursor();

		if(this->comparador.comparar(verticeActual->obtenerDato(), arista->obtenerVerticeOrigen()->obtenerDato())){

			verticeActual->borrarAdyacencia(arista);
		}
	}
}

template<class T>
Grafo<T>::~Grafo(){

	delete this->vertices;
}

#endif /* GRAFO_H_ */
