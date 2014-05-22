#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Individuo.h"
#include "Poblacion.h"

class Quicksort{
	
public:
	void quicksort( Individuo * const, int, int );
	void swap( int * const, int * const );
	int particion( Individuo * const, int, int );
};

#endif