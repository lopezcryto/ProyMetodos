#include "SimpsonComp.h"

SimpsonComp::SimpsonComp()
{
    //ctor
}

SimpsonComp::~SimpsonComp()
{
    //dtor
}

void SimpsonComp::ingresaDatos()
{

}

int SimpsonComp::seleccinaMetodo(int nRenglones)
{
    /// Se toma el numero de renglones ingresado
    ///  cuando se usa simp 1/3 -> 1
    ///  Cuando se usa simp 3/8 -> 2
    ///  cuando se usa  sim 3/8 - sim 1/3 ->  3

    if (nRenglones%2==0) return 1 ;
    else if(nRenglones%3==0) return 2;
    else  return 3;
}

void SimpsonComp::Executa_metodo(){

    /// Ingresa datos
    ingresaDatos();
    ///  Cuenta los datos ingresados
    //int a = ndatos();

    /// Ejecuta
    /*
    switch (seleccinaMetodo(a)){
case 1:
    /// Caso simpson 1/3

    break;
case 2:
    /// caso simpson 3/8
    break;

case 3:
    /// caso simpson 1/3 y simpson 3/8
    /// ejecuta 1/3 -> tot13
    /// ejecuta 3/8 -> tot38
    /// el total a entrega es "tot13 + tot28  -> total"

    break;

    } */


}
