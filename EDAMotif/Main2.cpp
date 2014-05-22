#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstdlib> 
#include <string>
#include "Distancia.h"
#include "Individuo.h"
#include "Poblacion.h"
#include "Universo.h"
#include "Base.h"
using namespace std; 

Universo w;
Poblacion p;
Individuo pum[5];
Individuo indv;
double Pres[numbases];
double Reca[numbases];

void WriteFile2(Individuo a[]){
	ofstream myfile;
	myfile.open("C:/Users/J/Documents/Tesis/RMF/RMF/motifs.txt",ios::in | ios::ate);
	for(int i=0;i<5;i++){
		for(int j=0;j<=numvar-1;j++)
			myfile << a[i].crom.genes[j];
		myfile << "\n";
	}
	myfile.close();

}
void WriteFile(int a, double b){
	ofstream myfile;
	myfile.open("C:/Users/J/Documents/Tesis/RMF/RMF/valores.txt",ios::in | ios::ate);
	myfile <<a<<" "<<b<< "\n";
	myfile.close();
}
int construir(Individuo a[5],Individuo b[100]){
  string buff;
  int count=0;
  ifstream myfile ("motifs.txt");
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
		getline (myfile,buff);
		for(int i=0;i<=numvar-1;i++)
			a[count].crom.genes[i]=buff[i];
		count++;
		if(count==5)
			break;
    }
    myfile.close();
  }else cout << "Unable to open file";
  count=0;
  ifstream myfile2 ("mreales.txt");
  if (myfile2.is_open())
  {
    while (! myfile2.eof() )
    {
		getline (myfile2,buff);
		for(int i=0;i<=numvar-1;i++)
			b[count].crom.genes[i]=buff[i];
		count++;
    }
    myfile2.close();
  }else cout << "Unable to open file"; 
  return count;
}
double Promedio(double a[]){
	double suma=0.00;
	for(int i=0;i<=numbases-1;i++)
		suma+=a[i];
	return suma/numbases;
}
void WriteDatos(double a[],double b[]){
	ofstream myfile,myfile2;
	myfile.open("C:/Users/J/Documents/Tesis/RMF/RMF/Precision.txt",ios::in | ios::ate);
	//myfile<<"Precision"<<" "<<"Recall"<<"\n";
	for(int i=0;i<=numbases-1;i++){
			myfile << a[i]<<"\n";
	
	}
	//myfile << "\n";
	//myfile << Promedio(a)<<" "<<Promedio(b)<<"\n";
	myfile.close();
	myfile2.open("C:/Users/J/Documents/Tesis/RMF/RMF/Recall.txt",ios::in | ios::ate);
	//myfile<<"Precision"<<" "<<"Recall"<<"\n";
	for(int i=0;i<=numbases-1;i++)
			myfile2<<b[i]<<"\n";
	myfile2.close();
}

void Writeposecon(Individuo &x){
	ofstream myfile,myfile2;
	int cualq= w.b.tambase;
	myfile.open("C:/Users/J/Documents/Tesis/RMF/RMF/posecon.txt",ios::in | ios::ate);
	for(int i=0;i<=cualq-1;i++)
		myfile<<x.positron[i]<<"\n";
	myfile.close();
	myfile2.open("C:/Users/J/Documents/Tesis/RMF/RMF/minsec.txt",ios::in | ios::ate);
	for(int i=0;i<=numvar-1;i++)
		myfile2<<x.crom.genes[i];
	myfile2<<"\n";
	myfile2.close();
}
void main2(){
srand (time(NULL));
Cromosoma c;
Base b;
b.Construir();
c.Construir();
Individuo Inv;
Inv.Construir(c,b);
cout<<"\n";
/*int dhor=17;
int dver=6;
char mat[100][100];
for(int i=0;i<=dhor-1;i++)
	for(int j=0;j<=dver-1;j++)
		mat[i][j]=c.Letra();

for(int i=0;i<=dhor-1;i++){
	for(int j=0;j<=dver-1;j++)
		cout<< mat[i][j];
	cout<<"\n";
}
cin.get();

double a = Inv.Entropia(mat,dhor,dver);
*/

//t=Inv.Distancia_H("gggcag","cagctg");
/*
Inv.crom=c;
Inv.fitnessLV("aaaatttt");
t=Inv.fitness;*/
cout<<Inv.fitness<<"\n";
cin.get();

}


void main(){
		srand (time(NULL));
		//int o;
		/*
		std::ofstream os("valores.txt");
		std::ofstream os1("posecon.txt");
		std::ofstream os2("compa.txt");
		std::ofstream os3("encon.txt");
		std::ofstream os4("encon2.txt");
		std::ofstream os5("minsec.txt");
		std::ofstream os6("Poblacion.txt");

		ofstream myfile("C:/Users/J/Documents/Tesis/RMF/RMF/compa.txt",ios::in | ios::ate);
		myfile<<"CRP 18 sequences 105 bp"<<"\n";
		myfile<<"predicted motif of:"<<numvar<<"bp"<<"\n";
		myfile.close();*/
		//std::ofstream os1("metricas.txt");
		Individuo valores[numgeneraciones];
		Individuo menor;
		int contmax=0;
		int contar=0;
		for(int k=0;k<=numbases-1;k++){
			int contmax=0;
			int contar=0;
			//srand (time(NULL));
			menor.fitness=1000000;
			int ngeneraciones=0;
			int count =0;
			//system ("C:\\Users\\J\\Documents\\Tesis\\RMF\\GenBase\\GB\\Debug\\GB.exe");
			w.random();
			do {
				w.ordenar();
				w.GA_proxima(pum,contmax);
				w.ordenar();
				cout<< ngeneraciones+1<<" "<<w.pob[0].fitness<<" ";
				w.pob[0].crom.Imprimir_Cromosoma();
				cout<<"\n";
				//condicion alterna de terminación
				if(ngeneraciones==0){
					indv=w.pob[0];
					w.pob.Guardar_Individuos(w.b);
					for(int i=0;i<=numind-1;i++)
						cout<<w.pob.pobladores[i].fitness<<"\n";
					cin.get();
					//obtener(w.b);
				}
				else{
					if(indv.Distancia(w.pob[0].crom.genes)==0)
						count++;
					else if(w.pob[0].fitness<indv.fitness){
						indv=w.pob[0];
						count=0;
					}
					if(count==criterioparada){					
						//cout<< "se ha cumplido"<<"\n";
						/*for(int i=0;i<=w.b.tambase-1;i++){
							cout<<w.b.postmotivo[i]<<" "<<indv.positron[i]<<"\n";
							if(w.b.postmotivo[i]==indv.positron[i])
								contar++;
						}
						cout<<(double)(contar/w.b.tambase)<<"\n";*/
						Writeposecon(indv);
						Pres[k]=w.Precision(indv);
						Reca[k]=w.Recall(indv);
						pum[contmax]=indv;
						//cout<<"Presicion:"<<Pres[k]<<"\n";
						//cout<<"Recall:"<<Reca[k]<<"\n";
						//cin.get();
						w.bandera=1;
						break;
					}
				}
				//Guardar el mejor candidato de cada generacion
				w.pob.MejorFitness(valores[ngeneraciones]);
				if(valores[ngeneraciones].fitness<=menor.fitness)
					menor=valores[ngeneraciones];
				//WriteFile(ngeneraciones+1,valores[ngeneraciones].fitness);

				//fin de guardar el mejor
				ngeneraciones++;
			}while ((ngeneraciones <= numgeneraciones)&& w.pob.pobladores[0].fitness!=0);
			if((ngeneraciones >= numgeneraciones)|| w.pob.pobladores[0].fitness==0){
				/*for(int i=0;i<=w.b.tambase-1;i++){
							cout<<w.b.postmotivo[i]<<" "<<indv.positron[i]<<"\n";
							if(w.b.postmotivo[i]==indv.positron[i])
								contar++;
				}
				cout<<(double)(contar/w.b.tambase)<<"\n";
				cin.get();*/
					
					//Writeposecon(indv);
					//Pres[k]=w.Precision(indv);
					//Reca[k]=w.Recall(indv);
					
					//pum[contmax]=indv;
					//cout<<"Presicion:"<<Pres[k]<<"\n";
					//cout<<"Recall:"<<Reca[k]<<"\n";
			}
			/*cout<<contmax<<"\n";
			for(int i=0;i<contmax;i++){
				pum[i].crom.Imprimir_Cromosoma();
				cout<<"\n";
			}*/
			//cin.get();
		}

	//Grabar los posibles motifs
	//WriteFile2(pum);

	//cout<<"El motif encontrado es:";
	//menor.crom.Imprimir_Cromosoma();
	//cout<<"\n"<<"con valor de fitness="<<menor.fitness;
	//cout<<"se acabo"<<"\n";
	
	/*for(int i=0;i<=numbases-1;i++){
		cout<<" "<<Pres[i]<<" "<<Reca[i]<<"\n";*/

		//if(Pres[i]==0 || Reca[i]==0)
				//cin.get();
	}
	//cout<<Promedio(Pres)<<"\n";
	//cout<<Promedio(Reca)<<"\n";
	
	/*WriteDatos(Pres,Reca);
	w.CalcularConsensus();*/
	cin.get();
}

/*void main(){
Individuo mprop[5];
Individuo mmem[100];
int minimo=0;
int num=construir(mprop,mmem);
for(int i=0;i<5;i++)
	for(int j=0;j<num;j++)
		mprop[i].fitness=mprop[i].Distancia(mmem[j].crom.genes);

for(int i=0;i<5;i++)
	cout<<mprop[i].fitness<<"\n";
cin.get();


}*/