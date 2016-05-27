#include "DifDiv.h"
#include "unamGUI.h"
#include <cstdlib>
#include <iostream>
using namespace std;
DifDiv::DifDiv()
{



            double datos[_n_][_n_+1],rest;

            int no;
            do
            {
                cout << " \n\n\n\n\nCuantos datos vas a ingresar [3-10]: ";
                cin >> no;
                cout <<"Los datos respecto a X deben ser ingresados en orden ascendente\n";

            }while(no<3||no>10);
            tabula1(datos,no);
            Diferencias(datos,no);
            do
            {
                cout <<"\n\nQue valor desea encontrar: ";
                cin >> rest;
            }while(rest<datos[0][0]||rest>datos[no-1][0]);
            Divididas(datos,no,rest);


            system(Limpantalla);
            //opcion=-1;

}

DifDiv::~DifDiv()
{
    //dtor
}

void DifDiv::tabula1(double a[_n_][_n_+1],int xs)
{
    int i;

    cout <<"\tX\t||\tY\n";
    cout <<"============================\n";
    for(i=0;i<xs;i++)
    {
        do
        {
            cout <<"\tx="<< i <<"\n";
            cin >>a[i][0];
        }while(a[i][0]<=a[i-1][0]&&i!=0);
        cout << "\t\t||\ty="<< i;
        cin >>a[i][1];
    }
}

void DifDiv::Diferencias(double a[_n_][_n_+1],int xs)
{
   // int k=0;
    for(int i=1;i<xs;i++)
    {
        for(int j=0;j<xs-i;j++)
        {
            a[j][i+1]=(a[j+1][i]-a[j][i])/(a[j+i][0]-a[j][0]);
        }
    }

}


void  DifDiv::Divididas(double a[_n_][_n_+1],int xs,double val)
{
    double res;
    int j,t;
    for(int i=0;i<xs-1;i++)
    {
        if(val>a[i][0]&&val<a[i+1][0])
        {
            t=i;
            i=xs;
        }
    }
    if(t<xs/2)
    {
        res=a[t][xs-t];
        for(int i=xs-t;i>1;i--)
        {


    cout <<"\n\n"<<res<<" * ("<<val<<" - "<<a[i+t-2][0]<<") + "<<a[t][i-1]<<" = ";
    res=res*(val-a[i+t-2][0])+a[t][i-1];
    cout  << res << endl;
        }
    }
    else
    {
        res=a[0][2+t];
        for(int i=t+2,j=0;j<t+1;i--,j++)
        {

            cout <<"\n\n"<<res<<" * ("<<val<<" - "<< a[j+1][0]<<") + "<< a[j+1][i-1]<<" = ";
            res=res*(val-a[j+1][0])+a[j+1][i-1];
            cout << res;

        }
    }
    cout <<"\nEl resultado de la aproximacion es:"<< res<< endl;

}
