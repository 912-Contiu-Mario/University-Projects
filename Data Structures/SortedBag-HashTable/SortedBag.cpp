#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
using namespace std;

//Theta(capacity)
SortedBag::SortedBag(Relation r) {
	this->capacity = 16;
	this->array = new TElem[this->capacity];
	this->length = 0;
	for (int i = 0; i < this->capacity; i++)
		this->array[i] = UNOCCUPIED;
	this->relation = r;
}

//Best case: Theta(1), Worst case: Theta(capacity^2), Overall complexity: O(capacity^2)
void SortedBag::add(TComp e) {
	int probe_number = 0;
	int position = this->hashFunction(e, probe_number);
	while(probe_number<this->capacity && this->array[position]!=UNOCCUPIED && this->array[position]!=DELETED)
	{
		probe_number++;
		position = this->hashFunction(e, probe_number);
	}
	if (probe_number == this->capacity) {
		this->rehash();
		this->add(e);
	}
	else {
		this->array[position] = e;
		this->length++;
	}
}

//Best case: Theta(1), Worst case: Theta(capacity), Overall complexity: O(capacity)
bool SortedBag::remove(TComp e) {
	int probe_number = 0;
	int position = this->hashFunction(e, probe_number);
	while (probe_number < this->capacity && this->array[position] != UNOCCUPIED)
	{
		if (this->array[position] == e) {
			this->array[position] = DELETED;
			this->length--;
			return true;
		}
		probe_number++;
		position = this->hashFunction(e, probe_number);
	}
	return false;
}

//Best case: Theta(1), Worst case: Theta(capacity), Overall complexity: O(capacity)
bool SortedBag::search(TComp e) const
{
	int probe_number = 0;
	int position = this->hashFunction(e, probe_number);
	while (probe_number < this->capacity && this->array[position] != UNOCCUPIED)
	{
		if (this->array[position] == e)
			return true;
		probe_number++;
		position = this->hashFunction(e, probe_number);
	}
	return false;
}

//Best case: Theta(1), Worst case: Theta(capacity), Overall complexity: O(capacity)
int SortedBag::nrOccurrences(TComp elem) const {
	int probe_number = 0;
	int nbOccurences = 0;
	int position = this->hashFunction(elem, probe_number);
	while (probe_number < this->capacity && this->array[position] != UNOCCUPIED)
	{
		if (this->array[position] == elem)
			nbOccurences++;
		probe_number++;
		position = this->hashFunction(elem, probe_number);
	}
	return nbOccurences;
}

//Theta(1)
int SortedBag::size() const {
	
	return this->length;
}

//Theta(1)
bool SortedBag::isEmpty() const {
	return this->length == 0;
}

//Theta(1)
TElem SortedBag::hashFunction(TComp e, int probe_num) const
{
	return ((abs(e) % this->capacity) + probe_num * (2 * abs(e) + 1)) % this->capacity;
}

//Best case: Theta(1), Worst case: Theta(capacity^2), Overall complexity: O(capacity^2)
void SortedBag::rehash()
{
	int new_position;
	this->capacity *= 2;
	TElem* resized_hashtable = new TElem[capacity];
	for (int i = 0; i < this->capacity; i++)
		resized_hashtable[i] = UNOCCUPIED;
	for (int i = 0; i < this->capacity/2; i++)
	{
		if (this->array[i] != UNOCCUPIED && this->array[i] != DELETED)
		{
			int probe_num = 0;
			new_position = this->hashFunction(this->array[i], probe_num);
			while (probe_num < this->capacity && resized_hashtable[new_position] != UNOCCUPIED)
			{
				probe_num++;
				new_position = this->hashFunction(this->array[i], probe_num);
			}
			resized_hashtable[new_position] = this->array[i];
		}
	}
	delete[] this->array;
	this->array = resized_hashtable;
}


//Theta(1)
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

//Theta(1)
SortedBag::~SortedBag() {
	delete[] this->array;
}
