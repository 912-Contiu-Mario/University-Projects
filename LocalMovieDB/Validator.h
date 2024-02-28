#pragma once
#include <string>
#include <vector>
#include "Tutorial.h"
#include "ValidatorExceptions.h"

class TutorialValidator{
public:
	ValidatorException ve;
	//returns the validaty of the presenter
	void isValidPresenter(string& presenter);

	//returns the validaty of the link
	void isValidLink(string& link);

	//returns the validaty of the title
	void isValidTitle(string& title);

	//returns the validaty duration
	void isValidDuration(Duration& duration);

	//retuns the validaty of the likes
	void isValidLikes(int likes);

};
