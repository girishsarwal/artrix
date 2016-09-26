#ifndef MANAGERS_H
#define MANAGERS_H

#include "ConfigurationManager.h"
#include "MetricsManager.h"
#include "StateManager.h"
class ConfigurationManager;
class MetricsManager;
class StateManager;
class Managers
{
    public:
        static void Initialize();
        static ConfigurationManager* CM;

        static StateManager* SM;
        static MetricsManager* MM;

        static void Destroy();
        Managers();
        virtual ~Managers();
    protected:
    private:
};

#endif // MANAGERS_H
