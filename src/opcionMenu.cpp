/*
 * menuItem.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "opcionMenu.h"
#include <iostream>
#include "accion.h"
#include "configuracion.h"
#include "granjeros.h"

using namespace std;

OpcionMenu::OpcionMenu(){
	inicializarMenu(opcionMenu::SUBMENU, "", NULL, accion::NINGUNA);
}

OpcionMenu::OpcionMenu(std::string descripcion, Menu* subMenu){
	inicializarMenu(opcionMenu::SUBMENU, descripcion, subMenu, accion::NINGUNA);
}


OpcionMenu::OpcionMenu(std::string descripcion, accion::EAccion accion){
	inicializarMenu(opcionMenu::ACCION, descripcion, NULL, accion);
}

OpcionMenu::OpcionMenu(std::string descripcion, accion::EAccion accion, string leyendaIngresoUsuario){

	inicializarMenu(opcionMenu::ACCION, descripcion, NULL, accion);
	this->leyendaIngresoUsuario = leyendaIngresoUsuario;
}

void OpcionMenu::inicializarMenu(opcionMenu::Tipo tipo, string descripcion, Menu* subMenu, accion::EAccion accion){

	this->tipo = tipo;
	this->descripcion = descripcion;
	this->subMenu = subMenu;
	this->accion = accion;
	this->leyendaIngresoUsuario = "";
	this->resultado = NULL;
}

string OpcionMenu::obtenerDescripcion(){

	return this->descripcion;
}

accion::EAccion OpcionMenu::obtenerAccion(){
	return this->accion;
}

Menu* OpcionMenu::obtenerSubMenu(){
	return this->subMenu;
}

ResultadoOpcion* OpcionMenu::ejecutar(){

	if(this->resultado != NULL){
		delete this->resultado;
	}

	switch(this->tipo){

		case opcionMenu::SUBMENU:

			this->subMenu->mostrar();
			resultado = new ResultadoOpcion(this->subMenu);
			break;

		case opcionMenu::ACCION:

			string parametrosIngresados = "";
			resultado = new ResultadoOpcion(this->obtenerAccion());
			Accion* accion = resultado->obtenerAccion();

			bool parametrosCorrectos = false;
			switch(accion->obtenerTipo()){

				case accion::CON_PARAMETROS_USUARIO:

					while(!parametrosCorrectos){

						cout << this->leyendaIngresoUsuario << ": ";
						cout.flush();

						getline(cin, parametrosIngresados);

						parametrosCorrectos = accion->cambiarParametros(parametrosIngresados);
					}

					break;

				default:;
			}
	}

	return this->resultado;
}

OpcionMenu::~OpcionMenu(){

	if(this->resultado != NULL){
		delete this->resultado;
	}
}
