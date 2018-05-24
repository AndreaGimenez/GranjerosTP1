/*
 * plantillaTerrenoConsola.cpp
 *
 *  Created on: 23 may. 2018
 *      Author: administrador
 */

#include "plantillaTerrenoConsola.h"

using namespace std;

string PlantillaTerrenoConsola::simboloParcelaLimpia = " ";
string PlantillaTerrenoConsola::simboloParcelaSembrada = "%";
string PlantillaTerrenoConsola::simboloParcelaSeca = "*";
string PlantillaTerrenoConsola::simboloParcelaPodrida = "#";
string PlantillaTerrenoConsola::simboloParcelaCosechada = "·";
string PlantillaTerrenoConsola::simboloParcelaRegada = "R";
string PlantillaTerrenoConsola::simboloParcelaSinRegar = " ";
string PlantillaTerrenoConsola::simboloSeparacionEntreParcelas = "|";
string PlantillaTerrenoConsola::simboloSueloParcela = "¯";
unsigned int PlantillaTerrenoConsola::anchoParcela = 7;
unsigned int PlantillaTerrenoConsola::distanciaBordeIzquierdo = 4;

PlantillaTerrenoConsola::PlantillaTerrenoConsola() {
	// TODO Auto-generated constructor stub

}

string PlantillaTerrenoConsola::obtenerSimboloParcelaLimpia(){
	return simboloParcelaLimpia;
}

string PlantillaTerrenoConsola::obtenerSimboloParcelaSembrada(){
	return simboloParcelaSembrada;
}

string PlantillaTerrenoConsola::obtenerSimboloParcelaSeca(){
	return simboloParcelaSeca;
}

string PlantillaTerrenoConsola::obtenerSimboloParcelaPodrida(){
	return simboloParcelaPodrida;
}

string PlantillaTerrenoConsola::obtenerSimboloParcelaCosechada(){
	return simboloParcelaCosechada;
}

string PlantillaTerrenoConsola::obtenerSimboloParcelaRegada(){
	return simboloParcelaRegada;
}

string PlantillaTerrenoConsola::obtenerSimboloParcelaSinRegar(){
	return simboloParcelaSinRegar;
}

string PlantillaTerrenoConsola::obtenerSimboloSeparacionEntreParcelas(){
	return simboloSeparacionEntreParcelas;
}

string PlantillaTerrenoConsola::obtenerSimboloSueloParcela(){
	return simboloSueloParcela;
}

unsigned int PlantillaTerrenoConsola::obtenerAnchoParcela(){
	return anchoParcela;
}

unsigned int PlantillaTerrenoConsola::obtenerDistanciaBordeIzquierdo(){
	return distanciaBordeIzquierdo;
}
