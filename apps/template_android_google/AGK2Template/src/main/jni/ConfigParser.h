#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include <string>
#include <android/log.h>
#include <tinyxml2.h>
#include "screen.h"
#include "agk.h"
using namespace std;
using namespace AGK;
using namespace tinyxml2;
class ConfigParser
{
    public:
        ConfigParser();
        virtual ~ConfigParser();
        static void ParseScreen(const string& file, Screen** screen);
    protected:
    private:
};

#endif // CONFIGPARSER_H
