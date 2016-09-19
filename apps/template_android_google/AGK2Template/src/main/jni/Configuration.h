#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <string>
#include <android/log.h>
#include <tinyxml2.h>
#include "screen.h"
#include "agk.h"
using namespace std;
using namespace AGK;
using namespace tinyxml2;
class Configuration
{
    public:
        Configuration();
        virtual ~Configuration();
        static void ParseScreen(const string& file, Screen** screen);
    protected:
    private:
};

#endif // CONFIGURATION_H
