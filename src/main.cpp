/*
 * main.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "configuracion.h"
#include <iostream>

using namespace std;

void testParametros(){

	ParametroConfiguracion parametros;

	parametros.cambiarDificultad(MEDIO);
	parametros.cambiarCantidadJugadores(5);
	parametros.cambiarParametroN(10);
	parametros.cambiarParametroM(5);
	parametros.cambiarCantidadTurnos(30);

	Configuracion::inicializar(parametros);

	Lista<Cultivo*>* cultivos = Configuracion::obtenerCultivos();
	Lista<Destino*>* destinos = Configuracion::obtenerDestinos();

	cout << "Parametros configurados:" << endl << endl;

	cout << "Dificultad: " << Configuracion::obtenerDificultad() << endl;
	cout << "Cantidad de Jugadores: " << Configuracion::obtenerCantidadJugadores() << endl;
	cout << "Largo Terreno (cantidad de filas): " << Configuracion::obtenerLargoTerreno() << endl;
	cout << "Ancho Terreno (cantidad de columnas): " << Configuracion::obtenerAnchoTerreno() << endl;
	cout << "Creditos Iniciales: " << Configuracion::obtenerCreditosIniciales() << endl;
	cout << "Capacidad Inicial de Tanque: " << Configuracion::obtenerCapacidadInicialTanque() << endl;
	cout << "Cantidad de Turnos: " << Configuracion::obtenerCantidadTurnos() << endl;
	cout << "Capacidad Inicial de Almacen: " << Configuracion::obtenerCapacidadInicialAlmacen() << endl << endl;

	cout << "Cultivos disponibles" << endl << endl;

	cultivos->iniciarCursor();
	while(cultivos->avanzarCursor()){
		cout << cultivos->obtenerCursor()->obtenerNombre() << endl;
	}

	cout << endl;
	cout << "Destinos disponibles" << endl << endl;

	destinos->iniciarCursor();
	while(destinos->avanzarCursor()){
		cout << destinos->obtenerCursor()->obtenerNombre() << endl;
	}
}

int main(){

	testParametros();
	return 0;
}


