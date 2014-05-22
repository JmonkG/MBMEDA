#ifndef _AMatrix_h
#define _AMatrix_h

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string>
#include <cstring>
#include <math.h>
#include "parametros2.h"
#include "Individuo.h"

const int filas=5;
const int columnas=5;




class AMatrix{
public:
   
	double boxmull[dimm];
	double arr[nemg][dimm];
	double result[dimm];
	double nuevin[nemg][dimm];
	double Muu[dimm];
	double Sigma[dimm][dimm];
	double Sigma_Chol[dimm][dimm];
    double smuu;
	double svari;


	void Mean();
	void CoVariance();
	void Cholesky(double Matriz[dimm][dimm],int fil,int col);
	void BoxMullerTransform(double V[dimm]);
	void Suma(double Matriz[dimm][dimm],double V[dimm]);
	void CrearIndividuos(double Matriz[dimm][dimm]);

	void Mean(double H1[dimm],double H2[dimm],double H3[dimm],double H4[dimm],double Mu[dimm],int numeroindividuos);
	void CoVariance(double H1[dimm],double H2[dimm],double H3[dimm],double H4[dimm],double Mu[dimm]);
	double randn_trig(double mu, double sigma);
	double randn_notrig(double mu, double sigma);
	double media(int N, double valores[]);
	double varianza(int N,double media,double valores[]);
	void media();
	void varianza();

};

#endif