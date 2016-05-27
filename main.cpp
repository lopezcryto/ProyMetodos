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

            system(Pausa);

            //system(Limpantalla);
        }
        else if((menu == 'k') ||(menu =='K') )
        {

            cout << "SIMPSON 1/3"<< endl;

            simpson13 mets1;



            system(Pausa);

            //system(Limpantalla);
        }
        else if((menu == 'm') ||(menu =='M') )
        {

            cout << "SIMPSON 3/8"<< endl;

            simpson38 mets3;

            system(Pausa);

            //system(Limpantalla);
        }
        else if((menu == 'c' ) || (menu == 'C'))
        {
            ///  Creditos del proyecto

            gui.creditos();

            system(Pausa);

            //system(Limpantalla);
        }
        else if ((menu =='n')||(menu =='N'))
        {

            /// Spline cubico
               cout << "SPLINE CUBICO"<< endl;

            splincubico sp3;

            system(Pausa);

            //system(Limpantalla);
        }
        else if ((menu =='o')||(menu =='O'))
        {

            /// Diferencias divididas
               cout << "DIFERENCIAS DIVIDIDAS"<< endl;

            DifDiv dif1;

            system(Pausa);

            ///system(Limpantalla);
        }
        else if ((menu =='p')||(menu =='P'))
        {
            /// Regresion lineal
               cout << "REGRESION LINEAL"<< endl;

            RegresionLineal pros;

            system(Pausa);

            ///system(Limpantalla);
        }
        else if((menu == 'a' ) || (menu == 'A'))
        {

            gui.ayuda();

            system(Pausa);

            ///system(Limpantalla);
        }
        else if((menu == 'x' ) || (menu == 'X')) return 0;
    };
    return 0;
}
