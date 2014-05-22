#ifndef _ALETATORIO_H
#define _ALETATORIO_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "parametros2.h"

class Aleatorio{
	public:

		//Aleatorio(){inicializarRangoVariables();};
		double cuad(double x);
		double prob();
		double aleatorio(double, double);
		bool flip(double);
		int acotado(int,int);
		double cint(double x);
		double round(double r,int places);
		double normal(double m, double s);

		double MAX[numvar];
		double MIN[numvar];

		//void inicializarRangoVariables();
};




#endif