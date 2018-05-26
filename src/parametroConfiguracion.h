#ifndef PARAMETROCONFIGURACION_H_
#define PARAMETROCONFIGURACION_H_

//Dificultades del juego, determinan los recursos iniciales de los que dispondra cada jugar.
enum Dificultad{

	FACIL,
	MEDIO,
	DIFICIL
};

/*
 * 'ParametroConfiguracion' es un conjunto de parametros que determinaran los recursos iniciales de cada jugador.
 * Se utiliza para poder inicializar la configuracion del juego antes de comenzar la partida.
 * Todos los recursos depende de la dificultad y 2 parametros N y M.
 */
class ParametroConfiguracion {

private:

	Dificultad dificultad;
	unsigned int cantidadJugadores;
	unsigned int parametroN;
	unsigned int parametroM;
	unsigned int cantidadTurnos;

public:

	/*
	 * Pos: Crea un nuevo ParametroConfiguracion con valores default.
	 *	    La dificultad default es FACIL.
	 *	    La cantidad de jugadores default es 1.
	 *	    El parametro N default es 5.
	 *	    El parametro M default es 10.
	 *	    La cantidad de turnos default es 10.
	 */
	ParametroConfiguracion();

	//Pos: Cambia la dificultad a la indicada en el parametro.
	void cambiarDificultad(Dificultad dificultad);

	//Pos: Devuelve la dificultad actual.
	Dificultad obtenerDificultad();

	//Pre: 'cantidadJugadores' debe ser mayor a 0.
	//Pos: Cambia la cantidad de jugadores a 'cantidadJugadores'
	void cambiarCantidadJugadores(unsigned int cantidadJugadores);

	//Pos: Devuelve la cantidad de jugadores.
	unsigned int obtenerCantidadJugadores();

	//Pre: 'parametroN' debe ser mayor a 0.
	//Pos: Cambia el parametro M al valor pasado por parametro.
	void cambiarParametroN(unsigned int parametroN);

	//Pos: Devuelve el valor del parametro N.
	unsigned int obtenerParametroN();

	//Pre: 'parametroM' debe ser mayor a 0.
	//Pos: Cambia el parametro M al valor pasado por parametro.
	void cambiarParametroM(unsigned int parametroM);

	//Pos: Devuelve el valor del parametro M.
	unsigned int obtenerParametroM();

	//Pre: 'cantidadTurnos' debe ser mayor a 0.
	//Pos: Cambia la cantidad de turnos al valor pasado por parametro.
	void cambiarCantidadTurnos(unsigned int cantidadTurnos);

	//Pos: Devuelve la cantidad de turnos de la partida.
	unsigned int obtenerCantidadTurnos();
};

#endif /* PARAMETROCONFIGURACION_H_ */
