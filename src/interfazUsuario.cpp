/*
 * interfazUsuario.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "interfazUsuario.h"
#include <iostream>
#include <cstdlib>

using namespace std;

InterfazUsuario::InterfazUsuario() {
	this->menuPrincipal = NULL;
	this->menuPartida = NULL;
}

void InterfazUsuario::mostrarBienvenida(){

	cout << "GRANJEROS 1.0" << endl << endl;
}

void InterfazUsuario::solicitarNombresJugadores(unsigned int cantidadJugadores, Lista<string>& listaNombres){

	cout << "Ingresa los nombres de los jugadores!" << endl << endl;
	for(unsigned int i = 0; i < cantidadJugadores; i++){

		cout << "Nombre jugador " + i << ": ";
		cout.flush();

		string nombreJugador;
		cin >> nombreJugador;
		listaNombres.agregar(nombreJugador);
	}
}

void InterfazUsuario::cargarMenuPrincipal(){

	this->menuPrincipal = new Menu(PRINCIPAL);
	this->menues.apilar(this->menuPrincipal);
}

void InterfazUsuario::cargarMenuPartida(){

	Menu* menuPartida = new Menu(JUEGO);
	this->menues.apilar(menuPartida);
}

Menu* InterfazUsuario::obtenerMenuActual(){
	return this->menues.obtenerTope();
}

void InterfazUsuario::mostrarMenuActual(){

	if(!this->menues.estaVacia()){
		this->obtenerMenuActual()->mostrar();
	}
}

void InterfazUsuario::irAMenuAnterior(){

	this->menues.desapilar();
}

unsigned int InterfazUsuario::solicitarOpcion(){

	cout << this->obtenerMenuActual()->obtenerLeyendaIngresoUsuario() << ": ";
	cout.flush();

	unsigned int opcionElegida;
	cin >> opcionElegida;
	return opcionElegida;
}

ResultadoOpcion* InterfazUsuario::ejecutarOpcion(unsigned int iMenuItem){

	ResultadoOpcion* respuesta = this->obtenerMenuActual()->ejecutarOpcion(iMenuItem);

	if(respuesta->obtenerTipo() == resultadoOpcion::SUBMENU){
		this->agregarMenu(respuesta->obtenerSubMenu());
	}

	return respuesta;
}

bool InterfazUsuario::salir(){
	return this->menues.estaVacia();
}

void InterfazUsuario::mostrarDespedida(){

	cout << "CHAU!" << endl << endl;
}

void InterfazUsuario::agregarMenu(Menu* menu){
	this->menues.apilar(menu);
}

InterfazUsuario::~InterfazUsuario(){

	if(this->menuPartida != NULL){
			delete this->menuPartida;
	}

	if(this->menuPrincipal != NULL){
		delete this->menuPrincipal;
	}
}

