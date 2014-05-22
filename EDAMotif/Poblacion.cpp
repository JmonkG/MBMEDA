#include <iostream>
#include <cmath>

#include "Poblacion.h"
#include "Individuo.h"
#include "Base.h"
using namespace std; 

void Poblacion::setearNwin(){
	for(int i=0;i<=numind-1;i++)
		(*this).pobladores[i].nwin=0;
}
Poblacion &Poblacion::operator=(Poblacion &p)	{
	(*this).limsup=p.limsup;
	for(int i=0; i<= numind-1; i++)
		(*this)[i] = p[i];
	return *this;
}
void Poblacion::GenerarPoblacion(int tamano,Base &x){
	limsup=x.longgen-tamtruemotif;
	for(int i=0;i<=numind-1;i++){
		(*this).pobladores[i].Construir(tamano,x);
	}
}

void Poblacion::ImprimirPoblacion(){
	for(int i=0;i<=numind-1;i++){
		(*this).pobladores[i].crom.Imprimir_Cromosoma();
		cout<<" "<<(*this).pobladores[i].fitness<<"\n";
	}
}

/*void Poblacion::ImprimirBase(){
	for(int i=0;i<=elbase-1;i++)
		(*this).base[i].Imprimir_Genoma();
}

void Poblacion::GenerarGenoma(){
	Cromosoma c;
	int prob;
	(*this).motif.GenerarMotif();
	for(int j=0;j<=elbase-1;j++){
		prob=rand()%10+0;
		c=(*this).motif;
		if(prob!=0)
			c.MutarMotif();
		//c.Imprimir_Cromosoma();
		(*this).base[j].ConstruirGenoma(c);
	}
}
*/
void Poblacion::DespatWin(){
  int i=0;
  int bandera=0;
  while(i<=numind-1){
	  for(int j=i+1;j<=numind-1;j++)
		  if(pobladores[i].nwin==pobladores[j].nwin){
			  if(pobladores[i].fitness>pobladores[j].fitness)
					pobladores[i].nwin++;
			  else
					pobladores[j].nwin++;
			  OrdenarxWin();
			  bandera=1;
			  break;
		  }
	if(bandera==0)
		i++;
	else{
		i=0;
		bandera=0;
	}
  }
}
void Poblacion::OrdenarxWin(){
	Individuo aux;
	for (int i=0; i<numind-1; i++)
	{
		double max = (*this)[i].nwin;
		int maxx = i;
		for(int j=i+1; j<=numind-1; j++)
		{
			if ((*this)[j].nwin > max)
			{
				max = (*this)[j].nwin;
				maxx = j;
			}
		}
		//cout<<"\n";
		//(*this)[i].crom.ImprimirCromosoma();
		//(*this)[mindx].crom.ImprimirCromosoma();
		aux = (*this)[i];
		(*this)[i]=(*this)[maxx];
		(*this)[maxx]=aux;
		//cout<<"\n";
		//(*this).imprimir_Poblacion();
	}
}
void Poblacion:: OrdenarxSeleccionMax(){
	Individuo aux;
	for (int i=0; i<numind-1; i++)
	{
		double max = (*this)[i].fitness;
		int maxx = i;
		for(int j=i+1; j<=numind-1; j++)
		{
			if ((*this)[j].fitness > max)
			{
				max = (*this)[j].fitness;
				maxx = j;
			}
		}
		//cout<<"\n";
		//(*this)[i].crom.ImprimirCromosoma();
		//(*this)[mindx].crom.ImprimirCromosoma();
		aux = (*this)[i];
		(*this)[i]=(*this)[maxx];
		(*this)[maxx]=aux;
		//cout<<"\n";
		//(*this).imprimir_Poblacion();
	}

}
void Poblacion::OrdenarxSeleccion()	{
	Individuo aux;
	for (int i=0; i<numind-1; i++)
	{
		double min = (*this)[i].fitness;
		int mindx = i;
		for(int j=i+1; j<=numind-1; j++)
		{
			if ((*this)[j].fitness < min)
			{
				min = (*this)[j].fitness;
				mindx = j;
			}
		}
		//cout<<"\n";
		//(*this)[i].crom.ImprimirCromosoma();
		//(*this)[mindx].crom.ImprimirCromosoma();
		aux = (*this)[i];
		(*this)[i]=(*this)[mindx];
		(*this)[mindx]=aux;
		//cout<<"\n";
		//(*this).imprimir_Poblacion();
	}
}
void Poblacion::MejorFitness(Individuo &t){
	Individuo minimo=(*this).pobladores[0];
	for(int i=0;i<=numind-1;i++)
		if((*this).pobladores[i].fitness<=minimo.fitness){
			minimo=(*this).pobladores[i];
		}
	t=minimo;
}
void Poblacion::Shift(Base&x){
	int min,max;	
	Individuo inv,invplus,invmin;
	inv=invplus=invmin=pobladores[0];
	min=max=inv.crom.genes[0];

	for(int j=0;j<=numvar-1;j++)
		if(inv.crom.genes[j]<=min)
			min=inv.crom.genes[j];
	
	for(int j=0;j<=numvar-1;j++)
		if(inv.crom.genes[j]>=max)
			max=inv.crom.genes[j];
	cout<<min<<" "<<max<<"\n";
	//cin.get();
	for(int i=1;i<=limsup-max;i++){
		for(int j=0;j<=numvar-1;j++){
			invplus.crom.genes[j]+=i;
			if(min-i>=0)
				invmin.crom.genes[j]-=i;
		}
		invplus.CalcularFitness(x);
		invmin.CalcularFitness(x);
		
		invplus.ImprimirIndv();
		inv.ImprimirIndv();
		invmin.ImprimirIndv();
		//cin.get();
		if(invplus.fitness>inv.fitness && invplus.fitness>=invmin.fitness){
			cout<<"mejoro hacia adelante";
			//cin.get();
			pobladores[0]=invplus;
			break;
		}else if(invmin.fitness>inv.fitness && invmin.fitness>=invplus.fitness){
			cout<<"mejoro hacia atras";
			//cin.get();
			pobladores[0]=invplus;
			break;
		}
		else{
			cout<<"no mejora"<<"\n";
			//cin.get();
			invplus=invmin=inv;
			
		}
	}	

}
void Poblacion::EliminarRep(){
	Individuo indv;
	int k=0;
	cout<<"Eliminar repetidos"<<"\n";
	while(k<=numind-1){
		indv=pobladores[k];
		//cout<<"k:"<<k<<"\n";
		//indv.ImprimirIndv();
		for(int i=0;i<=numind-1;i++){
			if(indv.Iguales(pobladores[i].crom.genes)&& i!=k && indv.fitness==pobladores[i].fitness){
				//cout<<"i:"<<i<<"\n";
				//pobladores[i].ImprimirIndv();
				//cout<<"es repetido"<<"\n";
				//cin.get();
				pobladores[i].fitness=0.00; //PARA EL CASO EN QUE SE MAXIMIZE EL FITNESS
				//pobladores[i].ImprimirIndv();
				//cin.get();
			}
		}
	k++;
	}
}
/*void Poblacion::Generar1raPoblacion(Base &x){
  string buff,buff2,buff3;
  buff2=buff3="";
  Cromosoma ff;
  int cromo[200];
  int count=0;
  int count2=0;
  ifstream myfile ("C://Users//cjordan//Documents//Tesis//RMF//RMF//Poblacion.txt");
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
		getline (myfile,buff);
		int c= buff.length();
		// Lo que esta dentro del for es la construcciòn de un individuo
		//cout<<count2+1<<" INDIVIDUO"<<"\n";
		//cin.get();
		if(count2+1==11)
			int jajajaja=1;
		if(buff.empty())
			break;
		for(int i=0;i<=c-1;i++){
			if(buff.at(i)==','){
				//cout<<buff3<<"\n";
				//Conversion de char a int para almacenar en un arreglo
				if(buff3=="0"){
					cromo[count]=atoi(buff3.c_str());
					//cout<<cromo[count]<<"\n";
					count++;
				}
				if(cromo[count]=atoi(buff3.c_str())){
					//cout<<cromo[count]<<"\n";
					count++;
				}
				buff3="";
				if(i+1>=c)
					break;
				i++;
				while(buff.at(i)!=','){
					buff2+=buff.at(i);
					i++;
				}
				//cout<<buff2<<"\n";
				//Conversion de char a int para almacenar en un arreglo
				if(buff2=="0"){
					cromo[count]=atoi(buff2.c_str());
					//cout<<cromo[count]<<"\n";
					count++;
				}
				if(cromo[count]=atoi(buff2.c_str())){
					//cout<<cromo[count]<<"\n";
					count++;
				}
				buff2="";
			}else{
				buff3+=buff.at(i);
			}
		}
		if(count2==1)
			int op=1;
		ff.Construir(cromo);
		(*this).pobladores[count2].Construir(ff,x);
		count2++;
		//cout<<count+1<<"\n"; // count comienza desde 0, por eso el +1
		//limpieza de variables
		count=0;
		buff2=buff3="";
		//cout<<"*****"<<"\n";
    }
    myfile.close();
  }else cout << "Unable to open file";



}*/

void Poblacion::generar_poblacionGAUSS(Base&x){
	Individuo test;
	AMatrix ama_a,ama_c,ama_g,ama_t;
	double p[tamtruemotif],q[tamtruemotif],r[tamtruemotif],s[tamtruemotif];

	//Copiando los nucleotidos a,c,g,t de los PWM de la poblacion
	for(int i=0;i<=nemg-1;i++)
		for(int j=0;j<=dimm-1;j++)
			ama_a.arr[i][j]=(*this).pobladores[i].PWM[0][j];
	for(int i=0;i<=nemg-1;i++)
		for(int j=0;j<=dimm-1;j++)
			ama_c.arr[i][j]=(*this).pobladores[i].PWM[1][j];
	for(int i=0;i<=nemg-1;i++)
		for(int j=0;j<=dimm-1;j++)
			ama_g.arr[i][j]=(*this).pobladores[i].PWM[2][j];
	for(int i=0;i<=nemg-1;i++)
		for(int j=0;j<=dimm-1;j++)
			ama_t.arr[i][j]=(*this).pobladores[i].PWM[3][j];
	
	//calculo de la media y varianza de cada 
	ama_a.media();
	ama_a.varianza();
	ama_c.media();
	ama_c.varianza();
	ama_g.media();
	ama_g.varianza();
	ama_t.media();
	ama_t.varianza();
	
	for(int m=0;m<=numind-1;m++){
		for(int i=0;i<=tamtruemotif-1;i++){
			p[i] = ama_a.randn_notrig(ama_a.smuu,ama_a.svari);
			//cout<<i<<"pi"<<" ";
			q[i] = ama_c.randn_notrig(ama_c.smuu,ama_c.svari);
			//cout<<"qi"<<" ";
			r[i] = ama_g.randn_notrig(ama_g.smuu,ama_g.svari);
			//cout<<"ri"<<" ";
			s[i] = ama_t.randn_notrig(ama_t.smuu,ama_t.svari);
			//cout<<"si"<<"\n";
		}

		(*this).pobladores[m].Copy_NPWM(p,'a');
		 //cout<<m<<"APWM"<<" ";
		(*this).pobladores[m].Copy_NPWM(q,'c');
		// cout<<"CPWM"<<" ";
		(*this).pobladores[m].Copy_NPWM(r,'g');
			//cout<<"GPWM"<<" ";
		(*this).pobladores[m].Copy_NPWM(s,'t');
			//cout<<"TPWM"<<"\n";
		(*this).pobladores[m].Normalize_PWM();
			//cout<<"Normalizada PWM"<<"\n";
		(*this).pobladores[m].Create_NInd(); // esta es
		
		cout<<"-----------------"<<"NUMERO = "<<m<<"\n";
		
		for(int i=0;i<=numvar-1;i++)
			(*this).pobladores[m].crom.genes[i]=(*this).pobladores[m].fitnessLV(x.Genoma[i],i);
		(*this).pobladores[m].CalcularFitness(x);
		//cout<<"termino de calcular el fitness"<<"\n";
		//cin.get();
	}
	/*ama_a.Mean();
	ama_a.CoVariance();
	ama_a.Cholesky(ama_a.Sigma,dimm,dimm);
	ama_c.Mean();
	ama_c.CoVariance();
	ama_g.Mean();
	ama_g.CoVariance();
	ama_t.Mean();
	ama_t.CoVariance();*/

}