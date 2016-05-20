#include <iostream>
#include <cstdlib>

#define limpia_linux "clear"

#include "DifDiv.h"
#include "Lagrange.h"
#include "RegresionLineal.h"
#include "simpson13.h"
#include "simpson38.h"
#include "unamGUI.h"






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


        if ((menu == 'l') ||(menu =='L') ){
                cout << "LAGRANGE"<< endl;

        Lagrange metlag;


        system(limpia_linux);

        }
        else if((menu == 'k') ||(menu =='K') ){
                        cout << "SIMPSON 1/3"<< endl;
                simpson13 mets1;


        }
        else if((menu == 'm') ||(menu =='M') ){
            cout << "SIMPSON 3/8"<< endl;
        simpson38 mets3;

        }


    else if((menu == 'c' ) || (menu == 'C')){
        gui.creditos();
        gui.pausaLectura();
        system(limpia_linux);

    }

      else if((menu == 'a' ) || (menu == 'A')){
        gui.ayuda();
        gui.pausaLectura();
        system(limpia_linux);
      }

      else if((menu == 'x' ) || (menu == 'X')) return 0;

      };

    return 0;
}
