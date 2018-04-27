/*
 * parametroConfiguracion.h
 *
 *  Created on: 27 abr. 2018
 *      Author: administrador
 */

#ifndef PARAMETROCONFIGURACION_H_
#define PARAMETROCONFIGURACION_H_

//Dificultades del juego
enum Dificultad{

	FACIL,
	MEDIO,
	DIFICIL
};

class ParametroConfiguracion {

private:

	Dificultad dificultad;
	unsigned int cantidadJugadores;
	unsigned int parametroN;
	unsigned int parametroM;
	unsigned int cantidadTurnos;

public:

	ParametroConfiguracion();

	void cambiarDificultad(Dificultad dificultad);
	Dificultad obtenerDificultad();
	void cambiarCantidadJugadores(unsigned int cantidadJugadores);
	unsigned int obtenerCantidadJugadores();
	void cambiarParametroN(unsigned int parametroN);
	unsigned int obtenerParametroN();
	void cambiarParametroM(unsigned int parametroM);
	unsigned int obtenerParametroM();
	void cambiarCantidadTurnos(unsigned int cantidadTurnos);
	unsigned int obtenerCantidadTurnos();
};

#endif /* PARAMETROCONFIGURACION_H_ */
