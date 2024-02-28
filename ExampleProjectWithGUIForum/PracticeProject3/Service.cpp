#include "Service.h"
#include <random>
Service::Service(Repository& repo):repo{repo}
{

}

Repository& Service::getRepo()
{
	return this->repo;
}

int Service::getAnswerNumber(Question question)
{
	vector<Answer>& answers = this->getRepo().getAnswers();
	int number = 0;
	for (auto answer : answers)
	{
		if (answer.getQuestionId() == question.getId())
			number++;
	}
	return number;
}


void Service::sortQuestion()
{
	vector<Question>& questions = this->getRepo().getQuestions();
	sort(questions.begin(), questions.end(), [this](Question q1, Question q2)
		{
			return getAnswerNumber(q1) > getAnswerNumber(q2);
		}
	);
}

vector<Answer> Service::getAnswers(Question question)
{
	vector<Answer> answers = this->repo.getAnswers();
	vector<Answer> answers_to_return;
	int id = question.getId();
	for (auto i : answers)
	{
		if (i.getQuestionId() == id)
		{
			answers_to_return.push_back(i);
		}
	}
	return answers_to_return;
}

void Service::addQuestion(string text, string userName)
{
	vector<Question> questions = this->repo.getQuestions();
	int new_id=0;
	for (auto i : questions)
	{
		new_id += i.getId();
	}
	Question question(new_id, text, userName);
	repo.addQuestion(question);
}

void Service::addAnswer(int question_id, string user_name, string text)
{
	int id = rand() % 100;
	Answer answer(question_id, id, user_name, text, 0);
	this->repo.addAnswer(answer);
}




