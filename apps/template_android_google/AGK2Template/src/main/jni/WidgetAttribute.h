#ifndef WIDGETATTRIBUTE_H
#define WIDGETATTRIBUTE_H
#include <string>
using namespace std;
class WidgetAttribute
{
    public:
        WidgetAttribute();
        WidgetAttribute(const string&, const string&);
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
        string mValue;
    private:
};

#endif // WIDGETATTRIBUTE_H
