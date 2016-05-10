#include <iostream>
#include <cstdlib>

#include "DifDiv.h"
#include "Lagrange.h"
#include "RegresionLineal.h"
#include "simpson13.h"
#include "simpson38.h"
#include "unamGUI.h"
#define limpia_linux "clear"
#define limpia_win7 "cls"



using namespace std;

int main()
{
    unamGUI gui;


    while(1){
        gui.encabezado();
        gui.menuapp();
        gui.piepag();
        cout << "Menu[a-z]:" ;
        char menu;
        cin >> menu;



//        switch(menu){

        if ((menu == 'l') ||(menu =='L') ){
                cout << "LAGRANGE"<< endl;

        Lagrange metlag;


        system(limpia_linux);

        }


    //case 'l': case 'L':

      //  break;

    //case 'd': case 'D':
      //  cout << "DIFERENCIAS DIVIDIDAS"<<endl;
       // DifDiv DifDiv_run;

       //system(limpia_linux);
        //break;

    //case 'r': case 'R':
      //  cout << "REGRESION LINEAL"<<endl;

      //  RegresionLineal RegresionLineal_run;

      //system(limpia_linux);
       // break;

    //case 's': case 'S':
      //  cout << "INTEGRACION NUMERICA"<< endl;
       // SimpsonComp SimpsonComp;

       //system(limpia_linux);
        //break;


    else if((menu == 'c' ) || (menu == 'C')){
        gui.creditos();
        gui.pausaLectura();
        system(limpia_linux);

    }
    //case 'c': case 'C':

      //  break;

      else if((menu == 'a' ) || (menu == 'A')){
        gui.ayuda();
        gui.pausaLectura();
        system(limpia_linux);
      }
    //case 'a': case 'A':

      //  break;

      else if((menu == 'x' ) || (menu == 'X')) return 0;
    //case 'x': case 'X': return 0; break;




        //}
    };

    return 0;
}
