#include "aleatorio.h"

double Aleatorio::cuad(double x)	{
	return (x*x);
}

double Aleatorio::prob()	{
	return ((double)rand())/rmax;
}

double Aleatorio::aleatorio(double a, double b)	{
	return (prob()*(b-a) + a);
}

bool Aleatorio::flip(double p)	{
if (prob() > p)
		return true;
	else 
		return false;
}

double Aleatorio::normal(double m, double s)	{
	double x1, x2, w, y1;
	static double y2;
	static bool ultimo = false;
	if (ultimo==true)	{
		y1 = y2;
		ultimo = false;
	}
	else	{
		do	{
			x1 = 2.0 * prob() - 1.0;
			x2 = 2.0 * prob() - 1.0;
			w = cuad(x1) + cuad(x2);
		}	while (w >= 1.0);
		w = sqrt((-2.0* log(w))/w);
		y1 = x1*w;
		y2 = x2*w;
		ultimo = true;
	}
	return (m + y1*s);
}

int Aleatorio::acotado(int a, int b)	{
	return (a + rand()%(b-a+1));
}

/*void Aleatorio::inicializarRangoVariables()

	int i;
	switch(tipoPrograma)
	{
		case 1:
		{
			for(i=0;i<numvar;i++){
				MIN[i] = Q_MIN;
				MAX[i] = Q_MAX;
			}

			for(i=0;i<numvar;i++){
				MIN[i] = Yt[i] - VARIACION ;
				if(MIN[i]<0){
					MIN[i] = 0;
				}
				MAX[i] = Yt[i] + VARIACION ;
			}
			break;
		}
		default://
		{
			for(i=0;i<numvar;i++){
				MIN[i] = Q_MIN;
				MAX[i] = Q_MAX;
			}
			break;
		}
	}
}*/

double Aleatorio::cint(double x){
	
	double intpart;
	if (modf(x,&intpart)>=0.5)
		if( x>=0)
			return ceil(x);
		else
			return floor(x);
	else
		if( x<0)
			return ceil(x);
		else
			return floor(x);
}

double Aleatorio::round(double r,int places){
	double aaa;
	double off=pow(10.0,places);
	aaa=(*this).cint(r*off)/off;
	return aaa;
}