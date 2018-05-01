/*
 * menuItem.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef OPCIONMENU_H_
#define OPCIONMENU_H_

#ifndef NULL
#define NULL 0
#endif

#include <string>
#include "menu.h"
#include "resultadoOpcion.h"
#include "accion.h"

//Para cortar la referencia circular
class Menu;
class ResultadoOpcion;

namespace opcionMenu{

	enum Tipo{

		SUBMENU,
		ACCION
	};
}

class OpcionMenu {

private:

	opcionMenu::Tipo tipo;
	std::string nombre;

	//Atributos para items que contienen submenues
	Menu* subMenu;

	//Atributos para items de tipo accion
	std::string leyendaIngresoUsuario;
	accion::EAccion accion;

	//Para devolver luego de ejecutar la opcion
	ResultadoOpcion* respuesta;

	void inicializarMenu(opcionMenu::Tipo tipo, std::string nombre, Menu* subMenu, accion::EAccion accion);

public:

	OpcionMenu();
	OpcionMenu(std::string nombre, Menu* subMenu);
	OpcionMenu(std::string nombre, accion::EAccion accion);
	OpcionMenu(std::string nombre, accion::EAccion accion, std::string leyendaIngresoUsuario);

	std::string obtenerNombre();
	accion::EAccion obtenerAccion();
	Menu* obtenerSubMenu();
	ResultadoOpcion* ejecutar();

	~OpcionMenu();
};

#endif /* OPCIONMENU_H_ */
