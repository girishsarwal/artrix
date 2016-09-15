#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include <string>
#include <fstream>
#include <android/log.h>
#include <mxml.h>

#include "screen.h"
#include "agk.h"
using namespace std;
using namespace AGK;
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
