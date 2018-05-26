#include "accion.h"
#include <cstdlib>
#include "utils.h"


using namespace std;

Accion::Accion(){

	this->tipoAccion = accion::NINGUNA;
	this->cantidadParametros = 0;
	this->parametros = NULL;
}

Accion::Accion(Accion* accion){

	this->tipoAccion = accion->obtenerTipoAccion();
	this->cantidadParametros = accion->obtenerCantidadParametros();

	if(accion->obtenerParametros() != NULL){
		this->parametros = new Parametro[this->cantidadParametros];

		for(unsigned int iParametro = 0; iParametro < this->cantidadParametros; iParametro++){
			this->parametros[iParametro] = accion->obtenerParametros()[iParametro];
		}
	}else{
		this->parametros = NULL;
	}
}

Accion::Accion(accion::Tipo tipoAccion){

	this->tipoAccion = tipoAccion;
	this->cantidadParametros = 0;
	this->parametros = NULL;
}

Accion::Accion(accion::Tipo tipoAccion, unsigned int cantidadParametros, parametro::Tipo tiposParametros[]){

	this->tipoAccion = tipoAccion;
	this->cantidadParametros = cantidadParametros;

	if(cantidadParametros == 0){
		this->parametros = NULL;
	}else{
		this->parametros = new Parametro[this->cantidadParametros];

		for(unsigned int i = 0; i < cantidadParametros; i++){
			this->parametros[i].cambiarTipo(tiposParametros[i]);
		}
	}
}

bool Accion::usaParametros(){
	return (this->parametros != NULL);
}

Parametro* Accion::obtenerParametros(){
	return this->parametros;
}

void Accion::cambiarParametros(Parametro* parametros){

	this->parametros = parametros;
}

bool Accion::cambiarParametros(string parametros){

	bool cambiarCantidadParametros = cambiarValoresParametros(parametros);
	cambiarCantidadParametros = cambiarCantidadParametros && validarTipoParametros();

	return cambiarCantidadParametros;
}

bool Accion::cambiarValoresParametros(std::string parametros){

	unsigned int cantidadEspacios = Utils::contarRepeticiones(parametros, " ");

	//Tiene que haber exactamente obtenercantidadParametros() - 1 espacios de lo contrario se pasaron mas o menos parametros
	bool cambiarCantidadParametros = cantidadEspacios == this->obtenerCantidadParametros() - 1;

	if(cambiarCantidadParametros){

		unsigned int tamanioCadenaSeparada = cantidadEspacios + 1;

		for(unsigned int i = 0; i < tamanioCadenaSeparada; i++){

			unsigned int posicionSubcadena = parametros.find(" ");

			string elemento = parametros.substr(0, posicionSubcadena);
			this->parametros[i].cambiarValor(elemento);

			parametros = parametros.substr(posicionSubcadena + 1);
		}
	}

	return cambiarCantidadParametros;
}

bool Accion::validarTipoParametros(){

	bool parametrosCorrectos = true;

	for(unsigned int i = 0; i < this->obtenerCantidadParametros() && parametrosCorrectos; i++){

		parametrosCorrectos = this->parametros[i].validarValor();
	}

	return parametrosCorrectos;
}

accion::Tipo Accion::obtenerTipoAccion(){
	return this->tipoAccion;
}

unsigned int Accion::obtenerCantidadParametros(){
	return this->cantidadParametros;
}

Accion::~Accion(){

	if(this->parametros != NULL){
		delete[] this->parametros;
	}
}
