#include "WidgetAttribute.h"
WidgetAttribute::WidgetAttribute() {

}

WidgetAttribute::~WidgetAttribute() {

}

WidgetAttribute::WidgetAttribute(const string& name, XMLNode* xmlNode) {
    mName = name;
    mXmlNode = xmlNode;
}

const string& WidgetAttribute::GetName() const {
    return mName;
}

void WidgetAttribute::SetName(const string& name) {
    mName = name;
}

string WidgetAttribute::GetValueStr() const {
    return GetValue();
}

const int WidgetAttribute::GetValueInt() const {
    return atoi(GetValue().c_str());
}

const float WidgetAttribute::GetValueFloat() const {
    return atof(GetValue().c_str());
}
string WidgetAttribute::GetValue() const {
    return mXmlNode->Value();
}

void WidgetAttribute::SetValueStr(const string& value) {
    //mXmlNode = new XMLElement(value);
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
