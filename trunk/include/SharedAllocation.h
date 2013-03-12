#pragma once
#include "afx.h"
#define MAX_ITEMS 20
template <class T>
class SharedAllocation{
	T m_arrObjects[MAX_ITEMS];
private:
	int getNextAvailableSlot(){
		int index = -1;
		while(++index < MAX_ITEMS){
			if(m_arrObjects[index] == NULL)
				return index;
		}
		return -1;
	}
public:
	void add(T object){
		int index = getNextAvailableSlot();
		if(-1 == index){
			printf("WARNING: Allocation Overrun!\n");
			return;
		}
		m_arrObjects[index] = object;
		printf("SharedAllocation: Object Added at index %d\n", index);
	};
	
	void remove(T object){
		
	};
	
	void removeAtIndex(int index){
		if(index > MAX_ITEMS){
			printf("WARNING: Attempt to read beyond allocation boundaries\n");
		}
	};
	
	T getAtIndex(int index){
		if(index > MAX_ITEMS){
			printf("WARNING: Attempt to read beyond allocation boundaries\n");
		}
		return m_arrObjects[index];
	};
	
	int getCount(){
		return getNextAvailableSlot();
	};
	int getCapacity(){
		return MAX_ITEMS;
	};
	void clear(){
		memset(m_arrObjects, 0, sizeof(T) * MAX_ITEMS);
	}
};
