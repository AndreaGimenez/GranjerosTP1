/*
 * respuestaMenu.h
 *
 *  Created on: 28 abr. 2018
 *      Author: administrador
 */

#ifndef RESULTADOOPCION_H_
#define RESULTADOOPCION_H_

#ifndef NULL
#define NULL 0
#endif

#include "menu.h"
#include "accion.h"


//Para cortar la referencia circular
class Menu;

namespace resultadoOpcion{

	enum Tipo{

		SUBMENU,
		ACCION
	};
}

/*
 * 'ResultadoOpcion' es el resultado de haber elegido una opcion de menu. Puede ser de tipo SUBMENU o ACCION de acuerdo al tipo de opcion de menu.
 * Luego de llamar al metodo 'ejecutar' de 'OpcionMenu' se inicializa el resultado de haber ejecutado la opcion de menu para poder consultarla.
 * Si la opcion de menu es de tipo SUBMENU la respuesta sera de tipo SUBMENU y se podra obtener el submenu generado por la opcion de menu a traves de 'obtenerSubmenu'.
 * Si la opcion de menu es de tipo ACCION la respuesta sera de tipo ACCION y se podra obtener la accion con los parametros ingresados por le usuasio a traves de 'obtenerAccion'.
 */
class ResultadoOpcion {

private:

	resultadoOpcion::Tipo tipo;
	Menu* subMenu;
	Accion* accion;

	void inicializar(resultadoOpcion::Tipo tipo, Menu* subMenu, accion::EAccion accion);

public:

	/*
	 * Pos: Se inicializa el resultado como tipo 'SUBMENU' asociando 'subMenu'.
	 * No tiene accion asociada.
	 */
	ResultadoOpcion(Menu* subMenu);

	/*
	 * Pos: Se inicializa el resultado como tipo 'ACCION' y se crea una nueva instancia 'Accion',
	 * copia del elemento asociado al parametro 'accion' en 'Granjeros::acciones'.
	 * No tiene submenu asociado.
	 */
	ResultadoOpcion(accion::EAccion accion);

	/*
	 * Pos: Devuelve el tipo de resultado. Puede ser 'SUBMENU' O 'ACCION'.
	 */
	resultadoOpcion::Tipo obtenerTipo();

	/*
	 * Pos: Devuelve el submenu asociado al resultado. Si 'obtenerTipo' es distinto de 'SUBMENU' devuelve NULL.
	 */
	Menu* obtenerSubMenu();

	/*
	 * Pos: Deveuvel la accion asociada al resultado. Si 'obtenerTipo' es distinto de 'ACCION' devuelve NULL.
	 */
	Accion* obtenerAccion();

	/*
	 * Pos: Libera los recursos reservados.
	 */
	~ResultadoOpcion();
};

#endif /* RESPUESTAMENU_H_ */
