#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);
	TElem* sorted_array;
	int current;

public:
	~SortedBagIterator();
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

