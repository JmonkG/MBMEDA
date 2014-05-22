#ifndef _INDIVIDUO_H
#define _INDIVIDUO_H
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstdlib> 
#include <ctype.h>
#include <windows.h>
#include <cmath>
#include "aleatorio.h"
#include "Cromosoma.h"
#include "Base.h"
#include "Param.h"


using namespace std;

class Individuo	{
friend ostream& operator<<(ostream &stream, Individuo& x);	
public:
	
	//atributos
	Cromosoma crom;
	//int padre1;
	//int padre2;
	double fitness;

	double similarity[numvar];
	char IC[100][100];
	double PWM[4][tamtruemotif];
	char S_A[numvar][tamtruemotif];
	int dhor,dver;
	double nwin; //para el criterio de ranking
	int dimpos;
	
	double nuc_a[tamtruemotif];
	double nuc_c[tamtruemotif];
	double nuc_g[tamtruemotif];
	double nuc_t[tamtruemotif];

	//funciones
	void Calcular_Nuc();
	void Construir (Cromosoma,Base&);
	void Construir (int tamano,Base&);		
	void CalcularFitness(Base&);
	void CalcularSimilaridad();
	double CalcularSimilaridad(char v[tamtruemotif]);
	int MinimoS();
	void LocalFilter(Base&);
	void CalcularPWM();
	void ImprimirIndv();
	Individuo& operator=(Individuo&);
	//int dimension(char a[]);
	void EscribirEnArchivo(int k);
	int minimo(int a,int b,int c);
	double log2(double number);
	double CalcularIC(char matriz[100][100],int dhor,int dver,Base&);
	void construirIC(Base&);
	
	//Funciones para EL EDA
	void Copy_NPWM(double arr[tamtruemotif],char letra);
	void Normalize_PWM();
	void Create_NInd();



	//void Distancia(string a);
	int Iguales(int a[]);
	//int Distancia_dif(string a); //FITNESS
	//int Distancia_H(string a);
	//int Distancia_H(string a,string b);
	//int Distancia_H(int f,int e,Base &x);
	//int fitnessLV(string a);

	int fitnessLV(string a,int punt); //punt es el puntero de la secuencia elegida en S_A
	int Distancia_H(string a,int punt);

};



#endif