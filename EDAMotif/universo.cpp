#include <cmath>
#include <fstream>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstdlib> 
#include <string>
#include "universo.h"
using std::cout;
using std::endl;
using std::ostream;

char buf[80];


void Universo::random(int a)	{
	b.Construir();
	if(a==0)
		pob.GenerarPoblacion(b.longgen,b);
	else
		pob.GenerarPoblacion(b.longgen,b);
	/*for(int i=0;i<=numind-1;i++)
		pob.pobladores[i].CalcularFitness(b);*/
	//pob.ImprimirPoblacion();
	cout<<"\n";
	/*pob.random();
	for(int i=1;i<=numind;i++){
		for(int j=1;j<=numvar;j++){
			cout << pob.pobladores[i-1].crom.genes[j-1];
			cout<<",";
		}
		cout<< pob.pobladores[i-1].fitness;
		cout<<"\n";
	}*/
	//cin.get();
}

/*
void Universo::presentar()	{
	for(int i=1; i<=numind; i++)
		cout << pob[i] << endl;
}
*/


int Universo::seleccionar()	{ // Tournament Selection
	Aleatorio q;
	double p= q.prob();
	double punto =p * sumaFitness;
	double parcial = 0.0;
	int i=0; //antes estaba 1
	while (i<=numind-1)	{
		parcial = parcial + pob[i].fitness;
		if(parcial>punto)
			break;
		i++;
	}
	if(i!=numind)
		return (i);
	else if(i==numind)
		return i-1;

return 0;
}

int Universo::seleccionar1(){ //Roullette Wheel
    Aleatorio q;
	double suma=0;
	double p= q.prob();
	double w[numind];
	double denom= (*this).sumaFitness;
	//cout<<sumaFitness<<"\n";
	for(int j=0;j<=numind-1;j++){
		w[j]= (*this).sumaFitness-pob[j].fitness;
		///cout<<w[j]<<"\n";
	}
	for(int j=0;j<=numind-1;j++)
		suma+=w[j];
	for(int j=0;j<=numind-1;j++){
		w[j]=w[j]/suma;
		//cout<<pob[j].fitness<<" "<<w[j]<<"\n";
	}
	//cin.get();
	for(int i=numind-1;i>=1;i--){
	  if(p>w[i] && p<=w[i-1])
		  return i;
	  if(i==1)
		  return i-1;
	}
return 0;
}

int Universo::tournament_selection(){
	Aleatorio q;
	double c=q.prob();
	int a,b;
	do{
	a=rand()%(numind-1)+0;
	b=rand()%(numind-1)+0;
	}while(pob[a].fitness<=0 && pob[b].fitness<=0);
	if(pob[a].fitness>=pob[b].fitness){
		if(c<=ptour)
			return a;
		else
			return b;
	}else{
		if(c<=ptour)
			return b;
		else
			return a;
	
	}
}
void Universo::ordenar()	{
	pob.OrdenarxSeleccionMax();
}

void Universo::GA_CalcularEstadisticas()	{
	mejor = pob[0];
	peorFitness = pob[0].fitness;
	sumaFitness  = pob[0].fitness;
	for(int i=1; i<=numind-1; i++)	{
		double f = pob[i].fitness;
		sumaFitness = sumaFitness + f;
		if (f<peorFitness) peorFitness = f;
		if (f>peorFitness) mejor = pob[i];
	}
	promedioFitness = sumaFitness/numind;
}

/*void Universo::EscribirEnArchivo(int generaciones){
	ofstream myfile;
	myfile.open("FitnessEsfera.txt",ios::in | ios::ate);
	myfile <<generaciones<<" "<< (*this).pob.pobladores[numind-1].fitness<< "\n";
	myfile.close();

}*/

void Universo::ordenarbuff(){
	Individuo aux;
	for (int i=0; i<(2*numind)-1; i++)
	{
		double max = (*this).buff[i].nwin;
		int maxx = i;
		for(int j=i+1; j<=(2*numind)-1; j++)
		{
				if ((*this).buff[j].nwin > max)
				{
					max = (*this).buff[j].nwin;
					maxx = j;
				}
		}
		//cout<<"\n";
		//(*this)[i].crom.ImprimirCromosoma();
		//(*this)[mindx].crom.ImprimirCromosoma();
		aux = (*this).buff[i];
		(*this).buff[i]=(*this).buff[maxx];
		(*this).buff[maxx]=aux;
		//cout<<"\n";
		//(*this).imprimir_Poblacion();
	}

}
int Universo::Competir(Individuo inv,Individuo inv2[10]){
	int ret=0;
	for(int i=0;i<=9;i++)
	 if(inv.fitness>inv2[i].fitness)
		 ret++;
	return ret;
}

void Universo::Replacement(Individuo pob1[numind],Individuo temp[numind]){ //La generacion de los padres es pob1, la de los hijos temp
	int y;
	int count=0;
	int bandera=0;
	int k=0;
	Individuo a[10];
	//Realizar el tournament de los hijos a los padres
	for(int i=0;i<=numind-1;i++){
		for(int j=0;j<=9;j++){
			 y= rand()%(numind-1)+0;
			 /*if(temp[i].fitness>temp[y].fitness)
				 temp[i].nwin++;
			 else if(temp[i].fitness<temp[y].fitness){
				 temp[y].nwin++;
			 }*/
		 a[j]=temp[y];
		}
		temp[i].nwin=Competir(temp[i],a);
		//cout<<temp[i].nwin<<"\n";
	}
	//cin.get();
	//Realizar el tournament  de los padres a los hijos
	for(int i=0;i<=numind-1;i++){
		for(int j=0;j<=9;j++){
		 y= rand()%(numind-1)+0;
		 a[j]=pob[y];
		}
		pob1[i].nwin=Competir(pob1[i],a);
		//cout<<pob1[i].nwin<<"\n";
	}
	//cin.get();

}

void Universo::GA_Proxima_EDA(){
	Quicksort quick;
	Poblacion temp,pinicial;
	Cromosoma c1,c2;
	Cruce cR,cR2;
	int padre1, padre2;
	int k;
	pinicial=pob;
	for(int r=0;r<=numind-1;r++)
		temp.pobladores[r]=(*this).pob.pobladores[r];

	temp.generar_poblacionGAUSS(b);
	cout<<"terminar de generar la poblacion"<<"\n";
	temp.EliminarRep();
	cout<<"Elimino repetidos"<<"\n";
	Replacement(pinicial.pobladores,temp.pobladores);
	cout<<"REplacement"<<"\n";
	for(int k=0;k<=numind-1;k++)
		temp.pobladores[k].nwin+=temp.pobladores[k].fitness;
	for(int k=0;k<=numind-1;k++)
		pinicial.pobladores[k].nwin+=pinicial.pobladores[k].fitness;
	cout<<"Comienzo Quicksort"<<"\n";
	quick.quicksort(pinicial.pobladores,0,numind-1);
	quick.quicksort(temp.pobladores,0,numind-1);
	
	for(int i=0;i<=offspring-1;i++)
		pob[i]=pinicial[i];
	for(int k=offspring;k<=numind-1;k++)
		pob[k]=temp[k];
	quick.quicksort(pob.pobladores,0,numind-1);

}
void Universo::GA_proxima()
{
	Quicksort quick;
	Poblacion temp,pinicial; //pinicial es la poblacion de padres, temp la de hijos
	Cromosoma c1,c2;
	Cruce cR,cR2;
	int padre1, padre2;
	int k;
	//int cantElite; //UTILIZANDO ELITISMO
	//Aleatorio aleat;
	
	//cout << (*this).pob[1]<<"\n";
	(*this).sumaFitness=0;
	//
	GA_CalcularEstadisticas();
	//ELITISMO 
	
	int cantElite = (int)(numind * eliteP);
	//Elegir los elites
	/*for(int i=0; i<=cantElite-1; i++)
	{
		//hijo1=(*this).pob[(numind-1)-i]; //Caso de la Esfera
		hijo1=(*this).pob[i];
		// Caso Rastrigin
		temp[i] = hijo1;//numind - i + 1];
	}*/
	//cjordan=0;
	//OPERACIONES DE CRUCE Y MUTACION
	pinicial=pob;
	for (int i=cantElite; i<=numind-1; i++)// antes era i=cantElite
	{	
		padre1 = tournament_selection();
		padre2 = tournament_selection();
		c1 = (pob[padre1]).crom; 
		c2 = (pob[padre2]).crom;

		cR = Cruce::Cruce(c1,c2);
		cR2=Cruce::Cruce(c1,c2);
		switch(tipoCruce)
		{
		case 1:
			{
				cR.Un_Punto();
				break;
			}
		case 2:
			{
				cR.Uniforme();
				break;
			}
		case 3:
			{
				cR.BLX_Alfa();
				break;
			}
		case 4:
			{
				cR.Dos_Puntos();
				break;
			}
		}
		
		cR2.Tratar_De_Mutar();

		hijo[0].Construir(cR.hijo1,b);

		//if(hijo1.esFactible(aleat)==0)
		//{
			//hijo1.random(aleat);
		//}

		hijo[1].Construir(cR.hijo2,b);
		hijo[2].Construir(cR2.hijo1,b);
		hijo[3].Construir(cR2.hijo2,b);
		//if(hijo2.esFactible(aleat)==0)
		//{
			//hijo2.random(aleat);
		//}
		//temp.pobladores[i] = hijo[0];
		//i++;
		k=0;
		while(i<=numind-1 && k<=3){
			//cjordan++;
			temp.pobladores[i] = hijo[k];
			if(k<3)
			 i++;	
			k++;
		}

		//temp.imprimir_Poblacion();
		//
		
		
		//cout<<"\n";
		//cjordan++;
	}
	//PARA EL CASO DE CONTEMPLAR PENALIDAD
	/*Aleatorio aut;
	for(int j=0;j<=numind-1;j++){
		if(temp.pobladores[j].fitness<0)
			temp.pobladores[j].fitness=1;

	}*/
	/*if(bandera==1){
		for(int i=0;i<=numind-1;i++)
			for(int j=0;j<=rmax;j++)
				if(temp[i].Distancia(a[j].crom.genes)==0){
					temp[i].Construir();
					temp[i].CalcularFitness((*this).b);
				}
	}*/
	temp.EliminarRep();
	Replacement(pinicial.pobladores,temp.pobladores);
	for(int k=0;k<=numind-1;k++)
		temp.pobladores[k].nwin+=temp.pobladores[k].fitness;
	for(int k=0;k<=numind-1;k++)
		pinicial.pobladores[k].nwin+=pinicial.pobladores[k].fitness;
	quick.quicksort(pinicial.pobladores,0,numind-1);
	quick.quicksort(temp.pobladores,0,numind-1);
	
	for(int i=0;i<=offspring-1;i++)
		pob[i]=pinicial[i];
	for(int k=offspring;k<=numind-1;k++)
		pob[k]=temp[k];
	quick.quicksort(pob.pobladores,0,numind-1);
	//pinicial.DespatWin();
	//temp.DespatWin();
	/*
	for(int i=0;i<=(offspring/2)-1;i++)
		buff[i]=pinicial.pobladores[i];
	for(int i=(offspring/2);i<=offspring-1;i++)
		buff[i]=temp.pobladores[i-(offspring/2)];
	
	DespatBuffxWin();
	
	for(int i=0;i<=numind-1;i++)
		pob.pobladores[i]=buff[i];
		*/

	//pob = temp;
}

void Universo::DespatBuffxWin(){
  int i=0;
  Quicksort quick;
  int bandera=0;
  while(i<=(2*numind)-1){
	  for(int j=i+1;j<=(2*numind)-1;j++)
		  if(buff[i].nwin==buff[j].nwin){
			  if(buff[i].fitness>buff[j].fitness)
					buff[i].nwin++;
			  else
					buff[j].nwin++;
			  quick.quicksort(buff,0,(2*numind)-1);
			  bandera=1;
			  //cout<<"se activo la bandera"<<"\n";
			  break;
		  }
	if(bandera==0)
		i++;
	else{
		//cout<<"comienza todo de nuevo"<<"\n";
		i=0;
		bandera=0;
	}
  }
}
/*
double Universo::Recall(Individuo& x){
	double sumt=0.00;
	double sumb=0.00;
	int cualq=(*this).b.tambase;
	for(int j=0;j<=cualq-1;j++)
		if(b.postmotivo[j]!=-1)
			sumb+=1;
	for(int i=0;i<=cualq-1;i++){
		//cout<<x.positron[i]<<","<<b.postmotivo[i]<<"\n";
		if(x.positron[i]==b.postmotivo[i]){
			//cout<<"iguales!!"<<"\n";
			sumt+=1;
		}
		else if((x.positron[i]-b.postmotivo[i])==1 ||(b.postmotivo[i]-x.positron[i])==1 ){
			//cout<<"similares!!"<<"\n";
			sumt+=0;
		}else if((x.positron[i]-b.postmotivo[i])==2 || (b.postmotivo[i]-x.positron[i])==2 ){
			//cout<<"similares en 2!!"<<"\n";
			sumt+=0;
		}else if((x.positron[i]-b.postmotivo[i])==3 || (b.postmotivo[i]-x.positron[i])==3 ){
			//cout<<"similares en 3!!"<<"\n";
			sumt+=0;
		}
		else{
			//cout<<"diferentes!!"<<"\n";
		}
	}
	cout<<"Recall:"<<sumt<<"/"<<sumb<<"\n";
	return (sumt/sumb);
}
double Universo::Precision(Individuo& x){
	
	double sumt=0.00;
	double sumb=0.00;
	int hey=0;
	char prueb[numvar];
	int cualq=(*this).b.tambase;
	for(int j=0;j<=cualq-1;j++)
		if(b.postmotivo[j]!=-1)
			sumb+=1;
	for(int i=0;i<=cualq-1;i++){
		cout<<x.positron[i]<<","<<b.postmotivo[i]<<"\n";
		ImprimirdeBase(x.positron[i],i);
		ImprimirdeBase(b.postmotivo[i],i);
		hey=x.Distancia_H(b.postmotivo[i],i,b);
		cout<<"La distancia de Levenstein es: "<<hey<<"\n";
		/*if(x.positron[i]==b.postmotivo[i]){
			hey="iguales!!";
			cout<<"iguales!!"<<"\n";
			sumt+=1;
		}else if((x.positron[i]-b.postmotivo[i])==1 || (b.postmotivo[i]-x.positron[i])==1 ){
			hey="similares en 1!!";
			cout<<"similares en 1!!"<<"\n";
			sumt+=0;
		}else if((x.positron[i]-b.postmotivo[i])==2 || (b.postmotivo[i]-x.positron[i])==2 ){
			hey="similares en 2!!";
			cout<<"similares en 2!!"<<"\n";
			sumt+=0;
		}else if((x.positron[i]-b.postmotivo[i])==3 || (b.postmotivo[i]-x.positron[i])==3 ){
			hey="similares en 3!!";
			cout<<"similares en 3!!"<<"\n";
			sumt+=0;
		}
		else{
			hey="diferentes!!";
			cout<<"diferentes!!"<<"\n";
		}*//*
		EscribirArch(x.crom.genes,x.positron[i],b.postmotivo[i],i,hey);
	}
	//cout<<"Precision:"<<sumt<<"/"<<cualq<<"\n";
	return (sumt/cualq);
}
void Universo::ImprimirdeBase(int k,int j){
	
	for(int i=k;i<=k+(numvar-1);i++)
		cout<< b.Genoma[j][i];
	cout<<"\n";
}
void  Universo::EscribirArch(char a[numvar],int k,int j,int fila,int aja){
	int count=0;
	int count2=0;
	ofstream myfilee("C:/Users/cjordan/Documents/Tesis/RMF/RMF/encon.txt",ios::in | ios::ate);
	ofstream myfilem("C:/Users/cjordan/Documents/Tesis/RMF/RMF/encon2.txt",ios::in | ios::ate);
	ofstream myfile("C:/Users/cjordan/Documents/Tesis/RMF/RMF/compa.txt",ios::in | ios::ate);
	for(int y=k;y<=k+(numvar-1);y++){
		/*if(a[y]!=b.Genoma[fila][y])
			count++;*/
		/*myfile<<b.Genoma[fila][y];
		myfilee<<b.Genoma[fila][y];
	}
	myfilee<<"\n";
	myfile<<"\n";
	for(int y=j;y<=j+(numvar-1);y++){
		/*if(a[y]!=b.Genoma[fila][y])
			count2++;*//*
		myfile<<b.Genoma[fila][y];
		myfilem<<b.Genoma[fila][y];
	}
	myfile<<"\n";
	myfilem<<"\n";
	myfile<<aja;
	//myfile<<count<<","<<count2<<"\n";
	/*for(int o=0;o<=aja.length()-1;o++)
		myfile<<aja[o];*//*
	myfile<<"\n\n";
	myfile.close();
	myfilee.close();
	myfilem.close();
}

void Universo::CalcularConsensus(){
  Individuo iv,iv2;
  ifstream myfile ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\encon.txt");
  ofstream m("C:/Users/cjordan/Documents/Tesis/RMF/RMF/encon.txt",ios::in | ios::ate);
  ofstream n("C:/Users/cjordan/Documents/Tesis/RMF/RMF/encon2.txt",ios::in | ios::ate);
  m<<"\n";
  n<<"\n";
  int valconsens=0;
  char Consensus[numvar];
  char ConsensusM[numvar];
  int a,c,g,t;
  a=0;
  c=0;
  g=0;
  t=0;
  int count=0;
  int count2=0;
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
		getline (myfile,(*this).encon[count]);
	  //cout << Genoma[count]<< endl;
	  count++;
    }
    myfile.close();
	for(int i=0;i<=b.tambase-1;i++)
		cout<<encon[i]<<"\n";
  }else cout << "Unable to open file"; 
  cout<<"\n";
  int tamano=encon[0].length();
  for(int i=0;i<=tamano-1;i++){
	  for(int j=0;j<=b.tambase-1;j++){
		  if(encon[j][i]=='a')
			  a++;
		  if(encon[j][i]=='c')
			  c++;
		  if(encon[j][i]=='g')
			  g++;
		  if(encon[j][i]=='t')
			  t++;
	  }			
	 Consensus[i]=Mayor(a,c,g,t); 
	 valconsens+=MayorV(a,c,g,t);
	 a=c=g=t=0;
  }
  iv.crom.Construir(Consensus);
  iv.CalcularFitness((*this).b);
  for(int i=0;i<=tamano-1;i++)
	  cout<<Consensus[i];
  cout<<",Score:"<<valconsens<<", La distancia del consenso a la Base es: "<<iv.fitness<<"\n";
  cout<<"\n";
  for(int i=0;i<=tamano-1;i++)
	m<<Consensus[i];
  m<<"\n";
  m<<"Valor del Consensus es:"<<valconsens<<"\n";
  m<<"Distancia del Consensus a la Base es:"<<iv.fitness<<"\n";
  m.close();
   a=c=g=t=valconsens=0;
  ifstream myfile2 ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\encon2.txt");
   if (myfile2.is_open())
  {
    while (! myfile2.eof() )
    {
		getline (myfile2,(*this).motifs[count2]);
	  //cout << Genoma[count]<< endl;
	  count2++;
    }
	
    myfile.close();
  }else cout << "Unable to open file"; 
  for(int i=0;i<=b.tambase-1;i++)
	cout<<motifs[i]<<"\n";
  cout<<"\n";
   for(int i=0;i<=tamano-1;i++){
	  for(int j=0;j<=b.tambase-1;j++){
		  if(motifs[j][i]=='a')
			  a++;
		  if(motifs[j][i]=='c')
			  c++;
		  if(motifs[j][i]=='g')
			  g++;
		  if(motifs[j][i]=='t')
			  t++;
	  }			
	 ConsensusM[i]=Mayor(a,c,g,t);
	 valconsens+=MayorV(a,c,g,t);
	 a=c=g=t=0;
  }
   cout<<"\n";
   for(int i=0;i<=tamano-1;i++)
	  cout<<ConsensusM[i];
  iv2.crom.Construir(ConsensusM);
  iv2.CalcularFitness((*this).b);
  cout<<","<<valconsens<<", La distancia del consenso(motif real) a la Base es: "<<iv2.fitness<<"\n";
  for(int i=0;i<=tamano-1;i++)
	n<<ConsensusM[i];
  n<<"\n";
  n<<"Valor del Consensus es:"<<valconsens<<"\n";
  n<<"Distancia del Consensus(motif real) a la Base es:"<<iv2.fitness<<"\n";
  n.close();
  /*for(int i=0;i<=b.tambase-1;i++)
	  for(int j=0;j<=b.tambase-1;j++)
		  distan[i][j]= iv.Distancia_H(encon[i],motifs[j]);

  for(int i=0;i<=b.tambase-1;i++){
	 for(int j=0;j<=b.tambase-1;j++)
		 cout<<distan[i][j]<<"  ";
	 cout<<"\n";
  }*/
  //cin.get();
/*

}

int Universo::MayorV(int a,int c,int g, int t){
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
char Universo::Mayor(int a,int c,int g, int t){
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


/*void Pila::Push(int ele1, int ele2)
{
	elementos[pos] = ele1;
	pos++;
	elementos[pos] = ele2;
	pos++;

}
bool Pila::Empty(){
	return (pos==0);
}

void Pila::Pop(int *ele1,int *ele2){
	pos--;
	*ele2 = elementos[pos];
	pos--;
	*ele1 = elementos[pos];
}
*/