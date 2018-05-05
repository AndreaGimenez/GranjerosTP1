/*
 * granjeros.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "granjeros.h"
#include <iostream>
#include "utils.h"
#include "configuracion.h"
#include "creadorAcciones.h"

using namespace std;


Granjeros::Granjeros() {
}

bool Granjeros::iniciarJuego(){

	interfaz.mostrarBienvenida();
	CreadorAcciones::inicializar();
	interfaz.cargarMenuPrincipal();


	interfaz.mostrarMenuActual();

	while(!interfaz.salir()){

		unsigned int opcion = interfaz.solicitarOpcion();
		ResultadoOpcion* resultado = interfaz.ejecutarOpcion(opcion);

		if(resultado->obtenerTipo() == resultadoOpcion::ACCION){

			ejecutarAccion(resultado->obtenerAccion());
		}
	}

	interfaz.mostrarDespedida();

	return true;
}

void Granjeros::ejecutarAccion(Accion* accion){

	bool partidaFinalizada = false;

	ejecutarAccionConfiguracion(accion);
	partidaFinalizada = ejecutarAccionPartida(accion);

	if(!partidaFinalizada){
		interfaz.mostrarMenuActual();
	}
}

void Granjeros::ejecutarAccionConfiguracion(Accion* accion){

	switch (accion->obtenerAccion()){

		case accion::CAMBIAR_CANTIDAD_JUGADORES:

			this->parametrosConfiguracion.cambiarCantidadJugadores(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "La cantidad de jugadores ahora es: " << this->parametrosConfiguracion.obtenerCantidadJugadores() << endl;
			break;

		case accion::CAMBIAR_CANTIDAD_TURNOS:

			this->parametrosConfiguracion.cambiarCantidadTurnos(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "La cantidad de turnos ahora es: " << this->parametrosConfiguracion.obtenerCantidadTurnos() << endl;
			break;

		case accion::CAMBIAR_PARAMETRO_M:

			this->parametrosConfiguracion.cambiarParametroM(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "El parametro M ahora es: " << this->parametrosConfiguracion.obtenerParametroM() << endl;
			break;

		case accion::CAMBIAR_PARAMETRO_N:

			this->parametrosConfiguracion.cambiarParametroN(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "El parametro N ahora es: " << this->parametrosConfiguracion.obtenerParametroN() << endl;
			break;

		default:;
	}
}

bool Granjeros::ejecutarAccionPartida(Accion* accion){

	bool partidaFinalizada = false;

	switch (accion->obtenerAccion()){

		case accion::COMPRAR_CAPACIDAD_AGUA:

			//TODO partida.comprarCapacidadAgua();
			cout << "AUMENTO LA CAPACIDAD DEL TANQUE!" << endl;
			break;

		case accion::COMPRAR_CAPACIDAD_ALMACEN:

			//TODO partida.comprarCapacidadAlmacen();
			cout << "AUMENTO LA CAPACIDAD DEL ALMACEN!" << endl;
			break;

		case accion::COMPRAR_TERRENO:

			//TODO partida.comprarTerreno();
			cout << "COMPRASTE UN TERRENO!" << endl;
			break;

		case accion::COSECHAR:

			//TODO partida.cosechar();
			cout << "COSECHASTE!" << endl;
			break;

		case accion::ENVIAR_COSECHA:

			//TODO partida.enviarCosecha);
			cout << "ENVIASTE LA COSECHA!" << endl;
			break;

		case accion::JUGAR:

			comenzarPartida();
			break;

		case accion::REGAR:

			//TODO partida.regar();
			cout << "REGASTE!" << endl;
			break;

		case accion::SEMBRAR:

			//TODO partida.sembrar();
			cout << "SEMBRASTE!" << endl;
			break;
		case accion::VENDER_TERRENO:

			//TODO partida.venderTerreno();
			cout << "VENDISTE UN TERRENO!" << endl;
			break;

		case accion::FINALIZAR_TURNO:

			partidaFinalizada = avanzarTurno();
			break;

		case accion::SALIR:

			interfaz.irAMenuAnterior();
			break;

		default:;
	}

	return partidaFinalizada;
}

void Granjeros::comenzarPartida(){

	Lista<string> nombresJugadores;
	interfaz.solicitarNombresJugadores(this->parametrosConfiguracion.obtenerCantidadJugadores(), nombresJugadores);

	Configuracion::inicializar(this->parametrosConfiguracion);
	interfaz.cargarMenuPartida();

	//TODO: partida.inicializarPartida(nombresJugadores);
	//TODO: interfaz.mostrarEstadoPartida(partida);
}

bool Granjeros::avanzarTurno(){

	bool finPartida = false;
	//TODO: //partida.avanzarTurno(); avanzarTurno deberia avanzar el jugador y si es necesario cambiar la ronda. Tambien tiene que actualizar el estado del jugador, sus recursos (cambia de estado tambien las parcelas).
	//		Debería devolver true si la partida se finalizo.
	//finPartida = partida.avanzarTurno();

	//TODO: Este metodo generaria el bmp y mostraria el jugador y el estado actual de ese jugador.
	//		Como primero se llama a avanzarTurno el jugadorActual deberia ser el jugador que le toca jugar esta ronda
	//interfaz.mostrarEstadoPartida(partida);

	return finPartida;
}

Granjeros::~Granjeros(){
}
