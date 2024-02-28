#include "Service.h"
#include <assert.h>
#include <string>
#include <iostream>
#include "Utils.h"
using namespace std;


Repository<Tutorial>& Service::Get_Repository()
{
    return this->admin_repo;
}

WatchList* Service::Get_Watchlist_Repo()
{
    return this->user_watch_list;
}

TutorialValidator& Service::Get_Validator()
{
    return this->validator;
}

int Service::Set_Validator(TutorialValidator& new_validator)
{
    this->validator = new_validator;
    return 1;
}

void Service::Set_Repository(Repository<Tutorial>& new_repository)
{
    this->admin_repo = new_repository;
}

void Service::Add_Tutorial_Admin(string& title, string& presenter, Duration& duration, int likes, string& link)
{
    Tutorial tutorial_to_add(title, presenter, duration, likes, link);
    Repository<Tutorial>& repo = this->Get_Repository();
    repo.add_element(tutorial_to_add);
    repo.write_data_to_file();
}

void Service::Add_Tutorial_User(string& title, string& presenter, Duration& duration, int likes, string& link)
{
    Tutorial tutorial_to_add(title, presenter, duration, likes, link);
    WatchList* watchlist = this->Get_Watchlist_Repo();
    watchlist->add_element(tutorial_to_add);
    watchlist->write_data_to_file();
    watchlist->write_to_file();
}

void Service::Delete_Tutorial_Admin(string& title, string& presenter){
    Repository<Tutorial>& admin_repo = this->Get_Repository();
    Repository<Tutorial>* user_watchlist = this->Get_Watchlist_Repo();
    Tutorial tutorial_to_delete = admin_repo.search_tutorial(title, presenter);
    if (user_watchlist->search_tutorial(title, presenter) != Tutorial())
        user_watchlist->delete_element(tutorial_to_delete);
    admin_repo.delete_element(tutorial_to_delete);
    admin_repo.write_data_to_file();
}

void Service::Delete_Tutorial_User(string& title, string& presenter)
{
    WatchList* user_watchlist = this->Get_Watchlist_Repo();
    Tutorial tutorial_to_delete = user_watchlist->search_tutorial(title, presenter);
    user_watchlist->delete_element(tutorial_to_delete);
    user_watchlist->write_data_to_file();
    user_watchlist->write_to_file();
}

void Service::Update_Tutorial(string title, string presenter, string new_title, string new_presenter, Duration new_duration, int new_likes, string new_link, int option)
{
    Repository<Tutorial>& admin_repo = this->Get_Repository();
    WatchList* user_watchlist = this->Get_Watchlist_Repo();
    Tutorial tutorial = admin_repo.search_tutorial(title, presenter);
    Tutorial uw_tutorial = user_watchlist->search_tutorial(title, presenter);
    switch(option){
    case 1:
        if (admin_repo.search_tutorial(new_title, presenter) == Tutorial()){
            if (uw_tutorial != Tutorial())
            {
                user_watchlist->update_element(tutorial, Tutorial(new_title, tutorial.get_presenter(), tutorial.get_duration(), tutorial.get_likes(), tutorial.get_link()));
                user_watchlist->write_data_to_file();
                user_watchlist->write_to_file();
            }
            admin_repo.update_element(tutorial, Tutorial(new_title, tutorial.get_presenter(), tutorial.get_duration(), tutorial.get_likes(), tutorial.get_link()));
            admin_repo.write_data_to_file();
        }
        break;

    case 2:
        if (admin_repo.search_tutorial(title, new_presenter) == Tutorial()) {
            if (uw_tutorial != Tutorial())
            {
                user_watchlist->update_element(tutorial, Tutorial(tutorial.get_title(), new_presenter, tutorial.get_duration(), tutorial.get_likes(), tutorial.get_link()));
                user_watchlist->write_data_to_file();
                user_watchlist->write_to_file();
            }
            admin_repo.update_element(tutorial, Tutorial(tutorial.get_title(), new_presenter, tutorial.get_duration(), tutorial.get_likes(), tutorial.get_link()));
            admin_repo.write_data_to_file();
        }
        break;

    case 3:
        if (uw_tutorial != Tutorial())
        {
            user_watchlist->update_element(tutorial, Tutorial(tutorial.get_title(), tutorial.get_presenter(), new_duration, tutorial.get_likes(), tutorial.get_link()));
            user_watchlist->write_data_to_file();
            user_watchlist->write_to_file();
        }
        admin_repo.update_element(tutorial, Tutorial(tutorial.get_title(), tutorial.get_presenter(), new_duration, tutorial.get_likes(), tutorial.get_link()));
        admin_repo.write_data_to_file();
        
    case 4:
        if (uw_tutorial != Tutorial())
        {
            user_watchlist->update_element(tutorial, Tutorial(tutorial.get_title(), tutorial.get_presenter(), tutorial.get_duration(), new_likes, tutorial.get_link()));
            user_watchlist->write_data_to_file();
            user_watchlist->write_to_file();
        }
        admin_repo.update_element(tutorial, Tutorial(tutorial.get_title(), tutorial.get_presenter(), tutorial.get_duration(), new_likes, tutorial.get_link()));
        admin_repo.write_data_to_file();
        break;

    case 5:
        if (uw_tutorial != Tutorial())
        {
            user_watchlist->update_element(tutorial, Tutorial(tutorial.get_title(), tutorial.get_presenter(), tutorial.get_duration(), tutorial.get_likes(), new_link));
            user_watchlist->write_data_to_file();
            user_watchlist->write_to_file();
        }
        admin_repo.update_element(tutorial, Tutorial(tutorial.get_title(), tutorial.get_presenter(), tutorial.get_duration(), tutorial.get_likes(), new_link));
        admin_repo.write_data_to_file();
        break;
    }
}

void Service::DisplayWatchlist()
{
    this->user_watch_list->display_watchlist();
}


int Service::Tutorials_by_Presenter(string& presenter, Tutorial* array_of_tutorials)
{
    return this->Get_Repository().search_tut_by_pres(presenter, array_of_tutorials);
}

void Service::Process_Title(string& title)
{
    title = trim(title);
    title = r_redundant_spaces(title);
    this->Get_Validator().isValidTitle(title);
}

void Service::Process_Presenter(string& presenter)
{
    presenter = trim(presenter);
    presenter = r_redundant_spaces(presenter);
    this->Get_Validator().isValidPresenter(presenter);
}

void Service::Process_Duration(Duration& duration)
{
    this->Get_Validator().isValidDuration(duration);
}

void Service::Process_Likes(int& likes)
{
    this->Get_Validator().isValidLikes(likes);
}

void Service::Process_Link(string& link)
{
    link = trim(link);
    link = r_redundant_spaces(link);
    this->Get_Validator().isValidLink(link);
}

Tutorial Service::Search_Tutorial_S(string& title, string& presenter)
{
    return this->Get_Repository().search_tutorial(title, presenter);
}

string Service::Service_Array_To_String(int option)
{
    if (option == 1)
        return this->Get_Repository().repo_array_to_string();
    else if(option == 2)
        return this->Get_Watchlist_Repo()->repo_array_to_string();
}



