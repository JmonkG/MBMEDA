#include <cmath>
#include <fstream>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstdlib> 
#include <string>
#include "Base.h"
using namespace std;

Base&  Base::operator=(Base &p)	{
	for(int i=0; i<= tambase-1; i++)
		(*this)[i] = p[i];
	return *this;
}
void Base::calc_prob(){
pa=pc=pg=pt=0.00;
for(int i=0;i<=tambase-1;i++)
	for(int j=0;j<=longgen-1;j++){
			if(Genoma[i][j]=='a')
				pa++;
			if(Genoma[i][j]=='c')
				pc++;
			if(Genoma[i][j]=='g')
				pg++;
			if(Genoma[i][j]=='t')
				pt++;
	}
	pa=pa/(tambase*longgen);
	pc=pc/(tambase*longgen);
	pg=pg/(tambase*longgen);
	pt=pt/(tambase*longgen);
	//cout<<"pa:"<<pa<<"\n";
	//cout<<"pc:"<<pc<<"\n";
	//cout<<"pg:"<<pg<<"\n";
	//cout<<"pt:"<<pt<<"\n";
	//cin.get();
}
void Base::Construir(){
  //ifstream myfile ("CRP105bp18secNew.txt");
  ifstream myfile ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\base.txt");
  //ifstream myfile ("C:\\Users\\cjordan\\Documents\\Tesis\\EDA\\EDA - Motif\\EDA - Motif\\base.txt");
  int count=0;
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
		getline (myfile,(*this).Genoma[count]);
	  //cout << Genoma[count]<< endl;
	  count++;
    }
	
    myfile.close();
  }else cout << "Unable to open file 1"; 
  (*this).longgen=Genoma[0].length();
  (*this).tambase=count-1;
  calc_prob();
  ifstream myfile2 ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\inter.txt");
  //ifstream myfile2 ("C:\\Users\\cjordan\\Documents\\Tesis\\EDA\\EDA - Motif\\EDA - Motif\\inter.txt");
  count=0;
  if (myfile2.is_open())
  {
    while (! myfile2.eof() )
    {
		getline (myfile2,strConvert);
		(*this).postmotivo[count]=atoi(strConvert.c_str());
	  //cout << Genoma[count]<< endl;
	  count++;
    }
	
    myfile2.close();
  }else cout << "Unable to open file2"; 
  /* ifstream myfile3 ("C:\\Users\\cjordan\\Documents\\Tesis\\RMF\\RMF\\motifsCRP.txt");
 // ifstream myfile3 ("C:\\Users\\cjordan\\Documents\\Tesis\\EDA\\EDA - Motif\\EDA - Motif\\motifsCRP.txt");
 count=0;
 if (myfile3.is_open())
  {
    while (! myfile3.eof() )
    {
		getline (myfile3,Motifreal[count]);
		for(int i=0;i<=Motifreal[count].length();i++)
			Motifreal[count][i]=tolower(Motifreal[count][i]);
	  //cout << Motifreal[count]<< endl;
	  count++;
    }
    myfile3.close();
	(*this).nmotifsreales=count-1;
  }else cout << "Unable to open file3"; */

}