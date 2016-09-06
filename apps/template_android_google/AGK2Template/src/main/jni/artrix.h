#ifndef ARTRIX_H
#define ARTRIX_H
#include "statemanager.h"

class Artrix
{
    public:
        Artrix();
        virtual ~Artrix();

        void Begin();
        void Loop();
        void End();

    protected:

    private:

};

#endif // ARTRIX_H
