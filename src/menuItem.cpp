/*
 * menuItem.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "menuItem.h"
#include "accion.h"
#include <iostream>
#include "configuracion.h"
#include "granjeros.h"

using namespace std;

MenuItem::MenuItem(){
	inicializarMenu(menuItem::SUBMENU, "", NULL, accion::NINGUNA);
}

MenuItem::MenuItem(std::string nombre, Menu* subMenu){
	inicializarMenu(menuItem::SUBMENU, nombre, subMenu, accion::NINGUNA);
}


MenuItem::MenuItem(std::string nombre, accion::EAccion accion){
	inicializarMenu(menuItem::ACCION, nombre, NULL, accion);
}

MenuItem::MenuItem(std::string nombre, accion::EAccion accion, string leyendaIngresoUsuario){

	inicializarMenu(menuItem::ACCION, nombre, NULL, accion);
	this->leyendaIngresoUsuario = leyendaIngresoUsuario;
}

void MenuItem::inicializarMenu(menuItem::Tipo tipo, string nombre, Menu* subMenu, accion::EAccion accion){

	this->tipo = tipo;
	this->nombre = nombre;
	this->subMenu = subMenu;
	this->accion = accion;
	this->leyendaIngresoUsuario = "";
	this->respuesta = NULL;
}

string MenuItem::obtenerNombre(){

	return this->nombre;
}

accion::EAccion MenuItem::obtenerAccion(){
	return this->accion;
}

Menu* MenuItem::obtenerSubMenu(){
	return this->subMenu;
}

ResultadoOpcion* MenuItem::ejecutar(){

	if(this->respuesta != NULL){
		delete this->respuesta;
	}

	switch(this->tipo){

		case menuItem::SUBMENU:

			this->subMenu->mostrar();
			respuesta = new ResultadoOpcion(this->subMenu);
			break;

		case menuItem::ACCION:

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

MenuItem::~MenuItem(){

	if(this->respuesta != NULL){
		delete this->respuesta;
	}
}
