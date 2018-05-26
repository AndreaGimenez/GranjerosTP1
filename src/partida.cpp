#include <iostream>
#include <string>

#include "partida.h"
#include "lista.h"
#include "jugador.h"
#include "configuracion.h"

using namespace std ;

Partida::Partida(Lista<string>* nombresJugadores){

	this->nivelDeDificultad = Configuracion::obtenerDificultad();
	this->cantidadTurnos = Configuracion::obtenerCantidadTurnos();
	this->cantidadTurnosJugados = 0;
	this->jugadores = new Lista<Jugador*>;
	this->cargarJugadores(nombresJugadores);
}

Dificultad Partida::obtenerDificultad(){

	return this->nivelDeDificultad ;
}

unsigned int Partida::obtenerCantidadDeJugadores(){

	return this->jugadores->contarElementos() ;
}

unsigned int Partida::obtenerTurnoActual(){

	return this->cantidadTurnosJugados + 1;
}

Jugador* Partida::verJugadorActual(){

	return jugadores->obtenerCursor();
}

bool Partida::avanzarProximoJugador(){

	return jugadores->avanzarCursor();
}

void Partida::irAPrimerJugador(){

	this->jugadores->iniciarCursor();
	this->jugadores->avanzarCursor();
}

bool Partida::ejecutarAccionComprarCapacidadAgua(){

	return this->verJugadorActual()->comprarCapacidadTanque();
}

bool Partida::ejecutarAccionComprarCapacidadAlmacen(){

	return this->verJugadorActual()->comprarCapacidadAlmacen();
}

bool Partida::ejecutarAccionComprarTerreno(){

	return this->verJugadorActual()->comprarTerreno();
}

bool Partida::ejecutarAccionCosechar(unsigned int numeroTerreno, std::string coordenadasParcela){

	return this->verJugadorActual()->cosechar(numeroTerreno, coordenadasParcela);
}

bool Partida::ejecutarAccionEnviarCosecha(std::string nombreCultivo){

	bool ejecutarAccionCosecha = false;

	Cultivo* cultivo = Configuracion::obtenerCultivo(nombreCultivo);
	if(cultivo != NULL){
		ejecutarAccionCosecha = this->verJugadorActual()->enviar(cultivo);
	}

	return ejecutarAccionCosecha;
}

bool Partida::ejecutarAccionRegar(unsigned int numeroTerreno, std::string coordenadasParcela){

	return this->verJugadorActual()->regar(numeroTerreno, coordenadasParcela);
}

bool Partida::ejecutarAccionSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, std::string nombreCultivo){

	bool ejecutarAccionSembrar = false;

	Cultivo* cultivo = Configuracion::obtenerCultivo(nombreCultivo);
	if(cultivo != NULL){
		ejecutarAccionSembrar = this->verJugadorActual()->sembrar(numeroTerreno, coordenadasParcela, cultivo);
	}

	return ejecutarAccionSembrar;
}

bool Partida::ejecutarAccionVenderTerreno(unsigned int numeroTerreno){

	return this->verJugadorActual()->venderTerreno(numeroTerreno);
}

bool Partida::avanzarTurno(){

	bool partidaFinalizada = false;

	this->actualizar();

	//Si ya jugaron el turno todos los jugadores
	if(!avanzarProximoJugador()){

		this->cantidadTurnosJugados++;
		partidaFinalizada = this->partidaFinalizada();

		//Si todavia hay turnos por jugar entonces hay que ir al primer jugador nuevamente
		if(!partidaFinalizada){

			irAPrimerJugador();
		}
	}

	return partidaFinalizada;
}

void Partida::obtenerJugadoresOrdenados(Jugador** jugadoresOrdenados){

	if(!this->jugadores->estaVacia()){

		int jugadoresAgregados = 0;
		this->jugadores->iniciarCursor();
		while(this->jugadores->avanzarCursor()){

			Jugador* jugadorAAgregar = this->jugadores->obtenerCursor();

			if(jugadoresAgregados != 0){

				bool agregueJugador = false;
				int posicionAAgregarJugador = 0;

				for(; posicionAAgregarJugador <= jugadoresAgregados && !agregueJugador; posicionAAgregarJugador++){

					agregueJugador = (posicionAAgregarJugador == jugadoresAgregados
										   || jugadorAAgregar->monedasDisponibles() > jugadoresOrdenados[posicionAAgregarJugador]->monedasDisponibles());

					if(agregueJugador){

						for(int i = jugadoresAgregados - 1; i >= posicionAAgregarJugador; i--){
							jugadoresOrdenados[i+1] = jugadoresOrdenados[i];
						}
						jugadoresOrdenados[posicionAAgregarJugador] = jugadorAAgregar;
					}
				}
				jugadoresAgregados++;

			}else{

				jugadoresOrdenados[0] = jugadorAAgregar;
				jugadoresAgregados++;
			}
		}
	}
}

void Partida::cargarJugadores(Lista<string>* nombresJugadores){

	nombresJugadores->iniciarCursor() ;
	while(nombresJugadores->avanzarCursor()){

		this->jugadores->agregar(new Jugador(nombresJugadores->obtenerCursor()));
	}

	this->irAPrimerJugador();
}

void Partida::actualizar(){

	this->verJugadorActual()->actualizar();
}

bool Partida::partidaFinalizada(){

	return (this->cantidadTurnosJugados == this->cantidadTurnos);
}

Partida::~Partida(){

	jugadores->iniciarCursor() ;

	while(jugadores->avanzarCursor()){

		Jugador* jugadorObtenido = jugadores->obtenerCursor() ;
		delete jugadorObtenido ;
	}

	delete this->jugadores;
}
