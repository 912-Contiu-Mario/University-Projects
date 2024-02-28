#include "TaskRepository.h"

TaskRepository::TaskRepository(string prog_filename, string task_filename):task_filename{task_filename}
{
	ifstream programmer_file;
	programmer_file.open(prog_filename);
	ifstream task_file;
	task_file.open(task_filename);
	Programmer programmer_to_add;
	Task task;
	while (programmer_file >> programmer_to_add)
	{
		this->programmers.push_back(programmer_to_add);
	}
	while (task_file >> task)
	{
		this->tasks.push_back(task);
	}
}

void TaskRepository::writeToFile()
{
	ofstream file;
	file.open(this->task_filename);
	for (auto it : this->tasks)
	{
		file << it<<endl;
	}
}

void TaskRepository::addTask(Task& task)
{
	this->tasks.push_back(task);
	this->writeToFile();
}

void TaskRepository::removeTask(int index)
{
	this->tasks.erase(this->tasks.begin() + index);
	this->writeToFile();
}

void TaskRepository::updateTask(int index,string status, int id)
{
	this->tasks[index].setStatus(status);
	this->tasks[index].setId(id);

}

vector<Task>& TaskRepository::getAllTasks()
{
	return this->tasks;
}

vector<Programmer> TaskRepository::getAllProgrammers()
{
	return this->programmers;
}
