#pragma once
#include <vector>
#include "Task.h"
#include "Programmer.h"
#include <fstream>

using namespace std;
class TaskRepository
{
private:
	vector<Task> tasks;
	vector<Programmer> programmers;
	string task_filename;
public:
	TaskRepository(string filename, string task_filename);
	void writeToFile();
	void addTask(Task& task);
	void removeTask(int index);
	void updateTask(int index, string status, int id);
	vector<Task>& getAllTasks();
	vector<Programmer> getAllProgrammers();
};