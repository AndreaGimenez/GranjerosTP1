#include <iostream>
#include <string>

#include "jugador.h"
#include "configuracion.h"


using namespace std ;

Jugador::Jugador(string nombre){

	this->nombre = nombre;
	this->monedas = Configuracion::obtenerCreditosIniciales();
	this->unidadesRiego = 0;
	this->tanque = new Tanque(Configuracion::obtenerCapacidadInicialTanque());
	this->almacen = new Almacen(Configuracion::obtenerCapacidadInicialAlmacen());

	for(unsigned int i = 1; i <= Configuracion::obtenerCantidadTerrenosIniciales(); i++){
		Terreno* nuevoTerreno = new Terreno;
		this->terrenos.agregar(nuevoTerreno);
	}
}

void Jugador::aumentarUnidadesRiego(unsigned int unidadesRiegoASumar){

	if(unidadesRiegoASumar < 0){
		throw string("Cantidad de unidades de riego a sumar invalida \n");
	}

	this->unidadesRiego += unidadesRiegoASumar;
}

unsigned int Jugador::monedasDisponibles(){

	return this->monedas;

}

void Jugador::agregarMonedas(unsigned int monedasASumar){

	if(monedasASumar < 0){
		throw string("Cantidad de monedas a sumar invalida \n");
	}

	this->monedas += monedasASumar;
}


bool Jugador::gastarMonedas(unsigned int monedasAGastar){

	bool exito = false ;

	if(monedasAGastar < 0){
		throw string("Cantidad de monedas a gastar invalida \n");
	}

	if(monedasAGastar <= this->monedas){
		this->monedas -= monedasAGastar ;
		exito = true ;
	}

	return exito ;
}

bool Jugador::puedeGastarMonedas(unsigned int cantidadMonedas){

	return (cantidadMonedas <= this->monedas);
}

unsigned int Jugador::obtenerCantidadTerrenos(){

	return this->terrenos.contarElementos();
}

unsigned int Jugador::obtenerCantidadAlmacenada(std::string nombreCultivo){

	unsigned int cantidadAlmacenada = 0;

	Cultivo* cultivo = Configuracion::obtenerCultivo(nombreCultivo);

	if(cultivo != NULL){
		return this->almacen->obtenerCantidadAlmacenada(cultivo);
	}

	return cantidadAlmacenada;
}

unsigned int Jugador::obtenerCantidadDisponibleAlmacen(){
	return this->almacen->obtenerVolumenDisponible();
}

unsigned int Jugador::obtenerCantidadMaximaAlmacen(){
	return this->almacen->obtenerCapacidad();
}

unsigned int Jugador::obtenerCantidadMaximaTanque(){
	return this->tanque->volumenMaximo();
}

void Jugador::asignarNombre(string nombre) {

	this->nombre = nombre ;
}

string Jugador::obtenerNombre(){

	return this->nombre ;

}

void Jugador::imprimirJugador(){

	cout<<"Nombre del jugador: "<<obtenerNombre() ;
	cout<<"Cantidad de monedas: "<< monedasDisponibles() ;
	cout<<"Cantidad de terrenos"<<obtenerCantidadTerrenos() ;

}

Terreno* Jugador::buscarTerreno(unsigned int numeroTerreno){

	return this->terrenos.obtener(numeroTerreno);
}

bool Jugador::puedeAlmacenar(Cultivo* cultivo){

	return (this->puedeAlmacenar(cultivo, 1));
}

bool Jugador::puedeAlmacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar){

	return (this->almacen->puedeAlmacenarCosecha(cultivo, cantidadAAlmacenar));
}

bool Jugador::almacenar(Cultivo* cultivo){

	return this->almacenar(cultivo, 1);
}

bool Jugador::almacenar(Cultivo* cultivo, unsigned int cantidadAAlmacenar){

	bool almacenar = puedeAlmacenar(cultivo, cantidadAAlmacenar);

	if(almacenar){
		this->almacen->almacenarCosecha(cultivo, cantidadAAlmacenar);
	}

	return almacenar;
}

bool Jugador::puedeSembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo){

	bool puedeCosechar = false;

	Terreno* terreno = buscarTerreno(numeroTerreno);
	if(terreno != NULL){

		return (terreno->puedeSembrar(coordenadasParcela)
				&& puedeGastarMonedas(cultivo->obtenerCosto()));
	}

	return puedeCosechar;
}

bool Jugador::sembrar(unsigned int numeroTerreno, std::string coordenadasParcela, Cultivo* cultivo){

	bool puedeSembrar = this->puedeSembrar(numeroTerreno,coordenadasParcela, cultivo);

	if(puedeSembrar){

		this->buscarTerreno(numeroTerreno)->sembrar(coordenadasParcela, cultivo);
		this->gastarMonedas(cultivo->obtenerCosto());
	}

	return puedeSembrar;
}

bool Jugador::puedeCosechar(unsigned int numeroTerreno, string coordenadasParcela){

	bool puedeCosechar = false;

	Terreno* terreno = buscarTerreno(numeroTerreno);
	if(terreno != NULL){
		puedeCosechar = (terreno->puedeCosechar(coordenadasParcela)
						 && this->puedeAlmacenar(terreno->obtenerCultivo(coordenadasParcela)));
	}

	return puedeCosechar;
}

bool Jugador::cosechar(unsigned int numeroTerreno, std::string coordenadasParcela){

	bool puedeCosechar = this->puedeCosechar(numeroTerreno, coordenadasParcela);

	if(puedeCosechar){

		Cultivo* cultivoCosechado = this->buscarTerreno(numeroTerreno)->cosechar(coordenadasParcela);
		almacenar(cultivoCosechado);
	}

	return puedeCosechar;
}

bool Jugador::puedeRegar(unsigned int numeroTerreno, std::string coordenadasParcela){

	bool puedeRegar = false;

	Terreno* terreno = this->buscarTerreno(numeroTerreno);
	if(terreno != NULL){

		Cultivo* cultivo = terreno->obtenerCultivo(coordenadasParcela);
		puedeRegar = (terreno->puedeRegar(coordenadasParcela)
					  && puedeConsumirUnidadesRiego(cultivo->obtenerConsumoAgua()));
	}

	return puedeRegar;
}

bool Jugador::regar(unsigned int numeroTerreno, std::string coordenadasParcela){

	bool regar = puedeRegar(numeroTerreno, coordenadasParcela);

	if(regar){

		 int unidadesRiegoConsumidas = this->buscarTerreno(numeroTerreno)->regar(coordenadasParcela);
		 this->consumirUnidadesRiego(unidadesRiegoConsumidas);
	}

	return regar;
}

unsigned int Jugador::obtenerUnidadesRiego(){

	return this->unidadesRiego;
}

unsigned int Jugador::obtenerUnidadesRiegoAlmacenadas(){
	return this->tanque->volumenUtilizado();
}

unsigned int Jugador::obtenerUnidadesRiegoTotales(){

	return this->unidadesRiego + this->tanque->volumenUtilizado();
}

unsigned int Jugador::obtenerCantidadAlmacenadaTotal(){

	return this->almacen->obtenerVolumenUtilizado();
}

bool Jugador::puedeConsumirUnidadesRiego(unsigned int unidadesRiego){

	return (unidadesRiego <= this->obtenerUnidadesRiegoTotales());
}

bool Jugador::consumirUnidadesRiego(unsigned int unidadesRiego){

	bool consumirUnidadesRiego = puedeConsumirUnidadesRiego(unidadesRiego);

	if(consumirUnidadesRiego){

		if(this->unidadesRiego < unidadesRiego){

			unsigned int unidadesAConsumirTanque = unidadesRiego - this->unidadesRiego;
			this->unidadesRiego = 0;
			this->tanque->usarAguaAlmacenada(unidadesAConsumirTanque);
		}else{
			this->unidadesRiego -= unidadesRiego;
		}
	}

	return consumirUnidadesRiego;
}

bool Jugador::puedeEnviar(Cultivo* cultivo){

	return (this->puedeGastarMonedas(almacen->obtenerCostoEnvio(cultivo)));
}

bool Jugador::enviar(Cultivo* cultivo){

	bool enviar = puedeEnviar(cultivo);

	if(enviar){

		unsigned int costoEnvio = almacen->obtenerCostoEnvio(cultivo);
		this->agregarMonedas(almacen->enviarCosecha(cultivo));
		this->gastarMonedas(costoEnvio);
	}

	return enviar;
}

bool Jugador::puedeComprarTerreno(){

	return this->puedeGastarMonedas(Configuracion::obtenerCostoTerreno(this->obtenerCantidadTerrenos()+1));
}

bool Jugador::comprarTerreno(){

	bool comproTerreno=false;

	if(this->puedeComprarTerreno()){

		this->gastarMonedas(Configuracion::obtenerCostoTerreno(this->obtenerCantidadTerrenos()+1));

		Terreno* nuevoTerreno = new Terreno;
		this->terrenos.agregar(nuevoTerreno);

		comproTerreno=true;
	}

	return comproTerreno;
}

bool Jugador::puedeVenderTerreno(unsigned int numeroTerreno){

	return numeroTerreno>0 && numeroTerreno<=this->obtenerCantidadTerrenos();
}

bool Jugador::venderTerreno(unsigned int numeroTerreno){

	bool vendioTerreno=false;

	if(this->puedeVenderTerreno(numeroTerreno)){

		this->agregarMonedas(Configuracion::obtenerCostoTerreno(numeroTerreno)*0.5);
		this->terrenos.remover(numeroTerreno);

		vendioTerreno=true;
	}

	return vendioTerreno;
}

bool Jugador::puedeComprarCapacidadTanque(){

	return puedeGastarMonedas(Configuracion::obtenerCostoAumentoCapacidadTanque(this->tanque->volumenMaximo()));
}

bool Jugador::comprarCapacidadTanque(){

	bool puedeComprarVolumen = this->puedeComprarCapacidadTanque();

	if(puedeComprarVolumen){
		this->gastarMonedas(Configuracion::obtenerCostoAumentoCapacidadTanque(this->tanque->volumenMaximo()));
		this->tanque->ampliarTanque(this->tanque->volumenMaximo());
	}

	return puedeComprarVolumen ;
}

bool Jugador::puedeComprarCapacidadAlmacen(){

	return puedeGastarMonedas(Configuracion::obtenerCostoAumentoAlmacenamientoAlmacen(this->almacen->obtenerCapacidad()));
}

bool Jugador::comprarCapacidadAlmacen(){

	bool puedeComprarCapacidadAlmacen = this->puedeComprarCapacidadAlmacen();

	if(puedeComprarCapacidadAlmacen){

		this->gastarMonedas(Configuracion::obtenerCostoAumentoAlmacenamientoAlmacen(this->almacen->obtenerCapacidad()));
		this->almacen->ampliarAlmacen(this->almacen->obtenerCapacidad());
	}

	return puedeComprarCapacidadAlmacen;
}

void Jugador::actualizar(){

	actualizarUnidadesRiego();
	actualizarTerrenos();
}

void Jugador::actualizarUnidadesRiego(){

	this->tanque->almacenarAgua(this->unidadesRiego);
	this->unidadesRiego = 0;
}

void Jugador::actualizarTerrenos(){

	this->terrenos.iniciarCursor();
	while(this->terrenos.avanzarCursor()){
		terrenos.obtenerCursor()->actualizar();
	}
}

Jugador::~Jugador(){

	delete this->tanque;
	delete this->almacen;

	this->terrenos.iniciarCursor();
	while(this->terrenos.avanzarCursor()){
		delete this->terrenos.obtenerCursor();
	}
}
