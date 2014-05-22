#include "cromosoma.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstdlib> 
using std::cout;


ostream& operator<<(ostream& salida, Cromosoma& c)
{
	for (int i=0; i<=numvar-1; i++)
	{
		double b = c[i];
		salida << b << "  ";
	}
	return salida;
}


Cromosoma& Cromosoma::operator=(Cromosoma& c)
{
	for (int i=0; i<=numvar-1; i++)	{
		(*this)[i] = c[i];
	}
	(*this).longgen=c.longgen;
	return *this;
}

/*void Cromosoma::Construir(){
	for(int i=0;i<=numvar-1;i++)
		(*this).genes[i]=(*this).Letra();

}*/

int Cromosoma::GenerarPos(){
	return rand()%(longgen-(numvar-1))+0;
}
void Cromosoma::Construir(int tamano){
	(*this).longgen=tamano;
	for(int i=0;i<=numvar-1;i++){
		if(tamano!=numvar)
			(*this).genes[i]=rand()%(tamano-tamtruemotif)+0;
		else
			(*this).genes[i]=rand()%(tamtruemotif-1)+0;
	}
}
void Cromosoma::Construir(int a[]){
	for(int i=0;i<=numvar-1;i++)
		(*this).genes[i]= a[i];

}
/*char Cromosoma::Letra(){
	int valor = rand()%4+1;
	switch(valor){
		case 1:
			return 'a';
		case 2:
			return 'c';
		case 3:
			return 'g';
		case 4:
			return 't';
	}
}
*/
void Cromosoma::Imprimir_Cromosoma(){
	for(int i=0;i<=numvar-1;i++){
		cout<<(*this).genes[i]<<" ";
		//if(i!=numvar-1)
			//cout<<',';
	}
	
}
/*
void Cromosoma::Imprimir_Genoma(){
 for(int j=0;j<=dimgen-1;j++)
	 cout<<(*this).genoma[j];
 cout<<'\n';

}

void Cromosoma::ConstruirGenoma(Cromosoma& c){
	int count=0;
	int pos= rand()%((dimgen-numvar)-1)+0;
	for(int j=0;j<=dimgen-1;j++)
	 (*this).genoma[j] = (*this).Letra();
	for(int j=pos;j<=(pos+(numvar-1));j++){
		(*this).genoma[j]=c.genes[count];
		count++;
	}
	 
}
void Cromosoma::GenerarMotif(){
	(*this).Construir();
}
void Cromosoma::MutarMotif(){
	int puesto;
	for(int i=0;i<=numeromutaciones-1;i++){
		puesto= rand()%(numvar-1)+0;
		(*this).genes[puesto]=(*this).Letra();
	}
}
*/