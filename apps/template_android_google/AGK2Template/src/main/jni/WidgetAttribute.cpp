#include "WidgetAttribute.h"
WidgetAttribute::WidgetAttribute() {
    //ctor
}

WidgetAttribute::~WidgetAttribute() {
    //dtor
}
WidgetAttribute::WidgetAttribute(const string& name, const string& value) {
}

string WidgetAttribute::GetName() {
    return mName;
}

void WidgetAttribute::SetName(const string& name) {
    mName = name;
}

string WidgetAttribute::GetValueStr() {
    return mValue;
}

int WidgetAttribute::GetValueInt() {
    return atoi(mValue.c_str());
}

float WidgetAttribute::GetValueFloat() {
    return atof(mValue.c_str());
}

void WidgetAttribute::SetValueStr(const string& value) {
    mValue = value;
}

void WidgetAttribute::SetValueInt(int value) {
    char val[10];
    sprintf(val, "%d", value);
    SetValueStr(string(val));
}

void WidgetAttribute::SetValueFloat(float value) {
    char val[10];
    sprintf(val, "%f", value);
    SetValueStr(string(val));

}
