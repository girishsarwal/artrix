#pragma once
#include "afx.h"
template<typename T>
class Singleton{
private:
	static T* m_pInstance;
public:
	static T* getInstance(){
		if(NULL == m_pInstance){
			printf("Singleton:: No previous instance of singleton, creating\n");
			m_pInstance = new T();
		}
		return m_pInstance;
	}

};
template <typename T>
T* Singleton<T>::m_pInstance = NULL;

