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

	//Pos: Devuelve el simbolo que representa que una parcela esta limpia
	static std::string obtenerSimboloParcelaLimpia();

	//Pos: Devuelve el simbolo que representa que una parcela esta sembrada
	static std::string obtenerSimboloParcelaSembrada();

	//Pos: Devuelve el simbolo que representa que una parcela esta seca
	static std::string obtenerSimboloParcelaSeca();

	//Pos: Devuelve el simbolo que representa que una parcela esta podrida
	static std::string obtenerSimboloParcelaPodrida();

	//Pos: Devuelve el simbolo que representa que una parcela esta cosechada
	static std::string obtenerSimboloParcelaCosechada();

	//Pos: Devuelve el simbolo que representa que una parcela esta regada
	static std::string obtenerSimboloParcelaRegada();

	//Pos: Devuelve el simbolo que representa que una parcela esta sin regar
	static std::string obtenerSimboloParcelaSinRegar();

	//Pos: Devuelve el simbolo que separa las parcelas unas de otras
	static std::string obtenerSimboloSeparacionEntreParcelas();

	//Pos: Devuelve el simbolo que representa el suelo de una parcela
	static std::string obtenerSimboloSueloParcela();

	//Pos: Devuelve el ancho de una parcela. Es la cantidad simbolos que
	//	   tiene una parcela
	static unsigned int obtenerAnchoParcela();

	//Pos: Devuelve la distancia al borde izquierdo de la consola.
	//	   El terreno se comienza a dibujar a partir de esta distancia.
	static unsigned int obtenerDistanciaBordeIzquierdo();

};

#endif /* PLANTILLATERRENOCONSOLA_H_ */
