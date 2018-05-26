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
