/*
 * terreno.h
 *
 *  Created on: 29 abr. 2018
 *      Author: jonathan
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "parcela.h"

/*
 *
 */
class Terreno{

	private:

		unsigned int anchoTerreno;
		unsigned int largoTerreno;
		//unsigned int precio;
		Parcela** parcelas;

		unsigned int obtenerIndiceParcela(unsigned int coordenadas[]);

	public:

		/*
		 * Pre: Recibe la cantidad de columnas y filas, las cuales deben ser validas, mayores a 0.
		 * Post: Inicializa un terreno, con su cantidad de columnas, filas, precio y matriz dinamica.
		 */
		Terreno();

		// Post: Devuelve la cantidad de columnas
		unsigned int obtenerAnchoTerreno();

		// Post: Devuelve la cantidad de filas
		unsigned int obtenerLargoTerreno();

		// Post: Devuelve el precio actual del terreno
		unsigned int obtenerPrecio();

		// Post: Devuelve la cantidad de Parcelas que tiene el terreno
		unsigned int obtenerCantidadParcelas();

		// Post: Devuelve la cantidad de cultivos que se encuentran actualemnte en el terreno
		unsigned int obtenerCantidadCultivos();

		/*
		 * Pre: Coordenadas debe tener el formato "x,y", donde x es la fila e y la columna
		 * 		x no puede ser mayor que 'obtenerCantidadFilas' e 'y' no puede ser mayor que 'obtenerCantidadColumnas'
		 * Post: Devuelve la parcela con coordenadas 'coordenadas'. Si la parcela no existe devuelve NULL.
		 */
		Parcela* buscarParcela(std::string coordenadas);

		/*
		 * Pre: 'coordenadas' debe ser un array de tamanio 2.
		 * Post: Valida que los valores de 'coordenadas' sean correctos.
		 * 		 Para ser correctos los string deben representar digitos sin signo y encontrarse dentro de los limites del terreno.
		 */
		bool validarCoordenadas(std::string coordenadas[]);

		/*
		 * Pre: Coordenadas debe tener el formato "x,y", donde x es la fila e y la columna
		 * 		x no puede ser mayor que 'obtenerCantidadFilas' e 'y' no puede ser mayor que 'obtenerCantidadColumnas'
		 * Post: Devuelve el cultivo que se encuentra sembrado en la parcela. Si no hay ningun cultivo o las coordenadas
		 * 		 son invalidas devuelve NULL.
		 */
		Cultivo* obtenerCultivo(std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * Post: Indica si se puede realizar la siembra de 'cultivo' en la parcela indicada.
		 * 		 La siembra puede realizarse si 'coordenadasParcela' son coordenadas validas y la parcela se encuentra limpia.
		 */
		bool puedeSembrar(std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'puedeSembrar' debe ser true.
		 * Post: Realiza la siembra de la parcela indicada con 'cultivo'.
		 * 		 En caso de no poder realizar la accion devuelve false.
		 */
		bool sembrar(std::string coordenadasParcela, Cultivo* cultivo);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * Post: Indica si se puede realizar la cosecha de la parcela indicada.
		 * 		 La cosecha puede realizarse si 'coordenadasParcela' son coordenadas validas, la parcela se encuentra sembrada
		 * 		 y pasaron los turnos especificados para el crecimiento del cultivo en el archivo 'cultivos.txt'.
		 */
		bool puedeCosechar(std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'puedeCosechar' debe ser true.
		 * Post: Realiza la cosecha de la pacela indicada.
		 * 		 Devuelve el cultivo cosechado. La parcela queda inhabilitada para realizar otra siembra hasta que pasen los turnos
		 * 		 de recuperacion especificados en el archivo 'cultivos.txt'.
		 * 		 En caso de no poder realizar la accion devuelve NULL.
		 */
		Cultivo* cosechar(std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * Post: Indica si se puede regar la parcela indicada.
		 * 		 El riego puede realizarse si 'coordenadasParcela' son coordenadas validas y la parcela se encuentra sembrada.
		 * 		 Devuelve false si la accion no puede realizarse.
		 */
		bool puedeRegar(std::string coordenadasParcela);

		/*
		 * Pre: 'coordenadasParcela' debe tener el formato "x,y" donde 'x' indica el numero de fila e 'y' el numero de columna.
		 * 		'puedeRegar' debe ser true.
		 * Post: Realiza el riego de la pacela indicada.
		 * 		 Devuelve las unidades de riego consumidas de acuerdo a lo especificado en el archivo 'cultivos.txt'.
		 * 		 En caso de no poder realizar la accion devuelve NULL.
		 */
		int regar(std::string coordenadasParcela);

		// Post: Actualiza el estado de todas las parcelas del terreno de acuerdo a las acciones que realizo el jugador.
		void actualizar();

		// Libera la memoria solicitada
		~Terreno();
};




#endif /* TERRENO_H_ */
