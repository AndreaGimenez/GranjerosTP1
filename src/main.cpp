/*
 * main.cpp
 *
 *  Created on: 25 abr. 2018
 *      Author: administrador
 */

#include "configuracion.h"
#include "almacen.h"
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

void testAlmacen(){

	Almacen almacen;

	cout << "Inicio Test Almacen: " << endl << endl;
	cout << "Capacidad Inicial: " << almacen.obtenerCapacidad() << endl;
	cout << "Volumen Utilizado: " << almacen.obtenerVolumenUtilizado() << endl;
	cout << "Volumen Disponible: " << almacen.obtenerVolumenDisponible() << endl;
	cout << "Esta vacio: " << almacen.estaVacio() << endl;
	cout << "Esta lleno: " << almacen.estaLleno() << endl;

	cout << endl;

	Cultivo* cultivoA = Configuracion::obtenerCultivo("A");
	Cultivo* cultivoB = Configuracion::obtenerCultivo("B");

	cout << "Almaceno 5 unidades de Cultivo A" << endl;
	almacen.almacenarCosecha(cultivoA, 5);
	cout << "Almaceno 1 unidad de Cultivo B" << endl;
	almacen.almacenarCosecha(cultivoB);

	cout << "Capacidad: " << almacen.obtenerCapacidad() << endl;
	cout << "Volumen Utilizado: " << almacen.obtenerVolumenUtilizado() << endl;
	cout << "Volumen Disponible: " << almacen.obtenerVolumenDisponible() << endl;
	cout << "Esta vacio: " << almacen.estaVacio() << endl;
	cout << "Esta lleno: " << almacen.estaLleno() << endl;
	cout << "Cantidad Almacenada Cultivo A: " << almacen.obtenerCantidadAlmacenada(cultivoA) << endl;
	cout << "Cantidad Almacenada Cultivo B: " << almacen.obtenerCantidadAlmacenada(cultivoB) << endl;
	cout << "Costo envio A: " << almacen.obtenerCostoEnvio(cultivoA) << endl;
	cout << "Costo envio B: " << almacen.obtenerCostoEnvio(cultivoB) << endl << endl;

	cout << "Intento almacenar 10000: " << almacen.almacenarCosecha(cultivoA, 10000) << endl << endl;

	cout << "Amplio almacen en 200" << endl;
	almacen.ampliarAlmacen(200);
	cout << "Capacidad: " << almacen.obtenerCapacidad() << endl;
	cout << "Volumen Utilizado: " << almacen.obtenerVolumenUtilizado() << endl;
	cout << "Volumen Disponible: " << almacen.obtenerVolumenDisponible() << endl;

	cout << "Fin Test Almacen" << endl << endl;
}

int main(){

	testParametros();
	testAlmacen();
	return 0;
}


