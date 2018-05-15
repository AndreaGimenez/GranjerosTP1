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
#include "partida.h"

/*
 * 'InterfazUsuario' permite la interaccion con el usuario, tanto la salida como la entrada.
 * Se encarga de crear los menues y gestionarlos. Permite cargar y mostrar los menues principal
 * y de la partida así como ejecutar las acciones de esos menues.
 */
class InterfazUsuario {

private:

	Menu* menuPrincipal;
	Menu* menuPartida;

	Pila<Menu*> menues;

	Menu* crearMenuPrincipal();
	Menu* crearMenuConfiguracion();
	Menu* crearMenuPartida();
	void agregarMenu(Menu* menu);

	void mostrarDatosPartida(Partida* partida);
	void mostrarRecursosJugador(Jugador* jugador);
	void mostrarTerrenosJugadorPorConsola(Jugador* jugador);
	void mostrarTerrenosJugadorPorImagen(Jugador* jugador);
	void mostrarGanador(unsigned int cantidadJugadores, Jugador** jugadores);
	void mostrarPosiciones(unsigned int cantidadJugadores, Jugador** jugadores);

public:

	/*
	 * Pos: Inicializa la interfaz para comenzar a interactuar.
	 */
	InterfazUsuario();

	/*
	 * Pos: Muestra por pantalla un mensaje de bienvenida.
	 */
	void mostrarBienvenida();

	/*
	 * Pre: 'cantidadJugadores' debe ser mayor a 0.
	 * Pos: Solicita al usuario el ingreso de 'cantidadJugadores' nombres y los almacena en 'listaNombres'.
	 */
	void solicitarNombresJugadores(unsigned int cantidadJugadores, Lista<std::string>& listaNombres);

	/*
	 * Pos: Carga en la interfaz el menu principal, el mismo pasa a ser el menu actual. No lo muestra por pantalla.
	 */
	void cargarMenuPrincipal();

	/*
	 * Pos: Carga en la interfaz el menu de partida, el mismo pasa a ser el menu actual. No lo muestra por pantalla.
	 */
	void cargarMenuPartida();

	/*
	 * Pos: Devuelve el ultimo menu cargado. En caso de no haber ningun menu cargado devuelve NULL.
	 */
	Menu* obtenerMenuActual();

	/*
	 * Pos: Muestra por pantalla el ultimo menu cargado.
	 */
	void mostrarMenuActual();

	/*
	 * Pos: Actualiza el menu actual al menu anterior.
	 */
	void irAMenuAnterior();

	/*
	 * Pos: Solicita al usuario el ingreso de una de las opciones del menu actual y devuelve el numero de opcion elegida.
	 */
	unsigned int solicitarOpcion();

	/*
	 * Pos: Ejecuta el numero de opcion pasado por parametro y devuelve el resultado de la ejecucion.
	 */
	ResultadoOpcion* ejecutarOpcion(unsigned int numeroOpcion);

	/*
	 * Pos: Indica si el usuario salio del primero menu que se genero con la interfaz.
	 */
	bool salir();

	/*
	 * Pos: Muestra los terrenos del jugador que esta jugando
	 */
	void mostrarTerrenosJugador(Jugador* jugador);	

	/*
	 * Pos: Muestra por pantalla un mensaje de despedida.
	 */
	void mostrarDespedida();

	/*
	 * Pos: Crea un archivo BMP con el estado del jugador actual de la partida.
	 */
	void mostrarEstadoPartida(Partida* partida);

	// Post: Muesta por pantalla el resumen de la partida jugada. Determina el ganador de la partida y los recursos finales de cada jugador.
	void mostrarResumenPartida(Partida* partida);

	/*
	 * Pos: Libera los recursos reservados.
	 */
	~InterfazUsuario();
};

#endif /* INTERFAZUSUARIO_H_ */
