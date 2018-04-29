/*
 * parametro.h
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#ifndef PARAMETRO_H_
#define PARAMETRO_H_

#include <string>

namespace parametro{

	enum Tipo{
		CHAR,
		INT,
		STRING
	};
}

class Parametro {

private:

	parametro::Tipo tipo;
	std::string valor;
	void* valorConvertido;

	void cambiarValorConvertido();

public:
	Parametro(parametro::Tipo tipo, std::string valor);
	void cambiarValor(std::string valor);
	parametro::Tipo obtenerTipo();
	std::string obtenerValor();
	void* obtenerValorConvertido();
	void deleteValorConvertido();
	~Parametro();
};

#endif /* PARAMETRO_H_ */
