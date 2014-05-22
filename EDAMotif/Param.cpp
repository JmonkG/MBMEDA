#include "Param.h"

//Param={algoritmo,tamaño poblacion,tasa de mutacion, tasa de cruce, operador de mutacion, operador de cruce, operador de seleccion,tammotif,numvar}
void Param::SetParametros(double P[9]){
	(*this).algorithm=P[0];
	(*this).numind=P[1];
	(*this).tamtruemotif=P[7];
	(*this).numvar=P[8];
	(*this).pc=P[3];
	(*this).pm=P[2];
	(*this).tipoMutacion=P[4];
	(*this).tipoCruce=P[5];
	(*this).opSeleccion=P[6];

}
		int Param::get_algorithm(){return (*this).algorithm;}
		int Param::get_numind(){return (*this).numind;}
		int Param::get_numvar(){return (*this).numvar;}
		int Param::get_tipoCruce(){return (*this).tipoCruce;}
		int Param::get_tipoMutacion(){return (*this).tipoMutacion;}
		int Param::get_TamMotif(){return (*this).tamtruemotif;}
		int Param::get_opSeleccion(){return (*this).opSeleccion;}
		double Param::get_pc(){return (*this).pc;}
		double Param::get_pm(){return (*this).pm;}
		void Param::set_algorith(int a){(*this).algorithm=a;}
		void Param::set_numind(int a){(*this).numind=a;}
		void Param::set_numvar(int a){(*this).numvar=a;}
		void Param::set_tipoCruce(int a){(*this).tipoCruce=a;}
		void Param::set_tipoMutacion(int a){(*this).tipoMutacion=a;}
		void Param::set_opSeleccion(int a){(*this).opSeleccion=a;}
		void Param::set_pc(double a){(*this).pc=a;}
		void Param::set_pm(double a){(*this).pm=a;}
		void Param::set_TamMotif(int a){(*this).tamtruemotif=a;}