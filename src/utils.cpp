/*
 * utils.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "utils.h"
#include <cstdlib>

int Utils::stringToInt(std::string valor){

	return atoi(valor.c_str());
}

unsigned int Utils::stringToUnsignedInt(std::string valor){

	return atoi(valor.c_str());
}

char Utils::stringToChar(std::string valor){

	return valor.c_str()[0];
}
