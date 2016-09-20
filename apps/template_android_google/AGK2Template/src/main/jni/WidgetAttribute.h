#ifndef WIDGETATTRIBUTE_H
#define WIDGETATTRIBUTE_H
#include <string>
#include <tinyxml2.h>
using namespace std;
using namespace tinyxml2;
class WidgetAttribute
{
    public:
        WidgetAttribute();
        WidgetAttribute(const string&, XMLNode*);
        virtual ~WidgetAttribute();
        string GetName();
        void SetName(const string&);

        string GetValueStr();
        int GetValueInt();
        float GetValueFloat();


        void SetValueStr(const string&);
        void SetValueInt(int);
        void SetValueFloat(float);

    protected:
        string mName;
        XMLNode* mXmlNode;
    private:
        string GetValue();
};

#endif // WIDGETATTRIBUTE_H
