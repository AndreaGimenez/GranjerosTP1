/*
 * utils.h
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>

class Utils {
public:

	static bool esUnsignedInt(std::string cadena);
	static bool esInt(std::string cadena);
	static bool esChar(std::string cadena);
	static int stringToInt(std::string);
	static unsigned int stringToUnsignedInt(std::string valor);
	static char stringToChar(std::string valor);
	static std::string unsignedIntToString(unsigned int valor);
	static unsigned int contarRepeticiones(std::string cadena, std::string subcadena);
	static unsigned int splitString(std::string cadena, std::string subcadena, std::string* cadenaSeparada);

	static const char CHAR_0 = '0';
	static const char CHAR_9 = '9';
};

#endif /* UTILS_H_ */
