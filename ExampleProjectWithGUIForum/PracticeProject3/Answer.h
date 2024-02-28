#pragma once
#include <string>
using namespace std;
class Answer
{
private:
	int question_id;
	int answer_id;
	string user_name;
	string text;
	int votes;
public:
	int getQuestionId();
	int getAnswerId();
	string getUserName();
	string getText();
	int getVotes();
	void setQuestionId(int id);
	void setAnswerId(int id);
	void setUserName(string name);
	void setText(string text);
	void setVotes(int votes);
	void search();
	Answer(int q_id, int a_id, string u_name, string t, int v);
	string toString();
};

