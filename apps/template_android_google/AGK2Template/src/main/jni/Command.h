#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include "tinyxml2.h"
#include "utils.h"
using namespace std;
using namespace tinyxml2;
class Command
{
    public:
        /** Default constructor */
        Command();
        Command(const string&);
        Command(const string&, bool);
        Command(XMLNode*);
        /** Default destructor */
        virtual ~Command();

        bool GetIsAvailable();
        void SetIsAvailable(bool isAvailable);
        const string& GetName() const;
        void SetName(const string&);

        void PreExecute();
        virtual void Execute();
        void PostExecute();

    protected:
        virtual void OnSetAvailable();
        virtual void OnPreExecute();
        virtual void OnExecute() = 0;
        virtual void OnPostExecute();
    private:
        bool mIsAvailable;
        string mName;
};

#endif // COMMAND_H
