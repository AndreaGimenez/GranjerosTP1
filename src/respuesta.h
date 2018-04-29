/*
 * respuestaMenu.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_

#ifndef NULL
#define NULL 0
#endif

#include "menu.h"
#include "accion.h"

//Para cortar la referencia circular
class Menu;

namespace respuesta{

	enum Tipo{

		SUBMENU,
		ACCION
	};
}

class Respuesta {

private:

	respuesta::Tipo tipo;
	Menu* subMenu;
	Accion* accion;

	void inicializar(respuesta::Tipo tipo, Menu* subMenu, Accion* accion);

public:

	Respuesta();
	Respuesta(Menu* subMenu);
	Respuesta(Accion* accion);

	respuesta::Tipo obtenerTipo();
	Menu* obtenerSubMenu();
	Accion* obtenerAccion();
};

#endif /* RESPUESTAMENU_H_ */
