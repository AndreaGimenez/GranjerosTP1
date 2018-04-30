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
#include "menuItem.h"
#include "resultadoOpcion.h"

//Para cortar la referencia circular
class MenuItem;

enum TipoMenu{

	PRINCIPAL,
	CONFIGURACION,
	JUEGO
};

class Menu {

private:

	TipoMenu tipo;
	unsigned int cantidadItemsMenu;
	MenuItem* itemsMenu ;
	std::string titulo;
	std::string leyendaIngresoUsuario;

	void inicializarMenu(TipoMenu tipo, std::string titulo, unsigned int cantidadItems);
	void crearMenuPrincipal();
	void crearMenuConfiguracion();
	void crearMenuJuego();

public:

	Menu(TipoMenu tipo);

	std::string obtenerLeyendaIngresoUsuario();
	void mostrar();
	ResultadoOpcion* ejecutarOpcion(unsigned int opcion);

	~Menu();
};

#endif /* MENU_H_ */
