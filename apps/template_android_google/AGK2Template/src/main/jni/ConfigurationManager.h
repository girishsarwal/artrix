#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H
#include <android/log.h>
#include <android/native_activity.h>
#include <android/asset_manager.h>
#include <string>
#include <vector>
#include <tinyxml2.h>
#include <errno.h>
#include "agk.h"
#include "screen.h"
#include "WidgetFactory.h"
#include "ButtonWidget.h"
#include "Managers.h"
#include "utils.h"
#include "KeyedManager.h"


#define FILE_BUFFER_LENGTH 8192

#define COPY_MODE_DEFAULT   false  //follow each files force flag in manifest
#define COPY_MODE_FACTORY   true   //simulate all flags as force copy


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
        void CopyMedia(const string& file, int mode);
        void ParseScreens(const string& file);
        void ParseConfig(const string& file);


		KeyedManager<Screen*> mScreensManager;
    protected:
    private:
        static ConfigurationManager* mInstance;
        ANativeActivity* mActivity;

        string mLocalWritePath;
        void ReadFromAGKFile(const string& file, XMLDocument*);
        int CreateContainingFolder(const char* folder);
        void CopyMediaAssetToLocal(const string& file, bool force);
        void CopyMediaAssetToLocalAgk(const string& file, bool force);
};

#endif // CONFIGURATIONMANAGER_H
