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
#include "configuracion.h"

using namespace std;

unsigned int Granjeros::cantidadAcciones = 16;
Accion** Granjeros::acciones = NULL;

Granjeros::Granjeros() {
}

bool Granjeros::iniciarJuego(){

	interfaz.mostrarBienvenida();
	interfaz.cargarMenuPrincipal();
	cargarAcciones();

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

void Granjeros::destruirAcciones(){

	for(unsigned int iAccion = 0; iAccion < 16; iAccion++){
		delete acciones[iAccion];
	}
	delete[] acciones;
}

void Granjeros::ejecutarAccion(Accion* accion){

	bool partidaFinalizada = false;

	partidaFinalizada = ejecutarAccionConfiguracion(accion);
	partidaFinalizada = ejecutarAccionPartida(accion);

	if(!partidaFinalizada){
		interfaz.mostrarMenuActual();
	}
}

bool Granjeros::ejecutarAccionConfiguracion(Accion* accion){

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

	return false;
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
	//TODO: //partida.avanzarTurno(); avanzarTurno deberia avanzar el jugador y si es necesario cambiar la ronda. Debería devolver true si la partida se finalizo.
	//finPartida = partida.avanzarTurno();

	//TODO: Este metodo generaria el bmp y mostraria el jugador y el estado actual de ese jugador.
	//		Como primero se llama a avanzarTurno el jugadorActual deberia ser el jugador que le toca jugar esta ronda
	//interfaz.mostrarEstadoPartida(partida);

	return finPartida;
}

Accion* Granjeros::crearNuevaAccion(accion::EAccion accion){

	Accion* nuevaAccion = new Accion(acciones[accion]);
	return nuevaAccion;
}

Granjeros::~Granjeros(){

	destruirAcciones();
}
