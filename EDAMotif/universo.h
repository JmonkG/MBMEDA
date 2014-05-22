#ifndef _UNIVERSO_H
#define _UNIVERSO_H
#include <iostream>
#include <fstream>
#include "cruce.h"
#include "Base.h"
#include "Poblacion.h"
#include "Quicksort.h"

using namespace std;
class Universo	{
public:
	Poblacion pob;
	Base b;
	Individuo mejor;  //POSIBLEMENTE EL MOTIF
	double peorFitness, promedioFitness, sumaFitness;
	//int VFitnessanterior,contadorg;  //SEGUNDA CONDICION DE TERMINACION
	Individuo hijo1, hijo2,hijo3,hijo4;
	Individuo hijo[4];
	//FILE *fMejores,*fGeneraciones,*fUltima;
	int bandera;
	//string encon[100]; //conjunto de secuencias que representan el motif encontrado
	string motifs[100]; // conjunto de secuencias que representan el motif
	Individuo buff[offspring];
	int distan[20][20]; //Para medir la distancia de hamming
	void random(int a);
	//void presentar();
	//void EscribirEnArchivo(int generaciones);

	void ordenar();
	void ordenarbuff();
	int seleccionar();
	int seleccionar1();
	int tournament_selection();
	void Replacement(Individuo pob1[numind],Individuo temp[numind]);
	int Competir(Individuo inv,Individuo inv2[10]);
	void GA_CalcularEstadisticas();
	void GA_proxima();
	void DespatBuffxWin();
	
	
	void ImprimirdeBase(int i,int j);
	double Precision(Individuo&);
	double Recall(Individuo&);
	void EscribirArch(char a[numvar],int k,int j,int fila,int aja);
	void CalcularConsensus();
	char Mayor(int a,int c,int g, int t);
	int MayorV(int a,int c,int g, int t);

	void GA_Proxima_EDA();
	
};

/*class Pila{
public:
	int elementos[numvar];
	int pos;

	Pila(){pos = 0;}
	void Push(int, int);
	bool Empty();
	void Pop(int *,int *);
};*/

#endif