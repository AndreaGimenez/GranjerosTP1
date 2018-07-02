/*
 * GrafoMatriz.h
 *
 *  Created on: 21 jun. 2018
 *      Author: administrador
 */

#ifndef GrafoMatriz_H_
#define GrafoMatriz_H_

#include "lista.h"
#include <string>

const unsigned int INDEF=99999;
const unsigned short int CANT_PROVINCIAS=23;

template<class T> class GrafoMatriz {

private:

	unsigned int** matrizPesos; 
    unsigned int* pesosMinimos;
    Lista<T>* listaElementos;

public:
    /* Constructor
     *Pre: El primer elemento o vertice de la lista sera considerado como el origen
     * Post:Crea un grafo con matriz de pesos a adyacencias, inicicalizando una lista para
     * guardar los elementos que se vayan a meter en el grafo, la matriz con los pesos de las aristas
     * y un vector de posiciones minimas al origen(primer elemento de la lista)*/
	GrafoMatriz();

    /*Post:Devuelve la cantidad de elementos de la lista de vertices*/
    unsigned int obtenerCantidadElementos();

    /* Pre: Los vertices tienen que existir
     * Post: Devuelve la distancia entre los vertices pasados por parametro*/
    unsigned int obtenerPesoEntre(T origen, T destino);
	
	/*Post: Verifica que no haya un vertice con el mismo dato para no repetir vertices*/
	bool existeNodo(T dato);

	/*Post: Agrega un nodo a la matriz de vertices*/
	void insertarNodo(T dato);

	/*Post: Genera una conexion entre los vertices indicando el peso para llegar desde el origen
			hasta el destino*/
	void insertarArista(T datoOrigen, T datoDestino, unsigned int peso);

	/* Pre: El nodo debe existir
	 * Post: Elimina el nodo de la lista de vertices*/
	void borrarNodo(T dato);

	/*Pre: La arista debe existir entre los dos nodos
	  Post: elimina la conexion entre los nodos*/
	void borrarArista(T datoOrigen, T datoDestino);
	
    /* Pre: El grafo debe estar completo, en caso de que sea modificado luego, el vector
     * de pesosMinimos queda obsoleto
     * Post: Guarda en el vector pesosMinimos las distancias de cada vertice al origen*/
    void calcularPesosMinimos();

    /* Pre: Se debe haber llamado antes a la funcion calcularPesosMinimos()
     * Post: Devuelve la distancia minima desde el origen hasta el dato*/
    unsigned int obtenerPesoMinimoDesdeOrigenA(T dato);

	/*Post: Libera la lista de vertices*/
	~GrafoMatriz();

private:
        /*Post: inicializa la matriz de unsigned en un valor alto, que representa una indeterminacion
         *      de la distancia entre vertices. La diagonal de la matriz se inicializa en 0 porque es 
         *      la distancia desde un vertice a si mismo*/
        void inicializarMatriz();

        /*Post: Se inicializa el vector pesosMinimos en indeterminado, excepto la primera posicion que
                es 0, la distancia del origen a si mismo*/
        void inicializarPesosMinimos();

        /*Post: Devuelve el menor valor del vector pesosMinimos, exceptuando el valor 0*/
         unsigned int obtenerMenorValor(unsigned int j);

        /*Post: Devuelve la posicion del menor valor del vector pesosMinimos*/
        unsigned short int obtenerSiguienteFila(unsigned int adyacencia);

};

template<class T>
GrafoMatriz<T>::GrafoMatriz(){

	this->matrizPesos = new unsigned int*[CANT_PROVINCIAS];
    for(int i=0;i<CANT_PROVINCIAS;i++){
        matrizPesos[i]=new unsigned int[CANT_PROVINCIAS];
    }
    this->pesosMinimos=new unsigned int[CANT_PROVINCIAS];
    this->listaElementos=new Lista<T>;
    this->inicializarMatriz();
    this->inicializarPesosMinimos();
}

template<class T>
void GrafoMatriz<T>::inicializarMatriz(){
     for(int i=0;i<CANT_PROVINCIAS;i++){
         for(int j=0;j<CANT_PROVINCIAS;j++){
        
           if(i==j){
                this->matrizPesos[i][j]=0;
            }else{
                this->matrizPesos[i][j]=INDEF;        
            }
         }
    }
}

template<class T>
void GrafoMatriz<T>::inicializarPesosMinimos(){
    for(int i=0;i<CANT_PROVINCIAS;i++){
        if(i==0){
            this->pesosMinimos[i]=0;
        }else{
            this->pesosMinimos[i]=INDEF;
        }
    }
}

template<class T>
unsigned int GrafoMatriz<T>::obtenerPesoMinimoDesdeOrigenA(T dato){
    if(!this->existeNodo(dato)){
        throw std::string("No existe el vertice en el grafo");
    }
    unsigned short int contador=0;
    unsigned short int posicion;
    this->listaElementos->iniciarCursor();
    while(this->listaElementos->avanzarCursor()){
        if(this->listaElementos->obtenerCursor()==dato){
            posicion=contador;
        }
        contador++;
    }
    return this->pesosMinimos[posicion];
}

template<class T>
unsigned int GrafoMatriz<T>::obtenerCantidadElementos(){
    return this->listaElementos->contarElementos();
}

template<class T>
unsigned int GrafoMatriz<T>::obtenerPesoEntre(T origen, T destino){
    if(!this->existeNodo(origen) || !this->existeNodo(destino)){
        throw std::string("datos ingresados invalidos");
    }
    unsigned short int contador=0;
    unsigned short int fila, columna;
    this->listaElementos->iniciarCursor();
    while(this->listaElementos->avanzarCursor()){
        if(this->listaElementos->obtenerCursor()==origen){
            fila=contador;
        }else if(this->listaElementos->obtenerCursor()==destino){
            columna=contador;
        } 
        contador++;
    }
    return this->matrizPesos[fila][columna];
}

template<class T>
bool GrafoMatriz<T>::existeNodo(T dato){
	bool existeNodo = false;
	this->listaElementos->iniciarCursor();
    while(this->listaElementos->avanzarCursor()){
        if(this->listaElementos->obtenerCursor()==dato){
            existeNodo=true;
        }
    }
	return existeNodo;
}

template<class T>
void GrafoMatriz<T>::insertarNodo(T dato){
	if(!this->existeNodo(dato)){
        this->listaElementos->agregar(dato);
	}
}

template<class T>
void GrafoMatriz<T>::insertarArista(T datoOrigen, T datoDestino, unsigned int peso){
		if(!this->existeNodo(datoOrigen) || !this->existeNodo(datoDestino)){
            throw std::string("Error: datos no validos");
        }
        unsigned short int contador=0, posicionOrigen, posicionDestino;

        this->listaElementos->iniciarCursor();
        while(this->listaElementos->avanzarCursor()){
            if(this->listaElementos->obtenerCursor()==datoOrigen){
                posicionOrigen=contador;
            }else if(this->listaElementos->obtenerCursor()==datoDestino){
                posicionDestino=contador;
            }
            contador++;
        }
        this->matrizPesos[posicionOrigen][posicionDestino]=peso;
}

template<class T>
void GrafoMatriz<T>::borrarNodo(T dato){
    if(this->existeNodo(dato)){
        unsigned short int contador=0, posicion;
	    this->listaElementos->iniciarCursor();
        while(this->listaElementos->avanzarCursor()){
            if(this->listaElementos->obtenerCursor()==dato){
                posicion=contador;
            }
            contador++;
        }      
        for(int i=posicion+1;i<this->listaElementos->contarElementos();i++){
            for(int j=posicion+1;j<this->listaElementos->contarElementos();j++){
                if(i>posicion || j>posicion){
                    this->matrizPesos[i-1][j-1]=matrizPesos[i][j];                
                }else if(i<posicion && j>posicion){
                    this->matrizPesos[i][j-1]=this->matrizPesos[i][j];
                }else if(i>posicion && j<posicion){
                    this->matrizPesos[i-1][j]=this->matrizPesos[i][j];                    
                }else if(j==posicion){
                    this->matrizPesos[i][posicion]=INDEF;
                }else if(i==posicion){
                    this->matrizPesos[posicion][j]=INDEF;                    
                }

            }
        }   
        this->listaElementos->remover(posicion);
    }  
}

template<class T>
void GrafoMatriz<T>::borrarArista(T datoOrigen, T datoDestino){
    unsigned int posicionOrigen, posicionDestino;
    unsigned short int contador=0;
    this->listaElementos->iniciarCursor();
    while(this->listaElementos->avanzarCursor()){
        if(this->listaElementos->obtenerCursor()==datoOrigen){
            posicionOrigen=contador;
        }else if(this->listaElementos->obtenerCursor()==datoDestino){
            posicionDestino=contador;
        }
        contador++;
    }

	this->matrizPesos[posicionOrigen][posicionDestino]=INDEF;
}

template<class T>
unsigned int GrafoMatriz<T>::obtenerMenorValor(unsigned int j){
   
    unsigned int auxiliar=INDEF;
   
    for(unsigned int i=0;i<this->listaElementos->contarElementos();i++){
        if(this->pesosMinimos[i]<auxiliar && this->pesosMinimos[i]!=0 && this->matrizPesos[j][i] < INDEF){
            auxiliar=this->pesosMinimos[i];
        }
    }
   
    return auxiliar;
}

template<class T>
unsigned short int GrafoMatriz<T>::obtenerSiguienteFila(unsigned int adyacencia){
    unsigned short int siguienteFila;
    for(unsigned short int i=0;i<this->listaElementos->contarElementos();i++){
        if(adyacencia==this->pesosMinimos[i]){
            siguienteFila=i;
        }
    }
    return siguienteFila;
}

template<class T>
void GrafoMatriz<T>::calcularPesosMinimos(){
   
    bool fueVisitado[CANT_PROVINCIAS];
    unsigned short int tamanioVector=this->listaElementos->contarElementos();
    unsigned int adyacencia;
    unsigned short int siguienteFila;
   
    for(unsigned short int i=0;i<tamanioVector;i++){
        this->pesosMinimos[i]=this->matrizPesos[0][i];
        fueVisitado[i]=false;
    }

    for(int i=1;i<tamanioVector;i++){
        
        adyacencia=this->obtenerMenorValor(i);
        siguienteFila=this->obtenerSiguienteFila(adyacencia);
        
        for(int j=1;j<tamanioVector;j++){
            if(this->pesosMinimos[j]>this->matrizPesos[siguienteFila][j] + adyacencia
            && !fueVisitado[siguienteFila]){
                this->pesosMinimos[j]=this->matrizPesos[siguienteFila][j] + adyacencia;
            }            
        }
        fueVisitado[siguienteFila]=true;
    }   
     
}

template<class T>
GrafoMatriz<T>::~GrafoMatriz(){
    for(int i=0;i<CANT_PROVINCIAS;i++){
        delete[] matrizPesos[i];
    }
	delete[] this->matrizPesos;
    delete[] this->pesosMinimos;
    delete this->listaElementos; 
}

#endif /* GrafoMatriz_H_ */
