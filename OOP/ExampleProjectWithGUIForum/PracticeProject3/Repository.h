#pragma once
#include "Answer.h"
#include "Question.h"
#include "User.h"
#include <vector>
#include <fstream>

using namespace std;
class Repository
{
private:
	vector<User> users;
	vector<Answer> answers;
	vector<Question> questions;
public:
	void readFromFile();
	Repository();
	vector<User>& getUsers();
	vector<Answer>& getAnswers();
	vector<Question>& getQuestions();
	void addQuestion(Question& question);
	void addAnswer(Answer& answer);
};

