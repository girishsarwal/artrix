#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H
#include <android/log.h>
#include <android/native_activity.h>
#include <android/asset_manager.h>
#include <string>
#include <vector>
#include <tinyxml2.h>
#include "agk.h"
#include "screen.h"
#include "WidgetFactory.h"
#include "ButtonWidget.h"
#include "Managers.h"
#include "utils.h"


#define FILE_BUFFER_LENGTH 8192

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

        void Initialize(ANativeActivity*);

        void GenerateFactoryConfiguration();
        void CopyMedia(const string& file);
        void ParseScreens(const string& file);
        void ParseConfig(const string& file);
        vector<Screen*> GetScreens();
    protected:
    private:
        static ConfigurationManager* mInstance;
        ANativeActivity* mActivity;
        vector<Screen*> mScreens;
        string mLocalWritePath;
        void ReadFromAGKFile(const string& file, XMLDocument*);
        void CopyMediaAssetToLocal(const string& file);
};

#endif // CONFIGURATIONMANAGER_H
