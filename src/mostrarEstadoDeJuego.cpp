#include "mostrarEstadoDeJuego.h"
#include <iostream>
using namespace std;


BmpCultivos::BmpCultivos(){

	ladoCultivo=100;
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
	punteroImagen=&imagen;

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


void BmpCultivos::rellenarTerreno(BMP* punteroImagen, RGBApixel lapizVerdeClaro, RGBApixel lapizVerdeOscuro){

	srand(time(NULL));

	for(int i=0; i<punteroImagen->TellWidth(); i++){

		for(int j=0; j<punteroImagen->TellHeight(); j++){

			if((rand()%11)==5)

				punteroImagen->SetPixel(i, j, lapizVerdeOscuro);

			else

				punteroImagen->SetPixel(i, j, lapizVerdeClaro);

		}

	}

}


void BmpCultivos::crearEnmarcado(BMP* punteroImagen, RGBApixel lapizMarron){

	for(int k=mostrarEspacioLateral(); k<mostrarEspacioLateral(); k++){

		for(int l=punteroImagen->TellWidth()-mostrarEspacioLateral(); l>punteroImagen->TellWidth()-3; l--){

			for(int i=mostrarEspacioLateral(); i<punteroImagen->TellHeight()-mostrarEspacioLateral(); i++){

				punteroImagen->SetPixel(k, i, lapizMarron);
				punteroImagen->SetPixel(l, i, lapizMarron);

			}
		}
	}

	for(int k=mostrarEspacioLateral(); k<mostrarEspacioLateral()+3; k++){

		for(int l=punteroImagen->TellHeight()-mostrarEspacioLateral(); l>punteroImagen->TellHeight()-3; l--){

			for(int i=mostrarEspacioLateral(); i<punteroImagen->TellWidth()-mostrarEspacioLateral(); i++){

				punteroImagen->SetPixel(i, k, lapizMarron);
				punteroImagen->SetPixel(i, l, lapizMarron);

			}
		}
	}
}


void BmpCultivos::crearParcelas(BMP* punteroImagen, int i, int j, RGBApixel lapizMarron){

	for(; i<mostrarLadoCultivo(); i++){

		for(; j<mostrarLadoCultivo(); j++){

			punteroImagen->SetPixel(i, j, lapizMarron);

			punteroImagen->SetPixel(i+mostrarLadoCultivo(), j, lapizMarron);

			punteroImagen->SetPixel(i, j, lapizMarron);

			punteroImagen->SetPixel(i, j+mostrarLadoCultivo(), lapizMarron);

		}

	}

}

void BmpCultivos::asignarParcelas(BMP* punteroImagen, int salto, RGBApixel lapizMarron){

	for(int i=obtenerPixelActualAncho(); i<=obtenerTopeDeCoordenadas(); i+=salto){

		for(int j=obtenerPixelActualLargo(); j<=obtenerTopeDeCoordenadas(); j+=salto){

			crearParcelas(punteroImagen, i, j, lapizMarron);

		}

	}

}

void BmpCultivos::crearImagen(){

	rellenarTerreno(punteroImagen, lapizVerdeClaro, lapizVerdeOscuro);

	crearEnmarcado(punteroImagen, lapizMarron);

	//asignarParcelas(punteroImagen, salto, lapizMarron);

	imagen.WriteToFile("Aturno.bmp");

	cout << "done";

}


