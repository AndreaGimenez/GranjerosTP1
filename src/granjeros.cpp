/*
 * granjeros.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "granjeros.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Granjeros::Granjeros() {
	// TODO Auto-generated constructor stub

}

bool Granjeros::jugar(){

	interfaz.mostrarBienvenida();
	interfaz.mostrarMenuPrincipal();

	while(!interfaz.salir()){

		unsigned int opcion = interfaz.solicitarOpcion();
		Respuesta respuesta = interfaz.ejecutarOpcion(opcion);

		if(respuesta.obtenerTipo() == respuesta::ACCION){
			ejecutarAccionPartida(respuesta.obtenerAccion());
		}
	}

	interfaz.mostrarDespedida();

	return true;
}

void Granjeros::ejecutarAccionPartida(Accion* accion){

	//Lista<string>* parametros;
	//Lista<void*> parametrosConvertidos;

	Lista<void*>* parametrosConvertidos;

	switch (accion->obtenerAccion()){

			case accion::CAMBIAR_CANTIDAD_JUGADORES:
				parametrosConvertidos = accion->obtenerParametrosConvertidos();

				this->parametros.cambiarCantidadJugadores(*((int*)parametrosConvertidos->obtener(1)));
/*
				parametros = accion->obtenerParametros();


				parametros->iniciarCursor();
				while(parametros->avanzarCursor()){
					int* valor = new int;
					*valor = atoi(parametros->obtenerCursor().c_str());
					parametrosConvertidos.agregar(valor);
				}
				this->parametros.cambiarCantidadJugadores(*((int*)parametrosConvertidos.obtener(1)));

				parametros->iniciarCursor();
				while(parametrosConvertidos.avanzarCursor()){
					delete ((int*)parametrosConvertidos.obtenerCursor());
				}
*/
				cout << "CAMBIE LA CANTIDAD DE JUGADORES!" << endl;
				break;
			case accion::CAMBIAR_CANTIDAD_TURNOS:
				cout << "CAMBIE LA CANTIDAD DE TURNOS!" << endl;
				break;
			case accion::CAMBIAR_PARAMETRO_M:
				cout << "CAMBIE EL PARAMETRO M!" << endl;
				break;
			case accion::CAMBIAR_PARAMETRO_N:
				cout << "CAMBIE EL PARAMETRO N!" << endl;
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
	}

	interfaz.mostrarMenuActual();
}
