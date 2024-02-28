#pragma once
#include "Repository.h"
#include "WatchList.h"
class Service
{
private:
	Repository<Tutorial> admin_repo;
	WatchList* user_watch_list;	
	TutorialValidator validator;
public:

	void DisplayWatchlist();

	//returns the user watchlist
	WatchList* Service::Get_Watchlist_Repo();

	//puts into array_of_tutorials all tutorials by a presenter and returns the number of tutorials added
	int Tutorials_by_Presenter(string& presenter, Tutorial* array_of_tutorials);

	Service(const Repository<Tutorial> r, WatchList* u,TutorialValidator v): admin_repo{ r }, user_watch_list{u}, validator {v}
	{}

	//returns the admin_repo
	Repository<Tutorial>& Get_Repository();

	//returns the tutorial_validator
	TutorialValidator& Get_Validator();

	//sets a new tutorial_validator
	int Set_Validator(TutorialValidator& new_validator);

	//sets the admin_repo
	void Set_Repository(Repository<Tutorial>& new_repository);

	//adds a tutorial by constructing it with the given parameters
	void Add_Tutorial_Admin(string& title, string& presenter, Duration& duration, int likes, string& link);

	void Add_Tutorial_User(string& title, string& presenter, Duration& duration, int likes, string& link);


	//deletes a tutorial by the given parameters
	void Delete_Tutorial_Admin(string& title, string& presenter);

	void Delete_Tutorial_User(string& title, string& presenter);

	//updates a tutorial based on the option given, ignores all the other parameters
	void Update_Tutorial(string title, string presenter, string new_title, string new_presenter, Duration new_duration, int new_likes, string new_link, int option);

	//processes the title and returns its validaty
	void Process_Title(string& title);

	//porcesses the presenter and returns its validity
	void Process_Presenter(string& presenter);

	//processes the duration and returns its validaty
	void Process_Duration(Duration& duration);

	//porcesses the likes and returns its validaty
	void Process_Likes(int& likes);

	//processes the link and returns its validaty
	void Process_Link(string& link);

	//seearch a tutorial with a title and a presenter
	Tutorial Service::Search_Tutorial_S(string& title, string& presenter);

	//if option is 1 the dynamic array from repo is transformed into string form, if option 2 the dynamic array from watchlist is transformed into styring form
	string Service_Array_To_String(int option);
};


void test_service();