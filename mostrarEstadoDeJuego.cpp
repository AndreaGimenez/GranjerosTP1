#include "mostrarEstadoDeJuego.h"
#include <iostream>
using namespace std;


BmpCultivos::BmpCultivos(){

	imagen.SetSize(600,400);
	imagen.SetBitDepth(24);
	lapizVerdeClaro.Red=0, lapizVerdeClaro.Blue=0, lapizVerdeClaro.Green=100, lapizVerdeClaro.Alpha=0;
	lapizVerdeOscuro.Red=0, lapizVerdeOscuro.Blue=0, lapizVerdeOscuro.Green=50, lapizVerdeOscuro.Alpha=0;
	lapizMarron.Red=150, lapizMarron.Blue=100, lapizMarron.Green=125, lapizMarron.Alpha=1;

}


void BmpCultivos::crearParcela(){

	for(int k=20; k<23; k++){

		for(int l=580; l>577; l--){

			for(int i=20; i<380; i++){

				*imagen(k, i)=lapizMarron;
				*imagen(l, i)=lapizMarron;

			}
		}
	}

	for(int k=20; k<23; k++){

		for(int l=380; l>377; l--){

			for(int i=20; i<580; i++){

				*imagen(i, k)=lapizMarron;
				*imagen(i, l)=lapizMarron;

			}
		}
	}

	imagen.WriteToFile("Aturno.bmp");

}

void BmpCultivos::rellenarTerreno(){

	srand(time(NULL));

	for(int i=0; i<600; i++){

		for(int j=0; j<400; j++){

			if((rand()%11)==5)

				*imagen(i, j)=lapizVerdeOscuro;

			else

				*imagen(i, j)=lapizVerdeClaro;

		}

	}

}
