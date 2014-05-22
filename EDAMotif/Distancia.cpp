#include "Distancia.h"
#include <math.h>
#include <iostream>
#include <cstdlib>


int Distancia::dimension(char a[]){
	int count=0;
	while(a[count]=='a'|| a[count]=='c'||a[count]=='g'||a[count]=='t')
		count++;
	return count;

}