#ifndef _POBLACION_H
#define _POBLACION_H
#include <iostream>
#include <fstream>
#include "Individuo.h"
#include "Base.h"
#include "Distancia.h"
#include "AMatrix.h"
#include <string>


class Poblacion {
public:
	
	Cromosoma motif;
	int limsup; //cota superior para valores del crromosoma
	//Cromosoma base[elbase];
	Individuo pobladores[numind];
	Individuo& operator[](int i) {return pobladores[i];}
	Poblacion &operator= (Poblacion&);
	//void Generar1raPoblacion(Base&);
	void GenerarPoblacion(int tamano,Base&);
	void ImprimirPoblacion();
	void EliminarRep();
	void Shift(Base&);
	//void ImprimirBase();
	//void GenerarGenoma();
	void MejorFitness(Individuo&);
	void OrdenarxSeleccion();
	void OrdenarxSeleccionMax();
	void Guardar_Individuos(Base &);
	void setearNwin();
	void OrdenarxWin();
	void DespatWin();


	//Funciones con el EDA
	void generar_poblacionGAUSS(Base&x);
};
#endif
