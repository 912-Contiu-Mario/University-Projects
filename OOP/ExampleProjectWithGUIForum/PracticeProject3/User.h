#pragma once
#include <string>
using namespace std;
class User
{
private:
	string name;
public:
	string getName();
	User(string name);
	void setName(string name);

};

