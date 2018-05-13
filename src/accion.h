/*
 * accionMenu.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef ACCION_H_
#define ACCION_H_

#include <string>
#include "lista.h"


namespace accion{

	enum Tipo{

		CON_PARAMETROS_USUARIO,
		SIN_PARAMETROS_USUARIO
	};

	enum EAccion{

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
		FINALIZAR_PARTIDA,

		//ACCIONES GENERALES
		JUGAR,
		SALIR
	};
}

/*
 * 'Accion' representa la accion que realiza un usuario.
 * Cuando un usuario elige una opcion de menu de tipo accion la informacion de la accion realizada junto con los parametros ingresados por el usuario
 * (en caso de que la accion requiera parametros) se almacenan en una 'Accion'.
 * Las acciones posibles se encuentran definidas, para obtener una accion debe llamarse a 'Granjeros::crearNuevaAccion' pasando un 'EAccion' que indica
 * la accion que se realiza. Una vez obtenida la accion se podran completar tanto parametro como 'obtenerCantidadParametros'. Para cambiar los parametros utilizar 'cambiarParametros'.
 */

class Accion {

private:

	accion::Tipo tipo;
	accion::EAccion accion;
	unsigned int cantidadParametros;
	std::string* parametros;

public:

	/*
	 * Pos: Inicializa la accion sin parametros y sin accion.
	 */
	Accion();

	/*
	 * Pos: Inicializa la accion con los datos de la otra accion.
	 * 		Crea una nueva referencia de parametros y copia los parametros de 'accion' a this.
	 */
	Accion(Accion* accion);

	/*
	 * Pos: Inicializa la accion sin parametros.
	 */
	Accion(accion::EAccion accion);

	/*
	 * Pos: Inicializa la accion con la cantidad de parametros 'cantidadParametros'.
	 * 		Si 'cantidadParametros' es 0, se inicializa sin acciones, es igual que llamar a 'Accion(accion::EAccion accion'.
	 */
	Accion(accion::EAccion accion, unsigned int cantidadParametros);

	/*
	 * Pos: Devuelve el tipo de accion. Puede ser 'SIN_PARAMETROS_USUARIO' o 'CON_PARAMETROS_USUARIO'.
	 */
	accion::Tipo obtenerTipo();

	/*
	 * Pos: Devuelve los parametros que se encuentran seteados en la accion.
	 */
	std::string* obtenerParametros();

	//Post: Indica si los parametros ingresados por el usuario para la accion son correctos
	bool validarTipoParametros();

	/*
	 * Pos: Devuelve la accion asociada.
	 */
	accion::EAccion obtenerAccion();

	/*
	 * Pos: Devuelve la cantidad de parametros que soporta la accion.
	 */
	unsigned int obtenerCantidadParametros();

	/*
	 * Pre: La cantidad de parametros en 'parametros' debe ser igual a 'obtenerCantidadParametros'.
	 * Pos: Actualiza los parametros de la accion a los pasados por parametro.
	 */
	void cambiarParametros(std::string* parametros);

	/*
	 * Pre: 'parametros' representa los parametros separados por espacios. Solo puede haber 1 espacio de separacion.
	 * 		 La cantidad de parametros obtenidos debe ser igual a 'obtenerCantidadParametros'.
	 * Pos: Asigna los parametros al resultado de separar 'parametros' por espacios.
	 */
	bool cambiarParametros(std::string parametros);

	/*
	 * Pos: Libera los recursos reservados.
	 */
	~Accion();
};

#endif /* ACCIONMENU_H_ */
