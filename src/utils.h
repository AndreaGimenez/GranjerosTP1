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

	static int stringToInt(std::string);
	static unsigned int stringToUnsignedInt(std::string valor);
	static char stringToChar(std::string valor);
};

#endif /* UTILS_H_ */
