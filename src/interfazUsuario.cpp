/*
 * interfazUsuario.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#include "interfazUsuario.h"
#include <cstdlib>
#include <iostream>
#include "utils.h"


using namespace std;

InterfazUsuario::InterfazUsuario() {

	this->menuPrincipal = NULL;
	this->menuPartida = NULL;
}

void InterfazUsuario::mostrarBienvenida(){

	cout << "GRANJEROS 1.0" << endl << endl;
}

void InterfazUsuario::solicitarNombresJugadores(unsigned int cantidadJugadores, Lista<string>& listaNombres){

	cout << "Ingresa los nombres de los jugadores!" << endl << endl;
	for(unsigned int i = 1; i <= cantidadJugadores; i++){

		cout << "Nombre jugador " + Utils::unsignedIntToString(i) << ": ";
		cout.flush();

		string nombreJugador;
		getline(cin, nombreJugador);

		listaNombres.agregar(nombreJugador);
	}
}

void InterfazUsuario::cargarMenuPrincipal(){

	this->menuPrincipal = crearMenuPrincipal();
	this->menues.apilar(this->menuPrincipal);
}

void InterfazUsuario::cargarMenuPartida(){

	this->menuPartida = crearMenuPartida();
	this->menues.apilar(menuPartida);
}

Menu* InterfazUsuario::obtenerMenuActual(){
	return this->menues.obtenerTope();
}

void InterfazUsuario::mostrarMenuActual(){

	if(!this->menues.estaVacia()){
		this->obtenerMenuActual()->mostrar();
	}
}

void InterfazUsuario::irAMenuAnterior(){

	this->menues.desapilar();
}

unsigned int InterfazUsuario::solicitarOpcion(){

	return this->obtenerMenuActual()->solicitarOpcion();
}

ResultadoOpcion* InterfazUsuario::ejecutarOpcion(unsigned int iMenuItem){

	ResultadoOpcion* respuesta = this->obtenerMenuActual()->ejecutarOpcion(iMenuItem);

	if(respuesta->obtenerTipo() == resultadoOpcion::SUBMENU){
		this->agregarMenu(respuesta->obtenerSubMenu());
	}

	return respuesta;
}

bool InterfazUsuario::salir(){
	return this->menues.estaVacia();
}

void InterfazUsuario::mostrarDespedida(){

	cout << "CHAU!" << endl << endl;
}

void InterfazUsuario::agregarMenu(Menu* menu){
	this->menues.apilar(menu);
}

Menu* InterfazUsuario::crearMenuPrincipal() {

	Menu* menu = new Menu("MENU PRINCIPAL", 2);
	Menu* menuConfiguracion = crearMenuConfiguracion();

	menu->cambiarOpcion(1, OpcionMenu("Configuracion", menuConfiguracion));
	menu->cambiarOpcion(2, OpcionMenu("Jugar", accion::JUGAR));

	return menu;
}

Menu* InterfazUsuario::crearMenuConfiguracion() {

	Menu* menu = new Menu("CONFIGURACION", 4);

	menu->cambiarOpcion(1, OpcionMenu("Cambiar Cantidad de Jugadores",
									  accion::CAMBIAR_CANTIDAD_JUGADORES,
									  "Indique la cantidad de jugadores"));

	menu->cambiarOpcion(2, OpcionMenu("Cambiar Parametro N",
									  accion::CAMBIAR_PARAMETRO_N,
									  "Indique el nuevo valor del parametro: "));

	menu->cambiarOpcion(3, OpcionMenu("Cambiar Parametro M",
									  accion::CAMBIAR_PARAMETRO_M,
									  "Indique el nuevo valor del parametro"));

	menu->cambiarOpcion(4, OpcionMenu("Cambiar Cantidad de Turnos",
									  accion::CAMBIAR_CANTIDAD_TURNOS,
									  "Indique la cantidad de turnos a jugar en cada partida"));

	return menu;
}

Menu* InterfazUsuario::crearMenuPartida() {

	Menu* menu = new Menu("ACCIONES", 10, false);

	menu->cambiarOpcion(0, OpcionMenu("Finalizar Partida",
									  accion::FINALIZAR_PARTIDA));

	menu->cambiarOpcion(1, OpcionMenu("Sembrar",
									  accion::SEMBRAR,
									  "Indique, separando con espacios, el numero de terreno, las coordenadas de la parcela y el cultivo a sembrar (ej: 1 1,2 A)"));

	menu->cambiarOpcion(2, OpcionMenu("Cosechar",
									  accion::COSECHAR,
									  "Indique el numero de terreno y las coordenadas de la parcela a cosechar (ej: 1 1,2)"));

	menu->cambiarOpcion(3, OpcionMenu("Regar",
									  accion::REGAR,
									  "Indique el numero de terreno y las coordenadas de la parcela a regar (ej 1 1,2)"));

	menu->cambiarOpcion(4, OpcionMenu("Enviar Cosecha",
									  accion::ENVIAR_COSECHA,
									  "Indique el nombre del cultivo de la cosecha a enviar a destino (ej: A)"));

	menu->cambiarOpcion(5, OpcionMenu("Comprar Terreno",
										accion::COMPRAR_TERRENO));

	menu->cambiarOpcion(6, OpcionMenu("Vender Terreno",
									  accion::VENDER_TERRENO,
									  "Indique numero de terreno a vender (ej: 3)"));

	menu->cambiarOpcion(7, OpcionMenu("Ampliar capacidad Tanque",
								  	  accion::COMPRAR_CAPACIDAD_AGUA));

	menu->cambiarOpcion(8, OpcionMenu("Ampliar Almacen",
			  	  	  	  	  	  	  accion::COMPRAR_CAPACIDAD_ALMACEN));

	menu->cambiarOpcion(9, OpcionMenu("Finalizar Turno",
				  	  	  	  	  	  accion::FINALIZAR_TURNO));

	return menu;
}

void InterfazUsuario::mostrarEstadoPartida(Partida* partida){

	mostrarDatosPartida(partida);
	mostrarRecursosJugador(partida->verJugadorActual());
	mostrarTerrenosJugador(partida->verJugadorActual());
}

void InterfazUsuario::mostrarResumenPartida(Partida* partida){

	cout << endl << endl << "FIN DE LA PARTIDA!" << endl << endl;

	Jugador** jugadoresOrdenados = new Jugador*[partida->obtenerCantidadDeJugadores()];
	partida->obtenerJugadoresOrdenados(jugadoresOrdenados);
	mostrarGanador(partida->obtenerCantidadDeJugadores(), jugadoresOrdenados);
	mostrarPosiciones(partida->obtenerCantidadDeJugadores(), jugadoresOrdenados);

	delete[] jugadoresOrdenados;
	cout << endl << "Presione enter para ir al menu principal";
	string dummy = "";
	getline(cin, dummy);
}

void InterfazUsuario::mostrarGanador(unsigned int cantidadJugadores, Jugador** jugadores){

	cout << "                                          EL GANADOR ES                                           " << endl;
	cout << string(49 - jugadores[0]->obtenerNombre().size()/2, ' ');
	cout << jugadores[0]->obtenerNombre();
	cout << string(50 - jugadores[0]->obtenerNombre().size()/2, ' ');
	cout << endl << endl;
	cout << "                                  ./*,...........,*******/(((((*                                  " << endl
		 << "                             //****,**,......     ********/(((((/****,,                           " << endl
		 << "                             //****,**,......     ********/(((((/****,,                           " << endl
		 << "                           ,(/*  .****,.....      ********/(((((/*.  .,,.                         " << endl
		 << "                           ((/     .**,.........,,,,******/(((((*      ..                         " << endl
		 << "                           *(/      **,.......,,,,,**///**/(((((.     ..                          " << endl
		 << "                            *(*     /*,.........,,***///**((((((      .                           " << endl
		 << "                             .(/    ***.........**********(((((/    ..                            " << endl
		 << "                               ,*,   /*,,,,...,,*********/(((((.  ...                             " << endl
		 << "                                 ,*, */*,,,,,,****,,,,/**(((((/ .,.                               " << endl
		 << "                                    ,,*/*,,,,,,***///****(((((/*                                  " << endl
		 << "                                       ***,,,,,,,,******/(///                                     " << endl
		 << "                                        .**,,,,,,,*****////,                                      " << endl
		 << "                                          **,,,,,,,**,////                                        " << endl
		 << "                                           ,*,,,,,,,,*//*                                         " << endl
		 << "                                             ,,...,,***                                           " << endl
		 << "                                              ,,...***                                            " << endl
		 << "                                               .,.,*,                                             " << endl
		 << "                                               ,...*,                                             " << endl
		 << "                                               ,...**                                             " << endl
		 << "                                              .,...,*,                                            " << endl
		 << "                                              ,.....**                                            " << endl
		 << "                                             .,.....**,                                           " << endl
		 << "                                             ,......,**.                                          " << endl
		 << "                                            *,.....,,***                                          " << endl
		 << "                                        **/*,.....,****,,***                                      " << endl
		 << "                                        &%%%%%%%%%%%%%%%%%%&.									   " << endl;
}

void InterfazUsuario::mostrarPosiciones(unsigned int cantidadJugadores, Jugador** jugadores){

	cout << "Posiciones" << endl << endl;
	for(unsigned int i = 0; i < cantidadJugadores; i++){
		cout << i+1 << " - " << jugadores[i]->obtenerNombre() << " Monedas: " << jugadores[i]->monedasDisponibles() << endl;
	}
}

void InterfazUsuario::mostrarDatosPartida(Partida* partida){

	cout << "TURNO " << partida->obtenerTurnoActual() << endl << endl;
}

void InterfazUsuario::mostrarRecursosJugador(Jugador* jugador){

	cout << "Jugador: " << jugador->obtenerNombre() << endl << endl;
	cout << "Recursos Disponibles" << endl;
	cout << "Monedas: " << jugador->monedasDisponibles() << endl;
	cout << "Unidades de Riego: " << jugador->obtenerUnidadesRiego() << endl;
	cout << "Tanque: " << jugador->obtenerUnidadesRiegoAlmacenadas() << endl;
	cout << "Espacio disponible en Almacen: " << jugador->obtenerCantidadDisponibleAlmacen() << endl << endl;
}

void InterfazUsuario::mostrarTerrenosJugador(Jugador* jugador){
	//TODO: con EasyBMP hay que mostrar el estado de la partida (solo del jugador actual).
	//mostrarTerrenosJugadorPorImagen(jugador);
	mostrarTerrenosJugadorPorConsola(jugador);
<<<<<<< HEAD
}

void InterfazUsuario::mostrarTerrenosJugadorPorConsola(Jugador* jugador){
	Utils utils;
	Terreno* terreno;
	Parcela* parcelaActual;
	parcela::Estado estadoParcela;
	Cultivo* cultivoActual;
	char regada;
	
	for(int i=1;i<=jugador->obtenerCantidadTerrenos();i++){
		terreno=jugador->buscarTerreno(i);
		
		for(int j=1;j<=terreno->obtenerLargoTerreno();j++){
			cout<<"__________________________________________________________________________________"<<endl;
			cout<<"|";
			for(int k=1;k<=terreno->obtenerAnchoTerreno();k++){
				parcelaActual=terreno->buscarParcela(utils.unsignedIntToString(j) + "," + utils.unsignedIntToString(k));				
				estadoParcela=parcelaActual->obtenerEstado();				
				switch(estadoParcela){
					case parcela::LIMPIA:
						cout<<"|	|";
						break;
					case parcela::SEMBRADA:
						cultivoActual=parcelaActual->obtenerCultivo();
						if(parcelaActual->obtenerRegada())
							regada=' ';
						else regada='R';
						cout<<"|"<<cultivoActual->obtenerNombre()
							<<"("<<utils.unsignedIntToString(parcelaActual->obtenerTiempoSembrada())<<", "
							<<regada<<")"<<"|";
						break;
					case parcela::SECA:
						cout<<"|******|";
						break;
					case parcela::PODRIDA:
						cout<<"##("<<parcelaActual->obtenerTiempoRecuperacionRestante()<<")##";
				}
			}
			cout<<"|"<<endl;
			cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl;
			
		}
		cout<<endl<<endl;
	}
}

void InterfazUsuario::mostrarTerrenosJugadorPorImagen(Jugador* jugador){

=======
>>>>>>> e9afb4e479b0a49e1e7146727af6fde18a005b80
}

void InterfazUsuario::mostrarTerrenosJugadorPorConsola(Jugador* jugador){
	Terreno* terreno;
	Parcela* parcelaActual;
	parcela::Estado estadoParcela;
	Cultivo* cultivoActual;
	char regada;
	for(int i=1;i<jugador->obtenerCantidadTerrenos();i++){
		terreno=jugador->buscarTerreno(i);
		
		for(int j=0;j<terreno->obtenerLargoTerreno();j++){
			for(int k=0;k<terreno->obtenerAnchoTerreno();k++){
				parcelaActual=terreno->buscarParcela(to_string(j) + "," + to_string(k));				
				switch(parcelaActual->obtenerEstado()){
					case parcela::LIMPIA:
						cout<<"|		|";
						break;
					case parcela::SEMBRADA:
						cultivoActual=parcelaActual->obtenerCultivo();
						if(parcelaActual->obtenerRegada())
							regada=' ';
						else regada='R';
						cout<<"|"<<cultivoActual->obtenerNombre()
							<<"("<<to_string(parcelaActual->obtenerTiempoSembrada())<<", "
							<<regada<<")"<<"|";
						break;
					case parcela::SECA:
						cout<<"|********|";
						break;
					case parcela::PODRIDA:
						cout<<"##("<<parcelaActual->obtenerTiempoRecuperacionRestante()<<"##)";
				}
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
}

void InterfazUsuario::mostrarTerrenosJugadorPorImagen(Jugador* jugador){

}



InterfazUsuario::~InterfazUsuario(){

	if(this->menuPartida != NULL){
			delete this->menuPartida;
	}

	if(this->menuPrincipal != NULL){
		delete this->menuPrincipal;
	}
}

