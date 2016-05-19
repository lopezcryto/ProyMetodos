#include "simpson13.h"
#include <iostream>
using namespace std;

simpson13::simpson13()
{
    //ctor
    er1:
    cout << "Numero de datos a ingresar"<<endl;

    cin >> n;
    if(((n % 2) !=0) &&  (n >=2)){
        cout <<"El numero de datos debe ser par y mayor o igual a 2"<<endl;
        goto er1;
    }

    tabla = new float *[n];
    for(int i=0; i<n; i++){
        tabla[i] =new float[2];
    }

    carga(tabla);
}

simpson13::~simpson13()
{
    //dtor
}


/// algoritmo de  simpson 1/3
/// para tabla de datos procesados
float simpson13::simpson13f_verbose(int n, float a, float b , float **tabla){

    /// parametro  n numero de datos
    /// importante
    /// parametro referencia de la tabla
    /// parametro a, b limites de integracion

    float sipar =0.0;
    float nopar =0.0;
    float h = (b - a )/ (float)n;
    cout << "h="<< h<<endl;

    int i =1;
    while (i<n){

        if((i % 2) ==0){
          sipar += tabla[i][1];
          cout << i<<": "<< tabla[i][1] <<endl;
        }
        i++;

    }

    i =1;
    cout << "______"<< endl ;

    while (i<n){

        if((i % 2) !=0){
          nopar += tabla[i][1];
          cout << i<<": "<< tabla[i][1] <<endl;
        }
        i++;

    }
    cout << "("<<h<<"/3.0)*( "<<tabla[0][1]<<"  + (4 * "<<nopar<<") + (2 * "<<sipar<<")  + "<<tabla[n-1][1]<<")"
         << (h/3.0)*( tabla[0][1]  + (4 * nopar) + (2 * sipar)  + tabla[n-1][1])  <<endl;

    return (h/3.0)*( tabla[0][1]  + (4 * nopar) + (2 * sipar)  + tabla[n-1][1]) ;
}


/// algoritmo de  simpson 1/3
/// para tabla de datos procesados
float simpson13::simpson13f(int n, float a, float b , float **tabla){

    /// parametro  n numero de datos
    /// importante
    /// parametro referencia de la tabla
    /// parametro a, b limites de integracion

    float sipar =0.0;
    float nopar =0.0;
    float h = (b - a )/ (float)n;

    int i =1;
    while (i<n){

        if((i % 2) ==0){
          sipar += tabla[i][1];

        }
        i++;

    }

    i =1;

    while (i<n){

        if((i % 2) !=0){
          nopar += tabla[i][1];
        }
        i++;

    }

    return (h/3.0)*( tabla[0][1]  + (4 * nopar) + (2 * sipar)  + tabla[n -1][1]) ;
}


void simpson13::carga(float **tabla){

    float dif1 =0.0;
    float difAux =0.0;
    /// "Se cargan minimo 2 y al tercero se coparar con la diferencia "
    for (int i =0;i<n;i++){
        for (int j =0;j<2;j++){
                pato:
                cout << "("<<i<<", "<<j<<"):";
                cin >> tabla[i][j];
                /// Comparativa
                if( i >= 1 ) {
                     dif1 = tabla[1][0] -  tabla[0][0];
                    }

                if(i >=2 ){
                      difAux = tabla[i-1][0] -tabla[i][0] ;
                      if(dif1 != difAux){
                            cout << "reingresa datos con el mismo intervalo"<< dif1<<"<->" <<difAux<<endl;
                      goto pato;

                      }

                }

                }
            }

            for (int i =0;i<n;i++){
        for (int j =0;j<2;j++){
            cout << "   "<< tabla[i][j];
            }
        cout <<endl;
        }
}
