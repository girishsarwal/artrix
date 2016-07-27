#ifndef ARTRIX_H
#define ARTRIX_H
#include "statemanager.h"

class Artrix
{
    public:
        Artrix();
        virtual ~Artrix();

        void begin();
        void update();
        void shutdown();

    protected:

    private:

};

#endif // ARTRIX_H
