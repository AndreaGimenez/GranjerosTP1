/*
 * terreno.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: jonathan
 */

#include "terreno.h"
#include "utilidades.h"
#include "cultivo.h"

using namespace std;

	Terreno::Terreno(ParametroConfiguracion parametros){

		this->cantidadColumnas=parametros.obtenerParametroM();
		this->cantidadFilas=parametros.obtenerParametroN();
		this->precio=PRECIO_INICIAL*cantidadColumnas*cantidadFilas;
		terreno=new Cultivo[cantidadFilas][cantidadColumnas];
	}

	unsigned int Terreno::obtenerCantidadColumnas(){

		return this->cantidadColumnas;
	}

	unsigned int Terreno::obtenerCantidadFilas(){

		return this->cantidadFilas;
	}

	unsigned int Terreno::obtenerPrecio(){

		unsigned int precioActual=this->precio;
		for(int i=0; i<this->cantidadFilas; i++){
			for(int j=0; j<this->cantidadColumnas; j++){
				precioActual+=(this->(terreno*)[i][j]).costo;
			}
		}
		return precioActual;
	}

	unsigned int Terreno::obtenerCantidadParcelas(){

		return this->cantidadFilas * this->cantidadColumnas;
	}

	bool parcelaCultivada(char)

	unsigned int Terreno::obtenerCantidadCultivos(){

		unsigned int cantidadCultivos=0;
		for(int i=0; i<this->cantidadFilas; i++){
			for(int j=0; j<this->cantidadColumnas; j++){
				if()
			}
		}
	}

	Terreno::~Terreno(){

		delete terreno;
	}




