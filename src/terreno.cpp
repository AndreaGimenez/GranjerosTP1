/*
 * terreno.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: jonathan
 */

#include "terreno.h"
#include "utilidades.h"
#include "cultivo.h"
#include "configuracion.h"

using namespace std;

Terreno::Terreno(){

	this->cantidadColumnas = Configuracion::obtenerAnchoTerreno();
	this->cantidadFilas = Configuracion::obtenerLargoTerreno();
	//this->precio = PRECIO_INICIAL*cantidadColumnas*cantidadFilas;
	//this->parcelas = new Parcela[cantidadFilas][cantidadColumnas];
	this->parcelas = new Parcela*[this->cantidadFilas * this->cantidadColumnas];
}

unsigned int Terreno::obtenerCantidadColumnas(){

	return this->cantidadColumnas;
}

unsigned int Terreno::obtenerCantidadFilas(){

	return this->cantidadFilas;
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

	return this->cantidadFilas * this->cantidadColumnas;
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

Parcela* Terreno::buscarParcela(std::string strCoordenadas){

	//TODO: obtener las coordendas de strCoordenadas
	unsigned int coordenadas[2] = {0,0};
	return this->parcelas[coordenadas[0] * this->cantidadColumnas + coordenadas[1]];
}

Terreno::~Terreno(){

	delete parcelas;
}
