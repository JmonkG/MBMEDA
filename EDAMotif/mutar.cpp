#include "mutar.h"

Cromosoma Mutar::Uniforme(Cromosoma cO)
{
	Aleatorio aleat;
	int puesto;
	for(int i=0;i<=numeromutaciones-1;i++){
		puesto= aleat.acotado(0,numvar-1);
		cO.genes[puesto]=rand()%(numvar-1)+0;
	}
	//int punto;
	//punto = aleat.acotado(0, numvar-1);
	//cO.genes[punto] = rand()%Radio
		
		;//aleat.aleatorio(aleat.MIN[punto], aleat.MAX[punto]);
	return cO;
}
Cromosoma Mutar::UnPunto(Cromosoma c1){
 //Aleatorio aleat;
 int puesto;
 puesto= rand()%(numvar-1)+0;
 int t=c1.GenerarPos();
 c1.genes[puesto]=t;
 return c1;
}
