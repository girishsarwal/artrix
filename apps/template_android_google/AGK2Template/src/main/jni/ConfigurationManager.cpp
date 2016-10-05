#include "ConfigurationManager.h"
ConfigurationManager::ConfigurationManager() {
    mLocalWritePath = string(agk::GetWritePath());
}

ConfigurationManager::~ConfigurationManager() {
    //dtor
}

ConfigurationManager* ConfigurationManager::GetInstance()
{
    if(0 == mInstance)
        mInstance = new ConfigurationManager();
    return mInstance;
}
void ConfigurationManager::DestroyInstance()
{
    delete(mInstance);
}

void ConfigurationManager::Initialize(ANativeActivity* activity) {
    mActivity = activity;
    ALOGD("Activity Received", "%p", mActivity);
}

void ConfigurationManager::GenerateFactoryConfiguration() {
    /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    This function will check each file on startup and copy the defaults to the data directory
    **/



}

void ConfigurationManager::ParseScreens(const string& file) {
    ALOGD("Configuration::ParseScreens", "parsing screens from %s", file.c_str());
    XMLDocument doc;
    ReadFromAGKFile(file, &doc);
    for(XMLNode* screenNode = doc.RootElement()->FirstChild(); screenNode; screenNode = screenNode->NextSibling()) {        //screens
        Screen* screen = new Screen(screenNode->ToElement()->Attribute("name"));
        for(XMLNode* widgetNode = screenNode->FirstChild(); widgetNode; widgetNode= widgetNode->NextSibling()) {            //widgets
            Widget *w = NULL;
            WidgetFactory::CreateWidget(string(widgetNode->Value()), widgetNode, &w);
            if (w != NULL) {
                w->Initialize();            /** This function is introduced to maintain the object creation inheritance hierarchy **/
                screen->AddWidget(w);
            } else ALOGW("Configuration::ParseScreens", "There was a problem creating a widget of type %s", widgetNode->Value());
            ALOGD("Configuration::ParseScreens", "%d widgets were aded to screen %s", screen->GetWidgets().size(), screen->GetName().c_str());
        }
        mScreens.push_back(screen);
    }
    ALOGD("Configuration::ParseScreens", "%d screens were parsed", mScreens.size());
}

void ConfigurationManager::ParseConfig(const string& file) {
    ALOGD("Configuration::ParseConfig", "parsing configurations from %s", file.c_str());
    XMLDocument doc;
    ReadFromAGKFile(file, &doc);

    XMLElement* metrics = doc.RootElement()->FirstChildElement("metrics")->FirstChildElement();
    Managers::MM->Initialize(atof(metrics->Attribute("x")), atof(metrics->Attribute("y")));


    ALOGD("Configuration::ParseConfig", "%d keys were parsed", mScreens.size());
}

vector<Screen*> ConfigurationManager::GetScreens() {
    return mScreens;
}


void ConfigurationManager::ReadFromAGKFile(const string& file, XMLDocument* doc) {
     /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    We plan to use the AGK open file to load up the contents into the xml stream **/
    ALOGD("Configuration::ReadFromAGKFile", "trying to parse xml %s", file.c_str());
    int fileHandle = agk::OpenToRead(file.c_str());
    char* configString = (char*)malloc(sizeof(char) * FILE_BUFFER_LENGTH);
    memset(configString, 0, sizeof(char) * FILE_BUFFER_LENGTH);
    char* line = 0;
    if(agk::FileIsOpen(fileHandle)){
        while(!agk::FileEOF(fileHandle)) {
            line = agk::ReadLine(fileHandle);
            ALOGD("Configuration", "%s", line);
            strcat(configString, line);
        }
        agk::CloseFile(fileHandle);
    }
    delete(line);
    XMLError err;
    /* todo: find a way to load larger files */
    err = doc->Parse(configString, FILE_BUFFER_LENGTH);
    if(err != 0) {
        ALOGE("Configuration::ReadFromAGKFile", "there was a problem parsing the xml %d, %s, %s", doc->ErrorID(), doc->GetErrorStr1(), doc->GetErrorStr2());
    }
    delete(configString);
    ALOGD("Configuration::ReadFromAGKFile", "xml %s was parsed", file.c_str());
}

void ConfigurationManager::CopyMediaAssetToLocal(const string& file) {
    ALOGD("ConfigurationManager::CopyMediaAssetToLocal" ,"%s%s", mLocalWritePath.c_str(), file.c_str());

    /*AAssetManager* mgr = AAssetManager_fromJava(env, assetManager);
    AAsset* asset = AAssetManager_open(mgr, (const char *) js, AASSET_MODE_UNKNOWN);
    if (NULL == asset) {
        __android_log_print(ANDROID_LOG_ERROR, NF_LOG_TAG, "_ASSET_NOT_FOUND_");
        return JNI_FALSE;
    }
    long size = AAsset_getLength(asset);
    char* buffer = (char*) malloc (sizeof(char)*size);
    AAsset_read (asset,buffer,size);
    __android_log_print(ANDROID_LOG_ERROR, NF_LOG_TAG, buffer);
    AAsset_close(asset);
    */
}

void ConfigurationManager::CopyMedia(const string& manifestFile) {
    /** read a manifest file and make an xmldoc
        now go through the xml doc and do a direct move
    **/
    XMLDocument manifest;
    ReadFromAGKFile(manifestFile, &manifest);
    for(XMLNode* fileNode = manifest.RootElement()->FirstChild(); fileNode ; fileNode = fileNode ->NextSibling()) {
        CopyMediaAssetToLocal(string(fileNode->FirstChild()->ToText()->Value()));
    }
    ALOGD("Configuration::CopyMedia", "media was copied");
}

ConfigurationManager* ConfigurationManager::mInstance = NULL;
