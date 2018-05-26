#ifndef PARTIDA_H_
#define PARTIDA_H_

#include "jugador.h"
#include "lista.h"
#include "parametroConfiguracion.h"


using namespace std ;


/*
 * Clase que representa una partida determinada.
 * Una partida esta determinada por una cantidad de jugadores que realizan acciones a lo largo de una
 * cantidad especifica de turnos. Una vez que todos los jugadores realizaron una accion durante un turno
 * se avanza de turno y comienza nuevamente el primer jugador.
 * La cantidad de jugadores y la cantidad de turnos vienen dados por la configuracion realizada previo
 * al juego.
 * Maneja las acciones que realizan los jugadores durante un turno y mantiene el estado de cada jugador a lo largo del juego.
 * Las acciones que puede realizar un jugador son fijas y siempre las mismas:
 * 	-Sembrar
 * 	-Cosechar
 * 	-Regar
 * 	-Comprar:
 * 		-Capacidad de tanque
 * 		-Capacidad de almacen
 * 		-Terreno
 * 	-Vender:
 * 		-Terreno
 *
 * 	La partida finaliza cuando la cantidad de turnos jugados es igual a la cantidad de turnos de la partida.
 */
class Partida{

	private:

		Dificultad nivelDeDificultad;
		unsigned int cantidadTurnos;
		unsigned int cantidadTurnosJugados;
		Lista<Jugador*>* jugadores;

		void cargarJugadores(Lista<string>* nombresJugadores);
		void actualizar();

	public:

		/*
		 * Post: Inicializa la partida.
		 * 		 La partida tendrá tantos jugadores como los que haya en la lista 'nombresJugadores'.
		 * 		 El nivel de dificultad y la cantidad de turnos dependerán de la configuracion.
		 */
		Partida(Lista<string>* nombresJugadores);

		// Post: Devuelve la dificultad del juego.
		Dificultad obtenerDificultad();

		// Post: Devuelve la cantidad de jugadores que hay en la partida.
		unsigned int obtenerCantidadDeJugadores();

		// Post: Devuelve el numero de turno actual
		unsigned int obtenerTurnoActual();

		/*
		 * Post: Devuelve el jugador actual de la partida.
		 * 		 El mismo va variando a medida que avanzan los turnos de la partida con el metodo 'avanzarTurno'.
		 */
		Jugador* verJugadorActual();

		// Post: Avanza al jugador siguiente. Devuelve false si el jugador actual es el ultimo jugador.
		bool avanzarProximoJugador();

		// Post: Posiciona el jugador actual en el primer jugador.
		void irAPrimerJugador();

		/*
		 * Post: Compra una ampliacion para el tanque del jugador actual de la partida.
		 * 		 Consume los recursos necesarios para poder ampliarlo.
		 * 		 En caso que no se pueda realizar la accion por falta de recursos devuelve false.
		 */
		bool ejecutarAccionComprarCapacidadAgua();

		/*
		 * Post: Compra una ampliacion para el almacen del jugador actual de la partida.
		 * 		 Consume los recursos necesarios para poder ampliarlo.
		 * 		 En caso que no se pueda realizar la accion por falta de recursos devuelve false.
		 */
		bool ejecutarAccionComprarCapacidadAlmacen();

		/*
		 * Post: Compra un terreno para el jugador actual, el cual queda disponible para realizar siembras sobre el.
		 * 		 El precio de compra dependera del numero de terreno a comprar y de la dificultad de la partida.
		 * 		 Consume los recursos necesarios para poder comprar el terreno.
		 * 		 En caso que no se pueda realizar la accion por falta de recursos devuelve false.
		 */
		bool ejecutarAccionComprarTerreno();

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Cosecha la parcela indicada en 'coordenadasParcela' para el terreno 'numeroTerreno'.
		 * 		 La cosecha es almacenada en el almacen del jugador.
		 * 		 En caso que la accion no se pueda realizar devuelve false.
		 *
		 */
		bool ejecutarAccionCosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		/*
		 * Pre: 'nombreCultivo' debe ser el nombre de un cultivo presente en el archivo 'cultivos.txt'
		 * Post: Envia las cosechas almacenadas del jugador actual del cultivo 'nombreCultivo' al destino indicado en el archivo 'destinos.txt'.
		 * 		 Aumenta la cantidad de monedas del jugador actual de acuerdo a la rentabilidad del cultivo y consume monedas de acuerdo al costo de envio
		 * 		 calculado como precio * cantidad enviada. El precio se determina del archivo 'destinos.txt'.
		 * 		 En caso que la accion no se pueda realizar devuelve false.
		 */
		bool ejecutarAccionEnviarCosecha(std::string nombreCultivo);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Riega la parcela indicada en 'coordenadasParcela' para el terreno 'numeroTerreno', evitando que se seque.
		 * 		 Consume las unidades de riego correspondientes de acuerdo al cultivo que se encuentre sembrado en la parcela.
		 * 		 Las mismas son consumidas de las unidades de riego que el jugador obtuvo en el turno actual y del tanque en caso de ser necesario.
		 * 		 En caso que la accion no se pueda realizar por falta de recursos devuelve false.
		 */
		bool ejecutarAccionRegar(unsigned int numeroTerreno, std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * 		'nombreCultivo' debe ser el nombre de un cultivo presente en el archivo 'cultivos.txt'
		 * Post: Siembra la parcela indicada con el cultivo correspondiente a 'nombreCultivo'.
		 * 		 Consume la cantidad de monedas correspondientes al costo de la semilla del cultivo indicada en 'cultivos.txt'.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool ejecutarAccionSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, std::string nombreCultivo);

		/*
		 * Pre: 'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Vende el terreno correspondiente y aumenta las monedas del jugador actual.
		 * 		 La numeracion de los terrenos se ve modificada en caso de vender un terreno que no es el ultimo.
		 * 		 Ej:
		 * 		 	El jugador tiene 4 terrenos, su numeracion es: 1,2,3,4
		 * 		 	El jugador vende el terreno 2 los terrenos restantes quedan numerados: 1,2,3.
		 * 		 	El terreno 3 paso a ser el numero 2 y el numero 4 paso a ser el numero 3.
		 *
		 * 		 Devuelve false en caso no poder realizar la accion.
		 */
		bool ejecutarAccionVenderTerreno(unsigned int numeroTerreno);

		/*
		 * Pre: 'partidaFinalizada' debe ser false.
		 * Post: Actualiza el estado de la partida y los recursos del jugador actual.
		 * 		 Si existe un jugador luego del jugador actual entonces jugador actual pasa a ser el jugador siguiente.
		 * 		 Si no existe ningun jugador luego del jugador actual se avanza al siguiente turno y el jugador actual
		 * 		 pasa a ser el primer jugador.
		 * 		 En caso que no queden mas jugadores y se hayan jugado todos los turnos devuelve true, indicando que la
		 * 		 partida ya finalizo.
		 */
		bool avanzarTurno();

		//Post: Setea en 'jugadoresOrdenados' un array con los jugadores del juego ordenados de acuerdo a la cantidad de monedas que posea cada uno
		//		El primer elemento del array es el jugador que mas monedas posee y el ultimo el que menos tiene
		void obtenerJugadoresOrdenados(Jugador** jugadoresOrdenados);

		// Post: Indica si la partida se encuentra finalizada, es decir que se jugaron todos los turnos.
		bool partidaFinalizada();

		// Post: Libera los recursos reservados.
		~Partida();
};



#endif /* PARTIDA_H_ */
