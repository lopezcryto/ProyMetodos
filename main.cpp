#include <iostream>
#include <cstdlib>

#include "unamGUI.h"
#include "DifDiv.h"
#include "Lagrange.h"
#include "RegresionLineal.h"
#include "simpson13.h"
#include "simpson38.h"
#include "splincubico.h"

using namespace std;

int main()
{
    unamGUI gui;
    gui.welcome();


    while(1)
    {

        gui.encabezado();
        gui.menuapp();


        cout << "Menu[a-z]:" ;
        char menu;
        cin >> menu;


        if ((menu == 'l') ||(menu =='L') )
        {
            cout << "LAGRANGE"<< endl;
            Lagrange metlag;
            system(Limpantalla);
        }
        else if((menu == 'k') ||(menu =='K') )
        {
            cout << "SIMPSON 1/3"<< endl;
            simpson13 mets1;


        }
        else if((menu == 'm') ||(menu =='M') )
        {
            cout << "SIMPSON 3/8"<< endl;
            simpson38 mets3;

        }
        else if((menu == 'c' ) || (menu == 'C'))
        {
            gui.creditos();
            gui.pausaLectura();
            system(Limpantalla);
        }
        else if ((menu =='n')||(menu =='N'))
        {
            /// Spline cubico

            splincubico sp3;
             gui.pausaLectura();
            system(Limpantalla);
        }

        else if ((menu =='o')||(menu =='O'))
        {
            /// Diferencias divididas

            DifDiv dif1;


            gui.pausaLectura();
            system(Limpantalla);
        }

        else if ((menu =='o')||(menu =='O'))
        {
            /// Diferencias divididas

            gui.pausaLectura();
            system(Limpantalla);
        }
        else if ((menu =='p')||(menu =='P')){
            /// Regresion lineal
            RegresionLineal pri1;


        }

        else if((menu == 'a' ) || (menu == 'A'))
        {
            gui.ayuda();
            gui.pausaLectura();
            system(Limpantalla);
        }

        else if((menu == 'x' ) || (menu == 'X')) return 0;

    };

    return 0;
}
