#ifndef INTERFAZUSUARIO_H_
#define INTERFAZUSUARIO_H_

#include <string>
#include "menu.h"
#include "pila.h"
#include "partida.h"
#include "creadorImagen.h"

/*
 * 'InterfazUsuario' permite la interaccion con el usuario, tanto la salida (por consola e imagenes BMP)
 * como la entrada.
 * Se encarga de crear los menues y gestionarlos. Permite cargar y mostrar los menues principal
 * y de la partida así como ejecutar las acciones de esos menues.
 */
class InterfazUsuario {

private:

	Menu* menuPrincipal;
	Menu* menuPartida;

	Pila<Menu*> menues;

	CreadorImagen* creadorImagen;

	//Pos: Crea un menu con las opciones de menu del menu principal
	Menu* crearMenuPrincipal();

	//Pos: Crea un menu con las opciones de menu del menu de configuracion
	Menu* crearMenuConfiguracion();

	//Pos: Crea un menu con las opciones de menu del menu de partida
	Menu* crearMenuPartida();

	//Pos: Agrega 'menu' a la pila de menues. 'menu' pasa a ser el menu actual.
	void agregarMenu(Menu* menu);

	//Pos: Muestra por consola los datos de la partida.
	void mostrarDatosPartida(Partida* partida);

	//Pos: Muestra por consola los recursos que posee 'jugador'
	void mostrarRecursosJugador(Jugador* jugador);

	//Pos: Muestra por consola el jugador que gano
	void mostrarGanador(unsigned int cantidadJugadores, Jugador** jugadores);

	//Pos: Muestra por consola una lista con las posiciones de los jugadores
	void mostrarPosiciones(unsigned int cantidadJugadores, Jugador** jugadores);

	//Pos: Muestra los terrenos de 'jugador' por consola
	void mostrarTerrenosJugadorPorConsola(Jugador* jugador);

	//Pos: Muestra 'terreno' por consola, con el estado de sus parcelas
	void dibujarTerrenoConsola(Terreno* terreno);

	//Pos: Muestra por consola los valores de las coordenadas X del terreno
	void dibujarCoordenadasXEnConsola(Terreno* terreno);

	//Pos: Muestra por consola los valores de la coordenada Y
	void dibujarCoordenadaYEnConsola(unsigned int coordenadaY);

	//Pos: Muestra por consola 'parcela'. De acuerdo al estado de la parcela se muestra de manera diferente
	void dibujarParcelaEnConsola(Parcela* parcela);

	//Pos: Muestra por consola el suelo de la parcela
	void dibujarSueloTerrenoEnConsola(Terreno* terreno);

	//Pos: Devuelve la informacion a mostrar dentro de la parcela de acuerdo al estado de la misma
	std::string obtenerInformacionAMostrarParcela(Parcela* parcela);

	//Pos: Devuelve el simbolo que se debe dibujar dentro de la parcela para indicar su estado
	std::string obtenerSimboloParcela(Parcela* parcela);

	/*
	 * Pos: Crea una imagen BMP por cada terreno de 'jugador'. Las imagenes se crean en el mismo directorio
	 * 		que el entorno de ejecucion del programa.
	 * 		Los nombres de las imagenes son: "NombreJugador_Terreno_NumeroTerreno"
	 * 		Ejemplo: "Jugador1_Terreno_1"
	 */
	void mostrarTerrenosJugadorPorImagen(Jugador* jugador);

	/*
	 * Pos: Crea una imagen BMP de 'terreno' de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		La imagen se crean en el mismo directorio que el entorno de ejecucion del programa.
	 * 		Los nombres de las imagenes son: "NombreJugador_Terreno_NumeroTerreno"
	 * 		Ejemplo: "Jugador1_Terreno_1"
	 */
	void dibujarTerreno(Terreno* terreno);

	/*
	 * Pos: Dibuja una parcela de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela. El dibujo de la parcela dependera del estado de la misma.
	 */
	void dibujarParcela(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY);

	/*
	 * Pos: Dibuja una parcela limpia de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela.
	 */
	void dibujarParcelaLimpia(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY);

	/*
	 * Pos: Dibuja una parcela cosechada de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela.
	 */
	void dibujarParcelaCosechada(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY);

	/*
	 * Pos: Dibuja una parcela sembrada de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela.
	 */
	void dibujarParcelaSembrada(Parcela* parcela,unsigned int coordenadaX, unsigned int coordenadaY);

	/*
	 * Pos: Dibuja una seca sembrada de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela.
	 */
	void dibujarParcelaSeca(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY);

	/*
	 * Pos: Dibuja una parcela podrida de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela.
	 */
	void dibujarParcelaPodrida(Parcela* parcela, unsigned int coordenadaX, unsigned int coordenadaY);

	/*
	 * Pos: Dibuja una parcela sembrada de acuerdo a los parametros definidos en 'PlantillaTerrenoImagen'.
	 * 		El punto definido por coordenadaX y coordenadaY determina el extremo superior izquierdo
	 * 		de la parcela.
	 */
	void dibujarAlambradoParcela(int coordenadaXEnDibujo, int coordenadaYEnDibujo);
	void dibujarMarcasArado(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo);
	void dibujarCultivos(Parcela* parcela, unsigned int coordenadaXEnDibujo, unsigned int coordenadaYEnDibujo);
	void dibujarRiego(int coordenadaXEnDibujo, int coordenadaYEnDibujo);
	void dibujarHoz(Parcela* parcela, int coordenadaXEnDibujo, int coordenadaYEnDibujo);
	void dibujarCoordenadas(Terreno* terreno);
	void dibujarCoordenadasXParcelas(Terreno* terreno);
	void dibujarCoordenadasYParcelas(Terreno* terreno);
	void dibujarPoste(int coordenadaXEnDibujo, int coordenadaYEnDibujo);
	void dibujarAlambrado(int coordenadaXDesde, int coordenadaYDesde, int coordenadaXHasta, int coordenadaYHasta);

	int obtenerCoordenadaXParcelaEnDibujo(unsigned int coordenadaX);
	int obtenerCoordenadaYParcelaEnDibujo(unsigned int coordenadaY);
	std::string obtenerNombreImagenCultivo(Cultivo* cultivo);
	int obtenerCoordenadaXImagenCultivo(int coordenadaXParcela);
	int obtenerCoordenadaYImagenCultivo(int coordenadaYParcela);

public:

	// Pos: Inicializa la interfaz para comenzar a interactuar.
	InterfazUsuario();

	// Pos: Muestra por pantalla un mensaje de bienvenida.
	void mostrarBienvenida();

	/*
	 * Pre: 'cantidadJugadores' debe ser mayor a 0.
	 * Pos: Solicita al usuario el ingreso de 'cantidadJugadores' nombres y los almacena en 'listaNombres'.
	 */
	void solicitarNombresJugadores(unsigned int cantidadJugadores, Lista<std::string>& listaNombres);

	// Pos: Carga en la interfaz el menu principal, el mismo pasa a ser el menu actual. No lo muestra por pantalla.
	void cargarMenuPrincipal();

	// Pos: Carga en la interfaz el menu de partida, el mismo pasa a ser el menu actual. No lo muestra por pantalla.
	void cargarMenuPartida();

	// Pos: Devuelve el ultimo menu cargado. En caso de no haber ningun menu cargado devuelve NULL.
	Menu* obtenerMenuActual();

	// Pos: Muestra por pantalla el ultimo menu cargado.
	void mostrarMenuActual();

	// Pos: Actualiza el menu actual al menu anterior.
	void irAMenuAnterior();

	// Pos: Solicita al usuario el ingreso de una de las opciones del menu actual y devuelve el numero de opcion elegida.
	unsigned int solicitarOpcion();

	// Pos: Ejecuta el numero de opcion pasado por parametro y devuelve el resultado de la ejecucion.
	ResultadoOpcion* ejecutarOpcion(unsigned int numeroOpcion);

	// Pos: Indica si el usuario salio del primero menu que se genero con la interfaz.
	bool salir();

	// Pos: Muestra los terrenos del jugador que esta jugando
	void mostrarTerrenosJugador(Jugador* jugador);	

	// Pos: Muestra por pantalla un mensaje de despedida.
	void mostrarDespedida();

	// Pos: Crea un archivo BMP con el estado del jugador actual de la partida.
	void mostrarEstadoPartida(Partida* partida);

	// Pos: Muesta por pantalla el resumen de la partida jugada. Determina el ganador de la partida y los recursos finales de cada jugador.
	void mostrarResumenPartida(Partida* partida);

	// Pos: Libera los recursos reservados.
	~InterfazUsuario();
};

#endif /* INTERFAZUSUARIO_H_ */
