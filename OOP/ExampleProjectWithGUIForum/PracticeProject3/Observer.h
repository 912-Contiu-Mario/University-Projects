//#pragma once
//#include <vector>
//using namespace std;
//class Observer
//{
//public:
//	virtual void update(vector<Answer> vec) = 0;
//
//};
//
//class Observable
//{
//private:
//	vector<Observer*> observers;
//public:
//	void addObserver(Observer* obs)
//	{
//		observers.push_back(obs);
//	}
//	void notify()
//	{
//		for (Observer* obj : observers)
//		{
//			obj->update();
//		}
//	}
//};