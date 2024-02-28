#pragma once
#include <string>
#include <fstream>
class Programmer
{
private:
	std::string name;
	int id;
public:
	std::string getName() const;
	int getId() const;
	Programmer(std::string n, int i);
	Programmer():name{""}, id{0}{}
	friend std::ifstream& operator>>(std::ifstream& ifs, Programmer& programmer);
};