//
// Created by gsarwal on 2/11/16.
//
#include "afx.h"
#ifndef KEYEDMANAGER_H
#define KEYEDMANAGER_H
using namespace std;
template <class T>
class KeyedManager {
	private:
		map<string, T> mMap;
	public:
		void Add(T val) {
			printf("\nAdded managed object %s", val->GetName().c_str());
			mMap[val->GetName()] = val;
		}
		int Size() {
			return mMap.size();
		}
		T Get(const string& name) {
			return mMap[name];
		}
};


#endif //KEYEDMANAGER_H
