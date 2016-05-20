#ifndef SIMPSON13_H
#define SIMPSON13_H


class simpson13
{
    public:
        simpson13();
        virtual ~simpson13();
        //float simpson13f_verbose(int n, float a, float b , float **tabla );
        //float simpson13f(int n, float a, float b , float **tabla );
        void method(int n,  float **tabla, int verbose );
        void charger(int n, float **tabla);
        void viewTable(int n, float **tabla);
        void get_area();

    protected:

    private:
        int n_;
        float **tabla_ ;
        float area_;
};
#endif // SIMPSON13_H
