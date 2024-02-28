#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <algorithm>
using namespace std;


void merge(int array[], int const left, int const mid, int const right, Relation relation)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    int* leftArray = new int[subArrayOne], * rightArray = new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (relation(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

//Worst Case: O(nlog(n))
void mergeSort(int array[], int const begin, int const end, Relation relation)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, relation);
    mergeSort(array, mid + 1, end, relation);
    merge(array, begin, mid, end, relation);
}


//Best Case: Theta(capacity), Worst case: Theta(nlogn), Overall complexity: O(nlogn)
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->sorted_array = new TElem[bag.size()];
	int j = 0;
	for (int i = 0; i < bag.capacity; i++)
	{
		if (bag.array[i] != UNOCCUPIED&&bag.array[i]!=DELETED)
		{
			sorted_array[j] = bag.array[i];
			j++;
		}
	}
    mergeSort(sorted_array, 0, bag.size() - 1, bag.relation);
	this->current = 0;
}


//Theta(1)
SortedBagIterator::~SortedBagIterator()
{
    delete[] this->sorted_array;
}

//Theta(1)
TComp SortedBagIterator::getCurrent() {
	if (!this->valid())
		throw std::exception("invalid position");
	return this->sorted_array[this->current];
}


//Theta(1)
bool SortedBagIterator::valid() {
	return (this->current >= 0 && this->current < bag.size());
}

//Theta(1)
void SortedBagIterator::next() {
	if (!this->valid())
		throw std::exception("invalid position");
	this->current++;
}

//Theta(1)
void SortedBagIterator::first() {
	this->current = 0;
}

