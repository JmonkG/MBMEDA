#ifndef _SECUENCIA_H
#define _SECUENCIA_H
#include "parametros2.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using std::ostream;

class Secuencia {
	public:
		int dim;
		char sec[];
		char operator[](int i) {return sec[i];}
		friend ostream& operator<<(ostream&, Secuencia&);
		Secuencia& operator=(Secuencia&);
		void Construir(char a[],int b);

};

#endif