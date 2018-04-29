/*
 * interfazUsuario.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "interfazUsuario.h"
#include <iostream>

using namespace std;

InterfazUsuario::InterfazUsuario() {
}

void InterfazUsuario::mostrarMenuPrincipal(){

	Menu* menuPrincipal = new Menu(PRINCIPAL);
	this->menues.apilar(menuPrincipal);
	this->obtenerMenuActual()->mostrar();
}

unsigned int InterfazUsuario::solicitarOpcion(){

	cout << this->obtenerMenuActual()->obtenerLeyendaIngresoUsuario() << ": ";

	unsigned int opcionElegida;
	cin >> opcionElegida;
	return opcionElegida;
}

Respuesta InterfazUsuario::ejecutarOpcion(unsigned int iMenuItem){

	Respuesta respuesta = this->obtenerMenuActual()->ejecutarOpcion(iMenuItem);

	if(respuesta.obtenerTipo() == respuesta::SUBMENU){
		this->agregarMenu(respuesta.obtenerSubMenu());
	}

	return respuesta;
}

void InterfazUsuario::mostrarMenuActual(){
	if(!this->menues.estaVacia()){
		this->obtenerMenuActual()->mostrar();
	}
}

bool InterfazUsuario::salir(){
	return this->menues.estaVacia();
}

void InterfazUsuario::mostrarBienvenida(){

	cout << "GRANJEROS 1.0" << endl << endl;
}

void InterfazUsuario::mostrarDespedida(){

	cout << "CHAU!" << endl << endl;
}

Menu* InterfazUsuario::obtenerMenuActual(){
	return this->menues.obtenerTope();
}

void InterfazUsuario::agregarMenu(Menu* menu){
	this->menues.apilar(menu);
}

void InterfazUsuario::irAMenuAnterior(){
	delete this->menues.desapilar();
}

InterfazUsuario::~InterfazUsuario(){

	if(!this->menues.estaVacia()){
		while(this->menues.estaVacia()){
			delete this->menues.desapilar();
		}
	}
}

