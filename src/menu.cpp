#include "menu.h"
#include <iostream>
#include "utils.h"

using namespace std;

Menu::Menu(string titulo, unsigned int cantidadItemsMenu) {

	this->titulo = titulo;
	this->cantidadOpciones = cantidadItemsMenu + 1;
	this->opciones = new OpcionMenu[cantidadItemsMenu + 1];
	this->leyendaIngresoUsuario = "Ingrese una opcion";
	this->opciones[0] = OpcionMenu("Salir", accion::SALIR);
}

Menu::Menu(string titulo, unsigned int cantidadItemsMenu, bool agregarOpcionSalir) {

	this->titulo = titulo;
	this->leyendaIngresoUsuario = "Ingrese una opcion";

	if(agregarOpcionSalir){
		this->cantidadOpciones = cantidadItemsMenu + 1;
		this->opciones = new OpcionMenu[cantidadItemsMenu + 1];
		this->opciones[0] = OpcionMenu("Salir", accion::SALIR);
	}else{
		this->cantidadOpciones = cantidadItemsMenu;
		this->opciones = new OpcionMenu[cantidadItemsMenu];
	}
}

void Menu::cambiarOpcion(unsigned int indice, OpcionMenu opcion){

	this->opciones[indice] = opcion;
}

unsigned int Menu::solicitarOpcion(){

	bool opcionValida = false;
	string opcionElegida = "";

	while(!opcionValida){

		cout << this->obtenerLeyendaIngresoUsuario() << ": ";
		cout.flush();

		getline(cin, opcionElegida);

		opcionValida = validarOpcionElegida(opcionElegida);
		if(!opcionValida){
			cout << "La opcion ingresada no es valida" << endl;
		}
	}

	return Utils::stringToUnsignedInt(opcionElegida);
}

bool Menu::validarOpcionElegida(std::string opcionElegida){

	return (Utils::esUnsignedInt(opcionElegida)
			&& Utils::stringToUnsignedInt(opcionElegida) >= 0
			&& Utils::stringToUnsignedInt(opcionElegida) < this->cantidadOpciones);
}

ResultadoOpcion* Menu::ejecutarOpcion(unsigned int opcion){

	return this->opciones[opcion].ejecutar();
}

string Menu::obtenerLeyendaIngresoUsuario(){

	return this->leyendaIngresoUsuario;
}

void Menu::mostrar(){


	cout << endl << this->titulo << endl << endl;

	for(unsigned int iMenuItem = 1; iMenuItem < this->cantidadOpciones; iMenuItem++){

		cout << iMenuItem << " - " << this->opciones[iMenuItem].obtenerDescripcion() << endl;
	}

	cout << endl << "0" << " - " << opciones[0].obtenerDescripcion() << endl << endl;
}

Menu::~Menu() {

	if(this->opciones != NULL){

		for(unsigned int iMenuItem = 0; iMenuItem < this->cantidadOpciones; iMenuItem++){
			if(this->opciones[iMenuItem].obtenerSubMenu() != NULL){
				delete this->opciones[iMenuItem].obtenerSubMenu();
			}
		}
		delete[] this->opciones;
	}
}
