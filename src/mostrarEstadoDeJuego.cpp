#include "mostrarEstadoDeJuego.h"
#include <iostream>
using namespace std;


BmpCultivos::BmpCultivos(){

	ladoCultivo=10;
	espacioEntreCultivos=10;
	espacioLateral=10;
	espacioEntreLateralYCultivos=5;
				   /*x, y*/
	imagen.SetSize(asignarDimension(Configuracion::obtenerAnchoTerreno()), asignarDimension(Configuracion::obtenerLargoTerreno()));
	imagen.SetBitDepth(24);
	lapizVerdeClaro.Red=0, lapizVerdeClaro.Blue=0, lapizVerdeClaro.Green=100, lapizVerdeClaro.Alpha=0;
	lapizVerdeOscuro.Red=0, lapizVerdeOscuro.Blue=0, lapizVerdeOscuro.Green=50, lapizVerdeOscuro.Alpha=0;
	lapizMarron.Red=150, lapizMarron.Blue=100, lapizMarron.Green=125, lapizMarron.Alpha=0;
	coordenadaAncho=espacioLateral+espacioEntreLateralYCultivos;
	coordenadaLargo=coordenadaAncho;
	salto=ladoCultivo+espacioEntreCultivos;

}

int BmpCultivos::mostrarEspacioEntreCultivos(){

	return espacioEntreCultivos;

}

int BmpCultivos::mostrarEspacioLateral(){

	return espacioLateral;

}

int BmpCultivos::mostrarLadoCultivo(){

	return ladoCultivo;

}

int BmpCultivos::mostrarEspacioEntreLateralYCultivos(){

	return espacioEntreLateralYCultivos;

}

int BmpCultivos::obtenerPixelActualLargo(){

	return coordenadaLargo;

}

int BmpCultivos::obtenerPixelActualAncho(){

	return coordenadaAncho;

}

int BmpCultivos::obtenerTopeDeCoordenadas(){

	return Configuracion::obtenerAnchoTerreno()*(mostrarLadoCultivo()+mostrarEspacioEntreCultivos())-mostrarEspacioEntreCultivos();

}

int BmpCultivos::asignarDimension(int dimensionActual){

	int dimensionFinal;

	if(dimensionActual==1)

		dimensionFinal=mostrarLadoCultivo()+mostrarEspacioLateral()*2+mostrarEspacioEntreLateralYCultivos()*2;
	else

		dimensionFinal=(dimensionActual*mostrarLadoCultivo())+mostrarEspacioLateral()*2+mostrarEspacioEntreLateralYCultivos()*2+
						(mostrarEspacioEntreCultivos()*(dimensionActual-1));

	return dimensionFinal;
}

void BmpCultivos::rellenarTerreno(BMP imagen, RGBApixel lapizVerdeClaro, RGBApixel lapizVerdeOscuro){

	srand(time(NULL));

	for(int i=0; i<imagen.TellWidth(); i++){

		for(int j=0; j<imagen.TellHeight(); j++){

			if((rand()%11)==5)

				imagen.SetPixel(i, j, lapizVerdeOscuro);

			else

				imagen.SetPixel(i, j, lapizVerdeClaro);

		}

	}

}

void BmpCultivos::crearEnmarcado(BMP imagen, RGBApixel lapizMarron){

	for(int k=mostrarEspacioLateral(); k<mostrarEspacioLateral(); k++){

		for(int l=imagen.TellWidth()-mostrarEspacioLateral(); l>imagen.TellWidth()-3; l--){

			for(int i=mostrarEspacioLateral(); i<imagen.TellHeight()-mostrarEspacioLateral(); i++){

				imagen.SetPixel(k, i, lapizMarron);
				imagen.SetPixel(l, i, lapizMarron);

			}
		}
	}

	for(int k=mostrarEspacioLateral(); k<mostrarEspacioLateral()+3; k++){

		for(int l=imagen.TellHeight()-mostrarEspacioLateral(); l>imagen.TellHeight()-3; l--){

			for(int i=20; i<imagen.TellWidth()-mostrarEspacioLateral(); i++){

				imagen.SetPixel(i, k, lapizMarron);
				imagen.SetPixel(i, l, lapizMarron);

			}
		}
	}
}

void BmpCultivos::crearMaceta(BMP imagen, int i, int j, RGBApixel lapizMarron){

	for(; i<mostrarLadoCultivo(); i++){

		for(; j<mostrarLadoCultivo(); j++){

			imagen.SetPixel(i, j, lapizMarron);

			imagen.SetPixel(i+mostrarLadoCultivo(), j, lapizMarron);

			imagen.SetPixel(i, j, lapizMarron);

			imagen.SetPixel(i, j+mostrarLadoCultivo(), lapizMarron);

		}

	}

}

void BmpCultivos::asignarMacetas(BMP imagen, int salto, RGBApixel lapizMarron){

	for(int i=obtenerPixelActualAncho(); i<=obtenerTopeDeCoordenadas(); i+=salto){

		for(int j=obtenerPixelActualLargo(); j<=obtenerTopeDeCoordenadas(); j+=salto){

			crearMaceta(imagen, i, j, lapizMarron);

		}

	}

}

void BmpCultivos::crearParcela(){

	rellenarTerreno(imagen, lapizVerdeClaro, lapizVerdeOscuro);

	crearEnmarcado(imagen, lapizMarron);

	asignarMacetas(imagen, salto, lapizMarron);

	imagen.WriteToFile("Aturno.bmp");

}


