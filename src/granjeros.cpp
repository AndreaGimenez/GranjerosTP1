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

	bool accionEjecutada = false; //Indica si la accion ya se ejecuto en alguno de los metodos

	//Acciones que son estrictamente de configuracion previa a la partida
	accionEjecutada = ejecutarAccionConfiguracion(accion);

	if(!accionEjecutada)
		//Acciones que tienen que ver estrictamente con la partida
		accionEjecutada = ejecutarAccionPartida(accion);

	if(!accionEjecutada)
		//Acciones de finalizacion de menues
		accionEjecutada = ejecutarAccionSalida(accion);

	interfaz->mostrarMenuActual();
}

bool Granjeros::ejecutarAccionConfiguracion(Accion* accion){

	bool accionEjecutada = true;
	switch (accion->obtenerTipoAccion()){

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

		default:
			accionEjecutada = false;
	}

	return accionEjecutada;
}

bool Granjeros::ejecutarAccionPartida(Accion* accion){

	//Indica si 'accion' esta dentro de las acciones qeu contempla este metodo
	bool accionEjecutada = true;
	// Indica si la accion se ejecuto satisfactoriamente. En caso que 'accion' no pertenezca a las acciones que contempla este metodo queda en false
	bool accionEjecutadaExistosamente = false;

	switch (accion->obtenerTipoAccion()){

		case accion::COMPRAR_CAPACIDAD_AGUA:

			accionEjecutadaExistosamente = partida->ejecutarAccionComprarCapacidadAgua();
			if(accionEjecutadaExistosamente){
				cout << "AUMENTO LA CAPACIDAD DEL TANQUE!" << endl << endl;
			}
			break;

		case accion::COMPRAR_CAPACIDAD_ALMACEN:

			accionEjecutadaExistosamente = partida->ejecutarAccionComprarCapacidadAlmacen();
			if(accionEjecutadaExistosamente){
				cout << "AUMENTO LA CAPACIDAD DEL ALMACEN!" << endl << endl;
			}
			break;

		case accion::COMPRAR_TERRENO:

			accionEjecutadaExistosamente = partida->ejecutarAccionComprarTerreno();
			if(accionEjecutadaExistosamente){
				cout << "COMPRASTE UN TERRENO!" << endl << endl;
			}
			break;

		case accion::COSECHAR:

			accionEjecutadaExistosamente = partida->ejecutarAccionCosechar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()),
														   	   	   	   	   accion->obtenerParametros()[1].obtenerValor());
			if(accionEjecutadaExistosamente){
				cout << "COSECHASTE!" << endl;
			}
			break;

		case accion::ENVIAR_COSECHA:

			accionEjecutadaExistosamente = partida->ejecutarAccionEnviarCosecha(accion->obtenerParametros()[0].obtenerValor());
			if(accionEjecutadaExistosamente){
				cout << "ENVIASTE LA COSECHA!" << endl << endl;
			}
			break;

		case accion::JUGAR:

			this->comenzarPartida();
			accionEjecutadaExistosamente = true;
			break;

		case accion::REGAR:

			accionEjecutadaExistosamente = partida->ejecutarAccionRegar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()),
																		accion->obtenerParametros()[1].obtenerValor());
			if(accionEjecutadaExistosamente){
				cout << "REGASTE!" << endl << endl;
			}
			break;

		case accion::SEMBRAR:

			accionEjecutadaExistosamente = partida->ejecutarAccionSembrar(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()),
																		  accion->obtenerParametros()[1].obtenerValor(),
																		  accion->obtenerParametros()[2].obtenerValor());
			if(accionEjecutadaExistosamente){
				cout << "SEMBRASTE!" << endl << endl;
			}
			break;

		case accion::VENDER_TERRENO:

			accionEjecutadaExistosamente = partida->ejecutarAccionVenderTerreno(Utils::stringToUnsignedInt(accion->obtenerParametros()[0].obtenerValor()));
			if(accionEjecutadaExistosamente){
				cout << "VENDISTE UN TERRENO!" << endl << endl;
			}
			break;

		default:
			accionEjecutada = false;
	}

	if(accionEjecutada){
		if(accionEjecutadaExistosamente){
			this->interfaz->mostrarEstadoPartida(partida);
		}else{
			cout << "No se pudo realizar la accion" << endl << endl;
		}
	}

	return accionEjecutada;
}

bool Granjeros::ejecutarAccionSalida(Accion* accion){

	bool partidaFinalizada = false;
	bool accionEjecutada = true;
	switch (accion->obtenerTipoAccion()){

		case accion::FINALIZAR_TURNO:

			partidaFinalizada = avanzarTurno();

			if(partidaFinalizada){

				interfaz->mostrarResumenPartida(partida);
				finalizarPartida();
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

		default:
			accionEjecutada = false;
	}

	return accionEjecutada;
}

void Granjeros::comenzarPartida(){

	Lista<string> nombresJugadores;
	interfaz->solicitarNombresJugadores(this->parametrosConfiguracion->obtenerCantidadJugadores(), nombresJugadores);

	Configuracion::inicializar(this->parametrosConfiguracion);
	interfaz->cargarMenuPartida();

	partida = new Partida(&nombresJugadores);

	cout << endl << endl <<"COMIENZA LA PARTIDA!" << endl << endl << endl;

	iniciarTurno();
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
