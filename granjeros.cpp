/*
 * granjeros.cpp
 *
 *  Created on: 29 abr. 2018
 *      Author: administrador
 */

#include "granjeros.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "utils.h"
#include "configuracion.h"
#include "creadorAcciones.h"

using namespace std;


Granjeros::Granjeros() {

	this->parametrosConfiguracion = new ParametroConfiguracion;
	this->interfaz = new InterfazUsuario;
	this->partida = NULL;
}

void Granjeros::iniciarJuego(){

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
}

void Granjeros::ejecutarAccion(Accion* accion){

	ejecutarAccionConfiguracion(accion);
	ejecutarAccionPartida(accion);

	interfaz->mostrarMenuActual();
}

void Granjeros::ejecutarAccionConfiguracion(Accion* accion){

	switch (accion->obtenerAccion()){

		case accion::CAMBIAR_CANTIDAD_JUGADORES:

			this->parametrosConfiguracion->cambiarCantidadJugadores(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()));
			cout << "La cantidad de jugadores ahora es: " << this->parametrosConfiguracion->obtenerCantidadJugadores() << endl;
			break;

		case accion::CAMBIAR_CANTIDAD_TURNOS:

			this->parametrosConfiguracion->cambiarCantidadTurnos(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()));
			cout << "La cantidad de turnos ahora es: " << this->parametrosConfiguracion->obtenerCantidadTurnos() << endl;
			break;

		case accion::CAMBIAR_PARAMETRO_M:

			this->parametrosConfiguracion->cambiarParametroM(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()));
			cout << "El parametro M ahora es: " << this->parametrosConfiguracion->obtenerParametroM() << endl;
			break;

		case accion::CAMBIAR_PARAMETRO_N:

			this->parametrosConfiguracion->cambiarParametroN(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()));
			cout << "El parametro N ahora es: " << this->parametrosConfiguracion->obtenerParametroN() << endl;
			break;

		default:;
	}
}

void Granjeros::ejecutarAccionPartida(Accion* accion){

	bool partidaFinalizada = false;

	switch (accion->obtenerAccion()){

		case accion::COMPRAR_CAPACIDAD_AGUA:

			if(partida->ejecutarAccionComprarCapacidadAgua()){
				cout << "AUMENTO LA CAPACIDAD DEL TANQUE!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}

			break;

		case accion::COMPRAR_CAPACIDAD_ALMACEN:

			if(partida->ejecutarAccionComprarCapacidadAlmacen()){
				cout << "AUMENTO LA CAPACIDAD DEL ALMACEN!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;

		case accion::COMPRAR_TERRENO:

			if(partida->ejecutarAccionComprarTerreno()){
				cout << "COMPRASTE UN TERRENO!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;

		case accion::COSECHAR:

			if(partida->ejecutarAccionCosechar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()),
											   accion->obtenerParametros()[1].obtenerValor())){
				cout << "COSECHASTE!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;

		case accion::ENVIAR_COSECHA:

			if(partida->ejecutarAccionEnviarCosecha(accion->obtenerParametros()[0].obtenerValor())){
				cout << "ENVIASTE LA COSECHA!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;

		case accion::JUGAR:

			this->comenzarPartida();
			break;

		case accion::REGAR:

			if(partida->ejecutarAccionRegar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()),
											accion->obtenerParametros()[1].obtenerValor())){
				cout << "REGASTE!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;

		case accion::SEMBRAR:

			if(partida->ejecutarAccionSembrar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()),
											  accion->obtenerParametros()[1].obtenerValor(),
											  accion->obtenerParametros()[2].obtenerValor())){
				cout << "SEMBRASTE!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;
		case accion::VENDER_TERRENO:

			if(partida->ejecutarAccionVenderTerreno(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()))){
				cout << "VENDISTE UN TERRENO!" << endl;
			}else{
				cout << "No se pudo realizar la accion" << endl;
			}
			break;

		case accion::FINALIZAR_TURNO:

			partidaFinalizada = avanzarTurno();

			if(partidaFinalizada){

				finalizarPartida();
				interfaz->mostrarResumenPartida(partida);
				interfaz->irAMenuAnterior();
			}

			break;

		case accion::FINALIZAR_PARTIDA:

			finalizarPartida();
			interfaz->irAMenuAnterior();

			break;

		case accion::SALIR:

			interfaz->irAMenuAnterior();
			break;

		default:;
	}
}

void Granjeros::comenzarPartida(){

	Lista<string> nombresJugadores;
	interfaz->solicitarNombresJugadores(this->parametrosConfiguracion->obtenerCantidadJugadores(), nombresJugadores);

	Configuracion::inicializar(this->parametrosConfiguracion);
	interfaz->cargarMenuPartida();

	partida = new Partida(&nombresJugadores);

	cout << endl << endl <<"COMIENZA LA PARTIDA!" << endl << endl << endl;

	iniciarTurno();
	interfaz->mostrarEstadoPartida(partida);
}

bool Granjeros::avanzarTurno(){

	bool finPartida = partida->avanzarTurno();

	if(!finPartida){

		iniciarTurno();
		interfaz->mostrarEstadoPartida(partida);
	}

	return finPartida;
}

void Granjeros::iniciarTurno(){

	asignarUnidadesRiego();
}

void Granjeros::asignarUnidadesRiego(){

	srand(time(NULL));

	unsigned int potenciadorAgua = (rand() % 6) + 1;
	unsigned int unidadesRiego = 5 * potenciadorAgua;

	this->partida->verJugadorActual()->aumentarUnidadesRiego(unidadesRiego);
}

void Granjeros::finalizarPartida(){

	delete this->partida;
	this->partida = NULL;
}

Granjeros::~Granjeros(){

	delete this->parametrosConfiguracion;
	delete this->interfaz;

	if(this->partida != NULL){
		delete this->partida;
	}
}
