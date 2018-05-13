/*
 * parametro.h
 *
 *  Created on: 13 may. 2018
 *      Author: administrador
 */

#ifndef PARAMETRO_H_
#define PARAMETRO_H_

#include <string>

namespace parametro{

	enum Tipo{

		UNSIGNED_INT,
		INT,
		CHAR,
		STRING
	};
}

class Parametro {

private:

	std::string valor;
	parametro::Tipo tipo;

public:
	Parametro(std::string valor, parametro::Tipo tipo);

	std::string obtenerValor();
	void cambiarValor(std::string valor);
	parametro::Tipo obtenerTipo();
	void cambiarTipo(parametro::Tipo tipo);
};

#endif /* PARAMETRO_H_ */
