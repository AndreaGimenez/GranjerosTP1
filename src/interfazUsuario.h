/*
 * interfazUsuario.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef INTERFAZUSUARIO_H_
#define INTERFAZUSUARIO_H_

#include <string>
#include "menu.h"
#include "pila.h"

class InterfazUsuario {

private:

	Pila<Menu*> menues;
	bool flagSalir;

public:

	InterfazUsuario();

	void mostrarMenuPrincipal();
	void mostrarMenuPartida();
	unsigned int solicitarOpcion();
	Respuesta ejecutarOpcion(unsigned int opcion);
	void mostrarBienvenida();
	bool salir();
	Menu* obtenerMenuActual();
	void agregarMenu(Menu* menu);
	void irAMenuAnterior();
	void mostrarDespedida();
	void mostrarMenuActual();

	~InterfazUsuario();
};

#endif /* INTERFAZUSUARIO_H_ */
