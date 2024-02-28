#pragma once
#include <string>
#include <exception>
class RepositoryException: public std::exception {
protected:
	std::string error_message;
public:
	RepositoryException();
	RepositoryException(std::string& message);
	virtual ~RepositoryException() {}
	virtual const char* what() const override;
};


class DuplicateTutorialException : public RepositoryException {
	const char* what() const override;
};

class NonExistentTutorialException : public RepositoryException {
	const char* what() const override;
};

class FileException : public std::exception {
protected:std::string error_message;
public:
	FileException();
	FileException(std::string& message);
	virtual const char* what() const override;
};

class InvalidFileException : public FileException {
	const char* what() const override;
};

class FileStillOpenException: public FileException {
	const char* what() const override;
};