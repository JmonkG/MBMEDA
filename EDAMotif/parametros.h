#ifndef _PARAMETROS_H
#define _PARAMETROS_H

#define Q_MIN 196//Tope de minimo de las variables 
#define Q_MAX 1692//Tope de maximo de las variables 

#define DEMANDA 1312

#define NUM_INTENTOS 10//Intentos para generar un gen adecuado

#define error 50


	
const int tipoPrograma = 1;//1=Planificacion Hidrotermica
const int Radio = 20.00;

const int numvar = 20;

const int numind = 10;
const int numgeneraciones=100;
const int maxnumgeneraciones = 100;//230;	
const int numrepeticiones= 10;

#define FITNESS_INICIAL 0.1

const double pc = 0.80;
const double pm = 0.005;

const int tipoCruce = 2;//1=Un_Punto; 2=Uniforme; 3=BLX_Alfa; 4=Dos Puntos;

const int tipoMutacion = 1;//1=Uniforme; 2=No_Uniforme;

const double eliteP = 0.1;//En procentaje % de Poblacion Elite


const double Kt = 0.008633;//MW / m^3/s
const double Xmin = 5733;
const double Xmax = 22917;
const double X0 = Xmax;
const double X12 = Xmax;
const double MARGEN = Xmax*0.05;
const double Yt[numvar] = {743,623};//,516,431,447,532,748,1268,1719,1669,1518,1020};
//const double Yt[numvar] = {0.0};
const double DELTA_T = 2.592;
const double VARIACION = (Xmax-Xmin)/DELTA_T;

#endif