#include "Service.h"

Service::Service(TaskRepository& _repo):repo{_repo}
{
}

void Service::addTask(string desc, string status, int id)
{
	if (desc == "")
		throw exception("Description cannot be empty!");
	Task task(desc, status, 0);
	this->repo.addTask(task);
	this->notify();
}

void Service::removeTask(int index)
{
	if (index < 0 || index >= this->repo.getAllTasks().size())
		throw exception("Couldn't delete task!");
	this->repo.removeTask(index);
	this->notify();
}

TaskRepository& Service::getTaskRepository()
{
	return this->repo;
	// TODO: insert return statement here
}

void Service::startTask(int index, int id)
{
	Task task = this->repo.getAllTasks()[index];
	if (task.getStatus() != "open")
		throw exception("Choose an open task!");
	repo.updateTask(index, "In progress", id);
	this->notify();

}

void Service::doneTask(int index, int id)
{
	this->repo.updateTask(index, "Done", id);
	this->notify();
}



void Service::sortTasks()
{
	vector<Task>& tasks = this->repo.getAllTasks();
	sort(tasks.begin(), tasks.end(), sortFunction);
}

bool sortFunction(Task task1, Task task2)
{
	return task1.getStatus() < task2.getStatus();
}
