#ifndef REGRESIONLINEAL_H
#define REGRESIONLINEAL_H


class RegresionLineal
{
    public:
        RegresionLineal();
        virtual ~RegresionLineal();

    protected:

    private:

void coeficientes(double *x,double *y,double **matriz,int grado,int nDatos);//Llena la matriz del sistema de ecuaciones de los coeficientes.
void recorrido(double **matriz, int n,bool &op);//Recorre la matriz para resolverla por gauss jordan.
void reduccion (double **matriz, int i, int j,int n);//Reducción gauss jordan a ceros.
bool mdiagonal(double **matriz, int n);//Valída la matriz digonal antes de reducirla a unos.
void rauno(double **matriz,int n);//Reduduccion de la matriz diagonal a unos.
void pedirdatos(double *x,double *y,int nDatos);//Llena los vectores X y Y con los pares de coordenadas.
void imp(double **matriz, int n,bool op);//Impresion de los resultados.

};

#endif // REGRESIONLINEAL_H
