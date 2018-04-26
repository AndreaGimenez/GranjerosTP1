/*
 * fileReader.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "fileParser.h"

using namespace std;

FileParser::FileParser(std::string nombreArchivo, std::string regex, unsigned int cantidadElementos){

	this->nombreArchivo = nombreArchivo;
	this->regex = regex;
	this->cantidadElementos = cantidadElementos;
}

void FileParser::abrir(){

	this->inputStream.open(this->nombreArchivo.c_str());
}

string* FileParser::leerLinea(){

	string linea;
	this->inputStream >> linea;
	return parseLinea(linea);
}

string* FileParser::parseLinea(string linea){

	string* lineaParseada = new string[this->cantidadElementos];
	this->lineasParseadas.agregar(lineaParseada);

	unsigned int indiceElemento = 0;
	unsigned int cantidadElementosLeidos = 0;
	int posicionRegex = linea.find(regex);

	while(posicionRegex > 0){

		string elemento = linea.substr(0, posicionRegex);
		lineaParseada[indiceElemento] = elemento;

		cantidadElementosLeidos++;
		indiceElemento++;

		linea = linea.substr(posicionRegex + 1);
		posicionRegex = linea.find(regex);
	}

	if(linea != ""){

		lineaParseada[indiceElemento] = linea;
		cantidadElementosLeidos++;
	}

	if(cantidadElementosLeidos != this->cantidadElementos){
		throw string("La cantidad de elementos es distinta a la cantidad de elementos esperada");
	}

	return lineaParseada;
}

bool FileParser::estaAbierto(){
	return this->inputStream.is_open();
}

bool FileParser::esFinArchivo(){
	return this->inputStream.eof();
}

void FileParser::cerrar(){
	this->inputStream.close();
}

FileParser::~FileParser(){

	if(!this->lineasParseadas.estaVacia()){

		this->lineasParseadas.iniciarCursor();

		while(lineasParseadas.avanzarCursor()){
			delete[] this->lineasParseadas.obtenerCursor();
		}
	}

	if(this->estaAbierto()){
		this->cerrar();
	}
}
