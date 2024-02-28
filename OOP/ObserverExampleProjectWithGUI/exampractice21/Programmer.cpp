#include "Programmer.h"
#include "sstream"
using namespace std;
std::string Programmer::getName() const
{
    return this->name;
}

int Programmer::getId() const
{
    return this->id;
}

Programmer::Programmer(std::string n, int i):name{n}, id{i}
{
}

ifstream& operator>>(ifstream& ifs, Programmer& programmer)
{
	string to_process;
	getline(ifs, to_process);
	if (to_process == "")
		return ifs;
	stringstream ss(to_process);
	string name;
	
	string id;

	getline(ss, name, '|');
	getline(ss, id);

	programmer.name = name;
	programmer.id= stoi(id);
	return ifs;
}
