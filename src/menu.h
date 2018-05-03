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

/*
 * Un 'Menu' es un conjunto de opciones de diferente tipo y una entrada que permite al usuario seleccionar una de las opciones mostradas.
 * Permite indicar un titulo que sera mostrado al mostrarse el menu en pantalla, metodos para mostrar el menu en pantalla
 * y obtener la opcion seleccionada del usuario.
 * Las opciones se listan de 1 a N (donde en es la cantidad de opciones indicada) y se agrega la opcion 0: SALIR que permite volver al menu anterior.
 */
class Menu {

private:

	std::string titulo;
	std::string leyendaIngresoUsuario;
	unsigned int cantidadOpciones;
	OpcionMenu* opciones;

public:

	/*
	 * Pos: Inicializa un menu con 'cantidadOpciones' y un 'titulo'. El titulo se imprimirá al mostrarse el menu (mostrar()).
	 * 		Inicialmente las opciones de menu se crean con tipo SUBMENU pero sin ningun dato dentro (sin submenu, ni accion, ni descripcion).
	 * 		Las opciones de menu deben cambiarse por opciones validas con el metodo 'cambiarOpcion'.
	 */
	Menu(std::string titulo, unsigned int cantidadOpciones);

	/*
	 * Pos: Devuelve el titulo del menu.
	 */
	std::string obtenerTitulo();

	/*
	 * Pos: Devuelve la leyenda que se muestra al usuario al momento de solicitar el ingreso de una opcion.
	 */
	std::string obtenerLeyendaIngresoUsuario();

	/*
	 * Pos: Devuelve la cantidad de opciones que tiene el menu.
	 */
	unsigned int obtenerCantidadOpciones();

	/*
	 * Pos: Devuelve las opciones del menu.
	 */
	OpcionMenu* obtenerOpciones();

	/*
	 * Pre: 'numeroOpcion' debe ser mayor a 0 y menor o igual que 'obtenerCantidadOpciones'.
	 * Pos: Cambia la opcion de menu que se encuentra en el numero 'numeroOpcion'.
	 */
	void cambiarOpcion(unsigned int numeroOpcion, OpcionMenu opcion);

	/*
	 * Pos: Devuelve el numero de opcion elegida por el usuario;
	 */
	unsigned int solicitarOpcion();

	/*
	 * Pre: 'numeroOpcion' debe ser mayor a 0 y menor o igual que 'obtenerCantidadOpciones'.
	 * Pos: Ejecuta la opcion asociada a 'numeroOpcion' y devuelve el resultado de la ejecucion.
	 */
	ResultadoOpcion* ejecutarOpcion(unsigned int numeroOpcion);

	/*
	 * Pos: Muestra el menu en pantalla. Primero muestra el titulo y luego las opciones ordenadas de 1 a 'obtenerCantidadOpciones'.
	 * 		Al final y separada del resto se imprime la opcion Salir.
	 */
	void mostrar();

	/*
	 * Pos: Libera los recursos reservados.
	 */
	~Menu();
};

#endif /* MENU_H_ */
