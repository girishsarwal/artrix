#include "Configuration.h"
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))
Configuration::Configuration() {
    //ctor
}

Configuration::~Configuration() {
    //dtor
}
void Configuration::ParseScreen(const string& file, Screen** screen) {
    /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    We plan to use the AGK open file to load up the contents into the xml stream **/
    int fileHandle = agk::OpenToRead(file.c_str());
    char configString[2048];
    char* line = 0;
    if(agk::FileIsOpen(fileHandle)){
        while(!agk::FileEOF(fileHandle)) {
            line = agk::ReadLine(fileHandle);
            __android_log_print(ANDROID_LOG_INFO, "Configuration", "%s", line);
            strcat(configString, line);
        }
        agk::CloseFile(fileHandle);
    }
    XMLDocument doc;
    XMLError err;
    /* todo: find a way to load larger files */
    err = doc.Parse(configString, 2048);
    if(err == 0) {
        __android_log_print(ANDROID_LOG_INFO, "Configuration", "Parsed XML Document");
    } else {
    __android_log_print(ANDROID_LOG_INFO, "Configuration", "Problem Parsing %d, %s, %s", doc.ErrorID(), doc.GetErrorStr1(), doc.GetErrorStr2());
    }
    delete(line);
}
