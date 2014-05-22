#include "Quicksort.h"
#include "Individuo.h"
#include "Poblacion.h"

using std::cout;
using std::endl;
using std::setw;

using namespace std;
const int tamano = 100, MAXIMO = 1000;

/*int main()
{
  Quicksort q;	
  int arregloAordenar[ tamano ] = { 0 };
  int loop;
  srand( time( 0 ) );
  for ( loop = 0; loop < tamano; ++loop )
    arregloAordenar[ loop ] = rand() % MAXIMO;
  cout << "Los valores del arreglo antes de ordenarse son:\n";
  for ( loop = 0; loop < tamano; ++loop )
    cout << setw( 4 ) << arregloAordenar[ loop ];
  cout << "\n\n";
  if ( tamano == 1 )
    cout << "El arreglo esta ordenado: " << arregloAordenar[ 0 ] << '\n';
  else {
	//invocar Quicksort
    //q.quicksort( arregloAordenar, 0, tamano - 1 );
    cout << "Los valores del arreglo ordenado son:\n";
    for ( loop = 0; loop < tamano; ++loop )
      cout << setw( 4 ) << arregloAordenar[ loop ];
    cout << endl;
  }
  cin.get();
  return 0;
}*/

int maina(){
srand( time( 0 ) );
Base b;
b.Construir();
Individuo buff[200];
for(int i=0;i<=199;i++){
	buff[i].Construir(b.longgen,b);
	buff[i].nwin=rand()%10+0;
}
Quicksort q;
for(int i=0;i<=199;i++)
	cout<<buff[i].nwin<<" ";
cin.get();
q.quicksort(buff,0,200-1);
for(int i=0;i<=199;i++)
	cout<<buff[i].nwin<<" ";
cin.get();
return 0;
}
void Quicksort::quicksort( Individuo arreglo[tamano], int first, int last )
{
  int posicionActual;
  if ( first >= last ) //cuando es solo 1 elemento
    return;
  posicionActual = particion( arreglo, first, last );
  quicksort( arreglo, first, posicionActual - 1 );   
  quicksort( arreglo, posicionActual + 1, last );    
}
int Quicksort::particion( Individuo arreglo[tamano], int izquierda, int derecha )
{
  Individuo inv;
  int posicion = izquierda;
  while ( true ) {
    //por la derecha
	  while ( arreglo[ posicion ].nwin >= arreglo[ derecha ].nwin && posicion != derecha )
      --derecha;
    if ( posicion == derecha )
      return posicion;
    if ( arreglo[ posicion ].nwin < arreglo[ derecha ].nwin) {
      //swap( &arreglo[ posicion ], &arreglo[ derecha ] );
		inv=arreglo[posicion];
		arreglo[posicion]=arreglo[derecha];
		arreglo[derecha]=inv;
      posicion = derecha;
    }
	//por la izquierda
	while ( arreglo[ izquierda ].nwin >= arreglo[ posicion ].nwin && izquierda != posicion )
      ++izquierda;
    if ( posicion == izquierda )
      return posicion;
	if ( arreglo[ izquierda ].nwin < arreglo[ posicion ].nwin ) {
      //swap( &arreglo[ posicion ], &arreglo[ izquierda ] );
		inv= arreglo[posicion];
		arreglo[posicion]=arreglo[izquierda];
		arreglo[izquierda]=inv;
      posicion = izquierda;
    }
  }
}
void Quicksort::swap( int * const ptr1, int * const ptr2 )
{
  int temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}