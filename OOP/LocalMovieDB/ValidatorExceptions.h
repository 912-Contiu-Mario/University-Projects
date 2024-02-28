#include <string>
#include <exception>

class ValidatorException:public std::exception {
protected:
	std::string error_message;
public:
	ValidatorException();
	ValidatorException(const std::string& message);
	virtual const char* what() const override;
};


class InvalidTitleException: public ValidatorException{
	const char* what() const override;
};

class InvalidPresenterException : public ValidatorException {
	const char* what() const override;
};

class InvalidDurationException : public ValidatorException {
	const char* what() const override;
};

class InvalidLikesException : public ValidatorException {
	const char* what()const override;
};

class InvalidLinkException : public ValidatorException {
	const char* what()const override;
};