#ifndef MANAGERS_H
#define MANAGERS_H

#include "statemanager.h"

class Managers
{
    public:
        static void Initialize();
        static StateManager* SM;
        Managers();
        virtual ~Managers();
    protected:
    private:
};

#endif // MANAGERS_H
