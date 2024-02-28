#pragma once
#include "Repository.h"
#include "Observer.h"
#include <algorithm>

class Service
{
private:
	Repository& repo;

public:
	Service(Repository& repo);
	Repository& getRepo();
	int getAnswerNumber(Question question);
	void sortQuestion();
	vector<Answer> getAnswers(Question question);
	void addQuestion(string text, string userName);
	void addAnswer(int question_id, string user_name, string text);
	
};

