#include "Repository.h"
#include "sstream"

vector<string> tokenize(string to_tokenize, char separator)
{
	vector<string> tokens;
	stringstream ss(to_tokenize);
	string token;
	while (getline(ss, token, separator))
	{
		tokens.push_back(token);
	}
	return tokens;
}
void Repository::readFromFile()
{
	ifstream user_file("Users.txt");
	string user;
	vector<string> tokens;

	while (getline(user_file, user))
	{
		tokens = tokenize(user, '|');
		User user_to_add("");
		user_to_add.setName(tokens[0]);
		users.push_back(user_to_add);
	}
	ifstream question_file("Questions.txt");
	string question;
	while (getline(question_file, question))
	{
		tokens = tokenize(question, '|');
		Question question_to_add(0,"","");
		question_to_add.setId(stoi(tokens[0]));
		question_to_add.setText(tokens[1]);
		question_to_add.setUserName(tokens[2]);
		questions.push_back(question_to_add);
	}

	ifstream answers_file("Answers.txt");
	string answer;
	while (getline(answers_file, answer))
	{
		tokens = tokenize(answer, '|');
		Answer answer_to_add(0, 0, "", "", 0);

		answer_to_add.setAnswerId(stoi(tokens[0]));
		answer_to_add.setQuestionId(stoi(tokens[1]));
		answer_to_add.setUserName(tokens[2]);
		answer_to_add.setText(tokens[3]);
		answer_to_add.setVotes(stoi(tokens[4]));
		answers.push_back(answer_to_add);
	}


	



}

Repository::Repository()
{
	this->readFromFile();
}

vector<User>& Repository::getUsers()
{
	return users;
}

vector<Answer>& Repository::getAnswers()
{
	return answers;
}

vector<Question>& Repository::getQuestions()
{
	return questions;
}

void Repository::addQuestion(Question& question)
{
	this->questions.push_back(question);

}

void Repository::addAnswer(Answer& answer)
{
	answers.push_back(answer);
}


