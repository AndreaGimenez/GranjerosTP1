/*
 * parcela.cpp
 *
 *  Created on: 2 may. 2018
 *      Author: administrador
 */

#include "parcela.h"

Parcela::Parcela(){

	this->estado = parcela::LIMPIA;
	this->cultivo = NULL;
	this->regada = false;
	this->tiempoRecuperacionRestante = 0;
	this->tiempoSembrada = 0;
	this->actualizarEstado = true;
}

Cultivo* Parcela::obtenerCultivo(){

	return this->cultivo;
}

bool Parcela::puedeLimpiar(){

	return ((this->estado == parcela::COSECHADA	|| this->estado == parcela::PODRIDA	|| this->estado == parcela::SECA)
			&& this->tiempoRecuperacionRestante == 0);
}

void Parcela::limpiar(){

	if(puedeLimpiar()){
		this->estado = parcela::LIMPIA;
	}
}

bool Parcela::puedeSembrar(){

	return (this->estado == parcela::LIMPIA);
}

bool Parcela::sembrar(Cultivo* cultivo){

	bool puedeSembrar = this->puedeSembrar();

	if(puedeSembrar){

		this->cultivo = cultivo;
		this->estado = parcela::SEMBRADA;
		this->tiempoSembrada = 0;
		this->actualizarEstado = false;
	}

	return puedeSembrar;
}

bool Parcela::puedeRegar(){

	return (this->estado == parcela::SEMBRADA);
}

int Parcela::regar(){

	int unidadesRiegoConsumidas = -1;

	if(puedeRegar()){
		this->regada = true;
		unidadesRiegoConsumidas = this->obtenerCultivo()->obtenerConsumoAgua();
	}

	return unidadesRiegoConsumidas;
}

bool Parcela::puedeCosechar(){

	return (this->estado == parcela::SEMBRADA
		 && this->tiempoSembrada == cultivo->obtenerTiempoCrecimiento());
}

Cultivo* Parcela::cosechar(){

	Cultivo* cultivo = NULL;

	if(this->puedeCosechar()){

		cultivo = this->cultivo;
		this->estado = parcela::COSECHADA;
		this->tiempoRecuperacionRestante = this->cultivo->obtenerTiempoRecuperacion();
		this->cultivo = NULL;
		this->actualizarEstado = false;
	}

	return cultivo;
}


bool Parcela::puedePudrir(){

	return (this->estado == parcela::SEMBRADA
			&& this->tiempoSembrada > this->cultivo->obtenerTiempoCrecimiento());
}

void Parcela::pudrir(){

	if(puedePudrir()){

		this->estado = parcela::PODRIDA;
		this->tiempoRecuperacionRestante = this->cultivo->obtenerTiempoRecuperacion() / 2;
		this->cultivo = NULL;
	}
}

bool Parcela::puedeSecar(){

	return (this->estado == parcela::SEMBRADA
			&& !this->regada);
}

void Parcela::secar(){

	if(this->puedeSecar()){

		this->estado = parcela::SECA;
		this->tiempoRecuperacionRestante = 1;
		this->cultivo = NULL;
	}
}

parcela::Estado Parcela::obtenerEstado(){

	return this->estado;
}

unsigned int Parcela::obtenerTiempoRecuperacionRestante(){

	return this->tiempoRecuperacionRestante;
}

unsigned int Parcela::obtenerTiempoSembrada(){

	return this->tiempoSembrada;
}

bool Parcela::obtenerRegada(){
	
	return this->regada;
}

void Parcela::actualizar(){

	if(this->actualizarEstado && this->estado != parcela::LIMPIA){

		if(this->estado == parcela::SEMBRADA){

			this->tiempoSembrada++;

			if(puedeSecar()){
				this->secar();
			}else if(puedePudrir()){
				this->pudrir();
			}

		}else{

			this->tiempoRecuperacionRestante--;
		}

		if(puedeLimpiar()){
			this->limpiar();
		}
	}

	this->actualizarEstado = true;
}
