/*
 * main.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "configuracion.h"
#include <iostream>

using namespace std;

int main(){

	Configuracion::inicializar();

	Lista<Cultivo*>* cultivos = Configuracion::getCultivos();
	Lista<Destino*>* destinos = Configuracion::getDestinos();

	cultivos->iniciarCursor();
	while(cultivos->avanzarCursor()){
		cout << cultivos->obtenerCursor()->getNombre() << endl;
	}

	destinos->iniciarCursor();
	while(destinos->avanzarCursor()){
		cout << destinos->obtenerCursor()->getNombre() << endl;
	}

	return 0;
}


