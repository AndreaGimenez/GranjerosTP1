/*
 * tanque.cpp
 *
 *  Created on: 20 Apr 2018
 *      Author: Usuario
 */

#include <iostream>
#include <string>

#include "tanque.h"

using namespace std ;

Tanque::Tanque(unsigned int capacidad){

	this->capacidad = capacidad ;
	this->volumenOcupado = 0 ;

}

bool Tanque::estaLLeno(){

	return volumenOcupado == capacidad ;

}

bool Tanque::estaVacio(){

	return volumenOcupado == 0 ;

}

unsigned int Tanque::volumenUtilizado(){

	return volumenOcupado;

}

unsigned int Tanque::volumenLibre(){

	return (capacidad - volumenOcupado);

}

void Tanque::almacenarAgua(unsigned int cantidadDeAgua){

	if(this->volumenLibre() < cantidadDeAgua){
		while(!this->estaLLeno()){
			this->volumenOcupado ++ ;
			cantidadDeAgua -- ;
		}
	}

	else{
		this->volumenOcupado += cantidadDeAgua ;	//este caso podria contemplarse en el while de arriba, pero
	}									//preferi tratarlo aparte para evitar iterar en un ciclo innecesariamente.

}

bool Tanque::usarAguaAlmacenada(unsigned int aguaAUtilizar){

	bool exito = false ;

	if(this->volumenUtilizado() >= aguaAUtilizar){
		this->volumenOcupado -= aguaAUtilizar ;
		exito = true ;
	}

	return exito ;

}

void Tanque::imprimirEstado(){

	cout<<"Tanque \n Capacidad = "<<this->capacidad<<"\nVolumen Utilizado = "
		<<this->volumenUtilizado()<<"\nVolumen Libre = "
		<<this->volumenLibre()<<endl ;

}
