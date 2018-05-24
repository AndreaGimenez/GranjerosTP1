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

Dificultad Configuracion::dificultad = FACIL;
unsigned int Configuracion::cantidadTerrenosIniciales = 1;
unsigned int Configuracion::cantidadJugadores = 1;
unsigned int Configuracion::parametroN = 5;
unsigned int Configuracion::parametroM = 10;
unsigned int Configuracion::cantidadTurnos = 10;
Lista<Cultivo*>* Configuracion::cultivos = NULL;
Lista<Destino*>* Configuracion::destinos = NULL;

string Configuracion::resourcesPath = "resources/";
string Configuracion::imagesPath = resourcesPath + "img/";

string Configuracion::cultivosFileName = "cultivos.txt";
string Configuracion::destinosFileName = "destinos.txt";


Configuracion::Configuracion(){

}

void Configuracion::inicializar(ParametroConfiguracion* parametros){

	dificultad = parametros->obtenerDificultad();
	cantidadJugadores = parametros->obtenerCantidadJugadores();
	parametroN = parametros->obtenerParametroN();
	parametroM = parametros->obtenerParametroM();
	cantidadTurnos = parametros->obtenerCantidadTurnos();

	cargarCultivos();
	cargarDestinos();
}

void Configuracion::cargarCultivos(){

	cultivos = new Lista<Cultivo*>();

	FileParser parser(obtenerArchivoCultivos(), ",", 6);
	parser.abrir();

	while(!parser.esFinArchivo()){

		string* lineaParseada = parser.leerLinea();

		Cultivo* cultivo = new Cultivo(lineaParseada[0], atoi(lineaParseada[1].c_str()), atoi(lineaParseada[2].c_str()), atoi(lineaParseada[3].c_str()),
										atoi(lineaParseada[4].c_str()), atoi(lineaParseada[5].c_str()));

		cultivos->agregar(cultivo);
	}

	parser.cerrar();
}

string Configuracion::obtenerArchivoCultivos(){
	return resourcesPath + cultivosFileName;
}

void Configuracion::cargarDestinos(){

	destinos = new Lista<Destino*>();

	FileParser parser(obtenerArchivoDestinos(), ",", 4);
	parser.abrir();

	while(!parser.esFinArchivo()){

		string* lineaParseada = parser.leerLinea();

		Destino* destino = new Destino(lineaParseada[0], atoi(lineaParseada[1].c_str()), atoi(lineaParseada[2].c_str()), lineaParseada[3]);

		destinos->agregar(destino);
	}

	parser.cerrar();
}

string Configuracion::obtenerArchivoDestinos(){
	return resourcesPath + destinosFileName;
}

unsigned int Configuracion::obtenerCoeficienteDificultad(){

	unsigned int coeficienteDificultad;

	switch(dificultad){

	case FACIL:
		coeficienteDificultad = 10;
		break;
	case MEDIO:
		coeficienteDificultad = 5;
		break;
	case DIFICIL:
		coeficienteDificultad = 2;
		break;
	}

	return coeficienteDificultad;
}

Dificultad Configuracion::obtenerDificultad(){
	return dificultad;
}

unsigned int Configuracion::obtenerCantidadTerrenosIniciales(){
	return cantidadTerrenosIniciales;
}

unsigned int Configuracion::obtenerCantidadJugadores(){
	return cantidadJugadores;
}

unsigned int Configuracion::obtenerLargoTerreno(){
	return parametroN;
}

unsigned int Configuracion::obtenerAnchoTerreno(){
	return parametroM;
}

unsigned int Configuracion::obtenerCreditosIniciales(){
	return 2 * parametroN * parametroM * obtenerCoeficienteDificultad();
}

unsigned int Configuracion::obtenerCapacidadInicialTanque(){
	return parametroN * parametroM * obtenerCoeficienteDificultad();
}

unsigned int Configuracion::obtenerCantidadTurnos(){
	return cantidadTurnos;
}

unsigned int Configuracion::obtenerCapacidadInicialAlmacen(){
	return 2 * (parametroN + parametroM) * obtenerCoeficienteDificultad();
}

unsigned int Configuracion::obtenerCostoTerreno(unsigned int numeroTerrenoAComprar){
	return (numeroTerrenoAComprar * COSTO_MINIMO * (parametroN + parametroM)) / obtenerCoeficienteDificultad();
}

unsigned int Configuracion::obtenerCostoAumentoAlmacenamientoAlmacen(unsigned int aumentoAlmacenamiento){
	return (aumentoAlmacenamiento * COSTO_UNITARIO_ALMACENAMIENTO_ALMACEN);
}

unsigned int Configuracion::obtenerCostoAumentoCapacidadTanque(unsigned int aumentoVolumen){

	return(aumentoVolumen*COSTO_UNITARIO_ALMACENAMIENTO_TANQUE) ;
}

Lista<Cultivo*>* Configuracion::obtenerCultivos(){

	return cultivos;
}

Cultivo* Configuracion::obtenerCultivo(string nombreCultivo){


	Cultivo* cultivo = NULL;

	Lista<Cultivo*>* cultivosDisponibles = Configuracion::obtenerCultivos();
	cultivosDisponibles->iniciarCursor();

	while(cultivosDisponibles->avanzarCursor() && cultivo == NULL){

		Cultivo* cultivoActual = cultivosDisponibles->obtenerCursor();
		if(cultivoActual->obtenerNombre() == nombreCultivo){

			cultivo = cultivoActual;
		}
	}

	return cultivo;
}

Lista<Destino*>* Configuracion::obtenerDestinos(){

	return destinos;
}

Destino* Configuracion::obtenerDestino(Cultivo* cultivo){

	Destino* destino = NULL;

	Lista<Destino*>* destinosDisponibles = Configuracion::obtenerDestinos();
	destinosDisponibles->iniciarCursor();

	while(destinosDisponibles->avanzarCursor() && destino == NULL){

		Destino* destinoActual = destinosDisponibles->obtenerCursor();
		if(destinoActual->obtenerNombreCultivo() == cultivo->obtenerNombre()){

			destino = destinoActual;
		}
	}

	return destino;
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

unsigned int Configuracion::calcularRentabilidad(Cultivo* cultivo, unsigned int cantidad){

	return cultivo->obtenerRentabilidad() * cantidad;
}

string Configuracion::obtenerResourcesPath(){

	return resourcesPath;
}

string Configuracion::obtenerImagesPath(){

	return imagesPath;
}

Configuracion::~Configuracion() {

	destruirCultivos();
	destruirDestinos();
}

