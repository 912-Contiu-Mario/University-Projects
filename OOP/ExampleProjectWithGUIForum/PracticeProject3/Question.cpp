#include "Question.h"

int Question::getId()
{
    return id;
}

string Question::getText()
{
    return text;
}

string Question::getUserName()
{
    return user_name;
}

Question::Question(int id, string text, string user_name):id{id}, text{text}, user_name{user_name}
{
}

void Question::setId(int id)
{
    this->id = id;
}

void Question::setText(string text)
{
    this->text = text;
}

void Question::setUserName(string name)
{
    this->user_name = name;
}

string Question::toString()
{
    return "ID: " + to_string(id) +" | Text: " + text + " | User name: " + user_name;
}
