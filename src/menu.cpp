/*
 * menu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "menu.h"
#include <iostream>

using namespace std;

Menu::Menu(string titulo, unsigned int cantidadItemsMenu) {

	this->titulo = titulo;
	this->cantidadItemsMenu = cantidadItemsMenu + 1;
	this->opciones = new OpcionMenu[cantidadItemsMenu + 1];
	this->leyendaIngresoUsuario = "Ingrese una opcion: ";
	this->opciones[0] = OpcionMenu("Salir", accion::SALIR);
}

void Menu::cambiarOpcion(unsigned int indice, OpcionMenu opcion){

	this->opciones[indice] = opcion;
}

ResultadoOpcion* Menu::ejecutarOpcion(unsigned int opcion){

	return this->opciones[opcion].ejecutar();
}

string Menu::obtenerLeyendaIngresoUsuario(){

	return this->leyendaIngresoUsuario;
}

void Menu::mostrar(){


	cout << endl << this->titulo << endl << endl;

	for(unsigned int iMenuItem = 1; iMenuItem < this->cantidadItemsMenu; iMenuItem++){

		cout << iMenuItem << " - " << this->opciones[iMenuItem].obtenerNombre() << endl;
	}

	cout << endl << "0" << " - " << opciones[0].obtenerNombre() << endl << endl;
}

Menu::~Menu() {

	if(this->opciones != NULL){

		for(unsigned int iMenuItem = 0; iMenuItem < this->cantidadItemsMenu; iMenuItem++){
			if(this->opciones[iMenuItem].obtenerSubMenu() != NULL){
				delete this->opciones[iMenuItem].obtenerSubMenu();
			}
		}
		delete[] this->opciones;
	}
}
