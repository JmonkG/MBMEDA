#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cstring>
#include <conio.h>
#include <time.h> 
#include <string>
#include <windows.h>
#include "Universo.h"
#include "Individuo.h"
#include "Poblacion.h"
#include "Base.h"
#include "Quicksort.h"
#include "AMatrix.h"
#include <windows.h>
#include <dos.h>
#include "Param.h"


using namespace std;
const int corridas= 20;

Individuo Mejores[10];
double Precision[corridas];
double Recall[corridas];
string Motifs[corridas];
char Consensus[100];
int tamano;

Universo w;
Poblacion p;
Individuo pum[5];
Individuo indv;
Param parametricos;

int MayorV(int a,int c,int g, int t){
	int ver[4]={a,c,g,t};
	int mayor=a;
	for(int i=0;i<=3;i++)
		if(ver[i]>=mayor)
			mayor=ver[i];
	if(mayor==a)
		return a;
	if(mayor==c)
		return c;
	if(mayor==g)
		return g;
	if(mayor==t)
		return t;

return 0;
}
char Mayor(int a,int c,int g, int t){
	int ver[4]={a,c,g,t};
	int mayor=a;
	for(int i=0;i<=3;i++)
		if(ver[i]>=mayor)
			mayor=ver[i];
	if(mayor==a)
		return 'a';
	if(mayor==c)
		return 'c';
	if(mayor==g)
		return 'g';
	if(mayor==t)
		return 't';


return 'r';
}

void calcularConsensus(){
	int valconsens=0;
	int a=0;
	int c=0;
	int g=0;
	int t=0;

	 tamano=Motifs[0].length();
  for(int i=0;i<=tamano-1;i++){
	  for(int j=0;j<=corridas-1;j++){
		  if(Motifs[j][i]=='a')
			  a++;
		  if(Motifs[j][i]=='c')
			  c++;
		  if(Motifs[j][i]=='g')
			  g++;
		  if(Motifs[j][i]=='t')
			  t++;
	  }			
	 Consensus[i]=Mayor(a,c,g,t); 
	 valconsens+=MayorV(a,c,g,t);
	 a=c=g=t=0;
  }
}

void GuardarRes(int a){
ofstream myfile,myfile2;
	//myfile.open("C:/Users/cjordan/Documents/Tesis/RMF/RMF/REsultadosEstres.txt",ios::in | ios::ate);
	myfile.open("C:/Users/cjordan/Documents/Tesis/EDA/EDA - Motif/EDA - Motif/ResultadosEstres.txt",ios::in | ios::ate);
	//myfile<<"Precision"<<" "<<"Recall"<<"\n";
			myfile << a<<" ";
			for(int i=0;i<=numvar-1;i++)
				myfile<<w.pob[0].crom.genes[i]<<" ";
			myfile<<w.pob[0].fitness<<"\n";
			for(int y=0;y<=numvar-1;y++)
				myfile<<w.b.postmotivo[y]<<" ";
			myfile<<"\n";
			
	myfile << "\n";
	//myfile << Promedio(a)<<" "<<Promedio(b)<<"\n";
	myfile.close();
  
	
}
void ImprimirMotifs(){
ifstream myfile2 ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\minsec.txt");
int count=0;
  string strConvert;
  if (myfile2.is_open())
  {
    while (! myfile2.eof() )
    {
		getline (myfile2,strConvert);
		Motifs[count]=strConvert;
		//Precision[count]=atof(strConvert.c_str());
	  //cout << Genoma[count]<< endl;
	  count++;
    }
	
    myfile2.close();
  }else cout << "Unable to open file myfile2";
  for(int i=0;i<=corridas-1;i++)
	  cout<<Motifs[i]<<"\n";
  cout<<"\n";
  calcularConsensus();
  //Escribir en un archivo
  ofstream myfil("C://Users//cjordan//Documents//Tesis//RMF//RMF//Mmotifs.txt",ios::in | ios::ate);
  for(int i=0;i<=corridas-1;i++)
	myfil<<Motifs[i]<<"\n";
  myfil<<"\n";
  for(int i=0;i<=tamano-1;i++)
	myfil<<Consensus[i];
  myfil.close();


}

void ImprimirRes(){
  ifstream myfile2 ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\Precision.txt");
  int count=0;
  string strConvert;
  if (myfile2.is_open())
  {
    while (! myfile2.eof() )
    {
		getline (myfile2,strConvert);
		Precision[count]=atof(strConvert.c_str());
	  //cout << Genoma[count]<< endl;
	  count++;
    }
	
    myfile2.close();
  }else cout << "Unable to open file myfile2"; 

  ifstream myfile ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\Recall.txt");
  count=0;
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
		getline (myfile,strConvert);
		Recall[count]=atof(strConvert.c_str());
	  //cout << Genoma[count]<< endl;
	  count++;
    }
	
    myfile.close();
  }else cout << "Unable to open file myfile1"; 

}
/*void total(double precision[],double recall[]){
	double sumap=0.00,sumar=0.00;
	for(int i=0;i<=corridas-1;i++){
		sumap+=precision[i];
		sumar+=recall[i];
	}
	cout<< sumap/corridas<<" "<<sumar/corridas<<"\n";
}*/



void Prueba(int a,int b){

cout<<a<<"  "<<b<<"\n";
}
  
void LeerConfigParam(Base &x){
  string Buff;
  double Param[9];
  //Param={algoritmo,tamaño poblacion,tasa de mutacion, tasa de cruce, operador de mutacion, operador de cruce, operador de seleccion,sizemotif,numvar}
  int a=0;
  ifstream myfile ("C:\\Users\\cjordan\\Documents\\Visual Studio 2010\\Projects\\WindowsFormsApplication1\\WindowsFormsApplication1\\date.txt");
  if (myfile.is_open())
  {
    while (!myfile.eof())
    {		
		getline (myfile,Buff);
		a++;
		if(Buff!=""){
			Param[a-1]=atof(Buff.c_str());
		}
    }
	myfile.close();
  }else cout << "Unable to open file 1"; 
  Param[8]=x.tambase;
  parametricos.SetParametros(Param);
}
void CalculateBestAndWriteGenomes(Base &b){
ofstream myfile;
myfile.open("C:/Users/cjordan/Documents/Tesis/EDA/EDA - Motif/EDA - Motif/ResultadosEstres.txt",ios::in | ios::ate);
Individuo Mayor=Mejores[0];
	for(int i=0;i<=9;i++)
		if(Mejores[i].fitness>=Mayor.fitness)
			Mayor=Mejores[i];
	//Escribir el mejor en el Archivo, posicion y fitness
	myfile<<"\n"<<" El mejor es:"<<" \n";
	for(int y=0;y<=numvar-1;y++)
		myfile<<Mayor.crom.genes[y]<<" ";
	myfile<<Mayor.fitness<<"\n";
	//Escribir en file las secuencias del mejor
	for(int i=0;i<=numvar-1;i++){
		for(int j=Mayor.crom.genes[i];j<Mayor.crom.genes[i]+tamtruemotif;j++)
			myfile<<b.Genoma[i][j-1];
		myfile<<"\n";
	}
	myfile<<"\n";

}
void main(){
Base b;
b.Construir();
//LeerConfigParam(b);
std::ofstream os("C:/Users/cjordan/Documents/Tesis/EDA/EDA - Motif/EDA - Motif/ResultadosEstres.txt");
//system("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\GenBase\\GB\\Debug\\GB.exe"); //Ejecuta la Base
Quicksort q;
int ngen=1;
Individuo inv;
time_t start,end;
Param par;
double dif;
int nrep=1;
LeerConfigParam(b);
time(&start);
//par.SetValues(0);	//0 si quiere q ejecute EDA, 1 si quiere q ejecute GA   NOO VALE
for(int t=0;t<10;t++){
	    srand (time(NULL));
		ngen=nrep=1;
		w.random(0);
		for(int i=0;i<=numind-1;i++)
		    w.pob[i].LocalFilter(w.b);
					//cout<<a<<"\n";
					//cin.get();
					do {
						cout<<"Numero de generacion:"<<ngen<<"\n";
						w.ordenar();
						//w.pob.EliminarRep(); //elimina todos los repetidos
						if(parametricos.algorithm==1)
							w.GA_proxima(); //Utiliza algoritmos genéticos para resolver el problema
						else
							w.GA_Proxima_EDA(); //Utiliza el EDA para resolver el problema
						w.ordenar();
						w.pob[0].ImprimirIndv();
						if(ngen==1){
							inv=w.pob[0];
						}
						else{
							if(inv.fitness==w.pob[0].fitness && inv.Iguales(w.pob[0].crom.genes))
								nrep++;
							else{
								inv=w.pob[0];
								nrep=1;
							}
							if(nrep%10==0 && nrep!=0) { //stagnation

							//triger shifting of the fittest, simbolo % es para calcular el modulo 	
								cout<<"Comienzo del shifting"<<"\n";
								//cin.get();
								w.pob.Shift(w.b);
							}
							if(ngen%10==0 && ngen!=0){ // cada 10 generaciones
								//Triger local filtering
									cout<<"Comienzo del local filtering"<<"\n";
									//cin.get();
									for(int i=0;i<=numind-1;i++)
										w.pob[i].LocalFilter(w.b);
							}
						
						}
						ngen++;
						cout<<"NREP= "<<nrep<<" NGEN= "<<ngen<<"\n";
					}while(ngen<=numgeneraciones && nrep<=50);
					Mejores[t]=w.pob[0];
					GuardarRes(t);
					//cin.get();
					//w.pob[0].ImprimirIndv();
 }
CalculateBestAndWriteGenomes(b);
time(&end);
dif=difftime(end,start);
printf("se demoro %.2f segundos\n",dif);
cin.get();
}
void main2(){//PRUEBAS VARIAS

std::ofstream os("C:/Users/cjordan/Documents/Tesis/RMF/RMF/ResultadosEstres.txt");
Quicksort q;
int ngen=1;
Individuo inv;
int nrep=1;
for(int t=0;t<=10;t++){
	    srand (time(NULL));
		ngen=nrep=1;
		w.random(0);
		for(int i=0;i<=numind-1;i++)
		    w.pob[i].LocalFilter(w.b);
					/*cout<<a<<"\n";
					cin.get();*/
					do {
						cout<<"Numero de generacion:"<<ngen<<"\n";
						w.ordenar();
						//w.pob.EliminarRep(); //elimina todos los repetidos
						w.GA_proxima();
						w.ordenar();
						w.pob[0].ImprimirIndv();
						if(ngen==1){
							inv=w.pob[0];
						}
						else{
							if(inv.fitness==w.pob[0].fitness && inv.Iguales(w.pob[0].crom.genes))
								nrep++;
							else{
								inv=w.pob[0];
								nrep=1;
							}
							if(nrep%10==0 && nrep!=0) { //stagnation

							//triger shifting of the fittest, simbolo % es para calcular el modulo 	
								cout<<"Comienzo del shifting"<<"\n";
								//cin.get();
								w.pob.Shift(w.b);
							}
							if(ngen%10==0 && ngen!=0){ // cada 10 generaciones
								//Triger local filtering
									cout<<"Comienzo del local filtering"<<"\n";
									//cin.get();
									for(int i=0;i<=numind-1;i++)
										w.pob[i].LocalFilter(w.b);
							}
						
						}
						ngen++;
						cout<<"NREP= "<<nrep<<" NGEN= "<<ngen<<"\n";
					}while(ngen<=numgeneraciones && nrep<=50);
					//cin.get();
					GuardarRes(t);
					//w.pob[0].ImprimirIndv();
 }
}
void main4(){
	//std::ofstream os("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\Precision.txt");
	//std::ofstream os2("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\Recall.txt");
	std::ofstream os2("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\minsec.txt");
	for(int i=0;i<=corridas-1;i++){
		system ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\Debug\\RMF.exe");
	}
	
	ImprimirMotifs();	
	cout<<"\n";
	for(int i=0;i<=tamano-1;i++)
		cout<<Consensus[i];
	//for(int i=0;i<=corridas-1;i++)
		//cout<<Precision[i]<<" "<<Recall[i]<<"\n";
	//total(Precision,Recall);
	cin.get();

}

void Writeposecon(Individuo v){
	
	ofstream myfil("C://Users//cjordan//Documents//Tesis//EDA//EDA - Motif//EDA - Motif//EnterosEncontrados.txt",ios::in | ios::ate);
	myfil<<v.fitness<<" ";
	for(int i=0;i<=numvar-1;i++)
		myfil<<v.crom[i]<<" ";
	myfil<<"\n";
	myfil.close();
}



void mainttt(){

srand (time(NULL));
int cualquiera;
Aleatorio aleat;
AMatrix ama;


Base b;
Poblacion p;
b.Construir();
for(int i=0;i<=20000;i++){
	p.GenerarPoblacion(b.longgen,b);
	p.generar_poblacionGAUSS(b);
}
cout<<"Termino";
/*AMatrix ama;
Individuo inv;

inv.Construir(b.longgen,b);
inv.Create_NInd();
for(int i=0;i<=numvar-1;i++){
	inv.crom.genes[i]=inv.fitnessLV(b.Genoma[i],i);
	cout<<inv.crom.genes[i]<<"\n";
}
inv.CalcularFitness(b);*/
cin.get();
/*inv.ImprimirIndv();
cout<<"---------------------------"<<"\n";
cout<<"IC:"<<"\n";
for(int i=0;i<=inv.dver-1;i++){
	for(int j=0;j<=inv.dhor-1;j++)
		cout<<inv.IC[i][j];
	cout<<"\n";
}
cout<<"---------------------------"<<"\n";
cout<<"PWM:"<<"\n";
for(int i=0;i<=4-1;i++){
	for(int j=0;j<=4;j++)
		cout<<inv.PWM[i][j];
	cout<<"\n";
}
	double A[5]={-1,1,2,4,5};
	double B[5]={-2,3,1,9,10};
	double C[5]={4,0,3,14,15};
	double D[5]={-2,0,5,13,11};
	for(int k=0;k<=dimm-1;k++)
		ama.arr[0][k]=A[k];
	for(int k=0;k<=dimm-1;k++)
		ama.arr[1][k]=B[k];
	for(int k=0;k<=dimm-1;k++)
		ama.arr[2][k]=C[k];
	for(int k=0;k<=dimm-1;k++)
		ama.arr[3][k]=D[k];
	ama.Mean();
	ama.CoVariance();
	ama.Cholesky(ama.Sigma,dimm,dimm);
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++)
			cout<<ama.Sigma[i][j]<<"   ";
	    cout<<"\n";
	}
	cin.get();
*/
}
