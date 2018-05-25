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


OpcionMenu::OpcionMenu(std::string descripcion, accion::Tipo tipoAccion){
	inicializarMenu(opcionMenu::ACCION, descripcion, NULL, tipoAccion);
}

OpcionMenu::OpcionMenu(std::string descripcion, accion::Tipo tipoAccion, string leyendaIngresoUsuario){

	inicializarMenu(opcionMenu::ACCION, descripcion, NULL, tipoAccion);
	this->leyendaIngresoUsuario = leyendaIngresoUsuario;
}

void OpcionMenu::inicializarMenu(opcionMenu::Tipo tipo, string descripcion, Menu* subMenu, accion::Tipo tipoAccion){

	this->tipo = tipo;
	this->descripcion = descripcion;
	this->subMenu = subMenu;
	this->tipoAccion = tipoAccion;
	this->leyendaIngresoUsuario = "";
	this->resultado = NULL;
}

string OpcionMenu::obtenerDescripcion(){

	return this->descripcion;
}

accion::Tipo OpcionMenu::obtenerTipoAccion(){
	return this->tipoAccion;
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
			resultado = new ResultadoOpcion(this->obtenerTipoAccion());
			Accion* accion = resultado->obtenerAccion();

			bool parametrosCorrectos = false;
			if(accion->usaParametros()){

				while(!parametrosCorrectos){

					cout << this->leyendaIngresoUsuario << ": ";
					cout.flush();

					getline(cin, parametrosIngresados);

					parametrosCorrectos = accion->cambiarParametros(parametrosIngresados);

					if(!parametrosCorrectos){
						cout << "Los parametros ingresados no son correctos" << endl;
					}
				}
			}
	}

	return this->resultado;
}

OpcionMenu::~OpcionMenu(){

	if(this->resultado != NULL){
		delete this->resultado;
	}
}
