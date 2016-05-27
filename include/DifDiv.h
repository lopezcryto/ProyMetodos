#ifndef DIFDIV_H
#define DIFDIV_H

#define _n_ 10
#define _m_ 13



class DifDiv
{
    public:
        DifDiv();
        virtual ~DifDiv();
        void tabula1(double a[_n_][_n_+1],int xs);
        void Diferencias(double a[_n_][_n_+1],int xs);
        void Divididas(double a[_n_][_n_+1],int xs,double val);


    protected:

    private:
};

#endif // DIFDIV_H
