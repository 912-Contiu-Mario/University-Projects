#pragma once
#include <vector>
using namespace std;
class Observer {
public:
	virtual void update() = 0;
};
class Observable
{
private:
	vector<Observer*> observers;
public:
	void addObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void notify(){
		for (auto it : observers)
			it->update();
	}
};

