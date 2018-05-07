/*
 * terreno.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: jonathan
 */

#include "terreno.h"
#include "cultivo.h"
#include "configuracion.h"
#include "utils.h"

using namespace std;

Terreno::Terreno(){

	this->anchoTerreno = Configuracion::obtenerAnchoTerreno();
	this->largoTerreno = Configuracion::obtenerLargoTerreno();
	//this->precio = PRECIO_INICIAL*cantidadColumnas*cantidadFilas;
	//this->parcelas = new Parcela[cantidadFilas][cantidadColumnas];
	this->parcelas = new Parcela*[this->largoTerreno * this->anchoTerreno];
}

unsigned int Terreno::obtenerAnchoTerreno(){

	return this->anchoTerreno;
}

unsigned int Terreno::obtenerLargoTerreno(){

	return this->largoTerreno;
}

unsigned int Terreno::obtenerPrecio(){
	/*
	unsigned int precioActual=this->precio;
	for(int i=0; i<this->cantidadFilas; i++){
		for(int j=0; j<this->cantidadColumnas; j++){
			precioActual+=(this->(terreno*)[i][j]).costo;
		}
	}
	return precioActual;
	*/
	return 0;
}

unsigned int Terreno::obtenerCantidadParcelas(){

	return this->largoTerreno * this->anchoTerreno;
}

//bool parcelaCultivada(char)

unsigned int Terreno::obtenerCantidadCultivos(){

	/*
	unsigned int cantidadCultivos=0;
	for(int i=0; i<this->cantidadFilas; i++){
		for(int j=0; j<this->cantidadColumnas; j++){
			if()
		}
	}
	*/
	return 0;
}

Parcela* Terreno::buscarParcela(string strCoordenadas){

	Parcela* parcela = NULL;

	if(Utils::contarRepeticiones(strCoordenadas, ",") == 1){

		string coordenadas[2];
		Utils::splitString(strCoordenadas, ",", coordenadas);

		if(validarCoordenadas(coordenadas)){

			unsigned int coordenadasConvertidas[2] = {Utils::stringToUnsignedInt(coordenadas[0]), Utils::stringToUnsignedInt(coordenadas[1])};
			parcela = this->parcelas[obtenerIndiceParcela(coordenadasConvertidas)];
		}
	}

	return parcela;
}

bool Terreno::validarCoordenadas(string coordenadas[]){

	//Ambas tienen que ser int
	bool validarCoordenadas = (Utils::esUnsignedInt(coordenadas[0]) && Utils::esUnsignedInt(coordenadas[1]));
	//Ademas tienen que ser posiciones validas en el terreno
	return (validarCoordenadas
			&& (Utils::stringToUnsignedInt(coordenadas[0]) < this->largoTerreno)
			&& (Utils::stringToUnsignedInt(coordenadas[1]) < this->anchoTerreno));
}

Cultivo* Terreno::obtenerCultivo(string coordenadasParcela){

	Cultivo* cultivo = NULL;

	Parcela* parcela = buscarParcela(coordenadasParcela);
	if(parcela != NULL){
		cultivo = parcela->obtenerCultivo();
	}

	return cultivo;
}

unsigned int Terreno::obtenerIndiceParcela(unsigned int coordenadas[]){

	return coordenadas[0] * this->anchoTerreno + coordenadas[1];
}

bool Terreno::puedeSembrar(std::string coordenadasParcela){

	bool puedeSembrar = false;

	Parcela* parcela = buscarParcela(coordenadasParcela);

	if(parcela != NULL){
		puedeSembrar = parcela->puedeSembrar();
	}

	return puedeSembrar;
}

bool Terreno::sembrar(std::string coordenadasParcela, Cultivo* cultivo){

	bool puedeSembrar = this->puedeSembrar(coordenadasParcela);

	if(puedeSembrar){

		Parcela* parcela = buscarParcela(coordenadasParcela);
		parcela->sembrar(cultivo);
	}

	return puedeSembrar;
}

bool Terreno::puedeCosechar(std::string coordenadasParcela){

	bool puedeCosechar = false;

	Parcela* parcela = this->buscarParcela(coordenadasParcela);

	if(parcela != NULL){
		puedeCosechar = parcela->puedeCosechar();
	}

	return puedeCosechar;
}

Cultivo* Terreno::cosechar(std::string coordenadasParcela){

	Cultivo* cultivo = NULL;

	if(puedeCosechar(coordenadasParcela)){

		Parcela* parcela = this->buscarParcela(coordenadasParcela);
		cultivo = parcela->cosechar();
	}

	return cultivo;
}

bool Terreno::puedeRegar(string coordenadasParcela){

	bool puedeRegar = false;

	Parcela* parcela = buscarParcela(coordenadasParcela);
	if(puedeRegar){
		puedeRegar = parcela->puedeRegar();
	}

	return puedeRegar;
}

int Terreno::regar(string coordenadasParcela){

	int unidadesRiegoConsumidas = -1;

	if(puedeRegar(coordenadasParcela)){

		Parcela* parcela = buscarParcela(coordenadasParcela);
		unidadesRiegoConsumidas = parcela->regar();
	}

	return unidadesRiegoConsumidas;
}

void Terreno::actualizar(){

	for(unsigned int i = 0; i < this->obtenerCantidadParcelas(); i++){
		this->parcelas[i]->actualizar();
	}
}

Terreno::~Terreno(){

	delete parcelas;
}
