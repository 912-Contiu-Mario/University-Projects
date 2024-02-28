#include "User.h"

string User::getName()
{
    return name;
}

User::User(string name):name{name}
{
}

void User::setName(string name)
{
    this->name = name;
}
