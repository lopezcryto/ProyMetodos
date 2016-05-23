#include "RegresionLineal.h"
#include "unamGUI.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <sstream>


using namespace std;

RegresionLineal::RegresionLineal()
{
    //ctor
    cout<<"\n\n   =Metodo de minimos cuadrados polinomial="<<endl<<"\n   ";
    system(Pausa);
    do
    {
        system (Limpantalla);
        int nDatos,grado;
        bool op=false;
        string entrada;
        while(true)
        {
            cout<<"\n\tIntroduce la cantidad de puntos que vas a ingresar: ";
            getline(cin,entrada);
            stringstream mystream(entrada);
            if (mystream>>nDatos)
                break;
            cout<<"\n\tEntrada invalida."<<endl;
        }
        double *X=new double[nDatos];
        double *Y=new double[nDatos];
        pedirdatos(X,Y,nDatos);
        while(true)
        {
            cout<<"\n\tIntroduce el grado del polinomio que deseas encontrar: ";
            getline(cin,entrada);
            stringstream mystream(entrada);
            if (mystream>>grado)
                break;
            cout<<"\n\tEntrada invalida."<<endl;
        }
        double **matriz=new double*[grado+1];
        for (int i = 0; i < grado+1; ++i)
            matriz[i]=new double[grado+2];
        coeficientes(X,Y,matriz,grado,nDatos);
        recorrido(matriz,grado+1,op);
        imp(matriz,grado+1,op);
    }
    while(1);
}

RegresionLineal::~RegresionLineal()
{
    //dtor
}


void RegresionLineal::coeficientes(double *x,double *y,double **matriz,int grado,int nDatos)
{
    double *s=new double[(2*grado)+1];
    double suma;
    for(int k=0; k < 2*grado+1; k++)
    {
        suma=0.0;
        for(int i=0; i < nDatos; i++)
            suma+=pow(x[i], k);
        s[k]=suma;
    }
    for(int k=0; k<grado+1; k++)
    {
        suma=0.0;
        for(int i=0; i < nDatos; i++)
            suma+=pow(x[i], k)*y[i];
        matriz[k][grado+1]=suma;
    }
    for(int i=0; i < grado+1; i++)
    {
        for(int j=0; j < grado+1; j++)
            matriz[i][j]=s[i+j];
    }
}

void RegresionLineal::recorrido(double **matriz, int n,bool &op)
{
    int i,j,k=0;
    for (j = 0; j < n-1; ++j)
    {
        for (i = n-1; i >k ; --i)
        {
            if(mdiagonal(matriz,n))
                rauno(matriz,n);
            reduccion(matriz,i,j,n);
        }
        k++;
    }
    for (j = n-1;  j> 0; j--)
    {
        for (i = 0; i < k; ++i)
        {
            if(mdiagonal(matriz,n))
                rauno(matriz,n);
            reduccion(matriz,i,j,n);
        }
        k--;
    }
    for (i = 0; i < n; ++i)
    {
        if(matriz[i][i]==0)
            op=true;
    }
    if (!op&&mdiagonal(matriz,n))
        rauno(matriz,n);
}

void RegresionLineal::reduccion(double **matriz,int i,int j,int n)
{
    double *ra=new double[n+1];
    int k;
    for (k = 0; k < n+1; ++k)
        ra[k]=((matriz[i][k]*matriz[j][j])-(matriz[j][k]*matriz[i][j]));
    for (int k = 0; k < n+1; ++k)
        matriz[i][k]=ra[k];
}

bool RegresionLineal::mdiagonal(double **matriz, int n)
{
    bool op=false;
    int i;
    for (i = 0; i < n; ++i)
    {
        if(matriz[i][i]!=1)
            op=true;
    }
    for (i = 0; i < n; ++i)
    {
        if (matriz[i][i]==0)
            op=false;
    }
    return op;
}

void RegresionLineal::rauno(double **matriz,int n)
{
    int i,j;
    double aux;
    for (i = 0; i < n; ++i)
    {
        aux=matriz[i][i];
        for (j = 0; j < n+1; ++j)
            matriz[i][j]=(matriz[i][j]/aux);
    }
}

void RegresionLineal::pedirdatos(double *x,double *y,int nDatos)
{
    string entrada;
    system(Limpantalla);
    cout<<"\n\tIntroduce los datos xi."<<endl;
    for (int i = 0; i < nDatos; ++i)
    {
        while(true)
        {
            cout<<"\n\tx"<<i+1<<": ";
            getline(cin,entrada);
            stringstream mystream(entrada);
            if (mystream>>x[i])
                break;
            cout<<"\n\tEntrada invalida."<<endl;
        }
    }
    system(Pausa);
    cout<<"\n\tIntroduce los datos yi."<<endl;
    for (int i = 0; i < nDatos; ++i)
    {
        while(true)
        {
            cout<<"\n\ty"<<i+1<<": ";
            getline(cin,entrada);
            stringstream mystream(entrada);
            if (mystream>>y[i])
                break;
            cout<<"\n\tEntrada invalida."<<endl;
        }
    }
    system(Pausa);
    system(Limpantalla);
}

void RegresionLineal::imp(double **matriz, int n,bool op)
{
    system(Limpantalla);
    if (op)
        cout<<"\n\n\tLos pares de datos introducidos no generan un sistema de ecuaciones con solucion."<<endl;
    else
    {
        cout<< "\n\n\tLos coeficientes de tu polinomio son:\n"<<endl;
        for (int i = 0; i < n; ++i)
            if (matriz[i][n]>=0)
                cout<<setw(10)<<"a"<<i<<"  =  "<<matriz[i][n]<<endl;
            else
                cout<<setw(10)<<"a"<<i<<"  = "<<matriz[i][n]<<endl;
    }
    system (Pausa);
}

