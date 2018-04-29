/*
 * menuItem.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "menuItem.h"
#include "accion.h"
#include <iostream>

using namespace std;

MenuItem::MenuItem(){
}

MenuItem::MenuItem(std::string nombre, Menu* subMenu){
	inicializarMenu(menuItem::SUBMENU, nombre, subMenu, NULL);
}


MenuItem::MenuItem(std::string nombre, Accion* accion){
	inicializarMenu(menuItem::ACCION, nombre, NULL, accion);
}

MenuItem::MenuItem(std::string nombre, Accion* accion, string leyendaIngresoUsuario){

	inicializarMenu(menuItem::ACCION, nombre, NULL, accion);
	this->leyendaIngresoUsuario = leyendaIngresoUsuario;
}



void MenuItem::inicializarMenu(menuItem::Tipo tipo, string nombre, Menu* subMenu, Accion* accion){

	this->tipo = tipo;
	this->nombre = nombre;
	this->subMenu = subMenu;
	this->accion = accion;
	this->leyendaIngresoUsuario = "";
}

string MenuItem::obtenerNombre(){

	return this->nombre;
}

Accion* MenuItem::obtenerAccion(){
	return this->accion;
}

Menu* MenuItem::obtenerSubMenu(){
	return this->subMenu;
}

Respuesta MenuItem::ejecutar(){

	Respuesta respuesta;

	switch(this->tipo){

		case menuItem::SUBMENU:

			this->subMenu->mostrar();
			respuesta = Respuesta(this->subMenu);
			break;

		case menuItem::ACCION:

			string parametrosIngresados = "";

			switch(this->accion->obtenerTipo()){

				case accion::CON_PARAMETROS_USUARIO:

					cout << this->leyendaIngresoUsuario << ": ";
					cout.flush();

					cin.clear();
					cin.sync();
					cin.ignore();
					getline(cin, parametrosIngresados);

					this->accion->cambiarParametros(parametrosIngresados);
					respuesta = Respuesta(accion);

					break;

				case accion::SIN_PARAMETROS_USUARIO:

					respuesta = Respuesta(this->accion);

					break;
				}
	}

	return respuesta;
}


