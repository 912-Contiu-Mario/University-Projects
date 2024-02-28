#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	this->head = nullptr;
	this->tail = nullptr;
	this->relation = r;
	this->length = 0;
}
//Total complexity: Theta(1)
int SortedIndexedList::size() const {
	return this->length;
}
//Total complexity: Theta(1)
bool SortedIndexedList::isEmpty() const {
	return this->length == 0;
}


//Best case:  Theta(1)
//Worst case:  Theta(n)
//Total complexity: 0(n)
TComp SortedIndexedList::getElement(int i) const{
	if (i < 0 || i >= this->length)
		throw exception("Invalid position");
	Node* node = this->head;
	int current = 0 ;
	while(current<this->length){
		if (current == i)
			return node->get_element();
		current++;
		node = node->next();
	}
	return NULL_TCOMP;
}

//Total complexity: Theta(i)
TComp SortedIndexedList::remove(int i) {
	if (i < 0 || i >= this->length)
		throw exception("Invalid position!");
	Node* node = this->head;
	TComp aux;
	if (this->length == 1) {
		aux = this->head->get_element();
		this->length--;
		this->head = nullptr;
		this->tail = nullptr;
		return aux;
	}
	for (int j = 0; j < this->length; j++)
	{
		if (j == i)
		{
			if (j == 0)
			{
				node->next()->set_prev(nullptr);
				this->head = node->next();
				aux = node->get_element(); this->length--;
				delete node;
				return aux;
			}
			if (j == this->length - 1)
			{
				node->prev()->set_next(nullptr);
				this->tail = node->prev();
				aux = node->get_element(); this->length--;
				delete node;
				return aux;
			}
			aux = node->get_element();
			node->prev()->set_next(node->next());
			node->next()->set_prev(node->prev());
			delete node;
			this->length--;
			return aux;
		}
		node = node->next();
	}
}

//Best case:  Theta(1)
//Worst case:  Theta(n)
//Total complexity: 0(n)
int SortedIndexedList::search(TComp e) const {
	Node* node = this->head;
	for (int i = 0; i < this->length; i++)
	{
		if (node->get_element() == e)
			return i;
		node = node->next();
	}
	return -1;
}
//Theta(end)
void SortedIndexedList::removeBetween(int start, int end)
{
	if (start<0 || end > this->length-1)
		throw exception();
	this->length = this->length - (end - start + 1);
	int k = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (k == start)
		{
			Node* start_remove = current;
			if(current->prev()!=nullptr)
				start_remove = current->prev();
			Node* end_remove = current;
			while (k <= end)
			{
				end_remove = end_remove->next();
				delete end_remove->prev();
				k++;
			}
			if (start == 0|| end == this->length - 1)
			{
				if (start == 0 )
					this->head = end_remove;
				else {
					this->tail = start_remove;
				}
			}
			else
			{
				start_remove->set_next(end_remove);
				end_remove->set_prev(start_remove);
			}
			break;
		}
		k++;
		current = current->next();
	}
}


//Best case:  Theta(1)
//Worst case:  Theta(n)
//Total complexity: 0(n)
void SortedIndexedList::add(TComp e) {
	int done = 0;
	Node* node = this->head;
	Node* node_to_add = new Node(e);
	if (this->length == 0)
	{
		this->head = node_to_add;
		this->length++;
		return;
	}
	if (this->length == 1)
	{
		this->length++;
		if (this->relation(this->head->get_element(), node_to_add->get_element()) == 1)
		{
			this->tail = node_to_add;
			this->tail->set_prev(this->head);
			this->head->set_next(this->tail);
			return;
		}
		else
		{
			this->tail = this->head;
			this->head = node_to_add;
			this->head->set_next(this->tail);
			this->tail->set_prev(this->head);
			return;
		}
	}
	while (node != nullptr)
	{
		if (this->relation(node->get_element(), node_to_add->get_element())==0)
		{
			this->length++;
			if (node == this->head)
			{
				node_to_add->set_next(node);
				node->set_prev(node_to_add);
				this->head = node_to_add;		
				return;
			}
		
			node->prev()->set_next(node_to_add);
			node_to_add->set_prev(node->prev());
			node->set_prev(node_to_add);
			node_to_add->set_next(node);
			return;
		}
		node = node->next();
	}
	node_to_add->set_prev(this->tail);
	this->tail->set_next(node_to_add);
	this->tail = node_to_add;
	this->length++;
	return;
	
}
//Total complexity Theta(1)
ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//TODO - Implementation
}
