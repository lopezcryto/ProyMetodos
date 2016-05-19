#include "simpson38.h"
#include <iostream>
using namespace std;


simpson38::simpson38()
{
    //ctor
}

simpson38::~simpson38()
{
    //dtor
}


float simpson38f(int n, float a, float b, float tabla[][2]){


    float h = (b -a)/ (float)n;

    cout << "h="<< h <<endl ;


    float sum1 =0.0;

    float sum2 = 0.0;

    for(int i=1; i<n; i++){
        if((i % 3) ==0){
            sum1 += (2* tabla[i][1]);
            cout << (2* tabla[i][1])<< endl;


        }else{
            sum2 += (3* tabla[i][1]);
            cout << (2* tabla[i][1])<< endl;
        }
    }
    cout << "(0.375)*"<< h << "*( "<< tabla[0][1] <<" +  "<<tabla[n-1][1]<<" + "<<sum1
    <<" + "<<sum2<<")="<< (0.375)*h*(tabla[0][1] +  tabla[n-1][1] + sum1 + sum2) <<endl;


    return (0.375)*h*(tabla[0][1] +  tabla[n-1][1] + sum1 + sum2);

}




float simpson38f_verbose(int n, float a, float b, float tabla[][2]){


    float h = (b -a)/ (float)n;


    float sum1 =0.0;

    float sum2 = 0.0;

    for(int i=1; i<n; i++){
        if((i % 3) ==0){
            sum1 += (2* tabla[i][1]);

        }else{
            sum2 += (3* tabla[i][1]);
        }
    }

    return (0.375)*h*(tabla[0][1] +  tabla[n-1][1] + sum1 + sum2);

}
