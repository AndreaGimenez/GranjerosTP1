/*
 * fileReader.h
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#ifndef NULL
#define NULL 0
#endif

#include <fstream>
#include <string>
#include "lista.h"

/*
 * Parsea las lineas del archivo de acuerdo a los parametros indicados en el constructor.
 * En cada lectura del archivo devuelve un array con los elementos parseados.
 */
class FileParser {

private:

	std::string nombreArchivo;
	std::string regex;
	unsigned int cantidadElementos;
	std::ifstream inputStream;
	Lista<std::string*> lineasParseadas;

	std::string* parseLinea(std::string linea);

public:
	/*
	Pre: 'nombreArchivo' es la ruta absoluta donde se encuentra el archivo
		  'regex' representa una expresion regular que se utiliza para separar los tokens de la linea
		  'cantidadElementos' indica la cantidad esperada de elementos a ser leidos en cada linea del archivo

	Pos: se prepara FileParser para comenzar a utilizarse
	*/
	FileParser(std::string absolutePathArchivo, std::string regex, unsigned int cantidadElementos);

	/*
	Pos: abre el archivo asociado al parser
	 */
	void abrir();

	//Pre: debe haber lineas por leer, controlar con esFinArchivo()
	//Pos: devuelve el resultado de parsear la linea del archivo.
	//	   Cada posicion de 'lineaParseada' representa un elemento que se encuentra separado por 'regex'
	//	   Ejemplo: linea de archivo: A,100,3
	//				regex = ","
	//				lineaParseada[0] -> A
	//				lineaParseada[1] -> 100
	//				lineaParseada[2] -> 3
	std::string* leerLinea();

	//Post: indica si FileParser se encuentra disponible para hacer una lectura.
	bool estaAbierto();

	//Pre: FileParser debe estar abierto
	//Pos: indica si es el final del archivo
	bool esFinArchivo();

	//Pre: FileParser debe estar abierto
	//Pos: cierra FileReader
	void cerrar();

	//Pos: si FileParser se encuentra abierto lo cierra
	~FileParser();
};

#endif /* FILEPARSER_H_ */
