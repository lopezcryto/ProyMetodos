#ifndef SIMPSON38_H
#define SIMPSON38_H


class simpson38
{
    public:
        simpson38();
        virtual ~simpson38();
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

#endif // SIMPSON38_H
