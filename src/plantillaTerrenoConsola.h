#ifndef PLANTILLATERRENOCONSOLA_H_
#define PLANTILLATERRENOCONSOLA_H_

#include <string>

/*
 * Define las dimensiones de un terreno dibujado por consola.
 * Define los simbolos para los diferentes estados de las parceles
 * (SEMBRADA, LIMPIA, etc), el simbolo de separacion entre parcelas,
 * el anchos de las parcelas, los bordes, etc.
 */
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

	/*
	 * El constructor es privado para que no se pueda instanciar,
	 * dado que no es necesario
	 */
	PlantillaTerrenoConsola();

public:

	//Pos:
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
