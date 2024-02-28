#include "RepositoryExceptions.h"
#include <string>
using namespace std;

RepositoryException::RepositoryException(string& message): error_message{message}
{}

RepositoryException::RepositoryException() : exception{}, error_message{ "" }
{}

const char* RepositoryException:: what() const
{
	return this->error_message.c_str();
}

const char* DuplicateTutorialException::what() const
{
	char* error_message = "This Tutorial exists already in the repo!\n";
	return error_message;
}

const char* NonExistentTutorialException::what() const
{
	return "Tutorial doesn't exist!\n";
}

FileException::FileException(std::string& message)
{
	this->error_message = message;
}

const char* FileException::what() const
{
	return this->error_message.c_str();
}

FileException::FileException(): exception{}, error_message{""}
{}

const char* InvalidFileException::what() const
{
	return "File couldn't be opened!\n";
}

const char* FileStillOpenException::what() const
{
	return "File couldn't be closed!\n";
}
