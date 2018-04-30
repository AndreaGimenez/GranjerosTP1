/*
 * menuItem.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#ifndef NULL
#define NULL 0
#endif

#include <string>
#include "menu.h"
#include "respuesta.h"
#include "accion.h"

//Para cortar la referencia circular
class Menu;
class Respuesta;

namespace menuItem{

	enum Tipo{

		SUBMENU,
		ACCION
	};
}

class MenuItem {

private:

	menuItem::Tipo tipo;
	std::string nombre;

	//Atributos para items que contienen submenues
	Menu* subMenu;

	//Atributos para items de tipo accion
	std::string leyendaIngresoUsuario;
	accion::EAccion accion;

	//Para devolver luego de ejecutar la opcion
	Respuesta* respuesta;

	void inicializarMenu(menuItem::Tipo tipo, std::string nombre, Menu* subMenu, accion::EAccion accion);

public:

	MenuItem();
	MenuItem(std::string nombre, Menu* subMenu);
	MenuItem(std::string nombre, accion::EAccion accion);
	MenuItem(std::string nombre, accion::EAccion accion, std::string leyendaIngresoUsuario);

	std::string obtenerNombre();
	accion::EAccion obtenerAccion();
	Menu* obtenerSubMenu();
	Respuesta* ejecutar();

	~MenuItem();
};

#endif /* MENUITEM_H_ */
