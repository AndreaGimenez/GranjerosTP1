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

	this->parametrosConfiguracion = new ParametroConfiguracion;
	this->interfaz = new InterfazUsuario;
	this->partida = NULL;
}

bool Granjeros::iniciarJuego(){

	interfaz->mostrarBienvenida();
	CreadorAcciones::inicializar();
	interfaz->cargarMenuPrincipal();


	interfaz->mostrarMenuActual();

	while(!interfaz->salir()){

		unsigned int opcion = interfaz->solicitarOpcion();
		ResultadoOpcion* resultado = interfaz->ejecutarOpcion(opcion);

		if(resultado->obtenerTipo() == resultadoOpcion::ACCION){

			ejecutarAccion(resultado->obtenerAccion());
		}
	}

	interfaz->mostrarDespedida();

	return true;
}

void Granjeros::ejecutarAccion(Accion* accion){

	bool partidaFinalizada = false;

	ejecutarAccionConfiguracion(accion);
	partidaFinalizada = ejecutarAccionPartida(accion);

	if(!partidaFinalizada){
		interfaz->mostrarMenuActual();
	}
}

void Granjeros::ejecutarAccionConfiguracion(Accion* accion){

	switch (accion->obtenerAccion()){

		case accion::CAMBIAR_CANTIDAD_JUGADORES:

			this->parametrosConfiguracion->cambiarCantidadJugadores(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "La cantidad de jugadores ahora es: " << this->parametrosConfiguracion->obtenerCantidadJugadores() << endl;
			break;

		case accion::CAMBIAR_CANTIDAD_TURNOS:

			this->parametrosConfiguracion->cambiarCantidadTurnos(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "La cantidad de turnos ahora es: " << this->parametrosConfiguracion->obtenerCantidadTurnos() << endl;
			break;

		case accion::CAMBIAR_PARAMETRO_M:

			this->parametrosConfiguracion->cambiarParametroM(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "El parametro M ahora es: " << this->parametrosConfiguracion->obtenerParametroM() << endl;
			break;

		case accion::CAMBIAR_PARAMETRO_N:

			this->parametrosConfiguracion->cambiarParametroN(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "El parametro N ahora es: " << this->parametrosConfiguracion->obtenerParametroN() << endl;
			break;

		default:;
	}
}

bool Granjeros::ejecutarAccionPartida(Accion* accion){

	bool partidaFinalizada = false;

	switch (accion->obtenerAccion()){

		case accion::COMPRAR_CAPACIDAD_AGUA:

			partida->ejecutarAccionComprarCapacidadAgua();
			cout << "AUMENTO LA CAPACIDAD DEL TANQUE!" << endl;
			break;

		case accion::COMPRAR_CAPACIDAD_ALMACEN:

			partida->ejecutarAccionComprarCapacidadAlmacen();
			cout << "AUMENTO LA CAPACIDAD DEL ALMACEN!" << endl;
			break;

		case accion::COMPRAR_TERRENO:

			partida->ejecutarAccionComprarTerreno();
			cout << "COMPRASTE UN TERRENO!" << endl;
			break;

		case accion::COSECHAR:

			partida->ejecutarAccionCosechar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]), accion->obtenerParametros()[1]);
			cout << "COSECHASTE!" << endl;
			break;

		case accion::ENVIAR_COSECHA:

			partida->ejecutarAccionEnviarCosecha(accion->obtenerParametros()[0]);
			cout << "ENVIASTE LA COSECHA!" << endl;
			break;

		case accion::JUGAR:

			this->comenzarPartida();
			break;

		case accion::REGAR:

			partida->ejecutarAccionRegar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]), accion->obtenerParametros()[1]);
			cout << "REGASTE!" << endl;
			break;

		case accion::SEMBRAR:

			partida->ejecutarAccionSembrar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]), accion->obtenerParametros()[1], accion->obtenerParametros()[2]);
			cout << "SEMBRASTE!" << endl;
			break;
		case accion::VENDER_TERRENO:

			partida->ejecutarAccionVenderTerreno(Utils::stringToUnsignedInt(accion->obtenerParametros()[0]));
			cout << "VENDISTE UN TERRENO!" << endl;
			break;

		case accion::FINALIZAR_TURNO:

			partidaFinalizada = avanzarTurno();
			break;

		case accion::SALIR:

			interfaz->irAMenuAnterior();
			break;

		default:;
	}

	return partidaFinalizada;
}

void Granjeros::comenzarPartida(){

	Lista<string> nombresJugadores;
	interfaz->solicitarNombresJugadores(this->parametrosConfiguracion->obtenerCantidadJugadores(), nombresJugadores);

	Configuracion::inicializar(this->parametrosConfiguracion);
	interfaz->cargarMenuPartida();

	partida = new Partida(&nombresJugadores);
	interfaz->mostrarEstadoPartida(partida);
}

bool Granjeros::avanzarTurno(){

	//avanzarTurno deberia avanzar el jugador y si es necesario cambiar la ronda. Tambien tiene que actualizar el estado del jugador, sus recursos (cambia de estado tambien las parcelas).
	//Debería devolver true si la partida se finalizo.
	bool finPartida = partida->avanzarTurno();

	//TODO: Este metodo generaria el bmp y mostraria el jugador y el estado actual de ese jugador.
	//		Como primero se llama a avanzarTurno el jugadorActual deberia ser el jugador que le toca jugar esta ronda

	if(!finPartida){

		interfaz->mostrarEstadoPartida(partida);
	}

	return finPartida;
}

Granjeros::~Granjeros(){

	delete this->parametrosConfiguracion;
	delete this->interfaz;

	if(this->partida != NULL){
		delete this->partida;
	}
}
