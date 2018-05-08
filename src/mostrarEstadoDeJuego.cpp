#include "mostrarEstadoDeJuego.h"
#include <iostream>
using namespace std;


BmpCultivos::BmpCultivos(){

	perimetroCultivo=10;
	espacioEntreCultivos=10;
	espacioLateral=20;
	ancho=asignarDimension(Configuracion::obtenerAnchoTerreno(), perimetroCultivo, espacioEntreCultivos, espacioLateral);
	largo=asignarDimension(Configuracion::obtenerLargoTerreno(), perimetroCultivo, espacioEntreCultivos, espacioLateral);
				   /*x, y*/
	imagen.SetSize(ancho,largo);
	imagen.SetBitDepth(24);
	lapizVerdeClaro.Red=0, lapizVerdeClaro.Blue=0, lapizVerdeClaro.Green=100, lapizVerdeClaro.Alpha=0;
	lapizVerdeOscuro.Red=0, lapizVerdeOscuro.Blue=0, lapizVerdeOscuro.Green=50, lapizVerdeOscuro.Alpha=0;
	lapizMarron.Red=150, lapizMarron.Blue=100, lapizMarron.Green=125, lapizMarron.Alpha=1;
	coordenadaAncho=espacioLateral+perimetroCultivo/2;
	coordenadaLargo=espacioLateral+perimetroCultivo/2;

}

unsigned int BmpCultivos::asignarDimension(int dimensionActual, unsigned int perimetroCultivo, unsigned int espacioEntreCultivos, unsigned int espacioLateral){

	unsigned int dimensionFinal;

	if(dimensionActual==1)

		dimensionFinal=dimensionActual*perimetroCultivo+espacioLateral*2;

	dimensionFinal=dimensionActual*perimetroCultivo+espacioLateral+espacioEntreCultivos*dimensionActual;

	return dimensionFinal;
}

void BmpCultivos::rellenarTerreno(BMP imagen, unsigned int ancho, unsigned int largo){

	srand(time(NULL));

	for(unsigned int i=0; i<ancho; i++){

		for(unsigned int j=0; j<largo; j++){

			if((rand()%11)==5)

				*imagen(i, j)=lapizVerdeOscuro;

			else

				*imagen(i, j)=lapizVerdeClaro;

		}

	}

}

void BmpCultivos::crearEnmarcado(BMP imagen, unsigned int ancho, unsigned int largo, unsigned int espacioLateral, RGBApixel lapizMarron){

	espacioLateral/=2;

	for(unsigned int k=espacioLateral; k<(espacioLateral)+3; k++){

		for(unsigned int l=ancho-(espacioLateral); l>ancho-3; l--){

			for(unsigned int i=(espacioLateral); i<largo-(espacioLateral); i++){

				*imagen(k, i)=lapizMarron;
				*imagen(l, i)=lapizMarron;

			}
		}
	}

	for(unsigned int k=espacioLateral; k<espacioLateral+3; k++){

		for(unsigned int l=largo-espacioLateral; l>largo-3; l--){

			for(unsigned int i=20; i<ancho-espacioLateral; i++){

				*imagen(i, k)=lapizMarron;
				*imagen(i, l)=lapizMarron;

			}
		}
	}
}

void BmpCultivos::crearMaceta(BMP imagen, int coordenadaAncho, int coordenadaLargo, unsigned int perimetroCultivo, RGBApixel lapizMarron){

	for(int i=coordenadaAncho-perimetroCultivo/2; i<coordenadaAncho; i++){

		for(int j=coordenadaLargo-perimetroCultivo/2; j<coordenadaLargo; j++){

			*imagen(i, j)=lapizMarron;
			*imagen(i+perimetroCultivo, j)=lapizMarron;
			*imagen(i, j)=lapizMarron;
			*imagen(i, j+perimetroCultivo)=lapizMarron;

		}

	}

}

void BmpCultivos::crearParcela(){

	rellenarTerreno(imagen, ancho, largo);

	crearEnmarcado(imagen, ancho, largo, espacioLateral, lapizMarron);

	crearMaceta(imagen, coordenadaAncho, coordenadaLargo, perimetroCultivo, lapizMarron);

	imagen.WriteToFile("Aturno.bmp");

}


