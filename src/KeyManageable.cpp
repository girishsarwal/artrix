//
// Created by gsarwal on 2/11/16.
//

#include "KeyManageable.h"

int KeyManageable::nextId = 0;

const string& KeyManageable::GetName() const{
	return mName;
}

void KeyManageable::SetName(const string& name){
	printf("\nKeyManageable::SetName  %s", name.c_str());
	mName = name;
}

void KeyManageable::SetDefaultName(const string& baseType){
	mId = __getNextId();
	uint8_t bufferLength = (sizeof(char) * strlen(baseType.c_str())) + 5;
	char * name = (char*)malloc(bufferLength);
	memset(name, 0, bufferLength);
	sprintf(name, "%s-%d", baseType.c_str(), mId);
	string defaultName = string(name);
	SetName(defaultName);
	delete(name);
}
int KeyManageable:: __getNextId() {
	return ++nextId;
}

//bool KeyManageable::operator==(const KeyManageable& rhs) const {
//    return (this->mName == rhs.mName);
//};
//bool KeyManageable::operator!=(const KeyManageable& rhs) const {
//    return !(*this == rhs);
//};
