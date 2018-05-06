/*
 * almacen.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "almacen.h"
#include "configuracion.h"


Almacen::Almacen(){
	this->inicializar(Configuracion::obtenerCapacidadInicialAlmacen());
}

Almacen::Almacen(unsigned int capacidad){

	this->inicializar(capacidad);
}

void Almacen::inicializar(unsigned int capacidad){

	this->capacidad = capacidad;
	this->volumenUtilizado = 0;
}

unsigned int Almacen::obtenerCapacidad(){

	return this->capacidad;
}

unsigned int Almacen::obtenerVolumenUtilizado(){

	return this->volumenUtilizado;
}

unsigned int Almacen::obtenerVolumenDisponible(){

	return this->capacidad - this->volumenUtilizado;
}

bool Almacen::estaLleno(){

	return (this->volumenUtilizado == this->capacidad);
}

bool Almacen::estaVacio(){

	return (this->volumenUtilizado == 0);
}

unsigned int Almacen::obtenerCantidadAlmacenada(Cultivo* cultivo){

	unsigned int cantidadAlmacenada = 0;

	UnidadAlmacenamiento* unidadAlmacenamiento = this->buscarUnidadAlmacenamiento(cultivo);
	if(unidadAlmacenamiento != NULL){
		cantidadAlmacenada = unidadAlmacenamiento->obtenerCantidadAlmacenada();
	}

	return cantidadAlmacenada;
}

bool Almacen::puedeAlmacenarCosecha(Cultivo* cultivoAAlmacenar){

	return this->puedeAlmacenarCosecha(cultivoAAlmacenar, 1);
}

bool Almacen::puedeAlmacenarCosecha(Cultivo* cultivoAAlmacenar, unsigned int cantidadAAlmacenar){

	return (cantidadAAlmacenar <= this->obtenerCapacidad());
}

bool Almacen::almacenarCosecha(Cultivo* cultivoAAlmacenar){

	return this->almacenarCosecha(cultivoAAlmacenar, 1);
}

bool Almacen::almacenarCosecha(Cultivo* cultivoAAlmacenar, unsigned int cantidadAAlmacenar){

	bool almacenar = puedeAlmacenarCosecha(cultivoAAlmacenar, cantidadAAlmacenar);

	if(almacenar){

		UnidadAlmacenamiento* unidadAlmacenamientoCosechaAAlmacenar = this->buscarUnidadAlmacenamiento(cultivoAAlmacenar);

		//Si no encontre la unidad de almacenamiento del cultivo cosechado hay que agregarlo
		if(unidadAlmacenamientoCosechaAAlmacenar == NULL){
			unidadAlmacenamientoCosechaAAlmacenar = new UnidadAlmacenamiento(cultivoAAlmacenar);
			this->cosechasAlmacenadas.agregar(unidadAlmacenamientoCosechaAAlmacenar);
		}

		unidadAlmacenamientoCosechaAAlmacenar->almacenar(cantidadAAlmacenar);
		this->volumenUtilizado += cantidadAAlmacenar;
	}

	return almacenar;
}

bool Almacen::enviarCosecha(Cultivo* cultivoAEnviar){

	return this->enviarCosecha(cultivoAEnviar, this->obtenerCantidadAlmacenada(cultivoAEnviar));
}

bool Almacen::enviarCosecha(Cultivo* cultivoAEnviar, unsigned int cantidadAEnviar){

	UnidadAlmacenamiento* unidadAlmacenamientoCosechaAEnviar = this->buscarUnidadAlmacenamiento(cultivoAEnviar);
	bool cosechaEnviada = false;

	if(unidadAlmacenamientoCosechaAEnviar != NULL){

		cosechaEnviada = unidadAlmacenamientoCosechaAEnviar->desalmacenar(cantidadAEnviar);

		if(cosechaEnviada){
			this->volumenUtilizado -= cantidadAEnviar;
		}
	}

	return cosechaEnviada;
}

unsigned int Almacen::obtenerCostoEnvio(Cultivo* cultivoAEnviar){

	unsigned int costo = 0;
	unsigned int cantidadAlmacenada = this->obtenerCantidadAlmacenada(cultivoAEnviar);

	if(cantidadAlmacenada > 0){

		Destino* destino = Configuracion::obtenerDestino(cultivoAEnviar);

		if(destino != NULL){
			costo = cantidadAlmacenada * destino->obtenerPrecio();
		}
	}

	return costo;
}

UnidadAlmacenamiento* Almacen::buscarUnidadAlmacenamiento(Cultivo* cultivoABuscar){

	UnidadAlmacenamiento* unidadAlmacenamientoCosechaAAlmacenar = NULL;

	//Busco la unidad de almacenamiento del cultivo cosechado
	cosechasAlmacenadas.iniciarCursor();
	while (cosechasAlmacenadas.avanzarCursor() && unidadAlmacenamientoCosechaAAlmacenar == NULL){

		UnidadAlmacenamiento* unidadAlmacenamiento = cosechasAlmacenadas.obtenerCursor();
		if(unidadAlmacenamiento->obtenerCultivo()->obtenerNombre() == cultivoABuscar->obtenerNombre()){
			unidadAlmacenamientoCosechaAAlmacenar = unidadAlmacenamiento;
		}
	}

	return unidadAlmacenamientoCosechaAAlmacenar;
}

void Almacen::ampliarAlmacen(unsigned int unidadesAmpliacion){

	this->capacidad += unidadesAmpliacion;
}

Almacen::~Almacen(){

	if(!this->cosechasAlmacenadas.estaVacia()){

		this->cosechasAlmacenadas.iniciarCursor();
		while(this->cosechasAlmacenadas.avanzarCursor()){
			delete this->cosechasAlmacenadas.obtenerCursor();
		}
	}
}
