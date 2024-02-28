#include "Answer.h"

int Answer::getQuestionId()
{
    return question_id;
}

int Answer::getAnswerId()
{
    return answer_id;
}

string Answer::getUserName()
{
    return user_name;
}

string Answer::getText()
{
    return text;
}

int Answer::getVotes()
{
    return votes;
}

void Answer::setQuestionId(int id)
{
    this->question_id = id;
}

void Answer::setAnswerId(int id)
{
    this->answer_id = id;
}

void Answer::setUserName(string name)
{
    this->user_name = name;
}

void Answer::setText(string text)
{
    this->text = text;
}

void Answer::setVotes(int votes)
{
    this->votes = votes;

}

void Answer::search()
{

}

Answer::Answer(int q_id, int a_id, string u_name, string t, int v):question_id{q_id}, answer_id{a_id}, user_name{u_name}, text{t}, votes{v}
{
}

string Answer::toString()
{
    return "Question ID: " + to_string(question_id) + " | Answer ID: "+ to_string(answer_id) + " | User name: "+ user_name + " | Text: "+text + " | Votes: "+ to_string(votes);
}
