/*
 * parcela.h
 *
 *  Created on: 2 may. 2018
 *      Author: administrador
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "cultivo.h"

namespace parcela{

	enum Estado{

		LIMPIA = 0,
		SEMBRADA,
		COSECHADA,
		PODRIDA,
		SECA
	};
}

/*
 * Es la unidad basica de un terreno, en ella se siembran y cosechan los cultivos.
 * Solo puede realizarse una siembra cuando el estado es parcela::LIMPIA.
 * Las parcelas sembradas deben regarse en todos los turnos para evitar que se seque.
 * En caso de secarse se pierde el cultivo y habra que esperar un turno para realizar una nueva siembra.
 * Una vez transcurridos los turnos necesarios que indique el cultivo se podra cosechar.
 * En caso de no cosechar en el turno correspondiente se pierde el cultivo y no se podrá sembrar nuevamente
 * hasta que transcurran la mitad de los turnos de recuperacion que indica el cultivo.
 * Luego de cosechar deben esperarse los turnos que indique el cultivo para la recuperacion de la parcela.
 */
class Parcela {

private:

	Cultivo* cultivo;
	parcela::Estado estado;
	bool regada;
	unsigned int tiempoRecuperacionRestante;
	unsigned int tiempoSembrada;

	/*
	 * Este flag indica si se debe actualizar la parcela al final del turno al invocar el metodo 'actualizar'
	 * Se setea en false cuando se realiza una accion sobre una parcela en un turno. De esa manera se evita que se actualicen los tiempos al finalizar ese turno.
	 * Siempre que se cambia el estado desde la accion de un jugador, por ejemplo sembrar, cosecha, etc. este flag se setea en true para no modificar los tiempos de siembra y recuperacion.
	 * Se setea en true en 'sembrar' y 'cosechar'
	 */
	bool actualizarEstado;

public:


	// Post: Inicializa la parcela sin cultivo, lista para ser sembrada.
	Parcela();

	/*
	 * Post: Devuelve el cultivo que se encuentra sembrado enl a parcela.
	 * 		Si 'obtenerEstado' no es parcela::SEMBRADA devuelve NULL.
	 */
	Cultivo* obtenerCultivo();

	// Post: Indica si la parcela se puede limpiar.
	bool puedeLimpiar();

	/*
	 * Pre: 'puedeLimpiar' debe ser true.
	 * Post: Limpia la parcela, dejandola disponible para realizar una nueva siembra.
	 *
	 */
	void limpiar();

	// Post: Indica si la parcela esta en condiciones de ser sembrada.
	bool puedeSembrar();

	/*
	 * Pre: 'puedeSembrar' debe ser true.
	 * Post: Siembra en la parcela el cultivo pasado por parametro.
	 * 		En caso que el sembrado no se pueda realizar la parcela no se modifica.
	 *
	 */
	bool sembrar(Cultivo* cultivo);

	// Post: Indica si la parcela esta en condiciones de ser regada.
	bool puedeRegar();

	/*
	 * Pre. 'puedeRegar' debe ser true.
	 * Post: Riega la parcela evitando que se seque.
	 * 		En caso que no se pueda realizar el riego no se modifica la parcela.
	 *
	 */
	int regar();

	// Post: Indica si la parcela esta en condiciones de ser cosechada.
	bool puedeCosechar();

	/*
	 * Pre: 'puedeCosechar' debe ser true.
	 * Post: Cosecha la parcela y devuelve el cultivo que se encontraba sembrado.
	 * 		No se podra realizar otra siembra hasta que pasen los turnos necesarios de recuperacion de la parcela
	 * 		que indique el cultivo.
	 * 		En caso que no se pueda realizar el cosechado no se modifica la parcela y se devuelve NULL.
	 */
	Cultivo* cosechar();

	// Post: Indica si la parcela puede pudrirse.
	bool puedePudrir();

	/*
	 * Pre: 'puedePudrir' debe ser true.
	 * Post: Pudre la parcela, quita el cultivo que se encontraba presente y evita que se pueda realizar otra siembra
	 * 		durante la mitad de los turnos de recuperacion que indica el cultivo.
	 */
	void pudrir();

	/*
	 * Post: Indica si la parcela puede secarse.
	 */
	bool puedeSecar();

	/*
	 * Pre: 'puedeSecar' debe ser true.
	 * Post: Seca la parcela, quita el cultivo que se encontraba sembrado y evita qeu se pueda realizar otra siembra
	 * 		durante el turno siguiente.
	 */
	void secar();

	// Post: Devuelve el estado en que se encuentra la parcela.
	parcela::Estado obtenerEstado();

	// Post: Devuelve la cantidad de turnos que es necesario esperar para poder realizar una nueva siembra.
	unsigned int obtenerTiempoRecuperacionRestante();

	// Post: Devuelve la cantidad de turnos que el cultivo estuvo sembrado en la parcela.
	unsigned int obtenerTiempoSembrada();

	// Post: Devuelve si la parcela fue regada en el turno actual.
	bool obtenerRegada();

	/*
	 * Post: Actualiza la parcela luego de transcurrido un turno de acuerdo a las acciones que se realizaron sobre ella.
	 * 		Debe invocarse al final de cada turno.
	 */
	void actualizar();
};

#endif /* PARCELA_H_ */
