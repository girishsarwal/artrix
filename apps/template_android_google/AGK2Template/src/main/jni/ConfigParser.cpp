#include "ConfigParser.h"

ConfigParser::ConfigParser() {
    //ctor
}

ConfigParser::~ConfigParser() {
    //dtor
}
void ConfigParser::ParseScreen(const string& file, Screen** screen) {
    /** we cant use fopen here as all assets in Agk are zipped up into the AssetManager.
    We plan to use the AGK open file to load up the contents into the xml stream **/
    int fileHandle = agk::OpenToRead(file.c_str());
    char configString[2048];
    char* line = 0;
    if(agk::FileIsOpen(fileHandle)){
        while(!agk::FileEOF(fileHandle)) {
            line = agk::ReadLine(fileHandle);
            __android_log_print(ANDROID_LOG_INFO, "ConfigParser", "%s", line);
            strcat(configString, line);
        }
        agk::CloseFile(fileHandle);
    }
    mxml_node_t* tree = mxmlLoadString(NULL, configString, MXML_TEXT_CALLBACK);
    mxml_node_t* screensNode = mxmlFindPath(tree, "screens/screen");
    if(screensNode != NULL) {
        mxmlElementGetAttr(screensNode, "type");
    }
    delete(line);
}
