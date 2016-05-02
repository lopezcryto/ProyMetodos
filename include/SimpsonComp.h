#ifndef SIMPSONCOMP_H
#define SIMPSONCOMP_H


#include "simpson13.h"
#include "simpson38.h"

/*
Selecciona la mejor opcion para realizar el metodo
*/

class SimpsonComp
{
    public:
        SimpsonComp();
        virtual ~SimpsonComp();

        // ingreso manual de datos
        void ingresaDatos();

        // selecciona el o los metodo a usar
        int seleccinaMetodo(int);

        // Ejecuta
        void Executa_metodo();

    protected:

    private:

};

#endif // SIMPSONCOMP_H
