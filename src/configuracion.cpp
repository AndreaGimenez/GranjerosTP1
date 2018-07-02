#include <string>
#include <cstdlib>

#include "configuracion.h"
#include "fileParser.h"
#include "utils.h"

using namespace std;

Dificultad Configuracion::dificultad = FACIL;
unsigned int Configuracion::cantidadTerrenosIniciales = 1;
unsigned int Configuracion::cantidadJugadores = 1;
unsigned int Configuracion::parametroN = 5;
unsigned int Configuracion::parametroM = 10;
unsigned int Configuracion::cantidadTurnos = 10;
Lista<Lugar*>* Configuracion::lugares = NULL;
Lista<Cultivo*>* Configuracion::cultivos = NULL;
Lista<Trayecto*>* Configuracion::trayectos = NULL;

string Configuracion::resourcesPath = "resources/";
string Configuracion::imagesPath = resourcesPath + "img/";

string Configuracion::cultivosFileName = "cultivos.txt";
string Configuracion::destinosFileName = "destinos.txt";

const unsigned int CULTIVOS_CANTIDAD_DATOS = 6;
const unsigned int POSICION_CULTIVOS_CULTIVO = 0;
const unsigned int POSICION_DESTINOS_COSTO = 1;
const unsigned int POSICION_DESTINOS_TIEMPO_CRECIMIENTO = 2;
const unsigned int POSICION_DESTINOS_RENTABILIDAD = 3;
const unsigned int POSICION_DESTINOS_TIEMPO_RECUPERACION = 4;
const unsigned int POSICION_DESTINOS_CONSUMO_AGUA = 5;

const unsigned int DESTINOS_CANTIDAD_DATOS = 5;
const unsigned int POSICION_DESTINOS_ORIGEN = 0;
const unsigned int POSICION_DESTINOS_DESTINO = 1;
const unsigned int POSICION_DESTINOS_DISTANCIA = 2;
const unsigned int POSICION_DESTINOS_PRECIO = 3;
const unsigned int POSICION_DESTINOS_CULTIVO = 4;


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

	FileParser parser(obtenerArchivoCultivos(), ",", CULTIVOS_CANTIDAD_DATOS);
	parser.abrir();

	while(!parser.esFinArchivo()){

		string* lineaParseada = parser.leerLinea();

		Cultivo* cultivo = new Cultivo(lineaParseada[POSICION_CULTIVOS_CULTIVO], atoi(lineaParseada[POSICION_DESTINOS_COSTO].c_str()),
										atoi(lineaParseada[POSICION_DESTINOS_TIEMPO_CRECIMIENTO].c_str()), atoi(lineaParseada[POSICION_DESTINOS_RENTABILIDAD].c_str()),
										atoi(lineaParseada[POSICION_DESTINOS_TIEMPO_RECUPERACION].c_str()), atoi(lineaParseada[POSICION_DESTINOS_CONSUMO_AGUA].c_str()));

		cultivos->agregar(cultivo);
	}

	parser.cerrar();
}

string Configuracion::obtenerArchivoCultivos(){
	return resourcesPath + cultivosFileName;
}

void Configuracion::cargarDestinos(){

	lugares = new Lista<Lugar*>;
	trayectos = new Lista<Trayecto*>;

	FileParser parser(obtenerArchivoDestinos(), ",", DESTINOS_CANTIDAD_DATOS);
	parser.abrir();

	while(!parser.esFinArchivo()){

		string* lineaParseada = parser.leerLinea();

		Cultivo* cultivo = obtenerCultivo(lineaParseada[POSICION_DESTINOS_CULTIVO]);
		Lugar* lugarOrigen = obtenerLugar(lineaParseada[POSICION_DESTINOS_ORIGEN]);
		Lugar* lugarDestino = obtenerLugar(lineaParseada[POSICION_DESTINOS_DESTINO]);

		Trayecto* trayecto = new Trayecto(lugarOrigen, lugarDestino,
										  Utils::stringToUnsignedInt(lineaParseada[POSICION_DESTINOS_PRECIO]),
										  Utils::stringToUnsignedInt(lineaParseada[POSICION_DESTINOS_DISTANCIA]));
		trayectos->agregar(trayecto);
		cultivo->agregarTrayecto(trayecto);
	}

	calcularCostoMinimoDestinos();

	parser.cerrar();
}

void Configuracion::calcularCostoMinimoDestinos(){

	cultivos->iniciarCursor();
	while(cultivos->avanzarCursor()){

		Cultivo* cultivo = cultivos->obtenerCursor();
		cultivo->calcularCostoMinimoDestinos();
	}
}

Lugar* Configuracion::obtenerLugar(string nombreLugar){

	Lugar* lugar = NULL;//Este es el valor a devolver

	lugares->iniciarCursor();
	while(lugares->avanzarCursor() && lugar == NULL){
		if((lugares->obtenerCursor()->obtenerNombre() == nombreLugar)){
			lugar = lugares->obtenerCursor();
		}
	}

	if(lugar == NULL){
		lugar = new Lugar(nombreLugar);
		lugares->agregar(lugar);
	}

	return lugar;
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

void Configuracion::destruirCultivos(){

	if(!cultivos->estaVacia()){

		cultivos->iniciarCursor();

		while(!cultivos->avanzarCursor()){
			delete cultivos->obtenerCursor();
		}
	}

	delete cultivos;
}

void Configuracion::destruirLugares(){

	if(!lugares->estaVacia()){

		lugares->iniciarCursor();

		while(!lugares->avanzarCursor()){
			delete lugares->obtenerCursor();
		}
	}

	delete lugares;
}

void Configuracion::destruirTrayectos(){

	if(!trayectos->estaVacia()){

		trayectos->iniciarCursor();

		while(!trayectos->avanzarCursor()){
			delete trayectos->obtenerCursor();
		}
	}

	delete trayectos;
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

	destruirTrayectos();
	destruirCultivos();
	destruirLugares();
}

