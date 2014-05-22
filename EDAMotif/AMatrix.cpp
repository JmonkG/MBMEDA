#include "AMatrix.h"
#include "Individuo.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
const double PI=3.141592;
using namespace std;

void  AMatrix::Cholesky(double Matriz[dimm][dimm],int fil,int col){
	double L[dimm][dimm];
	double suma=0;
	for(int i=0;i<=fil-1;i++){
		for(int j=0;j<=col-1;j++)
			L[i][j]=0.0;
	}
	for(int i=0;i<=dimm-1;i++){
		for(int k=0;k<=i-1;k++)
			suma+=(L[k][i]*L[k][i]);
		L[i][i]=sqrt(Matriz[i][i]-suma);
		suma=0.0;
		for(int j=i+1;j<=dimm-1;j++){
			for(int k=0;k<=i-1;k++)
				suma+=L[k][i]*L[k][j];
			L[i][j]=(1/L[i][i])*(Matriz[i][j]-suma);
			suma=0.0;
		}
		suma=0.0;
	}
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			Sigma_Chol[i][j]=L[i][j];
			cout<<L[i][j]<<" ";
		}
		cout<<"\n";
	}

	//return 1;
}
void AMatrix::BoxMullerTransform(double V[dimm]){
	double u1,u2;
	for(int i=0;i<=dimm-1;i+=2){
			u1=rand()%100+0;
			u1=u1/100;
			u2=rand()%100+0;
			u2=u2/100;
			V[i]=sqrt(-2*log(u1))*cos(2*PI*u2);
			if(i+1<=dimm-1)
				V[i+1]=sqrt(-2*log(u1))*sin(2*PI*u2);
	}
	for(int i=0;i<=dimm-1;i++)
		cout<<V[i]<<" ";
	cout<<"\n";
	
}
void AMatrix::CrearIndividuos(double Matriz[dimm][dimm]){

	for(int i=0;i<=nemg-1;i++){
		(*this).BoxMullerTransform((*this).boxmull);
		(*this).Suma(Matriz,boxmull);
		for(int j=0;j<=dimm;j++)
			nuevin[i][j]=Muu[j]+result[j];
	}

}
void AMatrix::Suma(double Matriz[dimm][dimm],double V[dimm]){
	double mult=0;
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++)
			mult+=Matriz[i][j]*V[j];
		result[i]=mult;
		mult=0;
	}
	for(int i=0;i<=dimm-1;i++)
		cout<<result[i]<<" ";
	cout<<"\n";
}
//falta dividir para el numero de individuos
//la formula original es 1/T sumatoria(xi)..
void AMatrix::Mean(double H1[dimm],double H2[dimm],double H3[dimm],double H4[dimm],double Mu[dimm],int numeroindividuos){
   double buffer[dimm];
   double buff2[tamtruemotif];
   for(int i=0;i<=dimm-1;i++){
		buffer[i]=H1[i]+H2[i]+H3[i]+H4[i];
		buffer[i]=buffer[i]/numeroindividuos;
		Mu[i]=buffer[i];
		cout<<Mu[i]<<"\n";
   }
  cout<<"\n";

	
}
void AMatrix::Mean(){
  double buff2[dimm];
  for(int i=0;i<=dimm-1;i++){
	  buff2[i]=0;
	for(int j=0;j<=nemg-1;j++)
	  buff2[i]+=arr[j][i];
	buff2[i]=buff2[i]/nemg;
	(*this).Muu[i]=buff2[i];
  }

}
void AMatrix::CoVariance(){
	double cov[dimm][dimm];
	double covbf[dimm][dimm];
	int y=0;
	for(int i=0;i<=dimm-1;i++)
		for(int j=0;j<=dimm-1;j++)
			cov[i][j]=0.0;
	while(y!=nemg){

		// CALCULA la COV
	  for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			covbf[i][j]=((*this).arr[y][i]-Muu[i])*(arr[y][j]-Muu[j]);
			cout<<covbf[i][j]<<" ";
		}
		  cout<<"\n";
		}
	  //LO suma al final
	  for(int i=0;i<=dimm-1;i++)
		for(int j=0;j<=dimm-1;j++){
			cov[i][j]+=(covbf[i][j]); 
			cout<<cov[i][j]<<" ";
		}
		cout<<"\n";

		y++;
	}
	for(int i=0;i<=dimm-1;i++)
	 for(int j=0;j<=dimm-1;j++)
		//Sigma[i][j]=cov[i][j]/(nemg-1); // el factor nemg-1 es utilizado cuando no se considera bajo ninguna distribucion
		Sigma[i][j]=cov[i][j]/(nemg);
}
void AMatrix::CoVariance(double H1[dimm],double H2[dimm],double H3[dimm],double H4[dimm],double Mu[dimm]){

	double cov[dimm][dimm];
	double covbf[dimm][dimm];
	double cov2[dimm][dimm];
	double cov3[dimm][dimm];
	double cov4[dimm][dimm];
   int y=0;


	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			cov[i][j]=(H1[i]-Mu[i])*(H1[j]-Mu[j]);
			cout<<cov[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			cov2[i][j]=(H2[i]-Mu[i])*(H2[j]-Mu[j]);
			cout<<cov2[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			cov3[i][j]=(H3[i]-Mu[i])*(H3[j]-Mu[j]);
			cout<<cov3[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			cov4[i][j]=(H4[i]-Mu[i])*(H4[j]-Mu[j]);
			cout<<cov4[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0;i<=dimm-1;i++){
		for(int j=0;j<=dimm-1;j++){
			cov[i][j]+=(cov2[i][j]+cov3[i][j]+cov4[i][j]); // 3 es el no. de elementos -1
			cov[i][j]=cov[i][j]/3;
			cout<<cov[i][j]<<" ";
		}
		cout<<"\n";
	}
 
	(*this).Cholesky(cov,3,3);

}


/******************************************************************************/
/* randn()
 * 
 * Normally (Gaussian) distributed random numbers, using the Box-Muller 
 * transformation.  This transformation takes two uniformly distributed deviates
 * within the unit circle, and transforms them into two independently 
 * distributed normal deviates.  Utilizes the internal rand() function; this can
 * easily be changed to use a better and faster RNG.
 * 
 * The parameters passed to the function are the mean and standard deviation of 
 * the desired distribution.  The default values used, when no arguments are 
 * passed, are 0 and 1 - the standard normal distribution.
 * 
 * 
 * Two functions are provided:
 * 
 * The first uses the so-called polar version of the B-M transformation, using
 * multiple calls to a uniform RNG to ensure the initial deviates are within the
 * unit circle.  This avoids making any costly trigonometric function calls.
 * 
 * The second makes only a single set of calls to the RNG, and calculates a 
 * position within the unit circle with two trigonometric function calls.
 * 
 * The polar version is generally superior in terms of speed; however, on some
 * systems, the optimization of the math libraries may result in better 
 * performance of the second.  Try it out on the target system to see which
 * works best for you.  On my test machine (Athlon 3800+), the non-trig version
 * runs at about 3x10^6 calls/s; while the trig version runs at about
 * 1.8x10^6 calls/s (-O2 optimization).
 * 
 * 
 * Example calls:
 * randn_notrig();	//returns normal deviate with mean=0.0, std. deviation=1.0
 * randn_notrig(5.2,3.0);	//returns deviate with mean=5.2, std. deviation=3.0
 * 
 * 
 * Dependencies - requires <cmath> for the sqrt(), sin(), and cos() calls, and a
 * #defined value for PI.
 */

/******************************************************************************/
//	"Polar" version without trigonometric calls
double AMatrix::randn_notrig(double mu, double sigma) {//(double mu=0.0, double sigma=1.0) {
	static bool deviateAvailable=false;	//	flag
	static float storedDeviate;			//	deviate from previous calculation
	double polar, rsquared, var1, var2;
	
	//	If no deviate has been stored, the polar Box-Muller transformation is 
	//	performed, producing two independent normally-distributed random
	//	deviates.  One is stored for the next round, and one is returned.
	if (!deviateAvailable) {
		
		//	choose pairs of uniformly distributed deviates, discarding those 
		//	that don't fall within the unit circle
		do {
			var1=2.0*( double(rand())/double(RAND_MAX) ) - 1.0;
			var2=2.0*( double(rand())/double(RAND_MAX) ) - 1.0;
			rsquared=var1*var1+var2*var2;
		} while ( rsquared>=1.0 || rsquared == 0.0);
		
		//	calculate polar tranformation for each deviate
		polar=sqrt(-2.0*log(rsquared)/rsquared);
		
		//	store first deviate and set flag
		storedDeviate=var1*polar;
		deviateAvailable=true;
		
		//	return second deviate
		return var2*polar*sigma + mu;
	}
	
	//	If a deviate is available from a previous call to this function, it is
	//	returned, and the flag is set to false.
	else {
		deviateAvailable=false;
		return storedDeviate*sigma + mu;
	}
}


/******************************************************************************/
//	Standard version with trigonometric calls
#define PI 3.14159265358979323846

double AMatrix::randn_trig(double mu, double sigma) {
	static bool deviateAvailable=false;	//	flag
	static float storedDeviate;			//	deviate from previous calculation
	double dist, angle;
	
	//	If no deviate has been stored, the standard Box-Muller transformation is 
	//	performed, producing two independent normally-distributed random
	//	deviates.  One is stored for the next round, and one is returned.
	if (!deviateAvailable) {
		
		//	choose a pair of uniformly distributed deviates, one for the
		//	distance and one for the angle, and perform transformations
		dist=sqrt( -2.0 * log(double(rand()) / double(RAND_MAX)) );
		angle=2.0 * PI * (double(rand()) / double(RAND_MAX));
		
		//	calculate and store first deviate and set flag
		storedDeviate=dist*cos(angle);
		deviateAvailable=true;
		
		//	calcaulate return second deviate
		return dist * sin(angle) * sigma + mu;
	}
	
	//	If a deviate is available from a previous call to this function, it is
	//	returned, and the flag is set to false.
	else {
		deviateAvailable=false;
		return storedDeviate*sigma + mu;
	}
}

double AMatrix::media(int N, double valores[]){
   double miu=0;
	for(int i=0;i<=N-1;i++)
		miu+=valores[i];
	return miu/N;

}
void AMatrix::media(){
   double miu=0;
	for(int i=0;i<=nemg-1;i++)
		for(int j=0;j<=dimm-1;j++)
			miu+=arr[i][j];
	smuu= miu/(nemg*dimm);

}
double AMatrix::varianza(int N,double media,double valores[]){
 double varia=0;
  for(int i=0;i<=N-1;i++)
	  varia+=pow((valores[i]-media),2);
  return varia/(N-1);
}
void AMatrix::varianza(){
 double varia=0;
  	for(int i=0;i<=nemg-1;i++)
		for(int j=0;j<=dimm-1;j++)
			varia+=pow((arr[i][j]-smuu),2);
  svari = varia/((nemg*dimm)-1);
}