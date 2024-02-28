#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	this->current = list.head;
}

void ListIterator::first(){
	this->current = list.head;
}

void ListIterator::next(){
	if (valid())
		this->current = list.next[this->current];
	else throw exception();
}

bool ListIterator::valid() const{
	return this->current >= 0 && this->current!=-1;
}

TComp ListIterator::getCurrent() const{
	if(valid())
		return list.elems[this->current];
}


