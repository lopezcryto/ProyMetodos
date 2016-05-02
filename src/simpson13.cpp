#include "simpson13.h"

simpson13::simpson13()
{
    //ctor
}

simpson13::~simpson13()
{
    //dtor
}


/// algoritmo de  simpson 1/3
/// para tabla de datos procesados
double simpson13D(){

    // parametro  n numero de datos
    /// importante
    // parametro referencia de la tabla
     // parametro a, b limites de integracion

     // Sumatoria de impares
     int i =1;
     int j =1;

     double impar =0;
        while(j <= (n-1) ){
                ///// operacion a realizar en suma
                // cout << a << endl;
                impar +=  tabla[1][j];
        j = 2*(i)+1;
        i++;
        }

     double par = 0 ;
     // Sumatoria de 2
      i =2;
      j =2;

        while(j < (n-2) ){
                ///// operacion a realizar en suma
                // cout << a << endl;
                par +=  tabla[1][j];
        j = 2*(i);
        i++;
        }

    /// a y b los podemos sacar de la tabla
    // double  h = ( tabla[0][n-1] -tabla[0][0])/ n;
    double h = (b- a)/ n;


  return (h/3.0)*(tabla[1][0] + 4*(impar) + 2*(par) +  tabla[1][n-1]);
}
