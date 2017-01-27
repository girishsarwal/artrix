//
// Created by gsarwal on 2/11/16.
//
#ifndef KEYMANAGEABLE_H
#define KEYMANAGEABLE_H
#include <string>
#include <typeinfo>

using namespace std;

class KeyManageable {
private:
	static int nextId;
	static int __getNextId();

protected:
	int mId;
	string mName;
public:
	const string& GetName() const;
	void SetName(const string&);
	void SetDefaultName(const string&);
};




#endif //KEYMANAGEABLE_H
