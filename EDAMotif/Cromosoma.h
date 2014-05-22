#ifndef _CROMOSOMA_H
#define _CROMOSOMA_H
#include "parametros2.h"
#include "Distancia.h"
#include <iostream>
#include <stdlib.h>
//#include "AMatrix.h"
#include <time.h>
#include <math.h>
#include <cstring>
#include "Param.h"

#define PI_PI 3.141592653589793238


using std::ostream;


typedef int Alelo;


class Cromosoma {
	public:
		int longgen;
		Alelo genes[numvar];
		Param parmter;
		///Alelo genoma[dimgen];
		Alelo& operator[](int i) {return genes[i];}
		friend ostream& operator<<(ostream&, Cromosoma&);
		Cromosoma& operator=(Cromosoma&);
		int GenerarPos();
		void Construir(int tamano);
		void Construir(int a[]);
		//void ConstruirGenoma(Cromosoma&);
		//char Letra();
		void Imprimir_Cromosoma();
		//void Imprimir_Genoma();
		//void GenerarMotif();
		//void MutarMotif();

};

#endif