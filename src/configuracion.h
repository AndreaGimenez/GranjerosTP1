#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include "cultivo.h"
#include "lista.h"
#include "parametroConfiguracion.h"
#include "lugar.h"

int const COSTO_MINIMO = 20;
int const COSTO_UNITARIO_ALMACENAMIENTO_ALMACEN = 2;
int const COSTO_UNITARIO_ALMACENAMIENTO_TANQUE = 2 ;


/*
 * Clase que representa las configuraciones del juego.
 * Contiene los valores iniciales, dificultades, realiza todos los calculos que dependan
 * de la dificultad del juego, contiene los recursos disponibles, constantes, etc.
 * La configuracion es comun a tode el juego por ende no debe instanciarse en cada lugar,
 * debe inicializarse una unica vez y luego utilizarse de manera estatica.
 *
 * Tambien incluye los path relativos donde se almacenan los archivos que necesita el juego.
 * Path de archivos de cultivos: resources/cultivos.txt
 * Path de archivos de destinos: resources/destinos.txt
 * Path de archivos de imagenes: resources/img
 */
class Configuracion {

private:

	static Dificultad dificultad;
	static unsigned int cantidadTerrenosIniciales;
	static unsigned int cantidadJugadores;
	static unsigned int parametroN;
	static unsigned int parametroM;
	static unsigned int cantidadTurnos;
	static Lista<Lugar*>* lugares;
	static Lista<Cultivo*>* cultivos;
	static Lista<Trayecto*>* trayectos;
	static std::string resourcesPath;
	static std::string imagesPath;
	static std::string cultivosFileName;
	static std::string destinosFileName;

	//Para evitar que sea instanciada el constructor es private, debe usarse de manera estatica.
	Configuracion();

	/*
	 * Pre: En el archivo 'cultivos.txt' no puede haber mas de 1 linea con el mismo cultivo.
	 * Pos: Carga los cultivos con la informacion del archivo 'cultivos.txt'.
	 */
	static void cargarCultivos();

	// Pos: Devuelve la ruta completa con el nombre del archivo de cultivos.
	static std::string obtenerArchivoCultivos();

	/*
	 * Pre: En el archivo 'destinos.txt' no puede haber mas de 1 destino para cada cultivo.
	 * Pos: Carga los destinos con la informacion del archivo 'destinos.txt'.
	 */
	static void cargarDestinos();

	// Pos: Devuelve la ruta completa con el nombre del archivo de destinos.
	static std::string obtenerArchivoDestinos();

	/*
	 * Pos: Devuelve el coeficiente que se utilizara para calcular:
	 * 			- Creditos iniciales
	 *			- Capacidad inicial del tanque
	 *			- Capacidad inicial del almacen
	 */
	static unsigned int obtenerCoeficienteDificultad();

	// Pos: Libera memoria pedida para los cultivos
	static void destruirCultivos();

	// Pos: Libera memoria pedida para los destinos
	static void destruirLugares();

	// Pos: Libera memoria pedida para los trayectos
	static void destruirTrayectos();

	// Pos: Calcula los costos minimos para cada destino de los cultivos
	static void calcularCostoMinimoDestinos();

public:

	// Pos: Inicializa la configuracion de acuerdo a los parametros del juego y archivos de configuracion.
	static void inicializar(ParametroConfiguracion* parametros);

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la dificultad configurada.
	 */
	static Dificultad obtenerDificultad();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la cantidad de terrenos iniciales para un jugador.
	 */
	static unsigned int obtenerCantidadTerrenosIniciales();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la cantidad de jugadores de la partida
	 */
	static unsigned int obtenerCantidadJugadores();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve el largo del terreno, la dimension representada por las filas.
	 */
	static unsigned int obtenerLargoTerreno();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve el ancho del terreno, la dimension representada por las columnas.
	 */
	static unsigned int obtenerAnchoTerreno();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la cantidad de creditos iniciales de la partida.
	 */
	static unsigned int obtenerCreditosIniciales();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la capacidad inicial del tanque.
	 */
	static unsigned int obtenerCapacidadInicialTanque();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la cantidad de turnos.
	 */
	static unsigned int obtenerCantidadTurnos();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la capacidad inicial del almacen.
	 */
	static unsigned int obtenerCapacidadInicialAlmacen();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * 	   'numeroTerrenoAComprar' debe ser la cantidad de terrenos del jugador + 1.
	 * Pos: Devuelve el costo de comprar el terreno.
	 */
	static unsigned int obtenerCostoTerreno(unsigned int numeroTerrenoAComprar);

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve el costo de comprar las undiades de almacenamiento indicadas en 'aumentoAlmacenamiento'.
	 */
	static unsigned int obtenerCostoAumentoAlmacenamientoAlmacen(unsigned int aumentoAlmacenamiento);

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve el costo de comprar las undiades de almacenamiento indicadas en 'aumentoVolumen'.
	 */
	static unsigned int obtenerCostoAumentoCapacidadTanque(unsigned int aumentoVolumen);

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve los cultivos disponibles para que utilicen los jugadores.
	 *      Los mismos dependerán de la configuración del archivo 'cultivos.txt'.
	 */
	static Lista<Cultivo*>* obtenerCultivos();

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve el cultivo que corresponde al nombre pasa por parametro 'nombreCultivo'.
	 * 	    En caso que 'nombreCultivo' no pertenezca a ningun cultivo disponible devuelve NULL.
	 */
	static Cultivo* obtenerCultivo(std::string nombreCultivo);

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve el lugar cuyo nombre se corresponde con 'nombreLugar'.
	 */
	static Lugar* obtenerLugar(std::string nombreLugar);

	/*
	 * Pre: Se debe haber inicializado la configuracion con 'inicializar'.
	 * Pos: Devuelve la rentabilidad de enviar 'cantidad' de cosechas de 'cultivo.
	 */
	static unsigned int calcularRentabilidad(Cultivo* cultivo, unsigned int cantidad);

	// Pos: Devuelve la rentabilidad de enviar 'cantidad' de cosechas de 'cultivo.
	static std::string obtenerResourcesPath();

	// Pos: Devuelve el directorio de imagenes, donde se encuentran las imagenes necesarias para el juego.
	static std::string obtenerImagesPath();

	// Pos: Libera la memoria reservada para los cultivos y destinos.
	~Configuracion();
};

#endif /* CONFIGURACION_H_ */
