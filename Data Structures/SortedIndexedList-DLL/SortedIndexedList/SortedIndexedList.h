#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
#define NULL_TCOMP -11111


class Node {
private:
	TComp element;
	Node* next_node;
	Node* prev_node;
public:
	Node()
	{
		this->element = 0;
		this->next_node = nullptr;
		this->prev_node = nullptr;
	}
	Node(TComp& element)
	{
		this->element = element;
		this->next_node = nullptr;
		this->prev_node = nullptr;
	}

	//Theta(1)
	TComp& get_element()
	{
		return this->element;
	}

	//Theta(1)
	void set_element(TComp& element)
	{
		this->element = element;
	}


	//Theta(1)
	Node* next()
	{
		return this->next_node;
	}

	//Theta(1)
	void set_next(Node* node)
	{
		this->next_node = node;
	}

	//Theta(1)
	Node* prev()
	{
		return this->prev_node;
	}

	//Theta(1)
	void set_prev(Node* prev)
	{
		this->prev_node = prev;
	}
};



class SortedIndexedList {
private:
	friend class ListIterator;
private:
	Node* head;
	Node* tail;	
	Relation relation;
	int length;
public:
	// constructor
	SortedIndexedList(Relation r);

	// returns the size of the list
	int size() const;

	//checks if the list is empty
	bool isEmpty() const;

	// returns an element from a position
	//throws exception if the position is not valid
	TComp getElement(int pos) const;

	// adds an element in the sortedList (to the corresponding position)
	void add(TComp e);

	// removes an element from a given position
	//returns the removed element
	//throws an exception if the position is not valid
	TComp remove(int pos);

	// searches for an element and returns the first position where the element appears or -1 if the element is not in the list
	int search(TComp e) const;

	// returns an iterator set to the first element of the list or invalid if the list is empty
	ListIterator iterator();
	void removeBetween(int start, int end);
	//destructor
	~SortedIndexedList();
	

};
