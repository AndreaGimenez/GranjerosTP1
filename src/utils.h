#ifndef UTILS_H_
#define UTILS_H_

#include <string>

class Utils {
public:

	/*
	 * Pos: Indica si 'cadena' es un entero sin signo.
	 * 		Este metodo no garantiza la conversion de cadena a un unsigned int
	 * 		solo determina si todos los valores de la cadena son digitos y no
	 * 		tiene signo.
	 * 		Si cadena esta vacia devuelve false.
	 */
	static bool esUnsignedInt(std::string cadena);

	/*
	 * Pos: Indica si 'cadena' es un entero.
	 * 		Este metodo no garantiza la conversion de cadena a un int
	 * 		solo determina si todos los valores de la cadena son digitos
	 * 		y puede haber o no un '-' al inicio de la cadena.
	 */
	static bool esInt(std::string cadena);

	/*
	 * Pos: Indica si 'cadena' es un char.
	 * 		Este metodo no garantiza la conversion de cadena a un char
	 * 		solo determina si el largo de la cadena es 1.
	 */
	static bool esChar(std::string cadena);

	/*
	 * Pos: Convierte 'cadena' a int y devuelve el valor convertido.
	 */
	static int stringToInt(std::string cadena);

	/*
	 * Pos: Convierte 'cadena' a unsigned int y devuelve el valor convertido.
	 */
	static unsigned int stringToUnsignedInt(std::string cadena);

	/*
	 * Pos: Convierte 'cadena' a unsigned int y devuelve el valor convertido.
	 */
	static char stringToChar(std::string cadena);

	/*
	 * Pos: Convierte 'valor' a un string y devuelve el valor convertido.
	 */
	static std::string unsignedIntToString(unsigned int valor);

	/*
	 * Pos: Convierte 'valor' a un string y devuelve el valor convertido.
	 */
	static std::string intToString(int valor);

	/*
	 * Pos: Devuelve la cantidad de veces que aparece 'subcadena' dentra de 'cadena'
	 */
	static unsigned int contarRepeticiones(std::string cadena, std::string subcadena);

	/*
	 * Pre: 'cadenaSeparada' debe ser al menos del tamanio 'contarRepeticiones' + 1.
	 * Pos: Separa 'cadena' en los lugares donde 'cadena' coincide con 'subcadena'.
	 * 		Setea el resultado de la separacion en 'cadenaSeparada' y devuelve el tamanio
	 * 		de 'cadenaSeparada'
	 *
	 * 		Ej: 'cadena' = "1,2,3,4"
	 * 			'subcadena' = ","
	 * 			'cadenaSeparada' = {1,2,3,4}
	 * 			Devuelve 4
	 */
	static unsigned int splitString(std::string cadena, std::string subcadena, std::string* cadenaSeparada);

	/*
	 * Pos: Concatena a 'cadena' 'cantidad' veces el 'relleno'. Si 'rellenarDerecha' es true lo
	 * 		concatena a la derecha sino lo concatena a la izquiera de 'cadena'.
	 */
	static std::string fillString(std::string cadena, std::string relleno, unsigned int cantidad, bool rellenerDerecha);

	/*
	 * Pos: Concatena a 'cadena' 'largo - cadena.size()' veces el 'relleno'. Si 'rellenarDerecha' es true lo
	 * 		concatena a la derecha sino lo concatena a la izquiera de 'cadena'.
	 */
	static std::string padString(std::string cadena, std::string relleno, unsigned int largo, bool rellenerDerecha);

	static const char CHAR_0 = '0';
	static const char CHAR_9 = '9';
};

#endif /* UTILS_H_ */
