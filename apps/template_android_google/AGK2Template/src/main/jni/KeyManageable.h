//
// Created by gsarwal on 2/11/16.
//
#include <string>
#include <typeinfo>
#ifndef KEYMANAGEABLE_H
#define KEYMANAGEABLE_H
using namespace std;

class KeyManageable {
private:
	static uint16_t nextId;
	static uint16_t __getNextId();

protected:
	uint16_t mId;
	string mName;
public:
	const string& GetName() const;
	void SetName(const string&);
	void SetDefaultName();
};




#endif //KEYMANAGEABLE_H
