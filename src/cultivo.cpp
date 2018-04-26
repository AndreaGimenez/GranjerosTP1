/*
 * Cultivo.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "cultivo.h"

using namespace std;

Cultivo::Cultivo(string nombre, unsigned int costo, unsigned int tiempoCrecimiento, unsigned int rentabilidad,
			unsigned int tiempoRecuperacion, unsigned int consumoAgua){

	this->nombre = nombre;
	this->costo = costo;
	this->tiempoCrecimiento = tiempoCrecimiento;
	this->rentabilidad = rentabilidad;
	this->tiempoRecuperacion = tiempoRecuperacion;
	this->consumoAgua = consumoAgua;
}

unsigned int Cultivo::getConsumoAgua() {
	return consumoAgua;
}

void Cultivo::setConsumoAgua(unsigned int consumoAgua) {
	this->consumoAgua = consumoAgua;
}

unsigned int Cultivo::getCosto() {
	return costo;
}

void Cultivo::setCosto(unsigned int costo) {
	this->costo = costo;
}

std::string Cultivo::getNombre() {
	return nombre;
}

void Cultivo::setNombre(std::string nombre) {
	this->nombre = nombre;
}

unsigned int Cultivo::getRentabilidad() {
	return rentabilidad;
}

void Cultivo::setRentabilidad(unsigned int rentabilidad) {
	this->rentabilidad = rentabilidad;
}

unsigned int Cultivo::getTiempoCrecimiento() {
	return tiempoCrecimiento;
}

void Cultivo::setTiempoCrecimiento(unsigned int tiempoCrecimiento) {
	this->tiempoCrecimiento = tiempoCrecimiento;
}

unsigned int Cultivo::getTiempoRecuperacion() {
	return tiempoRecuperacion;
}

void Cultivo::setTiempoRecuperacion(unsigned int tiempoRecuperacion) {
	this->tiempoRecuperacion = tiempoRecuperacion;
}


