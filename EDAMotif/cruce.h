#ifndef _CRUCE_H
#define _CRUCE_H

#include "mutar.h"

class Cruce
{
public:
	Cromosoma hijo1,hijo2;
	Cruce();
	Cruce(Cromosoma p1,Cromosoma p2);

	void Tratar_De_Mutar();
	void Un_Punto();
	void Uniforme();
	void BLX_Alfa();
	void Dos_Puntos();
};

#endif