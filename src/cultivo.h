#ifndef CULTIVO_H_
#define CULTIVO_H_

#include <string>
#include "trayecto.h"
#include "GrafoMatriz.h"

/*
 * 'Cultivo' representa cada semilla que se puede sembrar en una parcela.
 * Tiene asociado:
 * 					- Un nombre, que es el tipo de cultivo, ej: A
 * 					- Un costo, en monedas, asociado a la compra del cultivo.
 * 					- Un tiempo de crecimiento, medido en turnos, que indica cuantos turnos serán necesarios
 * 					  esperar hasta poder cosechar la parcela.
 * 					- Una rentabilidad la cual se obtendra luego de enviar la cosecha del cultivo a alguno de los destinos disponibles.
 * 					- Un tiempo de recuperacion que indicara cuanto tiempo, medido en turnos, le llevara a la parcela estar nuevametne disponible
 * 					  para otra siembra.
 * 					- Consumo de agua, la cantidad de unidades de riego que son necesarias para regar la parcela que tenga sembrado el cultivo.
 */
class Cultivo {

private:

	std::string nombre;
	unsigned int costo;
	unsigned int tiempoCrecimiento;
	unsigned int rentabilidad;
	unsigned int tiempoRecuperacion;
	unsigned int consumoAgua;

	GrafoMatriz<Lugar*>* trayectos;

public:

	/*
	 * Pre: 'nombre' no debe estar vacio, es el identificador del cultivo por lo tanto no debe haber 2 cultivos con el mismo nombre.
	 * Pos: Crea el cultivo con los parametros pasados.
	 */
	Cultivo(std::string nombre, unsigned int costo, unsigned int tiempoCrecimiento, unsigned int rentabilidad,
			unsigned int tiempoRecuperacion, unsigned int consumoAgua);

	// Pos: Devuelve el consumo de agua, en unidades de riego, del cultivo.
	unsigned int obtenerConsumoAgua();

	// Pos: Devuelve el costo, en monedas, de comprar el cultivo.
	unsigned int obtenerCosto();

	// Pos: Devuelve el nombre del cultivo.
	std::string obtenerNombre();

	// Pos: Devuelve la rentabilidad que se obtiene al enviar la cosecha a un destino.
	unsigned int obtenerRentabilidad();

	// Pos: Devuelve el tiempo, medido en turnos, que es necesario esperar para poder cosechar la parcela.
	unsigned int obtenerTiempoCrecimiento();

	// Pos: Devuelve el tiempo, medido en turnos, que es necesario esperar para poder realizar una nueva siembra en la parcela.
	unsigned int obtenerTiempoRecuperacion();

	// Pos: Agrega un trayecto posible para el cultivo.
	void agregarTrayecto(Trayecto* trayecto);

	// Pos: Devuelve el costo de realizar el envio a 'lugar'.
	unsigned int obtenerCostoEnvio(Lugar* lugar);

	void calcularCostoMinimoDestinos();
};

#endif /* CULTIVO_H_ */
