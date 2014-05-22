#include "cruce.h"

Cruce::Cruce(Cromosoma p1,Cromosoma p2)
{
	
	hijo1 = p1;
	hijo2 = p2;
}

Cruce::Cruce()
{
}

//Invocación a los operadores de MUTACIÓN
void Cruce::Tratar_De_Mutar()
{
	Aleatorio aleat;
	if( (1-pm) < aleat.prob() )
	{
		hijo1 = Mutar::Uniforme(hijo1);
		hijo2 = Mutar::Uniforme(hijo2);
	}
}

 
void Cruce::Un_Punto()
{
	int sitio, i;	
	Aleatorio aleat;
	Cromosoma c;
	sitio = aleat.acotado(1, numvar-1);
	if (aleat.flip(pc)){
		for (i=sitio; i<=numvar-1; i++)	{
			c.genes[i]=hijo1.genes[i];
			hijo1.genes[i] = hijo2.genes[i];
			hijo2.genes[i] = c.genes[i];
		}
	}
}

void Cruce::Dos_Puntos(){
int sitio,sitio2, i;	
	Aleatorio aleat;
	Cromosoma c;
	sitio = aleat.acotado(1, numvar-1);
	sitio2= aleat.acotado(1, numvar-1);
	if(sitio>sitio2){
		if (aleat.flip(pc)){
			for (i=sitio2; i<=sitio; i++)	{
				c.genes[i]=hijo1.genes[i];
				hijo1.genes[i] = hijo2.genes[i];
				hijo2.genes[i] = c.genes[i];
			}
		}
	}else{
		if (aleat.flip(pc)){
			for (i=sitio; i<=sitio2; i++)	{
				c.genes[i]=hijo1.genes[i];
				hijo1.genes[i] = hijo2.genes[i];
				hijo2.genes[i] = c.genes[i];
			}
		}
	
	}
	
}


void Cruce::Uniforme()
{
	int i;
	Cromosoma crom;
	Aleatorio aleat;
	
	for (i=0; i<=numvar-1; i++)
	{
		if(aleat.aleatorio(0,1) < 0.5)
		{
			crom.genes[i]= hijo1.genes[i];
			hijo1.genes[i]=hijo2.genes[i];
			hijo2.genes[i] = crom.genes[i];
		}
		else
		{
			hijo1.genes[i] = hijo1.genes[i];
			hijo2.genes[i] = hijo2.genes[i];
		}
	}
}

void Cruce::BLX_Alfa()
{
	
	double cMin, cMax, I;
	double hK;
	double alfa = 0.5;
	Aleatorio aleat;
	for (int i=0; i<=numvar-1; i++)
	{
		if(hijo1.genes[i] > hijo2.genes[i]){
			cMax = hijo1[i];
			cMin = hijo2[i];
		}
		else{
			cMax = hijo2[i];
			cMin = hijo1[i];
		}
		I = cMax - cMin;
		do{
			hK = aleat.aleatorio( (cMin - (I*alfa)),(cMax + (I*alfa)) );
		}while(hK < aleat.MIN[i] || hK > aleat.MAX[i]);
		hijo1.genes[i] = (int)hK;
		hijo2.genes[i] = (int)hK;
	}
}

