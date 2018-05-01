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

	Menu* menuPrincipal;
	Menu* menuPartida;

	Pila<Menu*> menues;

	Menu* crearMenuPrincipal();
	Menu* crearMenuConfiguracion();
	Menu* crearMenuPartida();
	void agregarMenu(Menu* menu);

public:

	InterfazUsuario();

	void mostrarBienvenida();
	void solicitarNombresJugadores(unsigned int cantidadJugadores, Lista<std::string>& listaNombres);
	void cargarMenuPrincipal();
	void cargarMenuPartida();
	Menu* obtenerMenuActual();
	void mostrarMenuActual();
	void irAMenuAnterior();
	unsigned int solicitarOpcion();
	ResultadoOpcion* ejecutarOpcion(unsigned int opcion);
	bool salir();
	void mostrarDespedida();

	~InterfazUsuario();
};

#endif /* INTERFAZUSUARIO_H_ */
