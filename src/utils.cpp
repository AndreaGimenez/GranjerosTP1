/*
 * utils.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "utils.h"
#include <cstdlib>
#include <sstream>

using namespace std;

bool Utils::esUnsignedInt(string cadena){

	bool esInt = true;

	if(cadena == ""){
		esInt = false;
	}else{
		const char* caracteres = cadena.c_str();
		for(unsigned int i = 0; i < cadena.size() && esInt; i++){
			esInt = (caracteres[i] >= Utils::CHAR_0 && caracteres[i] <= Utils::CHAR_9);
		}
	}

	return esInt;
}

bool Utils::esInt(std::string cadena){

	bool esInt = true;

	if(cadena == ""){
		esInt = false;
	}else{

		unsigned int i = 0;

		if(cadena.at(0) == '-'){
			i = 1;
		}
		const char* caracteres = cadena.c_str();
		for(; i < cadena.size() && esInt; i++){
			esInt = (caracteres[i] >= Utils::CHAR_0 && caracteres[i] <= Utils::CHAR_9);
		}
	}

	return esInt;
}

bool Utils::esChar(std::string cadena){

	return (cadena.size() == 1);
}

int Utils::stringToInt(string valor){

	return atoi(valor.c_str());
}

unsigned int Utils::stringToUnsignedInt(string valor){

	return atoi(valor.c_str());
}

char Utils::stringToChar(std::string valor){

	return valor.c_str()[0];
}

string Utils::unsignedIntToString(unsigned int valor){

	ostringstream ss;
	ss << valor;
	return ss.str();
}

unsigned int Utils::contarRepeticiones(string cadena, string subcadena){

	unsigned int repeticiones = 0;

	if(cadena != ""){

		int posicionSubcadena = cadena.find(subcadena);

		while(posicionSubcadena >= 0){

			repeticiones++;

			cadena = cadena.substr(posicionSubcadena + subcadena.size());
			posicionSubcadena = cadena.find(subcadena);
		}
	}

	return repeticiones;
}

unsigned int Utils::splitString(string cadena, string subcadena, string* cadenaSeparada){

	unsigned int tamanioCadenaSeparada = contarRepeticiones(cadena, subcadena) + 1;

	for(unsigned int i = 0; i < tamanioCadenaSeparada; i++){

		unsigned int posicionSubcadena = cadena.find(subcadena);

		string elemento = cadena.substr(0, posicionSubcadena);
		cadenaSeparada[i] = elemento;

		cadena = cadena.substr(posicionSubcadena + 1);
	}

	return tamanioCadenaSeparada;
}

string Utils::fillString(string cadena, string relleno, unsigned int cantidad, bool rellenarDerecha){

	string cadenaRelleno = "";

	for(unsigned int i = 0; i < cantidad; i++){

		cadenaRelleno += relleno;
	}

	if(rellenarDerecha){
		cadena += cadenaRelleno;
	}else{
		cadena = cadenaRelleno + cadena;
	}

	return cadena;
}
