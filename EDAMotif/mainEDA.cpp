#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstdlib> 
#include "AMatrix.h"
using namespace std;


/*void mainCholesky(){
	int y;
	double M[5][5]={1,1,1,1,1,1,2,3,4,5,1,3,6,10,15,1,4,10,20,35,1,5,15,35,70};
	double Ay[5]={0,0,0,0,0};
	AMatrix a;
	y= a.Cholesky(M,5,5);
	a.BoxMullerTransform(Ay);
	a.Suma(M,Ay);
	cin.get();
}*/

void main333(){
	double A[3]={-0.5900,-0.2781,0.4227};
	double B[3]={-1.6702, 0.4716,-1.2128};
	double C[3]={0.6538,0.4942,0.7791};
	double D[3]={0.7150,0.9037,0.8909};
	double M[3];
	AMatrix a;

	a.Mean(A,B,C,D,M,4);
	a.CoVariance(A,B,C,D,M);
	cin.get();



}