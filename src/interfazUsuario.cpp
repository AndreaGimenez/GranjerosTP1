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
#include "configuracion.h"


using namespace std;

InterfazUsuario::InterfazUsuario() {

	this->menuPrincipal = NULL;
	this->menuPartida = NULL;
	this->creadorImagen = new CreadorImagen();
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
	cout << "Tanque: " << jugador->obtenerUnidadesRiegoAlmacenadas() << "/" << jugador->obtenerCantidadMaximaTanque() << endl;
	cout << "Espacio disponible en Almacen: " << jugador->obtenerCantidadAlmacenadaTotal() << "/" << jugador->obtenerCantidadMaximaAlmacen() << endl << endl;
}

void InterfazUsuario::mostrarTerrenosJugador(Jugador* jugador){

	mostrarTerrenosJugadorPorImagen(jugador);
	mostrarTerrenosJugadorPorConsola(jugador);
}

void InterfazUsuario::mostrarTerrenosJugadorPorConsola(Jugador* jugador){

	Terreno* terreno;
	Parcela* parcelaActual;
	parcela::Estado estadoParcela;
	Cultivo* cultivoActual;
	char regada;
	
	for(unsigned int i=1;i<=jugador->obtenerCantidadTerrenos();i++){
		terreno=jugador->buscarTerreno(i);
		
		cout << "    ";
		for(unsigned int k=1;k<=terreno->obtenerAnchoTerreno();k++){
			cout << "    " << k << "    ";
		}
		cout << endl;

		for(unsigned int j=1;j<=terreno->obtenerLargoTerreno();j++){

			cout<<"__________________________________________________________________________________"<<endl;
			cout<< j << "  |";
			for(unsigned int k=1;k<=terreno->obtenerAnchoTerreno();k++){
				parcelaActual=terreno->buscarParcela(Utils::unsignedIntToString(j) + "," + Utils::unsignedIntToString(k));
				estadoParcela=parcelaActual->obtenerEstado();				
				switch(estadoParcela){
					case parcela::LIMPIA:
						cout<<"|       |";
						break;
					case parcela::SEMBRADA:
						cultivoActual=parcelaActual->obtenerCultivo();
						if(parcelaActual->obtenerRegada())
							regada=' ';
						else regada='R';
						cout<<"|"<<cultivoActual->obtenerNombre()
							<<"("<<Utils::unsignedIntToString(parcelaActual->obtenerTiempoSembrada())<<", "
							<<regada<<")"<<"|";
						break;
					case parcela::SECA:
						cout<<"|*******|";
						break;
					case parcela::PODRIDA:
						cout<<"|##("<<parcelaActual->obtenerTiempoRecuperacionRestante()<<")##|";
						break;
					case parcela::COSECHADA:
						cout<<"|··("<<parcelaActual->obtenerTiempoRecuperacionRestante()<<")··|";
						break;
				}
			}
			cout<<"|"<<endl;
			cout << "   ¯" << Utils::fillString("", "¯", terreno->obtenerAnchoTerreno()*9, false) << "¯" <<endl;
			
		}
		cout<<endl<<endl;
	}
}

void InterfazUsuario::mostrarTerrenosJugadorPorImagen(Jugador* jugador){

	for(unsigned int iTerreno = 1; iTerreno <= jugador->obtenerCantidadTerrenos(); iTerreno++){

		creadorImagen->crearNuevaImagen(obtenerLargoTerreno(), obtenerAnchoTerreno(), 24);
		Terreno* terreno = jugador->buscarTerreno(iTerreno);
		dibujarTerreno(terreno);
		creadorImagen->guardarImagen(jugador->obtenerNombre() + "_Terreno_" + Utils::unsignedIntToString(iTerreno));
	}
}

void InterfazUsuario::dibujarTerreno(Terreno* terreno){

	for(unsigned int coordenadaY = 1; coordenadaY <= terreno->obtenerLargoTerreno(); coordenadaY++){
		for(unsigned int coordenadaX = 1; coordenadaX <= terreno->obtenerAnchoTerreno(); coordenadaX++){

			Parcela* parcelaActual = terreno->buscarParcela(Utils::unsignedIntToString(coordenadaY) + "," + Utils::unsignedIntToString(coordenadaX));
			dibujarParcela(parcelaActual, coordenadaX, coordenadaY);
		}
	}
}

void InterfazUsuario::dibujarParcela(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY){

	int coordenadaXEnDibujo = obtenerCoordenadaXEnDibujo(coordenadaX);
	int coordenadaYEnDibujo = obtenerCoordenadaYEnDibujo(coordenadaY);

	parcela::Estado estadoParcela = parcela->obtenerEstado();

	switch(estadoParcela){

		case parcela::LIMPIA:
			dibujarParcelaLimpia(parcela,coordenadaXEnDibujo, coordenadaYEnDibujo);
			break;
		case parcela::SEMBRADA:
			dibujarParcelaSembrada(parcela,coordenadaXEnDibujo, coordenadaYEnDibujo);
			break;
		case parcela::SECA:
			dibujarParcelaSeca(parcela,coordenadaXEnDibujo, coordenadaYEnDibujo);
			break;
		case parcela::PODRIDA:
			dibujarParcelaPodrida(parcela,coordenadaXEnDibujo, coordenadaYEnDibujo);
			break;
		case parcela::COSECHADA:
			dibujarParcelaCosechada(parcela,coordenadaXEnDibujo, coordenadaYEnDibujo);
			break;
	}

	dibujarAlambradoParcela(coordenadaXEnDibujo, coordenadaYEnDibujo);
	if(parcela->obtenerRegada()){
		dibujarRiego(coordenadaXEnDibujo, coordenadaYEnDibujo);
	}
}

void InterfazUsuario::dibujarRiego(int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	creadorImagen->pegarImagenConTransparencia("resources/img/gota.bmp", coordenadaXEnDibujo + obtenerAnchoParcela()/2 - 10,
								coordenadaYEnDibujo + obtenerLargoParcela() - 30, creadorImagen->obtenerColor(VERDE_HIERBA));
}

void InterfazUsuario::dibujarParcelaLimpia(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), obtenerLargoParcela(), coordenadaXEnDibujo,
											   coordenadaYEnDibujo, creadorImagen->obtenerColor(VERDE_CLARO), creadorImagen->obtenerColor(VERDE));
}

void InterfazUsuario::dibujarParcelaSembrada(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), obtenerLargoParcela(), coordenadaXEnDibujo,
											   coordenadaYEnDibujo, creadorImagen->obtenerColor(VERDE_CLARO), creadorImagen->obtenerColor(VERDE));

	dibujarCultivos(parcela, coordenadaXEnDibujo, coordenadaYEnDibujo);

	string nombreImagenCultivo = obtenerNombreImagenCultivo(parcela->obtenerCultivo());
	int coordenadaXImagenCultivo = obtenerCoordenadaXImagenCultivo(coordenadaXEnDibujo);
	int coordenadaYImagenCultivo = obtenerCoordenadaYImagenCultivo(coordenadaYEnDibujo);

	creadorImagen->pegarImagenConTransparencia(nombreImagenCultivo, coordenadaXImagenCultivo, coordenadaYImagenCultivo, creadorImagen->obtenerColor(VERDE_HIERBA));
}

void InterfazUsuario::dibujarCultivos(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	unsigned int anchoMarca = 5;
	unsigned int separacionEntreMarcas = 10;
	unsigned int cantidadMarcas = (obtenerLargoParcela() - separacionEntreMarcas)/(anchoMarca + separacionEntreMarcas);

	int posicionFinalUltimaMarca = coordenadaYEnDibujo;//Indica la coordenada Y en la que termino la ultima marca, se inicializa en el inicio de la parcela

	for(unsigned int i  = 0; i < cantidadMarcas; i ++){

		int posicionMarcaActual = posicionFinalUltimaMarca + separacionEntreMarcas;//La nueva marca comienza en esta coordenada
		creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), anchoMarca, coordenadaXEnDibujo,
												   posicionMarcaActual, creadorImagen->obtenerColor(VERDE_HIERBA), creadorImagen->obtenerColor(VERDE));
		posicionFinalUltimaMarca = posicionMarcaActual + anchoMarca;
	}
}

void InterfazUsuario::dibujarParcelaSeca(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), obtenerLargoParcela(), coordenadaXEnDibujo,
											   coordenadaYEnDibujo, creadorImagen->obtenerColor(AMARILLO_ARENA), creadorImagen->obtenerColor(AMARILLO_MIEL));
}

void InterfazUsuario::dibujarParcelaPodrida(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), obtenerLargoParcela(), coordenadaXEnDibujo,
											   coordenadaYEnDibujo, creadorImagen->obtenerColor(VERDE_HIERBA), creadorImagen->obtenerColor(MARRON_TIERRA));
}

void InterfazUsuario::dibujarParcelaCosechada(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), obtenerLargoParcela(), coordenadaXEnDibujo,
											   coordenadaYEnDibujo, creadorImagen->obtenerColor(MARRON_CLARO), creadorImagen->obtenerColor(VERDE));

	dibujarMarcasArado(parcela, coordenadaXEnDibujo, coordenadaYEnDibujo);
	dibujarHoz(parcela, coordenadaXEnDibujo, coordenadaYEnDibujo);
}

void InterfazUsuario::dibujarHoz(Parcela* parcela, int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	creadorImagen->pegarImagenConTransparencia("resources/img/hoz.bmp", coordenadaXEnDibujo + obtenerAnchoParcela()/2 - 50/2,
												coordenadaYEnDibujo + obtenerLargoParcela()/2 - 50/2, creadorImagen->obtenerColor(VERDE_HIERBA));
}

void InterfazUsuario::dibujarMarcasArado(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	unsigned int anchoMarca = 5;
	unsigned int separacionEntreMarcas = 10;
	unsigned int cantidadMarcas = (obtenerLargoParcela() - separacionEntreMarcas)/(anchoMarca + separacionEntreMarcas);

	int posicionFinalUltimaMarca = coordenadaYEnDibujo;//Indica la coordenada Y en la que termino la ultima marca, se inicializa en el inicio de la parcela

	for(unsigned int i  = 0; i < cantidadMarcas; i ++){

		int posicionMarcaActual = posicionFinalUltimaMarca + separacionEntreMarcas;//La nueva marca comienza en esta coordenada
		creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoParcela(), anchoMarca, coordenadaXEnDibujo,
												   posicionMarcaActual, creadorImagen->obtenerColor(MARRON), creadorImagen->obtenerColor(MARRON_TIERRA));
		posicionFinalUltimaMarca = posicionMarcaActual + anchoMarca;
	}
}

void InterfazUsuario::dibujarAlambradoParcela(int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	//Se dibujan 4 postes, uno en cada esquina de la parcela
	dibujarPoste(coordenadaXEnDibujo, coordenadaYEnDibujo);
	dibujarPoste(coordenadaXEnDibujo + obtenerAnchoParcela() - obtenerAnchoPoste(), coordenadaYEnDibujo);
	dibujarPoste(coordenadaXEnDibujo, coordenadaYEnDibujo + obtenerLargoParcela() - obtenerLargoPoste());
	dibujarPoste(coordenadaXEnDibujo + obtenerAnchoParcela() - obtenerAnchoPoste(),
				 coordenadaYEnDibujo + obtenerLargoParcela() - obtenerLargoPoste());

	//Se unen los postes con el alambrado
	dibujarAlambrado(coordenadaXEnDibujo + obtenerAnchoPoste(), coordenadaYEnDibujo + obtenerLargoPoste()/2,
					 coordenadaXEnDibujo + obtenerAnchoParcela() - obtenerAnchoPoste(), coordenadaYEnDibujo + obtenerLargoPoste()/2);
	dibujarAlambrado(coordenadaXEnDibujo + obtenerAnchoPoste()/2, coordenadaYEnDibujo + obtenerLargoPoste(),
					 coordenadaXEnDibujo + obtenerAnchoPoste()/2, coordenadaYEnDibujo + obtenerLargoParcela() - obtenerLargoPoste());
	dibujarAlambrado(coordenadaXEnDibujo + obtenerAnchoPoste(), coordenadaYEnDibujo + obtenerLargoParcela() - obtenerLargoPoste()/2,
					 coordenadaXEnDibujo + obtenerLargoParcela() - obtenerAnchoPoste(), coordenadaYEnDibujo + obtenerLargoParcela() - obtenerLargoPoste()/2);
	dibujarAlambrado(coordenadaXEnDibujo + obtenerAnchoParcela() - obtenerAnchoPoste()/2, coordenadaYEnDibujo + obtenerLargoPoste(),
					 coordenadaXEnDibujo + obtenerAnchoParcela() - obtenerAnchoPoste()/2, coordenadaYEnDibujo + obtenerLargoParcela() - obtenerLargoPoste());

}

void InterfazUsuario::dibujarPoste(int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(obtenerAnchoPoste(), obtenerLargoPoste(), coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(MARRON));
}

unsigned int InterfazUsuario::obtenerAnchoPoste(){
	return 6;
}

unsigned int InterfazUsuario::obtenerLargoPoste(){
	return 6;
}

void InterfazUsuario::dibujarAlambrado(int coordenadaXDesde, int coordenadaYDesde, int coordenadaXHasta, int coordenadaYHasta){

	Color* colorAlambrado = creadorImagen->obtenerColor(GRIS);

	if(coordenadaYDesde == coordenadaYHasta){
		creadorImagen->dibujarLineaHorizontal(colorAlambrado, coordenadaXHasta - coordenadaXDesde, coordenadaXDesde, coordenadaYDesde);
	}else if(coordenadaXDesde == coordenadaXHasta){
		creadorImagen->dibujarLineaVertical(colorAlambrado, coordenadaYHasta - coordenadaYDesde, coordenadaXDesde, coordenadaYDesde);
	}else{
		throw string("No hay soporte para alambrados que no sean verticales u horizontales");
	}
}

string InterfazUsuario::obtenerNombreImagenCultivo(Cultivo* cultivo){

	return "resources/img/Cultivo_" + cultivo->obtenerNombre() + ".bmp";
}

int InterfazUsuario::obtenerCoordenadaXImagenCultivo(int coordenadaXParcela){

	return coordenadaXParcela + obtenerAnchoParcela()/2 - 24/2;
}

int InterfazUsuario::obtenerCoordenadaYImagenCultivo(int coordenadaYParcela){

	return coordenadaYParcela + obtenerLargoParcela()/2 - 2/2;
}

int InterfazUsuario::obtenerCoordenadaXEnDibujo(unsigned int coordenadaX){

	return (coordenadaX - 1) * obtenerAnchoParcela() + obtenerDistanciaAlBorde();
}

int InterfazUsuario::obtenerCoordenadaYEnDibujo(unsigned int coordenadaY){

	return (coordenadaY - 1) * obtenerLargoParcela() + obtenerDistanciaAlBorde();
}

int InterfazUsuario::obtenerAnchoTerreno(){

	return Configuracion::obtenerAnchoTerreno() * obtenerAnchoParcela() + obtenerDistanciaAlBorde() * 2;
}


int InterfazUsuario::obtenerLargoTerreno(){

	return Configuracion::obtenerLargoTerreno() * obtenerLargoParcela() + obtenerDistanciaAlBorde() * 2;
}

int InterfazUsuario::obtenerAnchoParcela(){
	return 100;
}

int InterfazUsuario::obtenerLargoParcela(){
	return 100;
}

int InterfazUsuario::obtenerDistanciaAlBorde(){
	return 50;
}

InterfazUsuario::~InterfazUsuario(){

	if(this->menuPartida != NULL){
			delete this->menuPartida;
	}

	if(this->menuPrincipal != NULL){
		delete this->menuPrincipal;
	}

	delete this->creadorImagen;
}
