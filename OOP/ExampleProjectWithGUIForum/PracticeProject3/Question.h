#pragma once
#include <string>
using namespace std;
class Question
{
private:
	int id;
	string text;
	string user_name;
public:
	int getId();
	string getText();
	string getUserName();
	Question(int id, string text, string user_name);
	void setId(int id);
	void setText(string text);
	void setUserName(string name);
	string toString();
};

