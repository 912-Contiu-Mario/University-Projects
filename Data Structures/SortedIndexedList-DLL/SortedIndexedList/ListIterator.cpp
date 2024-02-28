#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	this->node = this->list.head;
}
//Theta(1)
void ListIterator::first(){
	this->node = this->list.head;
}
//Theta(1)
void ListIterator::next(){
	
	if (this->valid())
		this->node = this->node->next();
	else
		throw exception();
}


//Theta(1)
bool ListIterator::valid() const{
	if(node!=nullptr)
		return true;
	return false;
}


//Theta(1)
TComp ListIterator::getCurrent() const{
	if(this->valid())
		return this->node->get_element();
	return NULL_TCOMP;
}
