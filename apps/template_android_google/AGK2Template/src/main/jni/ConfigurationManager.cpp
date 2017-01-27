#include "ConfigurationManager.h"
using namespace AGK;
ConfigurationManager::ConfigurationManager() {
    mLocalWritePath = string(agk::GetWritePath());
}

ConfigurationManager::~ConfigurationManager() {

}

ConfigurationManager* ConfigurationManager::GetInstance()
{
    if(0 == mInstance)
        mInstance = new ConfigurationManager();
    return mInstance;
}
void ConfigurationManager::DestroyInstance() {
    if (0 != mInstance) {
        mInstance->Shutdown();
    }
    delete(mInstance);
}

void ConfigurationManager::Initialize(ANativeActivity* activity) {
    mActivity = activity;
    ALOGD("ConfigurationManager::Initialize", "Activity Received %p", mActivity);
}

void ConfigurationManager::Shutdown() {
    ALOGD("ConfigurationManager::Shutdown", "");
}

void ConfigurationManager::GenerateFactoryConfiguration() {
    /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    This function will check each file on startup and copy the defaults to the data directory
    **/
    CopyMedia("media.manifest", COPY_MODE_FACTORY);
}

//void ConfigurationManager::ParseScreens(const string& file) {
//	ALOGD("Configuration::ParseScreens", "parsing screens from %s", file.c_str());
//	XMLDocument doc;
//	ReadFromAGKFile(file, &doc);
//	for (XMLNode *screenNode = doc.RootElement()->FirstChild(); screenNode; screenNode = screenNode->NextSibling()) {        //screens
//		Screen *screen = new Screen();
//		screen->SetName(screenNode->ToElement()->Attribute("name"));
//
//		for (XMLNode *widgetNode = screenNode->FirstChild(); widgetNode; widgetNode = widgetNode->NextSibling()) {            //widgets
//			Widget *w = NULL;
//            WidgetFactory::CreateWidget(widgetNode, &w);
//			if (w != NULL) {
//				w->Initialize();            /** This function is introduced to maintain the object creation inheritance hierarchy **/
//				screen->AddWidget(w);
////				ALOGD("Adding widget ", "%s", w->GetName().c_str());
//			} else
//				ALOGW("Configuration::ParseScreens",
//				      "There was a problem creating a widget of type %s", widgetNode->Value());
//			ALOGD("Configuration::ParseScreens", "%d widgets were added to screen %s",
//			      screen->GetWidgets().size(), screen->GetName().c_str());
//
//			mScreensManager.Add(screen);
//		}
//		ALOGD("Configuration::ParseScreens", "%d screens were parsed", mScreensManager.Size());
//	}
//}

//void ConfigurationManager::ParseConfig(const string& file) {
//    ALOGD("Configuration::ParseConfig", "parsing configurations from %s", file.c_str());
//    XMLDocument doc;
//    ReadFromAGKFile(file, &doc);
//
//    XMLElement* metrics = doc.RootElement()->FirstChildElement("metrics")->FirstChildElement();
//    Managers::MM->Initialize(atof(metrics->Attribute("x")), atof(metrics->Attribute("y")));
//
//
//    ALOGD("Configuration::ParseConfig", "%d keys were parsed", mScreensManager.Size());
//}

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

int ConfigurationManager::CreateContainingFolder(const char* folder) {

    const size_t len = strlen(folder);
    char _path[PATH_MAX];
    char *p;
    errno = 0;
    if (len > sizeof(_path)-1) {
        errno = ENAMETOOLONG;
        return -1;
    }
    strcpy(_path, folder);
    for (p = _path + 1; *p; p++) {
        if (*p == '/') {
            *p = '\0';

            if (mkdir(_path, S_IRWXU) != 0) {
                if (errno != EEXIST)
                    return -1;
            }
            *p = '/';
        }
    }

    if (mkdir(_path, S_IRWXU) != 0) {
        if (errno != EEXIST)
            return -1;
    }
}
void ConfigurationManager::CopyMediaAssetToLocalAgk(const string& assetName, bool force = false, bool inflate = false) {
    /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    we will use AGK functon to copy files **/
    const char* an = assetName.c_str();
    ALOGD("ConfigurationManager::CopyMediaAssetToLocalAgk", "copying file %s", an);

    if(agk::GetFileExists(an)) {
        if(!force) {
            ALOGD("Configuration::CopyMediaAssetToLocalAgk", "file exists at %s%s", mLocalWritePath.c_str(), an);
            return;
        } else {
            ALOGD("Configuration::CopyMediaAssetToLocalAgk", "file exists %s%s. will be purged", mLocalWritePath.c_str(), an);
            agk::DeleteFile(an);
        }

    }

    int fileHandleSource = agk::OpenToRead(an);
    int fileHandleDestination = agk::OpenToWrite(an);
    long count = 0;
    if(!agk::FileIsOpen(fileHandleSource)) {
        ALOGE("ConfigurationManager::CopyMediaAssetToLocalAgk", "cannot read source file %s", an);
        return;
    }
    if(!agk::FileIsOpen(fileHandleSource)) {
        ALOGE("ConfigurationManager::CopyMediaAssetToLocalAgk", "cannot read destination file %s", an);
        return;
    }

    while(!agk::FileEOF(fileHandleSource)) {
        agk::WriteByte(fileHandleDestination, agk::ReadByte(fileHandleSource));
        count++;
    }
    agk::CloseFile(fileHandleSource);
    agk::CloseFile(fileHandleDestination);
    ALOGD("Configuration::CopyMediaAssetToLocalAgk", "%ld bytes were copied to %s%s", count, mLocalWritePath.c_str(), an);
    if(inflate) {
        agk::ExtractZip(an, "");
    }
}


void ConfigurationManager::CopyMediaAssetToLocal(const string& assetName, bool force = false) {
    /** splice the names into useful stuff **/

    const char* assetId = assetName.c_str();
    const char* rootpath = mLocalWritePath.c_str();
    char* filePath = (char*)malloc(sizeof(char) * (strlen(rootpath) + strlen(assetId)));
    sprintf(filePath, "%s%s", rootpath, assetId);
    char* folderPath = dirname(filePath);
    char* fileName = basename(filePath);

    CreateContainingFolder(folderPath);

    ALOGD("Filecopy", "file %s wll be copied to %s", fileName, folderPath);

    ALOGD("ConfigurationManager::CopyMediaAssetToLocal" ,"%s%s", mLocalWritePath.c_str(), assetId);
    AAsset* asset = AAssetManager_open(mActivity->assetManager, assetName.c_str(), AASSET_MODE_UNKNOWN);
    if (NULL == asset) {
        ALOGE("ConfigurationManager::CopyMediaAssetToLocal", "Asset not found");
        return;
    }
    long size = AAsset_getLength(asset);
    char* buffer = (char*) malloc (sizeof(char) * size);
    AAsset_read (asset,buffer,size);
    ALOGD("ConfigurationManager::CopyMediaAssetToLocal", "%p - %ld", buffer, size);

    FILE* fp = fopen(filePath, force? "w+":"w");
    if(NULL == fp){
        ALOGE("ConfigurationManager::CopyMediaAssetToLocal", "cannot open destination file %s", filePath);
        return;
    }

    long written = fwrite(buffer, sizeof(char), size, fp);
    ALOGD("ConfigurationManager::CopyMediaAssetToLocal", "%ld bytes copied to %s", written, filePath);
    fflush(fp);
    fclose(fp);
    AAsset_close(asset);

}

void ConfigurationManager::CopyMedia(const string& manifestFile, int mode) {
    /** read a manifest file and make an xmldoc
        now go through the xml doc and do a direct move
    **/
    XMLDocument manifest;
    ReadFromAGKFile(manifestFile, &manifest);
    for(XMLNode* fileNode = manifest.RootElement()->FirstChild(); fileNode ; fileNode = fileNode ->NextSibling()) {
        const char* force = fileNode->ToElement()->Attribute("force");
        const char* _inflate = fileNode->ToElement()->Attribute("inflate");
        bool inflate = (_inflate != NULL && (atoi(_inflate) == 1));
        if (mode != COPY_MODE_FACTORY) mode = force ? atoi(force): 0;
        CopyMediaAssetToLocalAgk(string(fileNode->FirstChild()->ToText()->Value()), mode, inflate);
    }
    ALOGD("Configuration::CopyMedia", "media was copied");
}


ConfigurationManager* ConfigurationManager::mInstance = NULL;
