#ifndef _BASE_H
#define _BASE_H
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cstring>
using namespace std;

class Base	{
public:
	string Genoma[1000];
	string strConvert;
	double pa,pc,pg,pt;
	int postmotivo[1000];
	string Motifreal[100];
	int nmotifsreales;
	int tambase;
	int longgen;
	string operator[](int i) {return Genoma[i];}
	Base &operator= (Base&);
	void Construir();
	void calc_prob();


	
};



#endif