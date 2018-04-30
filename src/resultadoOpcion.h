/*
 * respuestaMenu.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef RESULTADOOPCION_H_
#define RESULTADOOPCION_H_

#ifndef NULL
#define NULL 0
#endif

#include "menu.h"
#include "accion.h"

//Para cortar la referencia circular
class Menu;

namespace resultadoOpcion{

	enum Tipo{

		SUBMENU,
		ACCION
	};
}

class ResultadoOpcion {

private:

	resultadoOpcion::Tipo tipo;
	Menu* subMenu;
	Accion* accion;

	void inicializar(resultadoOpcion::Tipo tipo, Menu* subMenu, accion::EAccion accion);

public:

	ResultadoOpcion();
	ResultadoOpcion(Menu* subMenu);
	ResultadoOpcion(accion::EAccion accion);

	resultadoOpcion::Tipo obtenerTipo();
	Menu* obtenerSubMenu();
	Accion* obtenerAccion();

	~ResultadoOpcion();
};

#endif /* RESPUESTAMENU_H_ */
