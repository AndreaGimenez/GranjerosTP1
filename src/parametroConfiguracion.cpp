#include "parametroConfiguracion.h"
#include "configuracion.h"

using namespace std;

ParametroConfiguracion::ParametroConfiguracion(){

	this->dificultad = FACIL;
	this->cantidadJugadores = 1;
	this->parametroN = 5;
	this->parametroM = 10;
	this->cantidadTurnos = 10;
}

void ParametroConfiguracion::cambiarDificultad(Dificultad dificultad){

	this->dificultad = dificultad;
}

bool ParametroConfiguracion::cambiarDificultad(int dificultad){

	bool cambiarDificultad = validarDificultad(dificultad);
	if(cambiarDificultad){
		this->dificultad = convertirIntToDificultad(dificultad);
	}

	return cambiarDificultad;
}

bool ParametroConfiguracion::validarDificultad(int dificultad){

	return (dificultad >= 0 && dificultad <= 2);
}

Dificultad ParametroConfiguracion::convertirIntToDificultad(int intDificultad){

	Dificultad dificultad = FACIL;

	switch(intDificultad){

		case 0:
			dificultad = FACIL;
			break;

		case 1:
			dificultad = MEDIO;
			break;

		case 2:
			dificultad = DIFICIL;
			break;

		default:
			throw string("Valor de dificultad no valido");
	}

	return dificultad;
}

int ParametroConfiguracion::convertirDificultadToInt(Dificultad dificultad){

	int intDificultad = 0;

	switch(dificultad){

		case FACIL:
			intDificultad = 0;
			break;

		case MEDIO:
			intDificultad = 1;
			break;

		case DIFICIL:
			intDificultad = 2;
			break;
	}

	return intDificultad;
}

Dificultad ParametroConfiguracion::obtenerDificultad(){

	return this->dificultad;
}

string ParametroConfiguracion::obtenerNombreDificultad(Dificultad dificultad){

	string nombreDificultad = "";

	switch(dificultad){

		case FACIL:
			nombreDificultad = "FACIL";
			break;

		case MEDIO:
			nombreDificultad = "MEDIO";
			break;

		case DIFICIL:
			nombreDificultad = "DIFICIL";
			break;
	}

	return nombreDificultad;
}

unsigned int ParametroConfiguracion::obtenerCantidadJugadores(){

	return this->cantidadJugadores;
}

void ParametroConfiguracion::cambiarCantidadJugadores(unsigned int cantidadJugadores){

	this->cantidadJugadores = cantidadJugadores;
}

unsigned int ParametroConfiguracion::obtenerParametroN(){

	return this->parametroN;
}

void ParametroConfiguracion::cambiarParametroN(unsigned int parametroN){

	this->parametroN = parametroN;
}

unsigned int ParametroConfiguracion::obtenerParametroM(){

	return this->parametroM;
}

void ParametroConfiguracion::cambiarParametroM(unsigned int parametroM){

	this->parametroM = parametroM;
}

unsigned int ParametroConfiguracion::obtenerCantidadTurnos(){

	return this->cantidadTurnos;
}

void ParametroConfiguracion::cambiarCantidadTurnos(unsigned int cantidadTurnos){

	this->cantidadTurnos = cantidadTurnos;
}
