/*
 * Heap.h
 *
 *  Created on: 27 jun. 2018
 *      Author: administrador
 */

#ifndef HEAP_H_
#define HEAP_H_

const unsigned int MAX = 0;
const unsigned int TAMANIO_INICIAL = 31;
const unsigned int DIV_CAPAC_MIN = 4;
const unsigned int DIV_CAPAC_INTER = 2;
const unsigned int MULT_TAM = 2;

template<class T> class Heap{

private:

	T* arreglo;
	unsigned int cantidad;
	unsigned int tamanio;
	Comparador<T> comparador;

public:

	Heap();
	Heap(Comparador<T> comparador) ;
	unsigned int cantidadElementos();
	bool estaVacio();
	bool encolar(T dato);
	T obtenerMaximaPrioridad();
	T desencolar();
	void redimensionarArreglo(unsigned int nuevoTamanio);

private:

	void swap(unsigned int posicion1, unsigned int posicion2);
	void copiarElementos(T* nuevoArreglo);
	void heapSort(T arreglo[], int n) ;
	void heapify(T arreglo[], int n, int i) ;
};


template<class T>
Heap<T>::Heap(){

	this->arreglo = new T[TAMANIO_INICIAL];
	this->comparador = NULL;
	this->cantidad = 0;
	this->tamanio = TAMANIO_INICIAL;
}

template<class T>
Heap<T>::Heap(Comparador<T> comparador){

	this->arreglo = new T[TAMANIO_INICIAL];
	this->comparador = comparador;
	this->cantidad = 0;
	this->tamanio = TAMANIO_INICIAL;
}

template<class T>
void Heap<T>::redimensionarArreglo(unsigned int nuevoTamanio){

	T* nuevoArreglo = new T[nuevoTamanio];
	this->copiarElementos(nuevoArreglo);
	delete this->arreglo;
	this->arreglo = nuevoArreglo;
	this->tamanio = nuevoTamanio;
}

template<class T>
void Heap<T>::copiarElementos(T* nuevoArreglo){

	for(unsigned int i = 0; i < this->cantidad; i++){
		nuevoArreglo[i] = this->arreglo[i];
	}
}

template<class T>
void Heap<T>::swap(unsigned int posicion1, unsigned int posicion2){

	T temp = this->arreglo[posicion2];

	this->arreglo[posicion2] = this->arreglo[posicion1];
	this->arreglo[posicion1] = temp;
}

#endif /* HEAP_H_ */
