#ifndef _PARAM_H
#define _PARAM_H


class Param {
public:
		int algorithm;
		int numind;
		int numvar;
		double pc;
		double pm;
		int tipoCruce;
		int tipoMutacion;
		int opSeleccion;
		int tamtruemotif;

		void SetParametros(double P[9]);
		int get_algorithm();
		int get_numind();
		int get_numvar();
		int get_tipoCruce();
		int get_tipoMutacion();
		int get_opSeleccion();
		int get_TamMotif();
		void set_TamMotif(int a);
		double get_pc();
		double get_pm();
		void set_algorith(int a);
		void set_numind(int a);
		void set_numvar(int a);
		void set_tipoCruce(int a);
		void set_tipoMutacion(int a);
		void set_opSeleccion(int a);
		void set_pc(double a);
		void set_pm(double a);

};


#endif
