#include "ValidatorExceptions.h"

ValidatorException::ValidatorException():error_message{""}
{}

ValidatorException::ValidatorException(const std::string& message):error_message{message}
{}

const char* ValidatorException::what() const
{
	return this->error_message.c_str();
}

const char* InvalidTitleException::what() const
{
	return "Invalid title entered!\n";
}

const char* InvalidPresenterException::what() const
{
	return "Invalid Presenter entered!\n";
}

const char* InvalidDurationException::what() const 
{
	return "Invalid Duration entered!\n";
}

const char* InvalidLikesException::what() const 
{
	return "Invalid Likes entered!\n";
}

const char* InvalidLinkException::what() const
{
	return "Invalid Link entered!\n";
}
