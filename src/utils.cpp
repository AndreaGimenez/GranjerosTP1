/*
 * utils.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "utils.h"
#include <cstdlib>

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

int Utils::stringToInt(string valor){

	return atoi(valor.c_str());
}

unsigned int Utils::stringToUnsignedInt(string valor){

	return atoi(valor.c_str());
}

char Utils::stringToChar(std::string valor){

	return valor.c_str()[0];
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
