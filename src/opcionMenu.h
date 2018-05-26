#ifndef OPCIONMENU_H_
#define OPCIONMENU_H_

#ifndef NULL
#define NULL 0
#endif

#include <string>
#include "menu.h"
#include "resultadoOpcion.h"
#include "accion.h"

//Para cortar la referencia circular
class Menu;
class ResultadoOpcion;

namespace opcionMenu{

	enum Tipo{

		SUBMENU,
		ACCION
	};
}

/*
 * 'OpcionMenu' representa cada opcion de menu dentro de un menu.
 * Las opciones de menu tienen asociado un 'ResultadoOpcion' que se carga luego de llamar al metodo 'ejecutar' de la opcion.
 * De acuerdo al tipo de opcion de menu el resultado sera diferente.
 * Las opciones de menu pueden ser dos tipos, 'opcionMenu::SUBMENU' o 'opcionMenu::ACCION'.
 * 		-Si el usuario ingresa una opcion de menu de tipo 'opcionMenu::SUBMENU', automaticamente se mostrara el menu asociado ('obtenerSubmenu')
 * 		 y se devolvera el mismo dentro del resultado.
 * 		-Las opciones de tipo 'opcionMenu::ACCION', tienen asociada una accion(EAccion) que determina que accion consultar.
 * 		 Las acciones ya se encuentran predefinidas con todas sus caracteristicas (cantidad de parametros, etc),
 * 		 por lo que solo se pueden crear copias de esas acciones predefinidas a partir de un 'accion::EAccion'.
 * 		 Cuando el usuario ingresa una opcion de menu de este tipo se determina si la accion asociada requiere parametros, en caso de necesitarlos
 * 		 solicita al usuario el ingreso de los parametros y valida la cantidad de parametros obtenida. Luego devuelve un resultado con la accion generada.
 */
class OpcionMenu {

private:

	opcionMenu::Tipo tipo;
	std::string descripcion;

	//Atributos para items que contienen submenues
	Menu* subMenu;

	//Atributos para items de tipo accion
	std::string leyendaIngresoUsuario;
	accion::Tipo tipoAccion;

	//Para devolver luego de ejecutar la opcion
	ResultadoOpcion* resultado;

	void inicializarMenu(opcionMenu::Tipo tipo, std::string descripcion, Menu* subMenu, accion::Tipo tipoAccion);

public:

	/*
	 * Pos: Inicializa la opcion de menu como tipo 'opcionMenu::SUBMENU', sin submenu, sin descripcion, con accion igual a accion::NINGUNA
	 * 		y leyenda para ingreso de usuario vacia.
	 */
	OpcionMenu();

	/*
	 * Pos: Inicializa la opcion de menu como tipo 'opcionMenu::SUBMENU', con el submenu y descripcion pasado por parametro, accion igual a accion::NINGUNA
	 * 		y leyenda para ingreso de usuario vacia.
	 */
	OpcionMenu(std::string descripcion, Menu* subMenu);

	/*
	 * Pos: Inicializa la opcion de menu como tipo 'opcionMenu::ACCION', con la accion y descripcion pasados por parametros y sin submenu.
	 * 		La leyenda para ingreso usuario es la default.
	 *
	 */
	OpcionMenu(std::string descripcion, accion::Tipo tipoAccion);

	/*
	 * Pos: Inicializa la opcion de menu como tipo 'opcionMenu::ACCION', con la accion, descripcion y leyenda para ingreso usuario pasados por parametros y sin submenu.
	 */
	OpcionMenu(std::string descripcion, accion::Tipo tipoAccion, std::string leyendaIngresoUsuario);

	/*
	 * Pos: Devuelve el tipo de opcion de menu, puede ser 'opcionMenu::SUBMENU' o 'opcionMenu::ACCION'.
	 */
	opcionMenu::Tipo obtenerTipo();

	/*
	 * Pos: Devuelve la descripcion de la opcion de menu. La misma es la que se visualiza al imprimir el menu.
	 */
	std::string obtenerDescripcion();

	/*
	 * Pos: Devuelve la accion de la opcion de menu. Si el tipo de opcion de menu es 'opcion:SUBMENU' devuelve 'accion::NINGUNA'.
	 */
	accion::Tipo obtenerTipoAccion();

	/*
	 * Pos: Devuelve el submenu de la opcion de menu. Si el tipo de opcion de menu es 'opcion::ACCION' devuelve NULL.
	 */
	Menu* obtenerSubMenu();

	/*
	 * Pos: Ejecuta la opcion de menu y devuelve el resultado de la ejecucion.
	 * 		El resultado dependera del tipo de opcion de menu:
	 * 			-Si la opcion es 'opcion:SUBMENU' muestra el 'obtenerSubmenu' y lo devuelve como parte del resultado. El resultado es de tipo 'resultadoTipo::SUBMENU'.
	 * 			-Si la opcion es 'opcion:ACCION' crea una accion de acuerdo a 'obtenerAccion' y solicita los parametros al usuario en caso que utilice parametros.
	 * 			 Luego devuelve el resultado con la opcion asociada. El resultado es de tipo 'resultadoTipo::ACCION'.
	 */
	ResultadoOpcion* ejecutar();

	/*
	 * Pos: Libera los recursos reservados.
	 */
	~OpcionMenu();
};

#endif /* OPCIONMENU_H_ */
