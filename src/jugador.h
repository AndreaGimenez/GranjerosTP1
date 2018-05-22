/*
 * jugador.h
 *
 *  Created on: 19 Apr 2018
 *      Author: Andrea
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include<string>
#include "terreno.h"
#include "tanque.h"
#include "lista.h"
#include "almacen.h"
#include "tanque.h"

using namespace std ;

/*
 * 'Jugador' representa a cada participante de la partida.
 * Cada Jugador tendra a lo largo de la partida una cantidad de recursos los cuales podrá explotar
 * de acuerdo a determinadas acciones que podrá realizar.
 * Un jugador cuenta con:
 * 		-Monedas: Recurso con el cual podra comprar y ampliar los recursos de los que dispone.
 * 		-Unidades de riego: Necesarias para regar las parcelas sembradas.
 * 		-Terrenos: Conjunto de parcelas en las cuales se realizan las siembras.
 * 		-Tanque: Unidad de almacenamiento de unidades de riego. Alli se deposita el exedente de agua de cada turno.
 * 		-Almacen: Unidad de almacenamiento de unidades de cosecha. Alli se almacenan las cosechas de las parcelas
 * 				  para ser enviadas posteriormente a algun destino.
 *
 * 	Acciones que puede realizar el jugador:
 * 		-Sembrar
 * 		-Cosechar
 * 		-Regar
 * 		-Comprar:
 * 			-Capacidad de tanque
 * 			-Capacidad de almacen
 * 			-Terreno
 * 		-Vender:
 * 			-Terreno
 */
class Jugador{

	private:

		string nombre;
		unsigned int monedas;
		unsigned int unidadesRiego;
		Lista<Terreno*> terrenos;
		Tanque* tanque;
		Almacen* almacen;

	public:

		/*
		 * Post: Inicializa un jugador con su cantidad de monedas, turnos y el nombre pasado por parametro.
		 *		 Por default la cantidad de terrenos inicial es uno (1).
		 */
		Jugador(std::string nombreJugador);

		void aumentarUnidadesRiego(unsigned int unidadesRiegoASumar);

		//Post: Devuelve la cantidad de monedas que posee el jugador.
		unsigned int monedasDisponibles();

		/*
		 * Pre: La cantidad de monedas recibida es mayor a cero.
		 * Post: Incrementa la cantidad de monedas del jugador segun el monto de monedasASumar.
		 */
		void agregarMonedas(unsigned int monedasASumar);

		/*
		 * Pre: la cantidad de monedas recibida es mayor a cero.
		 * Post: Disminuye la cantidad de monedas del jugador segun el monto de monedasARestar.
		 * 		 Si tuvo exito devuelve "true", sino "false".
		 */
		bool gastarMonedas(unsigned int monedasAGastar);

		// Post: Indica si el jugador puede gastar 'cantidadMonedas'.
		bool puedeGastarMonedas(unsigned int cantidadMonedas);

		// Post: devuelve la cantidad de terrenos que posee el jugador.
		unsigned int obtenerCantidadTerrenos();

		// Post: Devuelve la cantidad de cosecha almacenada de 'nombreCultivo'
		unsigned int obtenerCantidadAlmacenada(std::string nombreCultivo);

		// Post: Devuelve la cantidad disponible en el almacen
		unsigned int obtenerCantidadDisponibleAlmacen();

		// Post: Devuelve la cantidad maxima que puede almacenar el jugador en el tanque.
		unsigned int obtenerCantidadMaximaTanque();

		// Post: Devuelve la cantidad maxima que puede almacenar el jugador en el almacen.
		unsigned int obtenerCantidadMaximaAlmacen();

		// Post: Asigna el nombre del jugador
		void asignarNombre(string nombre) ;

		// Post: Devuelve el nombre del jugador
		string obtenerNombre();

		// Post: Imprime el estado actual del jugador
		void imprimirJugador();

		/*
		 * Pre: 'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Devuelve el terreno asociado a 'numeroTerreno'. Los terrenos se numeran de 1 a 'cantidadDeTerrenos'.
		 * 		 En caso de no encontrarse el terreno indicado devuelve NULL.
		 */
		Terreno* buscarTerreno(unsigned int numeroTerreno);

		// Post: Indica si hay espacio suficiente para almacenar 1 unidad de 'cultivo'.
		bool puedeAlmacenar(Cultivo* cultivo);

		// Post: Indica si hay espacio suficiente para almacenar 'cantidadAAlmacenar' unidades de 'cultivo'.
		bool puedeAlmacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar);

		/*
		 * Pre: 'puedeAlmacenar' debe ser true.
		 * Post: Almacena 1 unidad de cosecha de 'cultivo'.
		 * 		 En caso de no poder almacenarse devuelve false.
		 */
		bool almacenar(Cultivo* cultivo);

		/*
		 * Pre: 'puedeAlmacenar' debe ser true.
		 * Post: Almacena 'cantidadAAlmacenar' unidades de cosecha de 'cultivo'.
		 * 		 En caso de no poder almacenarse devuelve false.
		 */
		bool almacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Indica si se puede realizar la siembra de 'cultivo' en la parcela indicada.
		 * 		 La siembra puede realizarse si:
		 * 		 		-El jugador cuenta con las monedas necesarias para comprar la semilla.
		 * 		 		-El terreno es apto para ser sembrado.
		 */
		bool puedeSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * 		'puedeSembrar' debe ser true.
		 * Post: Siembra la parcela indicada con 'cultivo'.
		 * 		 Consume la cantidad de monedas correspondientes al costo de la semilla del cultivo indicada en 'cultivos.txt'.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool sembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Indica si se puede realizar la cosecha del cultivo que esta sembrado en la parcela.
		 * 		 La cosecha puede realizarse si:
		 * 		 		-El jugador cuenta con espacio suficiente para almacenar la cosecha.
		 * 		 		-El terreno es apto para ser cosechado.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool puedeCosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * 		'puedeCosechar' debe ser true.
		 * Post: Cosecha y almacena el cultivo sembrado en la parcela indicada por 'numeroTerreno' y 'coordenadasParcela'.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool cosechar(unsigned int numeroTerreno, std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * Post: Indica si se puede regar la parcela indicada.
		 * 		 La parcela se puede regar si:
		 * 		 		-El jugador cuenta con las unidades de riego necesarias de acuerdo al cultivo sembrado.
		 * 		 		 Para calcular las unidades de riego que tiene el jugador se tienen en cuenta las unidades de riego almacenadas en el tanque.
		 * 		 		-El terreno es apto para ser regado.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool puedeRegar(unsigned int numeroTerreno, std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * 		'puedeRegar' debe ser true.
		 * Post: Riega la parcela indicada por 'numeroTerreno' y 'coordenadasParcela' evitando que se seque.
		 * 		 Consume las unidades de riego necesarias para el riego. Primero se consumen las unidades que obtuvo el jugador en el turno,
		 * 		 de no ser suficientes se consumen unidades de riego del tanque.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool regar(unsigned int numeroTerreno, std::string coordenadasParcela);

		// Post: Devuelve la cantidad de unidades de riego que tiene el jugador sin tener en cuenta las unidades del tanque.
		unsigned int obtenerUnidadesRiego();

		// Post: Devuelve la cantidad de unidades de riego almacenadas en el tanque.
		unsigned int obtenerUnidadesRiegoAlmacenadas();

		// Post: Devuelve la cantidad de unidades de riego que tiene el jugador teniendo en cuenta las unidades del tanque.
		unsigned int obtenerUnidadesRiegoTotales();

		// Post: Devuelve la cantidad almacenada de todos los cultivos.
		unsigned int obtenerCantidadAlmacenadaTotal();

		/*
		 * Post: Indica si el jugador puede consumir 'unidadesRiego'.
		 * 		 Este metodo tiene en cuenta las unidades de riega almacenadas en el tanque.
		 */
		bool puedeConsumirUnidadesRiego(unsigned int unidadesRiego);

		/*
		 * Post: Consume 'unidadesRiego' del jugador. Si las unidades de riego obtenidas en el turno no son suficientes, consume
		 * 		 el resto del tanque.
		 * 		 Devuelve false en caso que no se puedan consumir las unidades indicadas.
		 */
		bool consumirUnidadesRiego(unsigned int unidadesRiego);

		/*
		 * Post: Indica si se puede realizar el envio de la cosecha almacenada de 'cultivo'.
		 * 		 El envio se puede realizar si:
		 * 		 		-El jugador cuenta con las monedas necesarias para realizar el envio.
		 * 		 		 El costo del envio se calcula como cantidad almacenada * precio.
		 * 		 		 El precio se obtiene del archivo 'destinos.txt'
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool puedeEnviar(Cultivo* cultivo);

		/*
		 * Pre: 'puedeEnviar' debe ser true.
		 * Post: Realiza el envio de la cosecha almacenada de 'cultivo'.
		 * 		 Incrementa las monedas del jugador de acuerdo a la rentabilidad del cultivo definida en 'cultivos.txt' y la cantidad enviada.
		 * 		 Disminuye la cantidad almacenada a 0.
		 * 		 Consume las monedas del jugador de acuerdo al costo del envio.
		 * 		 El costo del envio se calcula como cantidad almacenada * precio.
		 * 		 El precio se obtiene del archivo 'destinos.txt'
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool enviar(Cultivo* cultivo);

		/*
		 * Post: Indica si el jugador puede comprar un nuevo terreno.
		 * 		 Para realizar al compra el jugador debe tener la cantidad de monedas necesarias para adquirir el terreno.
		 * 		 El costo del mismo dependera del numero de terreno que este comprando (es que decir cuantos terrenos tiene)
		 * 		 y la dificultad del juego.
		 */
		bool puedeComprarTerreno();

		/*
		 * Pre: 'puedeComprarTerreno' debe ser true.
		 * Post: Realiza la compra de un nuevo terreno.
		 * 		 El terreno comprado se puede utilizar inmediatamente, todas sus parcelas se encuentran limpias, sin cultivos.
		 * 		 Consume las monedas necesarias para la compra del terreno.
		 * 		 El numero de terreno sera igual al ultimo numero de terreno + 1.
		 *		 Ej:
		 * 		 	El jugador tiene 3 terrenos y compra 1:
		 *
		 * 		 	Situacion pre-compra:  |  1  |  2  |  3  |
		 * 		 	Situacion post-compra: |  1  |  2  |  3  |  4  |
		 *
		 * 		 	El nuevo terreno tiene el numero 4.
		 *
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool comprarTerreno();

		/*
		 * Pre: 'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * Post: Indica si el jugador puede vender un terreno.
		 * 		 Para realizar la venda el terreno debe existir.
		 */
		bool puedeVenderTerreno(unsigned int numeroTerreno);

		/*
		 * Pre: 'numeroTerreno' indica el numero de terreno que se quiere cosechar. Debe tener un valor mayor a 0 y menor que
		 * 		'obtenerCantidadTerrenos' del jugador actual.
		 * 		'puedeVenderTerreno' debe ser true.
		 * Post: Realiza la venta del terreno. El terreno deja de estar disponible y se aumentan las monedas del jugador de acuerdo
		 * 		 al precio de venta.
		 * 		 Al quitar el terreno todos los terrenos subsiguientes son renumerados.
		 * 		 Ej:
		 * 		 	El jugador tiene 4 terrenos y vende el terreno 2:
		 *
		 * 		 	Situacion pre-venta:  |  1  |  2  |  3  |  4  |
		 * 		 	Situacion post-venta: |  1  |  x  |  2  |  3  | -> |  1  |  2  |  3  |
		 *
		 * 		 	Ahora el terreno 3 es el 2 y el 4 es el 3.
		 *
		 * 		 Devuelve false en caso que la accion no pueda realizarse.
		 */
		bool venderTerreno(unsigned int numeroTerreno);

		/*
		 * Post: Indica si el jugador puede realizar una ampliacion de la capacidad del tanque.
		 * 		 Para realizar al compra el jugador debe tener la cantidad de monedas necesarias para adquirir el incremento de almacenamiento.
		 * 		 El costo del mismo dependera de la dificultad del juego.
		 */
		bool puedeComprarCapacidadTanque();

		/*
		 * Pre: 'puedeComprarCapacidadTanque' debe ser true.
		 * Post: Realiza la compra de la ampliacion de la capacidad del tanque.
		 * 		 Disminuye las monedas del jugador de acuerdo al costo de la ampliacion y aumenta la capacidad maxima de almacenamiento.
		 * 		 Devuelve false en caso que la accion no pueda realizarse.
		 */
		bool comprarCapacidadTanque();

		/*
		 * Post: Indica si el jugador puede realizar una ampliacion de la capacidad del almacen.
		 * 		 Para realizar al compra el jugador debe tener la cantidad de monedas necesarias para adquirir el incremento de almacenamiento.
		 * 		 El costo del mismo dependera de la dificultad del juego.
		 */
		bool puedeComprarCapacidadAlmacen();

		/*
		 * Pre: 'puedeComprarCapacidadAlmacen' debe ser true.
		 * Post: Realiza la compra de la ampliacion de la capacidad del almacen.
		 * 		 Disminuye las monedas del jugador de acuerdo al costo de la ampliacion y aumenta la capacidad maxima de almacenamiento.
		 * 		 Devuelve false en caso que la accion no pueda realizarse.
		 */
		bool comprarCapacidadAlmacen();

		/*
		 * Post: Actualiza los recursos del jugador y el estado de sus terrenos.
		 * 		 Las unidades de riego sobrantes del turno son almacenadas en el tanque.
		 * 		 Las parcelas de los terrenos actualizan su estado de acuerdo a las acciones que realizo el jugador en el turno.
		 */
		void actualizar();

		/*
		 * Post: Actualiza las unidades de riego del jugador.
		 * 		 Las unidades de riego sobrantes del turno son almacenadas en el tanque.
		 */
		void actualizarUnidadesRiego();

		// Post: Actualiza el estado de las parcelas de todos los terrenos de acuerdo a las acciones que realizo el jugador en el turno.
		void actualizarTerrenos();

		// Post: Libera los recursos reservados.
		~Jugador();
};



#endif /* JUGADOR_H_ */
