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

	return volumenOcupado == capacidad;
}

bool Tanque::estaVacio(){

	return volumenOcupado == 0;
}

unsigned int Tanque::volumenUtilizado(){

	return volumenOcupado;
}

unsigned int Tanque::volumenLibre(){

	return (capacidad - volumenOcupado);
}

void Tanque::almacenarAgua(unsigned int cantidadDeAgua){

	this->volumenOcupado += cantidadDeAgua;

	if(this->volumenOcupado > this->capacidad){
		this->volumenOcupado = this->capacidad;
	}
}

bool Tanque::usarAguaAlmacenada(unsigned int aguaAUtilizar){

	bool hayAguaSuficiente = (this->volumenUtilizado() >= aguaAUtilizar) ;

	if(hayAguaSuficiente){
		this->volumenOcupado -= aguaAUtilizar;
	}

	return hayAguaSuficiente;
}

void Tanque::imprimirEstado(){

	cout<<"Tanque \n Capacidad = "<<this->capacidad<<"\nVolumen Utilizado = "
		<<this->volumenUtilizado()<<"\nVolumen Libre = "
		<<this->volumenLibre()<<endl ;
}
