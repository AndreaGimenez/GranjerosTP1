#include "unidadAlmacenamiento.h"

UnidadAlmacenamiento::UnidadAlmacenamiento(Cultivo* cultivo){

	this->cultivo = cultivo;
	this->cantidadAlmacenada = 0;
}

Cultivo* UnidadAlmacenamiento::obtenerCultivo(){

	return this->cultivo;
}

void UnidadAlmacenamiento::almacenar(unsigned int cantidadAAlmacenar){

	this->cantidadAlmacenada += cantidadAAlmacenar;
}

bool UnidadAlmacenamiento::desalmacenar(unsigned int cantidadADesalmacenar){

	bool desalmacenar = (this->cantidadAlmacenada >= cantidadADesalmacenar);

	if(desalmacenar){
		this->cantidadAlmacenada -= cantidadADesalmacenar;
	}
	return desalmacenar;
}

unsigned int UnidadAlmacenamiento::obtenerCantidadAlmacenada(){

	return this->cantidadAlmacenada;
}
