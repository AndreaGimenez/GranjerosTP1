#include "interfazUsuario.h"
#include <cstdlib>
#include <iostream>
#include "utils.h"
#include "configuracion.h"
#include "plantillaTerrenoImagen.h"
#include "plantillaTerrenoConsola.h"


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
	
	for(unsigned int i = 1; i <= jugador->obtenerCantidadTerrenos(); i++){
		
		Terreno* terreno = jugador->buscarTerreno(i);

		dibujarTerrenoConsola(terreno);
		cout << endl << endl;
	}
}

void InterfazUsuario::dibujarTerrenoConsola(Terreno* terreno){

	dibujarCoordenadasXEnConsola(terreno);
	cout << endl;

	for(unsigned int j = 1; j <= terreno->obtenerLargoTerreno(); j++){

		//cout << "__________________________________________________________________________________" << endl;
		cout << endl;
		dibujarCoordenadaYEnConsola(j);
		cout << PlantillaTerrenoConsola::obtenerSimboloSeparacionEntreParcelas();
		for(unsigned int k = 1; k <= terreno->obtenerAnchoTerreno(); k++){

			Parcela* parcelaActual = terreno->buscarParcela(Utils::unsignedIntToString(j) + "," + Utils::unsignedIntToString(k));
			dibujarParcelaEnConsola(parcelaActual);
		}
		cout << PlantillaTerrenoConsola::obtenerSimboloSeparacionEntreParcelas() << endl;
		dibujarSueloTerrenoEnConsola(terreno);
	}
}

void InterfazUsuario::dibujarSueloTerrenoEnConsola(Terreno* terreno){

	cout << Utils::fillString("", " ", PlantillaTerrenoConsola::obtenerDistanciaBordeIzquierdo(), true)
		 << PlantillaTerrenoConsola::obtenerSimboloSueloParcela()
		 << Utils::fillString("", PlantillaTerrenoConsola::obtenerSimboloSueloParcela(),
				 	 	 	 terreno->obtenerAnchoTerreno() * (PlantillaTerrenoConsola::obtenerAnchoParcela() + 2), false)
		 << PlantillaTerrenoConsola::obtenerSimboloSueloParcela() << endl;
}

void InterfazUsuario::dibujarParcelaEnConsola(Parcela* parcela){

	string informacionAMostrar = obtenerInformacionAMostrarParcela(parcela);
	string simboloEstadoParcela = obtenerSimboloParcela(parcela);
	string simboloSeparacionEntreParcelas = PlantillaTerrenoConsola::obtenerSimboloSeparacionEntreParcelas();

	unsigned int cantidadSimbolosEstadoParcela = PlantillaTerrenoConsola::obtenerAnchoParcela() - informacionAMostrar.size();

	string dibujoParcela = simboloSeparacionEntreParcelas
						 + Utils::fillString("", simboloEstadoParcela, cantidadSimbolosEstadoParcela/2 + cantidadSimbolosEstadoParcela%2, true)
				  	  	 + informacionAMostrar
						 + Utils::fillString("", simboloEstadoParcela, cantidadSimbolosEstadoParcela/2, true)
				  	  	 + simboloSeparacionEntreParcelas;

	cout << dibujoParcela;
}

string InterfazUsuario::obtenerInformacionAMostrarParcela(Parcela* parcela){

	string informacionAMostrar = "";

	Cultivo* cultivo;
	string simboloRiego = (parcela->obtenerRegada())?PlantillaTerrenoConsola::obtenerSimboloParcelaRegada():PlantillaTerrenoConsola::obtenerSimboloParcelaSinRegar();

	switch(parcela->obtenerEstado()){

		case parcela::SEMBRADA:

			cultivo = parcela->obtenerCultivo();
			informacionAMostrar = cultivo->obtenerNombre() + "("
								 + Utils::unsignedIntToString(parcela->obtenerTiempoSembrada())
								 + ", "
								 + simboloRiego
								 + ")";
			break;

		case parcela::PODRIDA:

			informacionAMostrar = "(" + Utils::unsignedIntToString(parcela->obtenerTiempoRecuperacionRestante()) + ")";
			break;

		case parcela::COSECHADA:

			informacionAMostrar = "(" + Utils::unsignedIntToString(parcela->obtenerTiempoRecuperacionRestante()) + ")";
			break;

		default:

			informacionAMostrar = "";
	}

	return informacionAMostrar;
}

string InterfazUsuario::obtenerSimboloParcela(Parcela* parcela){

	string simboloEstadoParcela = "";

	switch(parcela->obtenerEstado()){

		case parcela::LIMPIA:

			simboloEstadoParcela = PlantillaTerrenoConsola::obtenerSimboloParcelaLimpia();
			break;

		case parcela::SEMBRADA:

			simboloEstadoParcela = PlantillaTerrenoConsola::obtenerSimboloParcelaSembrada();
			break;

		case parcela::SECA:

			simboloEstadoParcela = PlantillaTerrenoConsola::obtenerSimboloParcelaSeca();
			break;

		case parcela::PODRIDA:

			simboloEstadoParcela = PlantillaTerrenoConsola::obtenerSimboloParcelaPodrida();
			break;

		case parcela::COSECHADA:

			simboloEstadoParcela = PlantillaTerrenoConsola::obtenerSimboloParcelaCosechada();
			break;
	}

	return simboloEstadoParcela;
}

void InterfazUsuario::dibujarCoordenadaYEnConsola(unsigned int coordenadaY){

	string stringIndice = Utils::unsignedIntToString(coordenadaY);
	cout<<  Utils::padString(stringIndice, " ", PlantillaTerrenoConsola::obtenerDistanciaBordeIzquierdo(), true);
}

void InterfazUsuario::dibujarCoordenadasXEnConsola(Terreno* terreno){

	//hay que imprimir distancia de coordenadas Y + 1 porque hay que que agregar el espacio que ocupa la separacion de la parcela
	cout << Utils::fillString("", " ", PlantillaTerrenoConsola::obtenerDistanciaBordeIzquierdo() + 1, true);
	for(unsigned int k=1;k<=terreno->obtenerAnchoTerreno();k++){

		string stringIndice = Utils::unsignedIntToString(k);
		unsigned int cantidadEspacios = PlantillaTerrenoConsola::obtenerAnchoParcela() + 2 - stringIndice.size();//Es + 2 por la separacion de la parcela
		cout << Utils::fillString("", " ", cantidadEspacios/2, true) + stringIndice + Utils::fillString("", " ", cantidadEspacios/2 + cantidadEspacios%2, true);
	}
}

void InterfazUsuario::mostrarTerrenosJugadorPorImagen(Jugador* jugador){

	for(unsigned int iTerreno = 1; iTerreno <= jugador->obtenerCantidadTerrenos(); iTerreno++){

		creadorImagen->crearNuevaImagen(PlantillaTerrenoImagen::obtenerLargoTerreno(),
										PlantillaTerrenoImagen::obtenerAnchoTerreno(), 24);
		Terreno* terreno = jugador->buscarTerreno(iTerreno);
		dibujarTerreno(terreno);
		creadorImagen->guardarImagen(jugador->obtenerNombre() + "_Terreno_" + Utils::unsignedIntToString(iTerreno));
	}
}

void InterfazUsuario::dibujarTerreno(Terreno* terreno){

	dibujarCoordenadas(terreno);

	for(unsigned int coordenadaY = 1; coordenadaY <= terreno->obtenerLargoTerreno(); coordenadaY++){
		for(unsigned int coordenadaX = 1; coordenadaX <= terreno->obtenerAnchoTerreno(); coordenadaX++){

			Parcela* parcelaActual = terreno->buscarParcela(Utils::unsignedIntToString(coordenadaY) + "," + Utils::unsignedIntToString(coordenadaX));
			dibujarParcela(parcelaActual, coordenadaX, coordenadaY);
		}
	}
}

void InterfazUsuario::dibujarCoordenadas(Terreno* terreno){

	dibujarCoordenadasXParcelas(terreno);
	dibujarCoordenadasYParcelas(terreno);
}

void InterfazUsuario::dibujarCoordenadasXParcelas(Terreno* terreno){

	unsigned int distanciaHorizontalAlBorde = PlantillaTerrenoImagen::obtenerDistanciaHorizontalAlBorde();

	//Distancia en pixeles de la parte superior de la imagen de la coordenada respecto del margen superior del lienzo
	unsigned int coordenadaYNumeroCoordenada = PlantillaTerrenoImagen::obtenerDistanciaVerticalAlBorde()
											 - PlantillaTerrenoImagen::obtenerDistanciaParcelaCoordenadaX()
											 - PlantillaTerrenoImagen::obtenerAltoImagenNumeroCoordenada();

	for(unsigned int numeroCoordenada = 1; numeroCoordenada <= terreno->obtenerAnchoTerreno(); numeroCoordenada++){

		string stringNumeroCoordenada = Utils::unsignedIntToString(numeroCoordenada);
		unsigned int cantidadDigitosNumeroCoordenada = stringNumeroCoordenada.size();
		unsigned int cantidadEspaciosNumeroCoordenada = cantidadDigitosNumeroCoordenada - 1;//Si el numero tiene 2 digitos hay 1 espacio, si tiene 3 son 2 espacios, es decir n-1
		/*
		 * Calculamos la coordenada respecto del borde izquiero del lienzo del primer digito del numero de coordenada.
		 * Si el numero de coordenada fuese 15, indica la posicion donde va el 1.
		 *
		 * Se calcula como: distanciaHorizontalAlBorde
		 * 					+ (cantidad de parcelas antes que la parcela actual(es el numero de parcela actual - 1) * ancho de parcela)
		 * 					+ (la mitad del ancho de una parcela)
		 * 					- (la mitad del ancho que ocupa la imagen completa del numero de coordenada)
		 * 					                                    |
		 * 					                                    v
		 * 		hay que tener en cuenta que un numero de coordenada tiene n digitos y n - 1 espacios por lo tanto el ancho completo
		 * 		es el ancho de la imagen de 1 numero * n(digitos) + ancho del espacio entre numeros * n-1
		 */
		int coordenadaXPrimerDigito = distanciaHorizontalAlBorde
									+ ((numeroCoordenada - 1) * PlantillaTerrenoImagen::obtenerAnchoParcela())
									+ (PlantillaTerrenoImagen::obtenerAnchoParcela() / 2)
									- ((cantidadDigitosNumeroCoordenada * PlantillaTerrenoImagen::obtenerAnchoImagenNumeroCoordenada()
										+ (cantidadEspaciosNumeroCoordenada * PlantillaTerrenoImagen::obtenerEspacioDigitosCoordenada())) / 2);

		//Si el numero de coordenada tiene mas de 1 digito hay que buscar digito por digito la imagen que le corresponde y pegarlas una al lado de la otra
		//Por ejemplo el numero 10 primero busca la imagen 1 y la pega, luego busca la imagen del 0 y la pega al lado dejando un espacio entre las imagenes
		//A medida que se van pegando los digitos hay que ir moviendo la coordenada donde se pega el siguiente digito, para eso se usa esta variable
		int coordenadaXNumeroActual = coordenadaXPrimerDigito;
		for(unsigned int i = 0; i < cantidadDigitosNumeroCoordenada; i++){

			creadorImagen->pegarImagen(Configuracion::obtenerImagesPath() + stringNumeroCoordenada.substr(i, 1) + ".bmp", coordenadaXNumeroActual, coordenadaYNumeroCoordenada);
			coordenadaXNumeroActual = coordenadaXNumeroActual
									+ PlantillaTerrenoImagen::obtenerAnchoImagenNumeroCoordenada()
									+ PlantillaTerrenoImagen::obtenerEspacioDigitosCoordenada();
		}
	}
}

void InterfazUsuario::dibujarCoordenadasYParcelas(Terreno* terreno){

	unsigned int distanciaVerticalAlBorde = PlantillaTerrenoImagen::obtenerDistanciaVerticalAlBorde();

	for(unsigned int numeroCoordenada = 1; numeroCoordenada <= terreno->obtenerLargoTerreno(); numeroCoordenada++){

		string stringNumeroCoordenada = Utils::unsignedIntToString(numeroCoordenada);
		unsigned int cantidadDigitosNumeroCoordenada = stringNumeroCoordenada.size();
		unsigned int cantidadEspaciosNumeroCoordenada = cantidadDigitosNumeroCoordenada - 1;//Si el numero tiene 2 digitos hay 1 espacio, si tiene 3 son 2 espacios, es decir n-1

		int coordenadaXPrimerDigito = PlantillaTerrenoImagen::obtenerDistanciaHorizontalAlBorde()
									- PlantillaTerrenoImagen::obtenerDistanciaParcelaCoordenadaY()
									- (cantidadDigitosNumeroCoordenada * PlantillaTerrenoImagen::obtenerAnchoImagenNumeroCoordenada()
										+ (cantidadEspaciosNumeroCoordenada * PlantillaTerrenoImagen::obtenerEspacioDigitosCoordenada()));

		int coordenadaYEnDibujo = distanciaVerticalAlBorde
								+ ((numeroCoordenada - 1) * PlantillaTerrenoImagen::obtenerLargoParcela())
								+ (PlantillaTerrenoImagen::obtenerLargoParcela() / 2)
								- PlantillaTerrenoImagen::obtenerAltoImagenNumeroCoordenada() / 2;

		int coordenadaXNumeroActual = coordenadaXPrimerDigito;
		for(unsigned int i = 0; i < cantidadDigitosNumeroCoordenada; i++){

			creadorImagen->pegarImagen(Configuracion::obtenerImagesPath() + stringNumeroCoordenada.substr(i, 1) + ".bmp", coordenadaXNumeroActual, coordenadaYEnDibujo);
			coordenadaXNumeroActual = coordenadaXNumeroActual
									+ PlantillaTerrenoImagen::obtenerAnchoImagenNumeroCoordenada()
									+ PlantillaTerrenoImagen::obtenerEspacioDigitosCoordenada();
		}
	}
}

void InterfazUsuario::dibujarParcela(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY){

	//Estas variables almacenan la posicion dentro de la imagen en la que se debe dibujar la parela
	//A partir de los numeros de coordenada se puede obtener la posicion en la imagen
	int coordenadaXEnDibujo = obtenerCoordenadaXParcelaEnDibujo(coordenadaX);
	int coordenadaYEnDibujo = obtenerCoordenadaYParcelaEnDibujo(coordenadaY);

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

	creadorImagen->pegarImagenConTransparencia("resources/img/gota.bmp",
												coordenadaXEnDibujo + PlantillaTerrenoImagen::obtenerAnchoParcela()/2 - PlantillaTerrenoImagen::obtenerAnchoImagenRiego(),
												coordenadaYEnDibujo + PlantillaTerrenoImagen::obtenerLargoParcela() - PlantillaTerrenoImagen::obtenerAltoImagenRiego(),
												creadorImagen->obtenerColor(VERDE_HIERBA));
}

void InterfazUsuario::dibujarParcelaLimpia(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerAnchoParcela(), PlantillaTerrenoImagen::obtenerLargoParcela(),
											   coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(VERDE_CLARO), creadorImagen->obtenerColor(VERDE));
}

void InterfazUsuario::dibujarParcelaSembrada(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerAnchoParcela(), PlantillaTerrenoImagen::obtenerLargoParcela(),
											   coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(VERDE_CLARO), creadorImagen->obtenerColor(VERDE));

	dibujarCultivos(parcela, coordenadaXEnDibujo, coordenadaYEnDibujo);

	string nombreImagenCultivo = obtenerNombreImagenCultivo(parcela->obtenerCultivo());
	int coordenadaXImagenCultivo = obtenerCoordenadaXImagenCultivo(coordenadaXEnDibujo);
	int coordenadaYImagenCultivo = obtenerCoordenadaYImagenCultivo(coordenadaYEnDibujo);

	creadorImagen->pegarImagenConTransparencia(nombreImagenCultivo, coordenadaXImagenCultivo, coordenadaYImagenCultivo, creadorImagen->obtenerColor(VERDE_HIERBA));
}

void InterfazUsuario::dibujarCultivos(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	unsigned int anchoCultivo = PlantillaTerrenoImagen::obtenerAnchoCultivo();
	unsigned int separacionEntreCultivos = PlantillaTerrenoImagen::obtenerSeparacionEntreCultivos();
	unsigned int cantidadCultivos = (PlantillaTerrenoImagen::obtenerLargoParcela() - separacionEntreCultivos)/(anchoCultivo + separacionEntreCultivos);

	int posicionFinalUltimoCultivo = coordenadaYEnDibujo;//Indica la coordenada Y en la que termino la ultima marca, se inicializa en el inicio de la parcela

	for(unsigned int i  = 0; i < cantidadCultivos; i ++){

		int posicionCultivoActual = posicionFinalUltimoCultivo + separacionEntreCultivos;//La nueva marca comienza en esta coordenada
		creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerLargoParcela(), anchoCultivo,
												   coordenadaXEnDibujo, posicionCultivoActual, creadorImagen->obtenerColor(VERDE_HIERBA), creadorImagen->obtenerColor(VERDE));
		posicionFinalUltimoCultivo = posicionCultivoActual + anchoCultivo;
	}
}

void InterfazUsuario::dibujarParcelaSeca(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerAnchoParcela(), PlantillaTerrenoImagen::obtenerLargoParcela(),
											   coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(AMARILLO_ARENA), creadorImagen->obtenerColor(AMARILLO_MIEL));
}

void InterfazUsuario::dibujarParcelaPodrida(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerAnchoParcela(), PlantillaTerrenoImagen::obtenerLargoParcela(),
											   coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(VERDE_HIERBA), creadorImagen->obtenerColor(MARRON_TIERRA));
}

void InterfazUsuario::dibujarParcelaCosechada(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerAnchoParcela(), PlantillaTerrenoImagen::obtenerLargoParcela(),
											   coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(MARRON_CLARO), creadorImagen->obtenerColor(VERDE));

	dibujarMarcasArado(parcela, coordenadaXEnDibujo, coordenadaYEnDibujo);
	dibujarHoz(parcela, coordenadaXEnDibujo, coordenadaYEnDibujo);
}

void InterfazUsuario::dibujarHoz(Parcela* parcela, int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	creadorImagen->pegarImagenConTransparencia(Configuracion::obtenerImagesPath() + "hoz.bmp",
												coordenadaXEnDibujo + PlantillaTerrenoImagen::obtenerAnchoParcela()/2 - PlantillaTerrenoImagen::obtenerAnchoImagenHoz()/2,
												coordenadaYEnDibujo + PlantillaTerrenoImagen::obtenerLargoParcela()/2 - PlantillaTerrenoImagen::obtenerAltoImagenHoz()/2,
												creadorImagen->obtenerColor(VERDE_HIERBA));
}

void InterfazUsuario::dibujarMarcasArado(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo){

	unsigned int anchoMarcaArado = PlantillaTerrenoImagen::obtenerAnchoMarcaArado();
	unsigned int separacionEntreMarcasArado = PlantillaTerrenoImagen::obtenerSeparacionEntreMarcasArado();
	unsigned int cantidadMarcasArado = (PlantillaTerrenoImagen::obtenerLargoParcela() - separacionEntreMarcasArado)/(anchoMarcaArado + separacionEntreMarcasArado);

	int posicionFinalUltimaMarca = coordenadaYEnDibujo;//Indica la coordenada Y en la que termino la ultima marca, se inicializa en el inicio de la parcela

	for(unsigned int i  = 0; i < cantidadMarcasArado; i ++){

		int posicionMarcaActual = posicionFinalUltimaMarca + separacionEntreMarcasArado;//La nueva marca comienza en esta coordenada
		creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerLargoParcela(), anchoMarcaArado,
												   coordenadaXEnDibujo, posicionMarcaActual, creadorImagen->obtenerColor(MARRON), creadorImagen->obtenerColor(MARRON_TIERRA));
		posicionFinalUltimaMarca = posicionMarcaActual + anchoMarcaArado;
	}
}

void InterfazUsuario::dibujarAlambradoParcela(int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	unsigned int anchoParcela = PlantillaTerrenoImagen::obtenerAnchoParcela();
	unsigned int largoParcela = PlantillaTerrenoImagen::obtenerLargoParcela();
	unsigned int anchoPoste = PlantillaTerrenoImagen::obtenerAnchoPoste();
	unsigned int largoPoste = PlantillaTerrenoImagen::obtenerLargoPoste();

	//Se dibujan 4 postes, uno en cada esquina de la parcela
	dibujarPoste(coordenadaXEnDibujo, coordenadaYEnDibujo);
	dibujarPoste(coordenadaXEnDibujo + anchoParcela - anchoPoste, coordenadaYEnDibujo);
	dibujarPoste(coordenadaXEnDibujo, coordenadaYEnDibujo + largoParcela - largoPoste);
	dibujarPoste(coordenadaXEnDibujo + anchoParcela - anchoPoste,
				 coordenadaYEnDibujo + largoParcela - largoPoste);

	//Se unen los postes con el alambrado
	dibujarAlambrado(coordenadaXEnDibujo + anchoPoste, coordenadaYEnDibujo + largoPoste/2,
					 coordenadaXEnDibujo + anchoParcela - anchoPoste, coordenadaYEnDibujo + largoPoste/2);
	dibujarAlambrado(coordenadaXEnDibujo + anchoPoste/2, coordenadaYEnDibujo + largoPoste,
					 coordenadaXEnDibujo + anchoPoste/2, coordenadaYEnDibujo + largoParcela - largoPoste);
	dibujarAlambrado(coordenadaXEnDibujo + anchoPoste, coordenadaYEnDibujo + largoParcela - largoPoste/2,
					 coordenadaXEnDibujo + anchoParcela - anchoPoste, coordenadaYEnDibujo + largoParcela - largoPoste/2);
	dibujarAlambrado(coordenadaXEnDibujo + anchoParcela - anchoPoste/2, coordenadaYEnDibujo + largoPoste,
					 coordenadaXEnDibujo + anchoParcela - anchoPoste/2, coordenadaYEnDibujo + largoParcela - largoPoste);

}

void InterfazUsuario::dibujarPoste(int coordenadaXEnDibujo, int coordenadaYEnDibujo){

	creadorImagen->dibujarRectanguloConRelleno(PlantillaTerrenoImagen::obtenerAnchoPoste(), PlantillaTerrenoImagen::obtenerLargoPoste(),
											   coordenadaXEnDibujo, coordenadaYEnDibujo, creadorImagen->obtenerColor(MARRON));
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

	return Configuracion::obtenerImagesPath() + "Cultivo_" + cultivo->obtenerNombre() + ".bmp";
}

int InterfazUsuario::obtenerCoordenadaXImagenCultivo(int coordenadaXParcela){

	return coordenadaXParcela
			+ PlantillaTerrenoImagen::obtenerAnchoParcela() / 2
			- PlantillaTerrenoImagen::obtenerAnchoImagenNombreCultivo() / 2;
}

int InterfazUsuario::obtenerCoordenadaYImagenCultivo(int coordenadaYParcela){

	return coordenadaYParcela
			+ PlantillaTerrenoImagen::obtenerLargoParcela() / 2
			- PlantillaTerrenoImagen::obtenerAltoImagenNombreCultivo() / 2;
}

int InterfazUsuario::obtenerCoordenadaXParcelaEnDibujo(unsigned int coordenadaX){

	return (coordenadaX - 1) * PlantillaTerrenoImagen::obtenerAnchoParcela() + PlantillaTerrenoImagen::obtenerDistanciaHorizontalAlBorde();
}

int InterfazUsuario::obtenerCoordenadaYParcelaEnDibujo(unsigned int coordenadaY){

	return (coordenadaY - 1) * PlantillaTerrenoImagen::obtenerLargoParcela() + PlantillaTerrenoImagen::obtenerDistanciaVerticalAlBorde();
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
