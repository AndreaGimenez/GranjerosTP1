/*
 * menuItem.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "opcionMenu.h"

#include "accion.h"
#include <iostream>
#include "configuracion.h"
#include "granjeros.h"

using namespace std;

OpcionMenu::OpcionMenu(){
	inicializarMenu(opcionMenu::SUBMENU, "", NULL, accion::NINGUNA);
}

OpcionMenu::OpcionMenu(std::string nombre, Menu* subMenu){
	inicializarMenu(opcionMenu::SUBMENU, nombre, subMenu, accion::NINGUNA);
}


OpcionMenu::OpcionMenu(std::string nombre, accion::EAccion accion){
	inicializarMenu(opcionMenu::ACCION, nombre, NULL, accion);
}

OpcionMenu::OpcionMenu(std::string nombre, accion::EAccion accion, string leyendaIngresoUsuario){

	inicializarMenu(opcionMenu::ACCION, nombre, NULL, accion);
	this->leyendaIngresoUsuario = leyendaIngresoUsuario;
}

void OpcionMenu::inicializarMenu(opcionMenu::Tipo tipo, string nombre, Menu* subMenu, accion::EAccion accion){

	this->tipo = tipo;
	this->nombre = nombre;
	this->subMenu = subMenu;
	this->accion = accion;
	this->leyendaIngresoUsuario = "";
	this->respuesta = NULL;
}

string OpcionMenu::obtenerNombre(){

	return this->nombre;
}

accion::EAccion OpcionMenu::obtenerAccion(){
	return this->accion;
}

Menu* OpcionMenu::obtenerSubMenu(){
	return this->subMenu;
}

ResultadoOpcion* OpcionMenu::ejecutar(){

	if(this->respuesta != NULL){
		delete this->respuesta;
	}

	switch(this->tipo){

		case opcionMenu::SUBMENU:

			this->subMenu->mostrar();
			respuesta = new ResultadoOpcion(this->subMenu);
			break;

		case opcionMenu::ACCION:

			string parametrosIngresados = "";
			respuesta = new ResultadoOpcion(this->obtenerAccion());
			Accion* accion = respuesta->obtenerAccion();

			switch(accion->obtenerTipo()){

				case accion::CON_PARAMETROS_USUARIO:

					cout << this->leyendaIngresoUsuario << ": ";
					cout.flush();

					cin.clear();
					cin.sync();
					cin.ignore();
					getline(cin, parametrosIngresados);

					accion->cambiarParametros(parametrosIngresados);

					break;

				default:;
			}
	}

	return this->respuesta;
}

OpcionMenu::~OpcionMenu(){

	if(this->respuesta != NULL){
		delete this->respuesta;
	}
}
