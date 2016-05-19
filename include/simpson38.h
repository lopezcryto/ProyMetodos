#ifndef SIMPSON38_H
#define SIMPSON38_H


class simpson38
{
    public:
        simpson38();
        virtual ~simpson38();
        float simpson38f(int n,float a,float b, float tabla[][2]);
        float simpson38f_verbose(int n,float a,float b, float tabla[][2]);


    protected:

    private:
};

#endif // SIMPSON38_H
