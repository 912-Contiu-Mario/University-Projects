#include "Task.h"

ifstream& operator>>(ifstream& ifs, Task& task)
{
	string to_process;
	getline(ifs, to_process);
	if (to_process == "")
		return ifs;
	stringstream ss(to_process);
	string desc;
	string status;
	string id;

	getline(ss, desc, '|');
	getline(ss, status, '|');
	getline(ss, id);

	task.description = desc;
	task.status = status;
	task.id = stoi(id);
	return ifs;
}

ofstream& operator<<(ofstream& ofs, Task& task)
{
	ofs << task.description << "|" << task.status << "|" << task.id;
	return ofs;
}

Task::Task(string desc, string stat, int id):description{desc}, status{stat}, id{id}
{
}

string Task::toString()
{
	return "Description: " + description + " | Status: " + status + " | Id: " + std::to_string(id);
}

string Task::getDescrpition()
{
	return this->description;
}

string Task::getStatus()
{
	return status;
}

int Task::getId()
{
	return id;
}

void Task::setId(int i)
{
	this->id = i;
}

void Task::setStatus(string status)
{
	this->status = status;
}

