#include "individuo.h"
#include <cmath>

using std::cout;
using std::endl;


void Individuo::Construir (Cromosoma c,Base &x)
{
	crom = c;
	CalcularFitness(x);
	//padre1 = p1;
	//padre2 = p2;
}

void Individuo::CalcularFitness(Base &x){

	double sumafitness=0;
	(*this).dimpos=x.tambase;
	/*for(int z=0;z<=x.tambase-1;z++){
		if(tipodis==1)
			(*this).positron[z]=Distancia_dif(x.Genoma[z]);
		else
			(*this).positron[z]=(*this).fitnessLV(x.Genoma[z]);
		sumafitness+=(*this).fitness;
		//cout<<p.pobladores[k].fitness<<'\n';
	}*/
	construirIC(x);
	//cout<<"\n";
	double a =CalcularIC(IC,dhor,dver,x);
	//cout<<"calculo IC"<<"\n";
	(*this).CalcularPWM();
	//cout<<"calculo PWM"<<"\n";
	(*this).Calcular_Nuc();
	//cout<<"calculo NUC"<<"\n";
	(*this).fitness=a;
	//cout<<sumafitness<<"\n";
	/*for(int i=0;i<=x.tambase-1;i++){
		int t=positron[i];
		for(int j=0;j<=numvar-1;j++)
			cout<<x.Genoma[i][t+j];
		cout<<"\n";
	}*/
	//cout<<(*this).fitness<<"EL"<<"\n";
}

void Individuo::Calcular_Nuc(){
	for(int i=0;i<=3;i++){
	 if(i==0)
		 for(int j=0;j<=dhor-1;j++)
			 nuc_a[j]=(*this).PWM[i][j];
	 if(i==1)
		 for(int j=0;j<=dhor-1;j++)
			 nuc_c[j]=(*this).PWM[i][j];
	 if(i==2)
		  for(int j=0;j<=dhor-1;j++)
			 nuc_g[j]=(*this).PWM[i][j];
	 if(i==3)
		 for(int j=0;j<=dhor-1;j++)
			 nuc_t[j]=(*this).PWM[i][j];
	}


}
void Individuo::construirIC(Base &x){
	(*this).dhor= tamtruemotif;
	(*this).dver=x.tambase;
	for(int i=0;i<=dver-1;i++){
		int t=crom.genes[i];
		for(int j=0;j<=dhor-1;j++)
			IC[i][j]=x.Genoma[i][t+j];
		/*for(int j=0;j<=dhor-1;j++)
			cout<<IC[i][j];
		cout<<"\n";*/
		
	}
	/*for(int i=0;i<=dver-1;i++){
		for(int j=0;j<=dhor-1;j++)
			cout<<IC[i][j];
		cout<<"\n";
	}
	cin.get();*/

}
Individuo	&Individuo::operator=(Individuo &x)	{
	(*this).crom = x.crom;
	(*this).fitness = x.fitness;
	(*this).dimpos= x.dimpos;
	(*this).dhor=x.dhor;
	(*this).dver=x.dver;
	(*this).nwin=x.nwin;
	for(int i=0;i<=numvar-1;i++)
		(*this).similarity[i]=x.similarity[i];
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			(*this).IC[i][j]=x.IC[i][j];
	for(int i=0;i<=3;i++)
		for(int j=0;j<=tamtruemotif;j++)
			(*this).PWM[i][j]= x.PWM[i][j];
	for(int k=0;k<=numvar-1;k++)
		for(int u=0;u<=tamtruemotif-1;u++)
			(*this).S_A[k][u]=x.S_A[k][u];
	for(int i=0;i<=tamtruemotif-1;i++){
		nuc_a[i]=x.nuc_a[i];
		nuc_c[i]=x.nuc_c[i];
		nuc_g[i]=x.nuc_g[i];
		nuc_t[i]=x.nuc_t[i];
	}

	/*for(int y=0;y<=dimpos-1;y++)
		(*this).positron[y]=x.positron[y];*/
	return *this;
}

/*
void Individuo::copiarIndividuo(Individuo x){
	(*this).crom = x.crom;
	(*this).padre1 = x.padre1;
	(*this).padre2 = x.padre2;
	(*this).fitness = x.fitness;
}
*/
void Individuo::Construir (int tamano,Base&x)
{
	(*this).crom.Construir(tamano);
	(*this).CalcularFitness(x);

}

/*int Individuo::dimension(char a[]){
	int count=0;
	while(a[count]=='a'|| a[count]=='c'||a[count]=='g'||a[count]=='t')
		count++;
	return count;

}*/

int Individuo::Iguales(int a[]){
	int count=0;
	//int dimension= (*this).dimension(a);
	//cout<< dimension<<"\n";
	for(int i=0;i<=numvar-1;i++){
		if((*this).crom.genes[i]==a[i])
			count++;
	}
	if(count==numvar)
		return 1;
	else
		return 0;
}/*

void Individuo::Distancia(string a){
	int count=0;
	//int dimension= (*this).dimension(a);
	//cout<< dimension<<"\n";
	for(int i=0;i<=numvar-1;i++){
		if(isupper(a[i]))
			a[i]=(char)tolower(a[i]);

		if((*this).crom.genes[i]!=a[i])
			count++;
	}
	(*this).fitness=count;



}
int Individuo::Distancia_dif(string a){
 int minimo=0;
 int count=0;
 int position=0;
 int tam1=sizeof((*this).crom.genes)/sizeof(char);
 int tam2=a.length();
 if(tam1>tam2){
    int k=0;
	int y=0;
	while(y<tam1-1){
		count=0;
		for(int j=0;j<=tam2-1;j++){
			if((*this).crom.genes[j+k]!=a[j])
				count+=1;
			if(j==tam2-1){
				if(count<minimo || y==0){
					minimo=count;
					position=k;
				}
				y=j+k;
			}
		}
		k++;
	}
	(*this).fitness=minimo;
 }else if(tam2>tam1){
	int k=0;
	int y=0;
	while(y<tam2-1){
		count=0;
		for(int j=0;j<=tam1-1;j++){
			/*if(isupper(a[j]))
				a[j]=(char)tolower(a[j]);*/
			/*if(a[j+k]!=(*this).crom.genes[j])
				count+=1;
			if(j==tam1-1){
				if(count<minimo || y==0){
					minimo=count;
					position=k;
				}
				y=j+k;
			}
		}
		k++;
	}
	(*this).fitness=minimo;
}else{
	(*this).Distancia(a);
 }

 return position;
}

int Individuo::fitnessLV(string a){
	int position=0;
	int tam2= a.length();
	int minimo=0,count=0;
	int k=0,y=0;
	char b[numvar];
	if(a.length()==numvar){
		minimo=Distancia_H(a);
		position=k;
	}else{
		while((y+numvar)<=tam2-1){
			for(int j=0;j<=numvar-1;j++){
				b[j]=a[j+k];	
			}
			count=Distancia_H(b);
			if(count<minimo || y==0){
				minimo=count;
				position=k;
			}
			y++;
			k++;
		}
	}
	(*this).fitness=minimo;
return position;
}*/
int Individuo::minimo(int a,int b,int c){
	if(a<=b){
		if(a<=c && c<=b)
			return a;
		else if(a>c)
			return c;
	}
	else{
		if(b<=c && c<=a)
			return b;
		else if(b>c)
			return c;
	}
}


/*int Individuo::Distancia_H(int f,int e,Base &x){
int Hamming[numvar+1][numvar+1];
char a[numvar];
int count=0;
char b[numvar];
for(int i=f;i<=f+(numvar-1);i++){ 
	a[count]=x.Genoma[e][i];
	count++;
}
count=0;
for(int i=(*this).positron[e];i<=(*this).positron[e]+(numvar-1);i++){
	b[count]=x.Genoma[e][i];
	count++;
}
for(int i=0;i<=numvar;i++) for(int j=0;j<=numvar;j++) Hamming[i][j]=0;
for(int i=0;i<=numvar;i++) Hamming[0][i]=Hamming[i][0]=i;
for(int i=1;i<=numvar;i++)
	for(int j=1;j<=numvar;j++){
		if(a[j-1]==b[j-1])//(*this).crom.genes[i-1])
			Hamming[i][j]=Hamming[i-1][j-1];
		else
			Hamming[i][j]=minimo(1+Hamming[i-1][j],1+Hamming[i][j-1],1+Hamming[i-1][j-1]);
	}
/*for(int i=0;i<=numvar;i++) {
	for (int j=0;j<=numvar;j++) 
		cout<< Hamming[i][j]<<" ";
	cout<<"\n";
}*/
/*return Hamming[numvar][numvar];
}
int Individuo::Distancia_H(string a){
int Hamming[numvar+1][numvar+1];
for(int i=0;i<=numvar;i++) for(int j=0;j<=numvar;j++) Hamming[i][j]=0;
for(int i=0;i<=numvar;i++) Hamming[0][i]=Hamming[i][0]=i;
for(int i=1;i<=numvar;i++)
	for(int j=1;j<=numvar;j++){
		if((*this).crom.genes[i-1]==a[j-1])//(*this).crom.genes[i-1])
			Hamming[i][j]=Hamming[i-1][j-1];
		else
			Hamming[i][j]=minimo(1+Hamming[i-1][j],1+Hamming[i][j-1],1+Hamming[i-1][j-1]);
	}
/*for(int i=0;i<=numvar;i++) {
	for (int j=0;j<=numvar;j++) 
		cout<< Hamming[i][j];
	cout<<"\n";
}*/
/*return Hamming[numvar][numvar];
}

int Individuo::Distancia_H(string a,string b){
int Hamming[numvar+1][numvar+1];
for(int i=0;i<=numvar;i++) for(int j=0;j<=numvar;j++) Hamming[i][j]=0;
for(int i=0;i<=numvar;i++) Hamming[0][i]=Hamming[i][0]=i;
for(int i=1;i<=numvar;i++)
	for(int j=1;j<=numvar;j++){
		if(b[i-1]==a[j-1])//(*this).crom.genes[i-1])
			Hamming[i][j]=Hamming[i-1][j-1];
		else
			Hamming[i][j]=minimo(1+Hamming[i-1][j],1+Hamming[i][j-1],1+Hamming[i-1][j-1]);
	}
/*for(int i=0;i<=numvar;i++) {
	for (int j=0;j<=numvar;j++) 
		cout<< Hamming[i][j];
	cout<<"\n";
}*/
/*return Hamming[numvar][numvar];
}*/
double Individuo::log2(double number){
 return log(double(number))/log(double(2));

}
double Individuo::CalcularIC(char matriz[100][100],int dhor,int dver,Base &x){
	double a,c,g,t;
	a=c=g=t=0.000;
	double infoc[4];
	double iccol[tamtruemotif];
	double ic=0;
	for(int i=0;i<=3;i++)
		infoc[i]=0.00;
	for(int i=0;i<=dhor-1;i++){
		iccol[i]=0;
		for(int j=0;j<=dver-1;j++){
			if(matriz[j][i]=='a')
			  a++;
		  if(matriz[j][i]=='c')
			  c++;
		  if(matriz[j][i]=='g')
			  g++;
		  if(matriz[j][i]=='t')
			  t++;
		}
		if(a!=0)
			infoc[0]=((a/dver)*log2((a/dver)/x.pa));
		if(c!=0)
			infoc[1]=((c/dver)*log2((c/dver)/x.pc));
		if(g!=0)
			infoc[2]=((g/dver)*log2((g/dver)/x.pg));
		if(t!=0)
			infoc[3]=((t/dver)*log2((t/dver)/x.pt));
		for(int k=0;k<=3;k++){
			ic+=infoc[k];
			iccol[i]+=infoc[k];
		}
		//re inicializar los indicadores
		/*for(int k=0;k<=3;k++)
			cout<<infoc[k]<<",";
		cout<<"\n";
		cin.get();*/
		for(int k=0;k<=3;k++)
			infoc[k]=0;
		a=c=g=t=0.000;
	}
	double tot=0;
	for(int i=0;i<=tamtruemotif-1;i++)
		tot+=iccol[i];
	//cout<<ic<<"\n";
	//cin.get();
	return ic;
}
void Individuo::EscribirEnArchivo(int k){
	ofstream myfile;
	myfile.open("valores.txt",ios::in | ios::ate);
	myfile <<k<<" "<<(*this).fitness<< "\n";
	myfile.close();


}
void Individuo::CalcularSimilaridad(){
	double pont=0;
	int a,c,g,t;
	a=c=g=t=0;
	for(int i=0;i<=numvar-1;i++){
		for(int k=0;k<=tamtruemotif-1;k++){
			if(IC[i][k]=='a')
				pont+=PWM[0][k];
			if(IC[i][k]=='c')
				pont+=PWM[1][k];
			if(IC[i][k]=='g')
				pont+=PWM[2][k];
			if(IC[i][k]=='t')
				pont+=PWM[3][k];
		}
		//cout<<pont<<"\n";
		(*this).similarity[i]=pont;
		pont=0.0;
	}
}
double Individuo::CalcularSimilaridad(char v[tamtruemotif]){
	double pont=0;
	int a,c,g,t;
	a=c=g=t=0;
		for(int k=0;k<=tamtruemotif-1;k++){
			if(v[k]=='a')
				pont+=PWM[0][k];
			if(v[k]=='c')
				pont+=PWM[1][k];
			if(v[k]=='g')
				pont+=PWM[2][k];
			if(v[k]=='t')
				pont+=PWM[3][k];
		}
		return pont;

}
void Individuo::LocalFilter(Base &x){
	(*this).CalcularSimilaridad();
	char buff[tamtruemotif];
	int punt,k,m;
	double nsim;
	while(1){
		for(int i=0;i<=numvar-1;i++){
			cout<<crom.genes[i]<<" "<<(*this).similarity[i]<<"\n";
		}
		punt=(*this).MinimoS();
		/*cout<<"El minimo es:"<<similarity[punt]<<"\n\n";
		cin.get();*/
		double max=similarity[punt];
		k=0;
		while(k+(tamtruemotif-1)<x.longgen){
			for(int w=0;w<=tamtruemotif-1;w++)
				buff[w]=x.Genoma[punt][k+w];
			nsim=CalcularSimilaridad(buff);
			/*for(int i=0;i<=tamtruemotif-1;i++)
				cout<<buff[i];
			cout<<" "<<nsim<<"\n";
			cin.get();*/
			if(nsim>max){
					max=nsim;
					m=k;
			}
			k++;
		}
		if(max>similarity[punt]){
			/*cout<<"Ha mejorado, Sim anterior era:"<<similarity[punt]<<"Actual es:"<<max<<"\n";
			cin.get();*/
			similarity[punt]=max;
			crom.genes[punt]=m;
			
		}
		else{
			/*cout<<"no ha mejorado"<<"\n";
			cin.get();*/
			(*this).CalcularFitness(x);
			break;
		}
	}
		
}
void Individuo::ImprimirIndv(){
	crom.Imprimir_Cromosoma();
	cout<<" "<<(*this).fitness<<"\n";
}
void Individuo::CalcularPWM(){
	int a,c,g,t;
	Aleatorio aleat;
	a=c=g=t=0;
	for(int i=0;i<=dhor-1;i++){
		for(int j=0;j<=dver-1;j++){
			if(IC[j][i]=='a')
			  a++;
		  if(IC[j][i]=='c')
			  c++;
		  if(IC[j][i]=='g')
			  g++;
		  if(IC[j][i]=='t')
			  t++;
		}
			// 1 fila es A, 2da C, 3ra G, 4ta T
			PWM[0][i]=aleat.round((double)a/dver,1);
			PWM[1][i]=aleat.round((double)c/dver,1);
			PWM[2][i]=aleat.round((double)g/dver,1);
			PWM[3][i]=aleat.round((double)t/dver,1);
			a=c=g=t=0;
	}
	/*for(int i=0;i<=3;i++){
		for(int j=0;j<=tamtruemotif-1;j++)
			cout<<PWM[i][j]<<"  ";
		cout<<"\n";
	}*/
	int buffi;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=tamtruemotif-1;j++){
			buffi=PWM[i][j]*100;
			PWM[i][j]=(double)buffi/100;
		}
}
int Individuo::MinimoS(){
double minimo=similarity[0];
int punt;
for(int n=0;n<=numvar-1;n++)
	if((*this).similarity[n]<=minimo){
			minimo=(*this).similarity[n];
			punt=n;
	}
return punt;
}

//FUNCIONES PARA EL EDA

void Individuo::Copy_NPWM(double arr[tamtruemotif],char letra){
	
	if(letra=='a')
		for(int i=0;i<=tamtruemotif-1;i++)
			(*this).PWM[0][i]=arr[i];
	else if(letra=='c')
		for(int i=0;i<=tamtruemotif-1;i++)
			(*this).PWM[1][i]=arr[i];
	else if(letra=='g')
		for(int i=0;i<=tamtruemotif-1;i++)
			(*this).PWM[2][i]=arr[i];
	else if(letra=='t')
		for(int i=0;i<=tamtruemotif-1;i++)
			(*this).PWM[3][i]=arr[i];

}

void Individuo::Normalize_PWM(){
	double temp[4][tamtruemotif];
	double total;
	double sum;
	for(int i=0;i<=4-1;i++)
		for(int j=0;j<=tamtruemotif-1;j++){
			if(PWM[i][j]<0)
				PWM[i][j]=-1*PWM[i][j];
		}
	for(int i=0;i<=tamtruemotif-1;i++){
		total=0.0;
		for(int j=0;j<=4-1;j++){
			total+=PWM[j][i];
		}
		for(int j=0;j<=4-1;j++){
			temp[j][i]=(PWM[j][i])/total;//(100*PWM[j][i])/total;
		}
	}
	for(int i=0;i<=tamtruemotif-1;i++){
		sum=0;
		for(int j=0;j<=4-1;j++)
			sum+=temp[j][i];
	}
	for(int i=0;i<=4-1;i++)
		for(int j=0;j<=tamtruemotif-1;j++)
			(*this).PWM[i][j]=temp[i][j];


}

void Individuo::Create_NInd(){
 double hibrid[4][tamtruemotif];
 int ent,sum,rann;
 double dec;
 int count=0;
 int counta,countc,countg,countt;
 int kk=0;
 int al;
 int j=0;


  for(int i=0;i<=numvar-1;i++)
	  for(int j=0;j<=tamtruemotif-1;j++)
		  S_A[i][j]='w';
  for(int i=0;i<=4-1;i++)
		for(int j=0;j<=tamtruemotif-1;j++)
				hibrid[i][j]=PWM[i][j]*numvar;
  //proceso de depuracion, convertir double a int y completar hasta tener la suma=numvar
  for(int i=0;i<=4-1;i++){
	  for(int j=0;j<=tamtruemotif-1;j++){
			ent= hibrid[i][j];
			dec= hibrid[i][j]-ent;
			if(dec>=0.5)
				ent+=1;
			hibrid[i][j]=ent;		
	  }
  }
  
  //AQUI ESTA EL PROBLEMA
  for(int i=0;i<=tamtruemotif-1;i++){
	  sum=0;
	  for(int j=0;j<=4-1;j++){
		  sum+=hibrid[j][i];
	  }
	  while(sum<numvar-1){
		rann=rand()%3+0;
		hibrid[i][rann]+=1;
		 sum++;
	 }
  }
  //conversion a matriz matriz con variables (S(A))
  for(int i=0;i<=tamtruemotif-1;i++){
     kk=0;
	 while(kk<=3){
		 while(j<=hibrid[kk][i]-1){ 
			 count=0;
			 do{
				
				al=rand()%(numvar)+0;
				if(S_A[al][i]!='w'){
					count++;
				}
			}while(S_A[al][i]!='w' && count<3*numvar);
			if(kk==0){
				S_A[al][i]='a';
				
			}
			if(kk==1){
				S_A[al][i]='c';
				
			}
			if(kk==2){
				S_A[al][i]='g';
				
			}
			if(kk==3){
				for(int y=0;y<=numvar-1;y++){
					if(S_A[y][i]=='w')
						S_A[y][i]='t';
				}
				break;
			}
	 		j++; 
		 }
		 j=0;
		 kk++;
	 }
  }

  for(int i=0;i<=tamtruemotif-1;i++){
	  counta=countc=countg=countt=0;
	  for(int j=0;j<=numvar-1;j++)
		  if(S_A[j][i]=='w'){
		     for(int k=0;k<=numvar-1;k++){ //recorre la columna contanto cuantas variables a,c,g,t hay
				 if(S_A[k][i]=='a')
					 counta+=1;
				 if(S_A[k][i]=='c')
					 countc+=1;
				 if(S_A[k][i]=='g')
					 countg+=1;
				 if(S_A[k][i]=='t')
					 countt+=1;
			}
				if(hibrid[0][i]!= counta) //compara con los valores presentes, si en alguna falta una letra la pone en vez de w
					S_A[j][i]='a';
				else if(hibrid[1][i] != countc)
					S_A[j][i]='c';
				else if(hibrid[2][i] != countg)
					S_A[j][i]='g';
				else
					S_A[j][i]='t';
		  }
  }



  //cout<<"Impresion S(A)"<<"\n";

  for(int i=0;i<=numvar-1;i++){
	  for(int j=0;j<=tamtruemotif-1;j++){
		cout<<S_A[i][j]<<" ";
		if(S_A[i][j]=='w')
			cin.get();
	  }
	cout<<"\n";
  }
  //Sleep(2000);
}

int Individuo::fitnessLV(string a,int punt){
	int position=0;
	int tam2= a.length();
	int minimo=0,count=0;
	int k=0,y=0;
	char b[tamtruemotif];
	if(a.length()==tamtruemotif){
		minimo=Distancia_H(a,punt);
		position=k;
	}else{
		while((y+tamtruemotif)<=tam2-1){
			for(int j=0;j<=tamtruemotif-1;j++){
				b[j]=a[j+k];	
			}
			count=Distancia_H(b,punt);
			if(count<minimo || y==0){
				minimo=count;
				position=k;
			}
			y++;
			k++;
		}
	}
	//(*this).fitness=minimo;
return position;
}

int Individuo::Distancia_H(string a,int punt){
int Hamming[tamtruemotif+1][tamtruemotif+1];
for(int i=0;i<=tamtruemotif-1;i++) for(int j=0;j<=tamtruemotif-1;j++) Hamming[i][j]=0;
for(int i=0;i<=tamtruemotif-1;i++) Hamming[0][i]=Hamming[i][0]=i;
for(int i=1;i<=tamtruemotif-1;i++)
	for(int j=1;j<=tamtruemotif-1;j++){
		if((*this).S_A[punt][i-1]==a[j-1])//(*this).crom.genes[i-1])
			Hamming[i][j]=Hamming[i-1][j-1];
		else
			Hamming[i][j]=minimo(1+Hamming[i-1][j],1+Hamming[i][j-1],1+Hamming[i-1][j-1]);
	}
/*for(int i=0;i<=numvar;i++) {
	for (int j=0;j<=numvar;j++) 
		cout<< Hamming[i][j];
	cout<<"\n";
}*/
return Hamming[tamtruemotif-1][tamtruemotif-1];
}

