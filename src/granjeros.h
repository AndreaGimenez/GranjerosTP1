#ifndef GRANJEROS_H_
#define GRANJEROS_H_

#include "interfazUsuario.h"
#include "partida.h"
#include "parametroConfiguracion.h"
#include "accion.h"

/*
 * Clase principal del juego. Se encarga de gestionar el juego.
 * Utiliza 'InterfazUsuario' para interactuar con el usuario y enviar a la partida
 * los datos que ingresan los usuarios.
 * Contiene la configuracion de los parametros que elige el usuario.
 */
class Granjeros {

private:

	ParametroConfiguracion* parametrosConfiguracion;
	InterfazUsuario* interfaz;
	Partida* partida;

	/*
	 * Pre: Se debe haber iniciado el juego previamente con el metodo 'iniciarJuego'
	 * 		Dependiendo el tipo de accion puede requerir que se haya inicializado la partida
	 * 		con el metodo 'comenzarPartida'.
	 * Pos: Ejecuta una accion realizada por el usuario.
	 */

	void ejecutarAccion(Accion* accion);

	/*
	 * Pre: Se debe haber iniciado el juego previamente con el metodo 'iniciarJuego'
	 * Pos: Ejecuta una accion de cambio de parametro de configuracion realizada por el usuario.
	 * 		Si la accion no es de configuracion no realiza ninguna modificacion
	 * 		y devuelve false.
	 */
	bool ejecutarAccionConfiguracion(Accion* accion);

	/*
	 * Pre: Se debe haber iniciado una partida previamente con el metodo 'comenzarPartida'.
	 * Pos: Ejecuta una accion que se haya hecho dentro de la partida realizada por el usuario.
	 * 		Si la accion corresponde a una que se realice dentro de la partida
	 * 		no realiza ninguna modificacion	y devuelve false.
	 */
	bool ejecutarAccionPartida(Accion* accion);

	/*
	 * Pre: Se debe haber iniciado una partida previamente con el metodo 'comenzarPartida'.
	 * Pos: Ejecuta una accion de salida de menu.
	 * 		Si la accion no es de salida no realiza ninguna modificacion
	 * 		y devuelve false.
	 */
	bool ejecutarAccionSalida(Accion* accion);

	/*
	 * Pre: Se debe haber iniciado el juego previamente con el metodo 'iniciarJuego'
	 * Pos: Comienza una nueva partida, incializando la configuracion y los jugadores.
	 */
	void comenzarPartida();

	/*
	 * Pre: Se debe haber iniciado una partida previamente con el metodo 'comenzarPartida'.
	 * Pos: Avanza un turno dentro de la partida. Actualiza los recursos del jugador actual
	 * 		y avanza al siguiente jugador. Si el jugador actual es el ultimo entonces se avanza
	 * 		a la siguiente ronda. Si la ronda actual es la ultima se finaliza el juego y se devuelve
	 * 		true.
	 */
	bool avanzarTurno();

	/*
	 * Pre: Se debe haber iniciado una partida previamente con el metodo 'comenzarPartida'.
	 * Pos: Inicializa los nuevos recursos de los que dispondra el jugador para comenzar el turno.
	 */
	void iniciarTurno();

	/*
	 * Pre: Se debe haber iniciado una partida previamente con el metodo 'comenzarPartida'.
	 * Pos: Realiza el tiro del dado para obtener el potenciador de agua para el calculo
	 * 		de unidades de riego del turno actual del jugador. Aumenta las unidades de riego
	 * 		del jugador actual de acuerdo al potenciador obtenido.
	 */
	void asignarUnidadesRiego();

	/*
	 * Pre: Se debe haber iniciado una partida previamente con el metodo 'comenzarPartida'.
	 * Pos: Finaliza la partida en curso.
	 */
	void finalizarPartida();

public:

	// Pos: Inicializa los parametros de configuracion default y la interfaz de usuario.
	Granjeros();

	// Pos: Comienza la ejecucion del juego.
	void iniciarJuego();

	// Pos: Libera los recursos reservados.
	~Granjeros();
};

#endif /* GRANJEROS_H_ */
