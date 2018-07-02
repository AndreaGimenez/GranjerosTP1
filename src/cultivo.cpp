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

	trayectos = new GrafoMatriz<Lugar*>;
}

unsigned int Cultivo::obtenerConsumoAgua() {
	return consumoAgua;
}

unsigned int Cultivo::obtenerCosto() {
	return costo;
}

std::string Cultivo::obtenerNombre() {
	return nombre;
}

unsigned int Cultivo::obtenerRentabilidad() {
	return rentabilidad;
}

unsigned int Cultivo::obtenerTiempoCrecimiento() {
	return tiempoCrecimiento;
}

unsigned int Cultivo::obtenerTiempoRecuperacion() {
	return tiempoRecuperacion;
}

void Cultivo::agregarTrayecto(Trayecto* trayecto){

	Lugar* origen = trayecto->obtenerOrigen();
	Lugar* destino = trayecto->obtenerDestino();

	if(!this->trayectos->existeNodo(origen)){
		this->trayectos->insertarNodo(origen);
	}

	if(!this->trayectos->existeNodo(destino)){
		this->trayectos->insertarNodo(destino);
	}

	this->trayectos->insertarArista(origen, destino, trayecto->obtenerCosto());

	/*
	if(!this->trayectos->existeArista(origen, destino)){
		this->trayectos->insertarArista(origen, destino, trayecto->obtenerCosto());
	}
	*/
}

unsigned int Cultivo::obtenerCostoEnvio(Lugar* lugar){

	return this->trayectos->obtenerPesoMinimoDesdeOrigenA(lugar);
}

void Cultivo::calcularCostoMinimoDestinos(){

	this->trayectos->calcularPesosMinimos();
}
