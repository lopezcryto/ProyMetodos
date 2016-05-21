#ifndef UNAMGUI_H
#define UNAMGUI_H

#ifdef __linux__

#define Tiempolargo "sleep 10"
#define Tiempocorto "sleep 3"
#define Limpantalla "clear"

#endif // __linux__

#ifdef __MINGW32__

#define Tiempolargo "sleep 10"
#define Tiempocorto "sleep 3"
#define Limpantalla "clear"

#endif // __MINGW32__




class unamGUI
{
    public:
        unamGUI();
        virtual ~unamGUI();
        void encabezado();

        void ayuda();
        void creditos();
        void menuapp();
        void pausaLectura();
        void welcome();

    protected:

    private:
};

#endif // UNAMGUI_H
