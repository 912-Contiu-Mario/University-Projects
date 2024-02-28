#pragma once
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Task
{
private:
	std::string description;
	std::string status;
	int id;
public:
	Task(string desc, string sta, int id);
	Task() :description{ "" }, status{ "" }, id{ 0 } {};
	friend ifstream& operator>>(ifstream& ifs, Task& task);
	friend ofstream& operator<<(ofstream& ofs, Task& task);
	string toString();

	string getDescrpition();
	string getStatus();
	int getId();

	void setId(int i);
	void setStatus(string status);


};