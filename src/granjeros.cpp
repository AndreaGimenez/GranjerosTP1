/*
 * granjeros.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "granjeros.h"
#include <iostream>
#include <cstdlib>
#include "utils.h"

using namespace std;

unsigned int Granjeros::cantidadAcciones = 16;
Accion** Granjeros::acciones = NULL;

Granjeros::Granjeros() {
	// TODO Auto-generated constructor stub

}

bool Granjeros::jugar(){

	interfaz.mostrarBienvenida();
	interfaz.mostrarMenuPrincipal();

	cargarAcciones();

	while(!interfaz.salir()){

		unsigned int opcion = interfaz.solicitarOpcion();
		Respuesta* respuesta = interfaz.ejecutarOpcion(opcion);

		if(respuesta->obtenerTipo() == respuesta::ACCION){

			ejecutarAccionPartida(respuesta->obtenerAccion());
		}
	}

	interfaz.mostrarDespedida();

	return true;
}

void Granjeros::ejecutarAccionPartida(Accion* accion){

	switch (accion->obtenerAccion()){

			case accion::CAMBIAR_CANTIDAD_JUGADORES:

				this->parametros.cambiarCantidadJugadores(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
				cout << "La cantidad de jugadores ahora es: " << this->parametros.obtenerCantidadJugadores() << endl;
				break;

			case accion::CAMBIAR_CANTIDAD_TURNOS:

				this->parametros.cambiarCantidadTurnos(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
				cout << "La cantidad de turnos ahora es: " << this->parametros.obtenerCantidadTurnos() << endl;
				break;

			case accion::CAMBIAR_PARAMETRO_M:

				this->parametros.cambiarParametroM(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
				cout << "El parametro M ahora es: " << this->parametros.obtenerParametroM() << endl;
				break;

			case accion::CAMBIAR_PARAMETRO_N:

				this->parametros.cambiarParametroN(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
				cout << "El parametro N ahora es: " << this->parametros.obtenerParametroN() << endl;
				break;

			case accion::COMPRAR_CAPACIDAD_AGUA:

				cout << "AUMENTO LA CAPACIDAD DEL TANQUE!" << endl;
				break;

			case accion::COMPRAR_CAPACIDAD_ALMACEN:

				cout << "AUMENTO LA CAPACIDAD DEL ALMACEN!" << endl;
				break;

			case accion::COMPRAR_TERRENO:

				cout << "COMPRASTE UN TERRENO!" << endl;
				break;

			case accion::COSECHAR:

				cout << "COSECHASTE!" << endl;
				break;

			case accion::ENVIAR_COSECHA:

				cout << "ENVIASTE LA COSECHA!" << endl;
				break;

			case accion::JUGAR:

				cout << "EMPEZO EL JUEGO!" << endl;
				break;

			case accion::REGAR:

				cout << "REGASTE!" << endl;
				break;

			case accion::SEMBRAR:
				cout << "SEMBRASTE!" << endl;
				break;
			case accion::VENDER_TERRENO:

				cout << "VENDISTE UN TERRENO!" << endl;
				break;

			case accion::FINALIZAR_TURNO:

				//Aca la partida define si tiene que pasar al jugador siguiente o cambiar de ronda
				cout << "AVANZAR TURNO!" << endl;
				break;

			case accion::SALIR:

				interfaz.irAMenuAnterior();
				break;

			default:;
	}

	interfaz.mostrarMenuActual();
}


void Granjeros::cargarAcciones(){

	acciones = new Accion*[cantidadAcciones];
	acciones[0] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::NINGUNA);
	acciones[1] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::CAMBIAR_CANTIDAD_JUGADORES, 1);
	acciones[2] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::CAMBIAR_PARAMETRO_N, 1);
	acciones[3] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::CAMBIAR_PARAMETRO_M, 1);
	acciones[4] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::CAMBIAR_CANTIDAD_TURNOS, 1);
	acciones[5] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::SEMBRAR, 2);
	acciones[6] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::REGAR, 1);
	acciones[7] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::COSECHAR, 1);
	acciones[8] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::ENVIAR_COSECHA, 1);
	acciones[9] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::COMPRAR_TERRENO);
	acciones[10] = new Accion(accion::CON_PARAMETROS_USUARIO, accion::VENDER_TERRENO, 1);
	acciones[11] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::COMPRAR_CAPACIDAD_AGUA);
	acciones[12] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::COMPRAR_CAPACIDAD_ALMACEN);
	acciones[13] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::FINALIZAR_TURNO);
	acciones[14] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::JUGAR);
	acciones[15] = new Accion(accion::SIN_PARAMETROS_USUARIO, accion::SALIR);
}

Accion* Granjeros::crearNuevaAccion(accion::EAccion accion){

	Accion* nuevaAccion = new Accion(acciones[accion]);
	return nuevaAccion;
}

void Granjeros::destruirAcciones(){
	delete[] acciones;
}
