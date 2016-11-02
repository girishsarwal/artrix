//
// Created by gsarwal on 2/11/16.
//

#include "KeyManageable.h"

uint16_t KeyManageable::nextId = 0;

const string& KeyManageable::GetName() const{
	return mName;
}

void KeyManageable::SetName(const string& name){
	mName = name;
}

void KeyManageable::SetDefaultName(){
	char widgetName[10];
	sprintf(widgetName, "%s%d", typeid(this).name(), (++nextId));
	string defaultName = string(widgetName);
	SetName(defaultName);
}