/*
 * main.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "test.h"
#include "granjeros.h"
#include "mostrarEstadoDeJuego.h"

using namespace std;

int main(){

	//Test::correrTests();

	//Granjeros granjeros;
	//granjeros.iniciarJuego();

	BmpCultivos imagenTerreno;
	ParametroConfiguracion prueba1;

	prueba1.cambiarParametroM(1);
	prueba1.cambiarParametroN(1);


	imagenTerreno.crearParcela();


	return 0;
}


