#ifndef SIMPSON13_H
#define SIMPSON13_H


class simpson13
{
    public:
        simpson13();
        virtual ~simpson13();
        float simpson13f_verbose(int n, float a, float b , float **tabla );
        float simpson13f(int n, float a, float b , float **tabla );
        void carga(float **tabla);

    protected:

    private:
        int n;
        float **tabla ;

};
#endif // SIMPSON13_H
