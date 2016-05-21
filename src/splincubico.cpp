#include <iostream>
#include <iomanip>
#include <cmath>
#include "splincubico.h"

#define Tam 100
using namespace std;
splincubico::splincubico()
{
    //ctor
    spline_programa3();

}

splincubico::~splincubico()
{
    //dtor
}




void splincubico::Invierte(int Dim, float Sist[][Tam], float Inv[][Tam])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1,V2;

    /*Se inicializa la matriz inversa, como la matriz identidad:*/
    for(C1=1; C1<=Dim; C1++)
        for(C2=1; C2<=Dim; C2++)
            if (C1==C2) Inv[C1][C2]=1;
            else Inv[C1][C2]=0;

    for(Col=1; Col<=Dim; Col++)
    {
        NoCero=0;
        A=Col;
        while(NoCero==0)
        {
            if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001)))
            {
                NoCero=1;
            }
            else A++;
        }
        Pivote=Sist[A][Col];
        for(C1=1; C1<=Dim; C1++)
        {
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;
            V2=Inv[A][C1];
            Inv[A][C1]=Inv[Col][C1];
            Inv[Col][C1]=V2/Pivote;
        }
        for(C2=Col+1; C2<=Dim; C2++)
        {
            V1=Sist[C2][Col];
            for(C1=1; C1<=Dim; C1++)
            {
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];
                Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
            }
        }
    }

    /*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
    for(Col=Dim; Col>=1; Col--) for(C1=(Col-1); C1>=1; C1--)
        {
            V1=Sist[C1][Col];
            for(C2=1; C2<=Dim; C2++)
            {
                Sist[C1][C2]=Sist[C1][C2]-V1*Sist[Col][C2];
                Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
            }
        }
}
//////////////////////////////////////////////////////////////////////////////////////////





/// para el constructor
void splincubico::spline_programa3()
{
    cout <<"SPLINE CUBICO ";
    //int nd=0,posicion=0,grado=0, opcion=1;
    int nd=0,posicion=0, opcion=1;
    float numero=0,suma=0,DIF=0,respuesta=0;
    int nd1,nd2,nd3;
    //int Dimension;
    float Sistema[Tam][Tam],Inversa[Tam][Tam];
    do
    {



        do
        {
            cout<<"\n\t Ingresa el numero de datos minimo 4: ";
            cin>>nd;
        }
        while(nd<4);

        nd1=nd-1;
        nd2=nd-2;
        nd3=nd-3;

        //Dimension=nd3;
        float x[nd1],y[nd1],h[nd2],f[nd2],r[nd3],vr[nd3],s[nd1],a[nd2],b[nd2],c[nd2];
        //float m[nd3][nd3];

        cout<<"\n\t Ingresa los datos: ";
        cout<<"\n\n\t |||Porfavor dar los datos ordenados de menor a mayor|||\n\n";
        for( int i=0; i<=nd1; i++)
        {
            cout<<"\n\tx ["<<i<<"]  :";
            cin>>x[i];
            cout<<"\ty ["<<i<<"]  :";
            cin>>y[i];
        }

        for( int i=0; i<=nd1; i++)
        {
            h[i]=x[i+1]-x[i];
            f[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
        }

        cout<<"\n\n\t Tabla de valores:\n\n";
        cout<<"\n\t| x | \t | y |";

        for( int i=0; i<=nd1; i++)
        {
            cout<<"\n\t"<<x[i]<<"\t"<<y[i];
        }




        cout<<"\n\n\t Vector Hi:\n\n";
        for( int i=0; i<=nd2; i++)
        {
            cout<<"\n\t"<<h[i];
        }

        cout<<"\n\n\t Vector F[xi,xi+1]:\n\n";
        for( int i=0; i<=nd2; i++)
        {
            cout<<"\n\t"<<f[i];
        }

        //Asigna valores a la matriz
        for( int i=1; i<=nd2; i++)
        {
            for( int j=1; j<=nd2; j++)
            {

                if(i==j)
                {
                    Sistema[i][j]=2*(h[i-1]+h[i]);
                    if(i==1 && j==1)
                    {
                        Sistema[i][j+1]=h[i];
                    }
                    if(i==nd2 && j==nd2)
                    {
                        Sistema[i][j-1]=h[i-1];
                    }
                    if(i!=1 && i!= nd2 && j!=1 &&j!=nd2)
                    {
                        Sistema[i][j+1]=h[i];
                        Sistema[i][j-1]=h[i-1];
                    }
                }

            }
        }


        cout<<"\n\n\n\t Matriz\n\n";
        for( int i=1; i<=nd2; i++)
        {
            for(int j=1; j<=nd2; j++)
            {

                cout << "||   " << std::setprecision(6)<< Sistema[i][j]<< "  ||"<<endl;

            }
            cout<<"\n";
        }
         Invierte(nd2,Sistema,Inversa);

        for( int i=1; i<=nd2; i++)
        {
            for(int j=1; j<=nd2; j++)
            {
                Inversa[i-1][j-1]=Inversa[i][j];
            }
        }



        cout<<"\n\n\n\t Matriz Inversa\n\n";
        for( int i=0; i<=nd3; i++)
        {
            for(int j=0; j<=nd3; j++)
            {
                cout<<"||  "<<Inversa[i][j]<<"  ||";
            }
            cout<<"\n";
        }

        for( int i=0; i<=nd3; i++)
        {
            r[i]=6*(f[i+1]-f[i]);
        }

        cout<<"\n\n\tVector  [6 * Hi]:\n\n";
        for( int i=0; i<=nd3; i++)
        {
            cout<<"\n\t"<<r[i];


        }


        for( int i=0; i<=nd3; i++)
        {
            suma=0;
            for( int j=0; j<=nd3; j++)
            {
                suma=suma+(Inversa[i][j]*r[j]);
            }
            vr[i]=suma;
        }

        cout<<"\n\n\t Vector  [Inversa * (6 * Hi)]:\n\n";
        for( int i=0; i<=nd3; i++)
        {
            cout<<"\n\t"<<vr[i];
        }


        for( int i=0; i<=nd1; i++)
        {
            if(i==0)
            {
                s[i]=0;
            }
            if(i!=0 && i!=nd1)
            {
                s[i]=vr[i-1];
            }
            if(i==nd1)
            {
                s[nd1]=0;
            }

        }

        cout<<"\n\n\t Vector S:\n\n";
        for( int i=0; i<=nd1; i++)
        {
            cout<<"\n\t"<<s[i];
        }

        for( int i=0; i<=nd2; i++)
        {
            a[i]=((s[i+1]-s[i])/(6*h[i]));
            b[i]=(s[i]/2);
            c[i]=((y[i+1]-y[i])/(h[i]))-(((s[i+1]+(2*s[i]))*(h[i]))/6);
        }







        do
        {


            cout<<"\n\n\t Tabla de valores:\n\n";
            cout<<"\n\t| x | \t | y |";
            for( int i=0; i<=nd1; i++)
            {
                cout<<"\n\t"<<x[i]<<"\t"<<y[i];
            }

            cout<<"\n\n\tCoeficientes \t|| a ||\t|| b ||\t|| c ||\n\n";
            for( int i=0; i<=nd2; i++)
            {
                cout<<"\n\t"<<i<<"\t ||"<<a[i]<<" ||\t|| "<<b[i]<<" ||\t\t||"<<c[i];
            }


            do
            {
                cout<<"\n\n\t Ingrese el valor a interpolar:";
                cin>>numero;
                if(numero<x[0] or numero>x[nd1])
                {
                    cout<<"\n\t Valor fuera de la tabla, dar otro valor:";
                }

            }
            while(numero<x[0] or numero>x[nd1]);


            for( int i=0; i<=nd1; i++)
            {
                if (numero>x[i] && numero<x[i+1])
                {
                    posicion=i;
                }
            }

            cout<<"\n\n\t Numero de ecuacion a utilizar :"<<posicion;

            DIF=numero-x[posicion];

            respuesta=((a[posicion]*pow(DIF,3))+(b[posicion]*pow(DIF,2))+(c[posicion]*DIF)+y[posicion]);
            cout<<"\a\n\n\t Resultado:"<<respuesta;
            //getch();


            //system("cls");
            // menu_programa3();
            cout<<"\n\n\t Elije una opcion:";
            cout<<"\n\t   1)  Interpolar otro punto con la misma tabla.";
            cout<<"\n\t   2)  Ingresar otra tabla";
            cout<<"\n\t   3)  Salir.";
            cin>>opcion;
        }
        while(opcion==1);
    }
    while(opcion==2);


    //return 0;




}
