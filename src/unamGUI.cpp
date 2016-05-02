#include "unamGUI.h"
#include <iostream>
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
  cout << "\t\tUniversidad Nacional Autonoma de Mexico"<<endl;
  cout << "\t\tFacultad de estudios superiores Acatlan"<<endl;
  cout << "\t\tMetodos Numericos II Mayra Olguin"<<endl;
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
cout << "\n\n\t\t\t\t\tCreditos de desarrollo \n " << endl;
cout << "\t\t1\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t2\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t3\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t4\t 094161856 \tJimenez Molina Eduardo"<<endl;
cout << "\t\t5\t 094161856 \tJimenez Molina Eduardo"<<endl;
}

void unamGUI::menuapp()
{
cout << "\t\t1\t l \tMetodo Lagrange"<<endl;
cout << "\t\t2\t d \tMetodo Diferencias divididas"<<endl;
cout << "\t\t3\t r \tMetodos de regresion lineal"<<endl;
cout << "\t\t4\t s \tMetodos de Simpson" <<endl;
cout << "\t\t5\t a \tAyuda"<<endl;
cout << "\t\t5\t c \tCreditos"<<endl;
cout << "\t\t5\t x \tSalir"<< endl;
}

void unamGUI::pausaLectura()
{
cout << "Pausa de lectura para salir ingrese cualquier letra + [enter]";
char a;
cin >> a;
}












