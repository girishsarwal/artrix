#include "Configuration.h"
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))
#include <vector>
#include "ButtonWidget.h"
Configuration::Configuration() {
    //ctor
}

Configuration::~Configuration() {
    //dtor
}
void Configuration::GenerateFactoryConfiguration() {
    /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    This function will check each file on startup and copy the defaults to the data directory
    **/



}

void Configuration::ParseScreens(const string& file) {
    __android_log_print(ANDROID_LOG_DEBUG, "Configuration::ParseScreens", "parsing screens from %s", file.c_str());
    XMLDocument doc;
    ReadFromAGKFile(file, &doc);
    for(XMLNode* screenNode = doc.RootElement()->FirstChild(); screenNode; screenNode = screenNode->NextSibling()) {        //screens
        Screen* screen = new Screen(screenNode->ToElement()->Attribute("name"));
        for(XMLNode* widgetNode = screenNode->FirstChild(); widgetNode; widgetNode= widgetNode->NextSibling()) {            //widgets
            Widget *w = NULL;
            WidgetFactory::CreateWidget(string(widgetNode->ToElement()->Attribute("type")), widgetNode, &w);
            w->Initialize();            /** This function is introduced to maintain the object creation inheritance hierarchy **/
            screen->AddWidget(w);
            __android_log_print(ANDROID_LOG_DEBUG, "Configuration::ParseScreens", "%d widgets were aded to screen %s", screen->GetWidgets().size(), screen->GetName().c_str());
        }
        mScreens.push_back(screen);
    }
    __android_log_print(ANDROID_LOG_DEBUG, "Configuration::ParseScreens", "%d screens were parsed", mScreens.size());
}

void Configuration::ParseConfig(const string& file) {

}

vector<Screen*> Configuration::GetScreens() {
    return mScreens;
}

vector<Screen*> Configuration::mScreens;

const void Configuration::ReadFromAGKFile(const string& file, XMLDocument* doc) {
     /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    We plan to use the AGK open file to load up the contents into the xml stream **/
    __android_log_print(ANDROID_LOG_DEBUG, "Configuration::ReadFromAGKFile", "trying to parse xml %s", file.c_str());
    int fileHandle = agk::OpenToRead(file.c_str());
    char configString[2048];
    char* line = 0;
    if(agk::FileIsOpen(fileHandle)){
        while(!agk::FileEOF(fileHandle)) {
            line = agk::ReadLine(fileHandle);
            __android_log_print(ANDROID_LOG_DEBUG, "Configuration", "%s", line);
            strcat(configString, line);
        }
        agk::CloseFile(fileHandle);
    }
    delete(line);

    XMLError err;
    /* todo: find a way to load larger files */
    err = doc->Parse(configString, 2048);
    if(err != 0) {
        __android_log_print(ANDROID_LOG_DEBUG, "Configuration::ReadFromAGKFile", "there was a problem parsing the xml %d, %s, %s", doc->ErrorID(), doc->GetErrorStr1(), doc->GetErrorStr2());
    }
    __android_log_print(ANDROID_LOG_DEBUG, "Configuration::ReadFromAGKFile", "xml %s was parsed", file.c_str());
}
