#ifndef UNAMGUI_H
#define UNAMGUI_H

#ifdef __linux__

#define Tiempolargo "sleep 10"
#define Tiempocorto "sleep 3"
#define Limpantalla "clear"
#define Pausa "read -n1 -r -p \"Presiona una tecla para continuar...\" key"

#endif // __linux__

#ifdef __MINGW32__

#define Tiempolargo "timeout /t 10"
#define Tiempocorto "timeout /t 3"
#define Limpantalla "cls"
#define Pausa "pause"

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
