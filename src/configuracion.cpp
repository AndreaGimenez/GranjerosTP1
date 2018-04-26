/*
 * Configuracion.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include <string>
#include <cstdlib>

#include "configuracion.h"
#include "fileParser.h"

using namespace std;

Lista<Cultivo*>* Configuracion::cultivos = NULL;
Lista<Destino*>* Configuracion::destinos = NULL;

Configuracion::Configuracion(){

}

void Configuracion::inicializar(){

	cargarCultivos();
	cargarDestinos();
}

void Configuracion::cargarCultivos(){

	cultivos = new Lista<Cultivo*>();

	FileParser parser("resources/cultivos.txt", ",", 6);
	parser.abrir();

	while(!parser.esFinArchivo()){

		string* lineaParseada = parser.leerLinea();

		Cultivo* cultivo = new Cultivo(lineaParseada[0], atoi(lineaParseada[1].c_str()), atoi(lineaParseada[2].c_str()), atoi(lineaParseada[3].c_str()),
										atoi(lineaParseada[4].c_str()), atoi(lineaParseada[5].c_str()));

		cultivos->agregar(cultivo);
	}

	parser.cerrar();
}

void Configuracion::cargarDestinos(){

	destinos = new Lista<Destino*>();

	FileParser parser("resources/destinos.txt", ",", 3);
	parser.abrir();

	while(!parser.esFinArchivo()){

		string* lineaParseada = parser.leerLinea();

		Destino* destino = new Destino(lineaParseada[0], atoi(lineaParseada[1].c_str()), lineaParseada[2]);

		destinos->agregar(destino);
	}

	parser.cerrar();
}

Lista<Cultivo*>* Configuracion::getCultivos(){

	return cultivos;
}

Lista<Destino*>* Configuracion::getDestinos(){

	return destinos;
}

void Configuracion::destruirCultivos(){

	if(!cultivos->estaVacia()){

		cultivos->iniciarCursor();

		while(!cultivos->avanzarCursor()){
			delete cultivos->obtenerCursor();
		}
	}

	delete cultivos;
}

void Configuracion::destruirDestinos(){

	if(!destinos->estaVacia()){

		destinos->iniciarCursor();

		while(!destinos->avanzarCursor()){
			delete destinos->obtenerCursor();
		}
	}

	delete destinos;
}

Configuracion::~Configuracion() {

	destruirCultivos();
	destruirDestinos();
}

