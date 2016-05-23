#include "unamGUI.h"
#include <iostream>
#include <cstdlib>

using namespace std;

unamGUI::unamGUI()
{
    //ctor
}

unamGUI::~unamGUI()
{
    //dtor
}


void unamGUI::encabezado()
{
    cout << "\t\t      Universidad Nacional Autonoma de Mexico"<<endl;
    cout << "\t\t      Facultad de estudios superiores Acatlan"<<endl;
    cout << "\t\t         Metodos Numericos II Mayra Olguin"<<endl<< endl;
}


void unamGUI::ayuda()
{
    cout << "Texto de ayuda" << endl;
}

void unamGUI::welcome()
{
    cout <<"________________________________________________________________________________"<<endl;
    cout <<"         ##                       ##                       ##   "<<endl;
    cout <<"        ####                     ####                     ####   "<<endl;
    cout <<"       ######                   ######                   ######    "<<endl;
    cout <<"      ###  ###                 ###  ###                 ###  ###   "<<endl;
    cout <<"     ###    ###               ###    ###               ###    ###   "<<endl;
    cout <<"    ####     ###             ####     ###              ###     ###   "<<endl;
    cout <<"   ######     ###           ######     ###              ###     ###   "<<endl;
    cout <<"  ###  ###     ###         ###  ###     ###              ###     ###  "<<endl;
    cout <<" ###    ###     ###       ###    ###     ###       ##     ###     ### "<<endl;
    cout <<" ##      ###     ##       ###     ###     ##       ###     ###     ## "<<endl;
    cout <<"          ###              ###     ###              ###     ###      "<<endl;
    cout <<"           ###              ###     ###              ###     ###     "<<endl;
    cout <<"            ###              ###     ###              ###     ###    "<<endl;
    cout <<"             ##               ###     ##               ###    ###    "<<endl;
    cout <<"                               ###                      ###  ###     "<<endl;
    cout <<"                                ###                      ######      "<<endl;
    cout <<"                                 ###                      ####       "<<endl;
    cout <<"                                  ##                       ##        "<<endl<<endl;
    cout <<"                Facultad de estudios superiores Acatlan  "<<endl;
    cout <<"                         Univerdidad nacional            "<<endl;

    system(Tiempocorto);
    system(Limpantalla);

}

void unamGUI::creditos()
{
    cout << "\n\n\t\t\t\t\t Creditos de desarrollo \n " << endl;
    cout << "\t\t\t 094161856 \tJimenez Molina Eduardo"<<endl;
    cout << "\t\t\t 414490381 \tRamirez Velasquez Julian Andres"<<endl;
    cout << "\t\t\t 414027295 \tGomez Corrado Cinthya Abigail"<<endl;
    cout << "\t\t\t 311662467 \tGranados Cid Victor Mohadib "<<endl;


    system(Tiempocorto);
}

void unamGUI::menuapp()
{
    cout << "\t\t\t l \tMetodo Lagrange"<<endl;
    cout << "\t\t\t k \tMetodo de Simpson 1/3" <<endl;
    cout << "\t\t\t m \tMetodo de Simpson 3/8" <<endl;
    cout << "\t\t\t n \tSpline Cubico" <<endl;
    cout << "\t\t\t o \tMetodo Diferencias divididas"<<endl;
    cout << "\t\t\t p \tRegresion lineal minimos cuadrados"<<endl;

    cout << "\t\t\t a \tAyuda"<<endl;
    cout << "\t\t\t c \tCreditos"<<endl;
    cout << "\t\t\t x \tSalir"<< endl;

}

void unamGUI::pausaLectura()
{
    system(Tiempocorto);
}
