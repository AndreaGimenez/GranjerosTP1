/*
 * plantillaTerrenoConsola.h
 *
 *  Created on: 23 may. 2018
 *      Author: administrador
 */

#ifndef PLANTILLATERRENOCONSOLA_H_
#define PLANTILLATERRENOCONSOLA_H_

#include <string>

class PlantillaTerrenoConsola {

private:

	static std::string simboloParcelaLimpia;
	static std::string simboloParcelaSembrada;
	static std::string simboloParcelaSeca;
	static std::string simboloParcelaPodrida;
	static std::string simboloParcelaCosechada;
	static std::string simboloParcelaRegada;
	static std::string simboloParcelaSinRegar;
	static std::string simboloSeparacionEntreParcelas;
	static std::string simboloSueloParcela;
	static unsigned int anchoParcela;
	static unsigned int distanciaBordeIzquierdo;

	PlantillaTerrenoConsola();

public:

	static std::string obtenerSimboloParcelaLimpia();
	static std::string obtenerSimboloParcelaSembrada();
	static std::string obtenerSimboloParcelaSeca();
	static std::string obtenerSimboloParcelaPodrida();
	static std::string obtenerSimboloParcelaCosechada();
	static std::string obtenerSimboloParcelaRegada();
	static std::string obtenerSimboloParcelaSinRegar();
	static std::string obtenerSimboloSeparacionEntreParcelas();
	static std::string obtenerSimboloSueloParcela();
	static unsigned int obtenerAnchoParcela();
	static unsigned int obtenerDistanciaBordeIzquierdo();

};

#endif /* PLANTILLATERRENOCONSOLA_H_ */
