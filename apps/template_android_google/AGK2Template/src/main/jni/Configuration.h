#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <string>
#include <android/log.h>
#include <tinyxml2.h>
#include "screen.h"
#include "agk.h"
#include "WidgetFactory.h"
using namespace std;
using namespace AGK;
using namespace tinyxml2;
class Configuration
{
    public:
        Configuration();
        virtual ~Configuration();
        static void GenerateFactoryConfiguration();
        static void ParseScreens(const string& file);
        static void ParseConfig(const string& file);
        static vector<Screen*> GetScreens();
    protected:
    private:
        static vector<Screen*> mScreens;
        static const void ReadFromAGKFile(const string& file, XMLDocument*);
};

#endif // CONFIGURATION_H
