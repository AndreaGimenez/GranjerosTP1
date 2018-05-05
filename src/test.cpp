/*
 * test.cpp
 *
 *  Created on: 27 abr. 2018
 *      Author: administrador
 */

#include "test.h"
#include "configuracion.h"
#include "almacen.h"
#include "parcela.h"
#include <iostream>

using namespace std;

void Test::correrTests(){

	testParametros();
	testAlmacen();
	testParcela();
}

void Test::testParametros(){

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

void Test::testAlmacen(){

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
	cout << "Costo envio B: " << almacen.obtenerCostoEnvio(cultivoB) << endl;

	cout << "Intento almacenar 10000: " << almacen.almacenarCosecha(cultivoA, 10000) << endl << endl;

	cout << "Amplio almacen en 200" << endl;
	almacen.ampliarAlmacen(200);
	cout << "Capacidad: " << almacen.obtenerCapacidad() << endl;
	cout << "Volumen Utilizado: " << almacen.obtenerVolumenUtilizado() << endl;
	cout << "Volumen Disponible: " << almacen.obtenerVolumenDisponible() << endl << endl;

	cout << "Envío Cultivo A: " << almacen.enviarCosecha(cultivoA) << endl;
	cout << "Cantidad Almacenada Cultivo A: " << almacen.obtenerCantidadAlmacenada(cultivoA) << endl;

	cout << "Envío Cultivo B: " << almacen.enviarCosecha(cultivoB) << endl;
	cout << "Cantidad Almacenada Cultivo B: " << almacen.obtenerCantidadAlmacenada(cultivoB) << endl;

	cout << "Fin Test Almacen" << endl << endl;
}

void Test::testParcela1() {

	Parcela parcela;

	cout << "Test Siembra - Cosecha - Siembra: " << endl << endl;

	cout << "Comienza Turno 1" << endl;
	cout << "Estado parcela: " << parcela.obtenerEstado() << endl << endl;

	cout << "Siembro Cultivo A en Parcela " << endl;

	Cultivo* cultivoA = Configuracion::obtenerCultivo("A");
	if (parcela.puedeSembrar()) {
		parcela.sembrar(cultivoA);
	}

	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;

	cout << "Finaliza Turno 1 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 2" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl << endl;

	cout << "Riego Parcela" << endl << endl;
	parcela.regar();

	cout << "Finaliza Turno 2 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 3" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl << endl;

	cout << "Riego Parcela" << endl << endl;
	parcela.regar();

	cout << "Finaliza Turno 3 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 4" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl << endl;

	cout << "Cosecho Parcela" << endl;

	Cultivo* cultivoCosechado = NULL;
	if (parcela.puedeCosechar()) {
		cultivoCosechado = parcela.cosechar();
	}
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Cosechado: " << cultivoCosechado->obtenerNombre() << endl;
	cout << "Tiempo de Recuperacion: " << cultivoCosechado->obtenerTiempoRecuperacion() << endl << endl;

	cout << "Finaliza Turno 4 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 5" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl << endl;

	cout << "Finaliza Turno 5 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 6" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl << endl;

	cout << "Siembro Cultivo B en Parcela " << endl;

	Cultivo* cultivoB = Configuracion::obtenerCultivo("B");
	if (parcela.puedeSembrar()) {
		parcela.sembrar(cultivoB);
	}
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;
}

void Test::testParcela2() {

	Parcela parcela;

	cout << "Test Siembra - Seca - Siembra: " << endl << endl;

	cout << "Comienza Turno 1" << endl;
	cout << "Estado parcela: " << parcela.obtenerEstado() << endl << endl;

	cout << "Siembro Cultivo A en Parcela " << endl;

	Cultivo* cultivoA = Configuracion::obtenerCultivo("A");
	if (parcela.puedeSembrar()) {
		parcela.sembrar(cultivoA);
	}
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;

	cout << "Finaliza Turno 1 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 2" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl << endl;

	cout << "No Riego Parcela" << endl << endl;

	cout << "Finaliza Turno 2 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 3" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Tiempo Recuperacion Restante: " << parcela.obtenerTiempoRecuperacionRestante() << endl << endl;

	cout << "Finaliza Turno 3 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 4" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Siembro Cultivo B en Parcela " << endl;

	Cultivo* cultivoB = Configuracion::obtenerCultivo("B");
	if (parcela.puedeSembrar()) {
		parcela.sembrar(cultivoB);
	}
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;
}

void Test::testParcela3() {

	Parcela parcela;

	cout << "Test Siembra - Podrida - Siembra: " << endl << endl;

	cout << "Comienza Turno 1" << endl;
	cout << "Estado parcela: " << parcela.obtenerEstado() << endl << endl;

	cout << "Siembro Cultivo C en Parcela " << endl;

	Cultivo* cultivoC = Configuracion::obtenerCultivo("C");
	if (parcela.puedeSembrar()) {
		parcela.sembrar(cultivoC);
	}
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;

	cout << "Finaliza Turno 1 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 2" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl << endl;

	cout << "Riego Parcela" << endl << endl;
	parcela.regar();

	cout << "Finaliza Turno 2 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 3" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;

	cout << "Riego Parcela" << endl << endl;
	parcela.regar();

	cout << "No cosecho" << endl << endl;

	cout << "Finaliza Turno 3 (Actualizo parcela)" << endl << endl;
	parcela.actualizar();

	cout << "Comienza Turno 4" << endl;
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;

	Cultivo* cultivoB = Configuracion::obtenerCultivo("B");
	if (parcela.puedeSembrar()) {
		parcela.sembrar(cultivoB);
	}
	cout << "Estado Parcela: " << parcela.obtenerEstado() << endl;
	cout << "Cultivo Parcela: " << parcela.obtenerCultivo()->obtenerNombre() << endl;
	cout << "Tiempo Crecimiento: " << parcela.obtenerCultivo()->obtenerTiempoCrecimiento() << endl << endl;
}

void Test::testParcela(){

	ParametroConfiguracion parametros;

	parametros.cambiarDificultad(MEDIO);
	parametros.cambiarCantidadJugadores(5);
	parametros.cambiarParametroN(10);
	parametros.cambiarParametroM(5);
	parametros.cambiarCantidadTurnos(30);

	Configuracion::inicializar(parametros);

	cout << "Inicio Test Parcela: " << endl << endl;

	testParcela1();
	testParcela2();
	testParcela3();
}
