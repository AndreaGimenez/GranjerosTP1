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
								  new Accion(accion::SALIR));
}

void Menu::crearMenuPrincipal() {

	this->inicializarMenu(PRINCIPAL, "MENU PRINCIPAL", 2);
	this->itemsMenu[1] = MenuItem("Configuracion",
								  new Menu(CONFIGURACION));
	this->itemsMenu[2] = MenuItem("Jugar",
								  new Accion(accion::JUGAR));
}

void Menu::crearMenuConfiguracion() {

	this->inicializarMenu(CONFIGURACION, "CONFIGURACION", 4);

	parametro::Tipo tiposParametros[] = {parametro::INT};
	this->itemsMenu[1] = MenuItem("Cambiar Cantidad de Jugadores",
								  new Accion(accion::CAMBIAR_CANTIDAD_JUGADORES, 1, tiposParametros),
								  "Indique la cantidad de jugadores");
	this->itemsMenu[2] = MenuItem("Cambiar Parametro N",
								  new Accion(accion::CAMBIAR_PARAMETRO_N, 1, tiposParametros),
								  "Indique el nuevo valor del parametro: ");
	this->itemsMenu[3] = MenuItem("Cambiar Parametro M",
								  new Accion(accion::CAMBIAR_PARAMETRO_M, 1, tiposParametros),
								  "Indique el nuevo valor del parametro");
	this->itemsMenu[4] = MenuItem("Cambiar Cantidad de Turnos",
								  new Accion(accion::CAMBIAR_CANTIDAD_TURNOS, 1, tiposParametros),
								  "Indique la cantidad de turnos a jugar en cada partida");
}

void Menu::crearMenuAcciones() {

	this->inicializarMenu(ACCIONES, "ACCIONES", 9);

	parametro::Tipo tiposParametros[] = {parametro::STRING, parametro::CHAR};
	this->itemsMenu[1] = MenuItem("Sembrar",
			  	  	  	  	  	  new Accion(accion::SEMBRAR, 2, tiposParametros),
								  "Indique, separando con espacios, las coordenadas de la parcela y el cultivo a sembrar (ej: 1,2 A)");

	parametro::Tipo tiposParametros2[] = {parametro::STRING};
	this->itemsMenu[2] = MenuItem("Cosechar",
								  new Accion(accion::COSECHAR, 1, tiposParametros2),
								  "Indique las coordenadas de la parcela a cosechar (ej: 1,2)");

	this->itemsMenu[3] = MenuItem("Regar",
								  new Accion(accion::REGAR, 1, tiposParametros),
								  "Indique las coordenadas de la parcela a regar (ej 1,2)");

	parametro::Tipo tiposParametros3[] = {parametro::CHAR};
	this->itemsMenu[4] = MenuItem("Enviar Cosecha",
								  new Accion(accion::ENVIAR_COSECHA, 1, tiposParametros3),
								  "Indique el nombre del cultivo de la cosecha a enviar a destino (ej: A)");

	this->itemsMenu[5] = MenuItem("Comprar Terreno",
								  new Accion(accion::COMPRAR_TERRENO));

	parametro::Tipo tiposParametros4[] = {parametro::INT};
	this->itemsMenu[6] = MenuItem("Vender Terreno",
			  	  	  	  	  	  new Accion(accion::VENDER_TERRENO, 1, tiposParametros4),
								  "Indique numero de terreno a vender (ej: 3)");

	this->itemsMenu[7] = MenuItem("Ampliar capacidad Tanque",
								  new Accion(accion::COMPRAR_CAPACIDAD_AGUA));

	this->itemsMenu[8] = MenuItem("Ampliar Almacen",
			  	  	  	  	  	  new Accion(accion::COMPRAR_CAPACIDAD_ALMACEN));

	this->itemsMenu[9] = MenuItem("Finalizar Turno",
				  	  	  	  	  	  new Accion(accion::FINALIZAR_TURNO));
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

	cout << endl;
	cout << this->titulo << endl << endl;

	for(unsigned int iMenuItem = 1; iMenuItem < this->cantidadItemsMenu; iMenuItem++){

		cout << iMenuItem << " - " << this->itemsMenu[iMenuItem].obtenerNombre() << endl;
	}

	cout << endl;
	cout << "0" << " - " << itemsMenu[0].obtenerNombre() << endl << endl;
}

Respuesta Menu::ejecutarOpcion(unsigned int opcion){

	return this->itemsMenu[opcion].ejecutar();
}

Menu::~Menu() {

	if(this->itemsMenu != NULL){

		for(unsigned int iMenuItem = 0; iMenuItem < this->cantidadItemsMenu; iMenuItem++){
			if(this->itemsMenu[iMenuItem].obtenerAccion() != NULL){
				delete this->itemsMenu[iMenuItem].obtenerAccion();
			}
			if(this->itemsMenu[iMenuItem].obtenerSubMenu() != NULL){
				delete this->itemsMenu[iMenuItem].obtenerSubMenu();
			}
		}
		delete[] this->itemsMenu;
	}
}
