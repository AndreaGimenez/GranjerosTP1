/*
 * menu.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef MENU_H_
#define MENU_H_

#ifndef NULL
#define NULL 0
#endif

#include <string>
#include "opcionMenu.h"
#include "resultadoOpcion.h"

//Para cortar la referencia circular
class OpcionMenu;

class Menu {

private:

	std::string titulo;
	std::string leyendaIngresoUsuario;
	unsigned int cantidadItemsMenu;
	OpcionMenu* opciones;

public:

	Menu(std::string titulo, unsigned int cantidadOpciones);

	void cambiarOpcion(unsigned int indice, OpcionMenu opcion);
	ResultadoOpcion* ejecutarOpcion(unsigned int opcion);
	std::string obtenerLeyendaIngresoUsuario();
	void mostrar();

	~Menu();
};

#endif /* MENU_H_ */
