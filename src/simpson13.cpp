#include "simpson13.h"
#include <iostream>
using namespace std;

/// Constructor
simpson13::simpson13()
{

    er1:

    cout << "Numero de datos a ingresar"<<endl;

    cin >> n_;
    if(((n_ % 2) !=0) &&  (n_ >=2)){
        cout <<"El numero de datos debe ser par y mayor o igual a 2"<<endl;
        goto er1;
    }

    tabla_ = new float *[n_];
    for(int i=0; i<n_; i++){
        tabla_[i] =new float[2];
    }

    //carga(tabla);
    charger(n_, tabla_);

}

simpson13::~simpson13()
{
    //dtor
    for(int i=0; i<n_; i++)
        delete tabla_[i];
    delete tabla_;

}

/*
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
*/

/// algoritmo de  simpson 1/3
/// para tabla de datos procesados
void simpson13::method(int n,float **tabla, int verbose){

    /// parametro  n numero de datos
    /// importante
    /// parametro referencia de la tabla
    /// parametro a, b limites de integracion

    float sipar =0.0;
    float nopar =0.0;
    float h = (tabla[n-1][0] -tabla[0][0]  )/ (float)n;

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
  //  return (h/3.0)*( tabla[0][1]  + (4 * nopar) + (2 * sipar)  + tabla[n -1][1]) ;
  area_  = (h/3.0)*( tabla[0][1]  + (4 * nopar) + (2 * sipar)  + tabla[n -1][1]) ;
}


void simpson13::charger(int n, float **tabla){

    float Dif =0.0;
    float Aux =0.0;
    int cargado =0;

    /// "Se cargan minimo 2 y al tercero se coparar con la diferencia "
    for (int i =0;i<n;i++){
        for (int j =0;j<2;j++){
                pato:
                cout << "("<<i<<", "<<j<<"):";
                cin >> tabla[i][j];

                /// Comparativa
                if( i > 0 ) {
                        if (!cargado) {
                                Dif = tabla[1][0] -  tabla[0][0];
                        }
                    }
                    /// comparar siguiente carga

                if(i >1 ){
                      Aux = tabla[i][0] -tabla[i-1][0]  ;
                      if(Aux != Dif){
                            cout << "reingresa datos con el mismo intervalo"<< Dif<<"<>" <<Aux<<endl;
                      goto pato;
                      }
                }

                }
            }
      viewTable(n, tabla);

}


void simpson13::viewTable(int n ,float **tabla){
    cout << "\t| x\t| fx|"<<endl;
        for (int i =0;i<n;i++){
                for (int j =0;j<2;j++){
            cout << "\t| "<< tabla[i][j];
            }
        cout <<"|"<<endl;
        }
}
