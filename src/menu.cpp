/*
 * menu.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "menu.h"
#include <iostream>

using namespace std;

void Menu::inicializarMenu(TipoMenu tipo, string titulo, unsigned int cantidadItems) {

	this->tipo = tipo;
	this->titulo = titulo;
	this->cantidadItemsMenu = cantidadItems + 1;
	this->itemsMenu = new MenuItem[cantidadItemsMenu];

	this->itemsMenu[0] = MenuItem("Salir",
								  accion::SALIR);
}

void Menu::crearMenuPrincipal() {

	this->inicializarMenu(PRINCIPAL, "MENU PRINCIPAL", 2);

	this->itemsMenu[1] = MenuItem("Configuracion",
								  new Menu(CONFIGURACION));

	this->itemsMenu[2] = MenuItem("Jugar",
								  accion::JUGAR);
}

void Menu::crearMenuConfiguracion() {

	this->inicializarMenu(CONFIGURACION, "CONFIGURACION", 4);

	this->itemsMenu[1] = MenuItem("Cambiar Cantidad de Jugadores",
								  accion::CAMBIAR_CANTIDAD_JUGADORES,
								  "Indique la cantidad de jugadores");

	this->itemsMenu[2] = MenuItem("Cambiar Parametro N",
								  accion::CAMBIAR_PARAMETRO_N,
								  "Indique el nuevo valor del parametro: ");

	this->itemsMenu[3] = MenuItem("Cambiar Parametro M",
								  accion::CAMBIAR_PARAMETRO_M,
								  "Indique el nuevo valor del parametro");

	this->itemsMenu[4] = MenuItem("Cambiar Cantidad de Turnos",
								  accion::CAMBIAR_CANTIDAD_TURNOS,
								  "Indique la cantidad de turnos a jugar en cada partida");
}

void Menu::crearMenuAcciones() {

	this->inicializarMenu(ACCIONES, "ACCIONES", 9);

	this->itemsMenu[1] = MenuItem("Sembrar",
			  	  	  	  	  	  accion::SEMBRAR,
								  "Indique, separando con espacios, las coordenadas de la parcela y el cultivo a sembrar (ej: 1,2 A)");

	this->itemsMenu[2] = MenuItem("Cosechar",
								  accion::COSECHAR,
								  "Indique las coordenadas de la parcela a cosechar (ej: 1,2)");

	this->itemsMenu[3] = MenuItem("Regar",
								  accion::REGAR,
								  "Indique las coordenadas de la parcela a regar (ej 1,2)");

	this->itemsMenu[4] = MenuItem("Enviar Cosecha",
								  accion::ENVIAR_COSECHA,
								  "Indique el nombre del cultivo de la cosecha a enviar a destino (ej: A)");

	this->itemsMenu[5] = MenuItem("Comprar Terreno",
								  accion::COMPRAR_TERRENO);

	this->itemsMenu[6] = MenuItem("Vender Terreno",
			  	  	  	  	  	  accion::VENDER_TERRENO,
								  "Indique numero de terreno a vender (ej: 3)");

	this->itemsMenu[7] = MenuItem("Ampliar capacidad Tanque",
								  accion::COMPRAR_CAPACIDAD_AGUA);

	this->itemsMenu[8] = MenuItem("Ampliar Almacen",
			  	  	  	  	  	  accion::COMPRAR_CAPACIDAD_ALMACEN);

	this->itemsMenu[9] = MenuItem("Finalizar Turno",
				  	  	  	  	  accion::FINALIZAR_TURNO);
}

Menu::Menu(TipoMenu tipo) {

	this->tipo = PRINCIPAL;
	this->titulo = "";
	this->cantidadItemsMenu = 0;
	this->itemsMenu = NULL;
	this->leyendaIngresoUsuario = "Ingrese una opcion: ";

	switch(tipo){

		case PRINCIPAL:

			crearMenuPrincipal();
			break;

		case CONFIGURACION:

			crearMenuConfiguracion();
			break;

		case ACCIONES:

			crearMenuAcciones();
			break;
	}
}

string Menu::obtenerLeyendaIngresoUsuario(){

	return this->leyendaIngresoUsuario;
}

void Menu::mostrar(){


	cout << endl << this->titulo << endl << endl;

	for(unsigned int iMenuItem = 1; iMenuItem < this->cantidadItemsMenu; iMenuItem++){

		cout << iMenuItem << " - " << this->itemsMenu[iMenuItem].obtenerNombre() << endl;
	}

	cout << endl << "0" << " - " << itemsMenu[0].obtenerNombre() << endl << endl;
}

Respuesta* Menu::ejecutarOpcion(unsigned int opcion){

	return this->itemsMenu[opcion].ejecutar();
}

Menu::~Menu() {

	if(this->itemsMenu != NULL){

		for(unsigned int iMenuItem = 0; iMenuItem < this->cantidadItemsMenu; iMenuItem++){
			if(this->itemsMenu[iMenuItem].obtenerSubMenu() != NULL){
				delete this->itemsMenu[iMenuItem].obtenerSubMenu();
			}
		}
		delete[] this->itemsMenu;
	}
}
