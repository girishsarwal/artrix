#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H
#include <android/log.h>
#include <string>
#include <vector>
#include <tinyxml2.h>
#include "agk.h"
#include "screen.h"
#include "WidgetFactory.h"
#include "ButtonWidget.h"
#include "Managers.h"
#include "utils.h"

#define FILE_BUFFER_LENGTH 4096

using namespace std;
using namespace AGK;
using namespace tinyxml2;
class ConfigurationManager
{
    public:
        ConfigurationManager();
        virtual ~ConfigurationManager();
        static ConfigurationManager* GetInstance();
        static void DestroyInstance();

        void GenerateFactoryConfiguration();
        void ParseScreens(const string& file);
        void ParseConfig(const string& file);
        vector<Screen*> GetScreens();
    protected:
    private:
        static ConfigurationManager* mInstance;
        vector<Screen*> mScreens;
        const void ReadFromAGKFile(const string& file, XMLDocument*);
};

#endif // CONFIGURATIONMANAGER_H
