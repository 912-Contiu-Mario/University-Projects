#include "Validator.h"

void TutorialValidator::isValidTitle(string& title)
{
	if (title.length() > 100 || title.length() < 0)
		throw InvalidTitleException();
}

void TutorialValidator::isValidPresenter(string& presenter)
{
	if (presenter.length() < 2 || presenter.length() > 50)
		throw InvalidPresenterException();
}

void TutorialValidator::isValidDuration(Duration& duration)
{
	if (duration.get_minutes() < 0 || duration.get_seconds() < 0 || duration.get_seconds() > 60)
		throw InvalidDurationException();
}

void TutorialValidator::isValidLikes(int likes)
{
    if(likes < 0)
		throw InvalidLikesException();
}
void TutorialValidator::isValidLink(string& link)
{
	if (link.length() < 5)
		throw InvalidLinkException();
	
}




