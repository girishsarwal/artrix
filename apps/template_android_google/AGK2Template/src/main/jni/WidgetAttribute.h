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
        const string& GetName() const;
        void SetName(const string&);

        string GetValueStr() const;
        const int GetValueInt() const;
        const float GetValueFloat() const;


        void SetValueStr(const string&);
        void SetValueInt(int);
        void SetValueFloat(float);

    protected:
        string mName;
        XMLNode* mXmlNode;
    private:
        string GetValue() const;
};

#endif // WIDGETATTRIBUTE_H
