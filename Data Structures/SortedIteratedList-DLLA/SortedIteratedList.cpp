#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>


//Best Case: Theta(1), Worst Case: Theta(n), Total Complexity: O(n)
int SortedIteratedList::AllocateP()
{
	if (this->firstfree == -1) {
		Resize();
		firstfree = this->length;
	}
	int newFreePos = this->firstfree;
	this->firstfree = this->next[this->firstfree];
	return newFreePos;
}

//Total Complexity: Theta(capacity)
void SortedIteratedList::Resize()
{
	this->capacity *= 2;
	TComp* aux_elems = new TComp[this->capacity];
	int* aux_next = new int[this->capacity];
	int* aux_prev = new int[this->capacity];
	for (int i = 0; i < this->capacity-1; i++)
	{
		if (i < this->size()) {
			aux_elems[i] = this->elems[i];
			aux_next[i] = this->next[i];
			aux_prev[i] = this->prev[i];
		}
		else {
			aux_next[i] = i + 1;
			if (i > 0)
				aux_prev[i] = i - 1;
		}
	}
	aux_next[capacity - 1] = -1;
	delete[] this->elems;
	delete[] this->next;
	delete[] this->prev;

	this->elems = aux_elems;
	this->next = aux_next;
	this->prev = aux_prev;
}

SortedIteratedList::SortedIteratedList(Relation r) {
	this->relation = r;
	this->capacity = 5;
	this->elems = new TComp[capacity];
	this->next = new int[capacity];
	this->prev = new int[capacity];
	this->tail = -1;
	this->head = -1;
	this->length = 0;
	this->firstfree = 0;
	for (int i = 0; i < capacity-1; i++)
	{
		next[i] = i + 1;
		if (i > 0)
			prev[i] = i - 1;
	}
	next[capacity - 1] = -1;
}


//Theta(1)
int SortedIteratedList::size() const {
	
	return this->length;
}

//Theta(1)
bool SortedIteratedList::isEmpty() const {
	return this->length == 0;
}
//Theta(1)
ListIterator SortedIteratedList::first() const {
	ListIterator it(*this);
	it.first();
	return it;
}

//Theta(1)
TComp SortedIteratedList::getElement(ListIterator poz) const {
	if (!poz.valid())
		throw exception();
	return poz.getCurrent();
}
//Theta(1)
TComp SortedIteratedList::remove(ListIterator& poz) {
	if (!poz.valid())
		throw exception();
	TComp index_to_remove = poz.current;
	TComp element_to_remove = elems[index_to_remove];
	poz.next();
	int next_index = next[index_to_remove];
	int prev_index = prev[index_to_remove];
	if (prev_index == -1 && next_index == -1)
	{
		this->head = -1;
		this->tail = -1;
	}
	else if (prev_index == -1)
	{
		prev[next_index] = prev_index;
		head = next_index;
	}
	else if (next_index == -1)
	{
		next[prev_index] = next_index;
		tail = prev_index;
	}
	else {
		prev[next_index] = prev_index;
		next[prev_index] = next_index;
	}
	int new_first_free = index_to_remove;
	next[new_first_free] = firstfree;
	firstfree = new_first_free;
	this->length--;
	return element_to_remove;
}

//Best Case: Theta(1), Worst Case: Theta(n), Total: O(n)
ListIterator SortedIteratedList::search(TComp e) const{
	ListIterator it(*this);
	while (it.valid())
	{
		if (it.getCurrent() == e)
			return it;
		it.next();
	}
	return it;
}

int SortedIteratedList::removeAll(SortedIteratedList& other_list)
{
	ListIterator list_it = this->first();
	ListIterator other_list_it = other_list.first();
	TComp first_el = other_list_it.getCurrent();
	int del_elems = 0, last_removed;
	while (list_it.valid()&&other_list_it.valid())
	{
		if (list_it.getCurrent() == first_el)
		{
			while (other_list_it.valid())
			{
				if (other_list_it.getCurrent() == list_it.getCurrent())
				{
					this->remove(list_it);
					del_elems++;
					last_removed = list_it.current;
					if(list_it.valid())
						list_it.next();
					other_list_it.next();
				}
				else
				{
					if(list_it.valid())
						list_it.next();
					else {
						list_it.current = last_removed;
						other_list_it.next();
					}
				}
			}
			break;
		}
		list_it.next();
		if (!list_it.valid())
			other_list_it.next();
	}
	return del_elems;
}


//Best Case: Theta(1), Worst Case: Theta(n), Total: O(n)
void SortedIteratedList::add(TComp e) {
	int FreePos = this->AllocateP();
	this->elems[FreePos] = e;
	this->length++;
	int index = head;
	int k = 0;
	if (index == -1)
	{
		tail = FreePos;
		head = FreePos;
		next[FreePos] = -1;
		prev[FreePos] = -1;
		return;
	}
	while (index != -1)
	{
		if (!relation(elems[index], e))
			break;
		index = next[index];
		k++;
	}
	if (index == -1)
	{
		prev[FreePos] = tail;
		next[FreePos] = -1;
		next[tail] = FreePos;
		tail = FreePos;
		return;
	}
	//index is the index of next element from e
	next[FreePos] = index;
	prev[FreePos] = prev[index];
	if(prev[index]!=-1)
		next[prev[index]] = FreePos;
	prev[index] = FreePos;
	if (k == 0)
		head = FreePos;
}

SortedIteratedList::~SortedIteratedList() {
	delete[] this->elems;
	delete[] this->prev;
	delete[] this->next;
}
