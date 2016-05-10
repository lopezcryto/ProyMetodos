#include "Lagrange.h"
#include <iostream>
using namespace std;

Lagrange::Lagrange()
{
    //ctor
    int k;
char salir;
do{
    cout<<" \t Numero de datos\n K:";

    cin >> k;

    cout<<"C>\n ";

    float lista[k][2];

        for(int i=0; i< k; i++){
            for(int j=0;j <2; j++){
                if(j ==0) cout << "X_"<<i<<endl;
                    else cout << "Fx_"<<i<<endl;
                cin >> lista[i][j];
            }
        }


        cout <<"Tabla de datos"<< endl;
        cout <<"\t x \t fx"<< endl;
        for(int i=0; i< k; i++){
                cout <<"\t|";
            for(int j=0;j <2; j++){
                cout << lista[i][j]<< "\t ";
            }
            cout <<"|"<< endl;
        }



     do{
            cout << "Valor a interpolar X':";
            float x = 0.0;
            cin >> x;

            cout << "X'="<< metodo(x, k,lista)<< endl;

            cout << " otro  X'[esc-> no | s ->si]:";
            cin >> salir;
     }while(salir != 27);
     salir = 1;

     cout << "Cargar Nuevos datos [esc-> no | s ->si]:";
     cin >>salir;
}while(salir != 27);


}

Lagrange::~Lagrange()
{
    //dtor
}

/*

 x que se quiere interpolar
 k total de registros
 j Indice de base de producto
 _lista matrix de kx2

 */

float Lagrange::L(float x, int k, int j, float _lista[][2])
{


    float producto =1.0;

    for(int i=0; i < k; i++ )
        {
            if(i!= j) {
                    producto *= ( x - _lista[i][0])/(_lista[j][0] - _lista[i][0]);
            cout << "( x -"<< _lista[i][0] <<")/("<< _lista[j][0]<<" - "<<_lista[i][0]<<")";

            }


        }

    return producto;
}

/**

Metodo de lagrange

**/
float Lagrange::metodo(float x,int k, float _lista[][2])
{


    float suma ;

    suma = (float)0.0;

    for (int j =0; j < k; j++)
    {
        suma += _lista[j][1]*L(x, k, j, _lista);
    }

    return suma;

    }
