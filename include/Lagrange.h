#ifndef LAGRANGE_H
#define LAGRANGE_H


class Lagrange
{
    public:
        Lagrange();
        virtual ~Lagrange();
        float metodo(float x,int k, float _lista[][2]);
        float L(float x, int k, int j, float _lista[][2]);
        void run();

    protected:

    private:

};

#endif // LAGRANGE_H
