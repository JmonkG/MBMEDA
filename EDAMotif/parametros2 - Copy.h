#ifndef _PARAMETROS2_H
#define _PARAMETROS2_H

const int rmax =32767;

//PARAMETROS DEPENDIENTES DE RMF
const int numvar =18; //El numero de alelos que tendra un cromosoma (EDA = D)
const int numind=500; // el tamaño de la poblacion de individuos, usar 500 en la solucion con Algoritmos Geneticos
const int offspring=numind/2;


//const int elbase=15; // la dimensión de la base de secuencias
//const int dimgen=500; // el tamaño de una secuencia
const int numgeneraciones=50;
const int numbases=1; // el numero de bases que se generan(basado en GAME)

const double pc = 0.10;// original: 0.80
const double pm = 0.90;// original: 0.005
const double ptour=0.80;
const double eliteP = 0;//En procentaje % de Poblacion Elite
const int tipoCruce = 1;//1=Un_Punto; 2=Uniforme; 3=BLX_Alfa; 4=Dos Puntos;
const int tipoMutacion = 1;//1=Un punto; 2=Uniforme;
const int numeromutaciones=4;


//nuevos parametros
const int tipodis=1; //1=distancia hamming,2=distancia levenstein
const int criterioparada = 100;


//Constanstes (NO TOUCH!!)
const int tamtruemotif=18; //tamano del motif buscado (EDA = L)
const int dimm = tamtruemotif; //antes 5 
const int nemg=2; 

//randn function parametros
const int fil=5;
const int col=2;

#endif