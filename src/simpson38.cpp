#include "simpson38.h"
#include <iostream>
using namespace std;


simpson38::simpson38()
{
    er1:
    cout << "Número de datos a ingresar"<<endl;
    cin >> n_;
    //if(((n_ % 3) !=0) &&  (n_ >=3)){
        cout <<"El numero de datos debe ser factor de 3 y mayor o igual a 3"<<endl;
      //  goto er1;
    //}

    tabla_ = new float *[n_];
    for(int i=0; i<n_; i++){
        tabla_[i] =new float[2];
    }

    charger(n_, tabla_);
    method(n_, tabla_, 0);



    cout << "El Area bajo la curva es:"<< area_  ;

    cout << "Otra vez?[s/n]";
    char a;
    cin >> a;
    if (a == 's')  goto er1;


}

/// DEstructor
simpson38::~simpson38()
{

    //tabla = new float *[n];
    for(int i=0; i<n_; i++){
        //tabla[i] =new float[2];
        delete tabla_[i];
    }
    delete tabla_;

}


/*
    Implementacion de simpson 3/8
    la entrada se define en sus parametros
    n como el numero de datos de la tabla
    y la tabla
*/
void simpson38::method(int n,float **tabla, int verbose){

    /// h = (b-a)/n
    float h = (tabla[n-1][0] -tabla[0][0])/ (float)n;

    if (verbose)cout << "h="<< h <<endl ;


    float sum1 =0.0;

    float sum2 = 0.0;

    for(int i=1; i<n; i++){
        if((i % 3) ==0){
            sum1 += (2* tabla[i][1]);
            if (verbose)cout << (2* tabla[i][1])<< endl;


        }else{
            sum2 += (3* tabla[i][1]);
            if (verbose)cout << (2* tabla[i][1])<< endl;
        }
    }
    if (verbose)cout << "(0.375)*"<< h << "*( "<< tabla[0][1] <<" +  "<<tabla[n-1][1]<<" + "<<sum1
    <<" + "<<sum2<<")="<< (0.375)*h*(tabla[0][1] +  tabla[n-1][1] + sum1 + sum2) <<endl;


    //return (0.375)*h*(tabla[0][1] +  tabla[n-1][1] + sum1 + sum2);
    area_ = (0.375)*h*(tabla[0][1] +  tabla[n-1][1] + sum1 + sum2);

}


void simpson38::charger(int n, float **tabla) {

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
                            cout << "Reingresa datos con el mismo intervalo("<< Dif<<"!=" <<Aux<<")"<<endl;
                      goto pato;
                      }
                }

                }
            }

            viewTable(n, tabla);
}

void simpson38::viewTable(int n ,float **tabla){
    cout << "\t| x\t| fx|"<<endl;
        for (int i =0;i<n;i++){
                for (int j =0;j<2;j++){
            cout << "\t| "<< tabla[i][j];
            }
        cout <<"|"<<endl;
        }
}
