#pragma once
#include "SortedIndexedList.h"


//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIndexedList;
private:
	const SortedIndexedList& list;
	ListIterator(const SortedIndexedList& list);
	Node* node;

	//TODO - Representation

public:
	void first();
	void next();
	bool valid() const;
    TComp getCurrent() const;
};


