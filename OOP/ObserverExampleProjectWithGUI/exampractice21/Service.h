#pragma once
#include "TaskRepository.h"
#include "algorithm"
#include "Observer.h"
class Service :public Observable{
private:
	TaskRepository& repo;
public:
	Service(TaskRepository& _repo);
	void addTask(string desc, string status, int id);
	void removeTask(int index);
	TaskRepository& getTaskRepository();
	void startTask(int index, int id);
	void doneTask(int index, int id);
	void sortTasks();
};

bool sortFunction(Task task1, Task task2);