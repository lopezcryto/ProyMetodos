#include "unamGUI.h"
#include <iostream>
#include <cstdlib>
#define time_linux "sleep 10"

using namespace std;

unamGUI::unamGUI()
{
    //ctor
}

unamGUI::~unamGUI()
{
    //dtor
}


/**
Genera el encabezado de la aplicacion
**/
void unamGUI::encabezado()
{
  cout << "\t\t      Universidad Nacional Autonoma de Mexico"<<endl;
  cout << "\t\t      Facultad de estudios superiores Acatlan"<<endl;
  cout << "\t\t         Metodos Numericos II Mayra Olguin"<<endl;
}

/**
Genera el pie de pagina de la aplicacion
**/

void unamGUI::piepag()
{
  cout << "______________________________________________________"<<endl;
}

void unamGUI::ayuda(){
cout << "Texto de ayuda" << endl;
}

void unamGUI::creditos(){
cout << "\n\n\t\t\t\t\t Creditos de desarrollo \n " << endl;
cout << "\t\t1\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t2\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t3\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t4\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t5\t 094161856 \tJimenez Molina Eduardo"<<endl;
system("sleep 15");
}

void unamGUI::menuapp()
{
cout << "\t\t1\t l \tMetodo Lagrange"<<endl;
//cout << "\t\t2\t d \tMetodo Diferencias divididas"<<endl;
//cout << "\t\t3\t r \tMetodos de regresion lineal"<<endl;
cout << "\t\t4\t k \tMetodo de Simpson 1/3" <<endl;
cout << "\t\t4\t m \tMetodo de Simpson 3/8" <<endl;
cout << "\t\t5\t a \tAyuda"<<endl;
cout << "\t\t5\t c \tCreditos"<<endl;
cout << "\t\t5\t x \tSalir"<< endl;
}

void unamGUI::pausaLectura()
{
 system(time_linux);
}
