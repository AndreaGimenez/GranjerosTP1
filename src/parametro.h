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
	Parametro();
	Parametro(std::string valor, parametro::Tipo tipo);
	Parametro(parametro::Tipo tipo);

	std::string obtenerValor();
	void cambiarValor(std::string valor);
	parametro::Tipo obtenerTipo();
	void cambiarTipo(parametro::Tipo tipo);

	bool validarValor();
};

#endif /* PARAMETRO_H_ */
