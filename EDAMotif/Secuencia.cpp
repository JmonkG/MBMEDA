#include "secuencia.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
using std::cout;


ostream& operator<<(ostream& salida, Secuencia& c)
{
	for (int i=0; i<=numvar-1; i++)
	{
		double b = c[i];
		salida << b << "  ";
	}
	return salida;
}


Secuencia& Secuencia::operator=(Secuencia& c)
{
	for (int i=0; i<=(*this).dim-1; i++)	{
		(*this).sec[i] = c[i];
	}
	return *this;
}


void Secuencia::Construir(char a[],int b){
	(*this).dim=b;
	for(int i=0;i<=(*this).dim-1;i++){
		(*this).sec[i]=a[i];
	
	}

}