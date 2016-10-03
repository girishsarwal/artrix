#ifndef COMMAND_H
#define COMMAND_H
#include "utils.h"

class Command
{
    public:
        /** Default constructor */
        Command();
        /** Default destructor */
        virtual ~Command();

        bool GetIsAvailable();
        void SetIsAvailable(bool isAvailable);

        void PreExecute();
        virtual void Execute() = 0;
        void PostExecute();

    protected:
        virtual void OnSetAvailable();
        virtual void OnPreExecute();
        virtual void OnExecute();
        virtual void OnPostExecute();
    private:
        bool mIsAvailable;
};

#endif // COMMAND_H
