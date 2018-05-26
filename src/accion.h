#ifndef ACCION_H_
#define ACCION_H_

#include <string>
#include "lista.h"
#include "parametro.h"


namespace accion{

	enum Tipo{

		NINGUNA = 0,

		//ACCIONES DE CONFIGURACION
		CAMBIAR_CANTIDAD_JUGADORES,
		CAMBIAR_PARAMETRO_N,
		CAMBIAR_PARAMETRO_M,
		CAMBIAR_CANTIDAD_TURNOS,

		//ACCIONES DEL JUEGO
		SEMBRAR,
		REGAR,
		COSECHAR,
		ENVIAR_COSECHA,
		COMPRAR_TERRENO,
		VENDER_TERRENO,
		COMPRAR_CAPACIDAD_AGUA,
		COMPRAR_CAPACIDAD_ALMACEN,
		FINALIZAR_TURNO,

		//ACCIONES SALIDA
		FINALIZAR_PARTIDA,
		JUGAR,
		SALIR
	};
}

/*
 * 'Accion' representa una accion puntual que realiza un usuario.
 *
 * Una accion puede ser:
 * 			De configuracion (cuando se cambia el valor de un parametro de la configuracion)
 * 			De la partida (jugar, regar, sembrar, etc)
 * 			Otras como salir, finalizar partida, etc.
 *
 * La accion puede tener o parametros de acuerdo como este definida. En caso de utilizar parametros los mismos
 * deben ser de un tipo determinado. Los tipso permitidos se definen en 'parametro::Tipo'.
 * Una accion se identifica por su tipo ('accion::Tipo') y por los parametros que tiene almacenados (en caso que requiera).
 *
 * Las definiciones de las acciones se encuentran en la clase 'CreadorAcciones'.
 * Estas acciones se obtienen a traves del metodo 'CreadorAcciones::crearNuevaAccion' pasando por parametro
 * una 'accion::Tipo'. Una vez obtenida la accion se podran completar tantos parametros como 'obtenerCantidadParametros'.
 * Para cambiar los parametros utilizar 'cambiarParametros'.
 *
 * Cuando un usuario elige una 'OpcionMenu' de tipo 'parametro::ACCION', la informacion de la accion
 * realizada junto con los parametros ingresados por el usuario (en caso de que la accion requiera parametros)
 * se almacenan en una 'Accion'.
 */

class Accion {

private:

	accion::Tipo tipoAccion;
	unsigned int cantidadParametros;
	Parametro* parametros;

public:

	 // Pos: Inicializa la accion sin parametros. La accion es ninguna.
	Accion();

	/*
	 * Pos: Inicializa la accion con los datos de la otra accion.
	 * 		Crea una nueva referencia de parametros y copia los parametros de 'accion' a this.
	 */
	Accion(Accion* accion);

	 // Pos: Inicializa la accion sin parametros y con el tipo indicado en 'tipoAccion'.
	Accion(accion::Tipo tipoAccion);

	/*
	 * Pre: 'tiposParametros' debe tener 'cantidadParametros' elementos.
	 * Pos: Inicializa la accion con la cantidad de parametros 'cantidadParametros'.
	 * 		Si 'cantidadParametros' es 0, se inicializa sin acciones, es igual que llamar a 'Accion(accion::EAccion accion)'.
	 * 		Si 'cantidadParametros' es 0 el parametro 'tiposParametros' no es usado.
	 */
	Accion(accion::Tipo accion, unsigned int cantidadParametros, parametro::Tipo tiposParametros[]);

	 // Pos: Indica si la accion requiere que se indiquen parametros para poder ser ejecutada.
	bool usaParametros();

	 // Pos: Devuelve los parametros que se encuentran seteados en la accion.
	Parametro* obtenerParametros();

	//Post: Indica si los parametros que se encuentran seteados en la accion son de tipo valido de acuerdo a
	//		los tipos de parametros con los que se inicializo la accion ('tiposParametros').
	bool validarTipoParametros();

	// Pos: Devuelve el tipo de accion.
	accion::Tipo obtenerTipoAccion();

	//Post: Separa 'parametros' por ' ' y carga los valores obtenidos en los parametros de la accion
	bool cambiarValoresParametros(std::string parametros);

	/*
	 * Pos: Devuelve la cantidad de parametros que soporta la accion.
	 */
	unsigned int obtenerCantidadParametros();

	/*
	 * Pre: La cantidad de parametros en 'parametros' debe ser igual a 'obtenerCantidadParametros'.
	 * Pos: Actualiza los parametros de la accion a los pasados por parametro.
	 */
	void cambiarParametros(Parametro* parametros);

	/*
	 * Pre: 'parametros' representa los parametros separados por espacios. Solo puede haber 1 espacio de separacion.
	 * 		 La cantidad de parametros obtenidos debe ser igual a 'obtenerCantidadParametros'.
	 * Pos: Asigna los parametros al resultado de separar 'parametros' por espacios.
	 */
	bool cambiarParametros(std::string parametros);

	 // Pos: Libera los recursos reservados.
	~Accion();
};

#endif /* ACCIONMENU_H_ */
