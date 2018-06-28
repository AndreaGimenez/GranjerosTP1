#ifndef HEAP_H
#define HEAP_H

template<class T> class Heap {

	private:
		T** arreglo;
		unsigned int cantidad;
		unsigned int tamanio;
		//funcion_de_comparacion cmp; VER ESTO

	public:
		Heap() ;
		Heap(funcion_de_comparacion) ;
		Heap(T* arreglo[], unsigned int largo, funcion_de_comparacion) ;
		~Heap() ;
		unsigned int cantidadElementos();
		bool estaVacio();
		bool encolar(T dato);
		T obtenerMaximaPrioridad();
		T desencolar();

	private:
		void heapSort(T arreglo[], int n) ;
		void heapify(T arreglo[], int n, int i) ;
}

#endif // HEAP_H