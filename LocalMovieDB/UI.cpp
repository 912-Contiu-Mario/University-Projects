#include "UI.h"
void UI::user_type_menu_entries()
{
	 
	cout << "choose from the following user types: "<<endl;
	cout << "1. administrator"<<endl;
	cout << "2. user"<<endl;
	cout << "3. stop program"<<endl;
}

void UI::administrator_menu_entries()
{
	cout << "welcome to the administrator mode! as an andministrator, you have the following options:"<<endl;
	cout << "1. add tutorial"<<endl;
	cout << "2. delete tutorial"<<endl;
	cout << "3. update tutorial"<<endl;
	cout << "4. display database"<<endl;
	cout << "5. exit administrator" << endl;
}


UI::UI(Service& serv): service{serv}
{}


void UI::user_menu()
{
	int user_choice;
	while (true)
	{
		string presenter;
		cout << "1. see tutorials by a presenter\n";
		cout << "2. delete tutorial from watchlist\n";
		cout << "3. see watchlist\n";
		cout << "4. display watchlist\n";
		cout << "5. exit\n";
		cout << "> ";
		cin >> user_choice;
		if (user_choice == 1)
		{
			see_tutorial_presenter();
		}
		else if (user_choice == 2) {
			try
			{
				delete_user();
			}
			catch (exception& e)
			{
				cout << e.what();
			}
		}
		else if (user_choice == 4)
		{
			this->get_service().DisplayWatchlist();
		}
		else if (user_choice == 3)
			cout << this->get_service().Service_Array_To_String(2);
		else if (user_choice == 5)
			break;
		else
			cout << "incorrect user_choice\n\n";
	}
	this->start_menu();
}

void UI::administrator_menu()
{
	int adm_choice;
	while (true) {
		this->administrator_menu_entries();
		cout << "> ";
		cin >> adm_choice;
		if (adm_choice == 1)
		{
			try
			{
				this->add_admin();
			}
			catch (exception& e) {
				cout << e.what();
			}
		}
		else if (adm_choice == 2)
		{
			try {
				this->delete_admin();
			}
			catch (exception& e)
			{
				cout << e.what();
			}
		}
		else if (adm_choice == 3)
		{
			try
			{
				this->update_admin();
			}
			catch (exception& e)
			{
				cout << e.what();
			}
		}
		else if (adm_choice == 4)
		{
			cout << this->get_service().Service_Array_To_String(1);
		}
		else if (adm_choice == 5)
			break;
	}
	this->start_menu();
}

void UI::start_menu()
{
	this->user_type_menu_entries();
	int choice;
	cout << "> ";
	cin >> choice;
	if (choice == 1)
		this->administrator_menu();
	else if (choice == 2)
		this->user_menu();
	else if (choice == 3)
		exit(0);
	else
		cout << "invalid command\n\n";
}

void UI::update_menu_entries()
{
	cout << "choose what to update" << endl;
	cout << "1. new_title" << endl;
	cout << "2. new_presenter" << endl;
	cout << "3. new_duration" << endl;
	cout << "4. new_likes" << endl;
	cout << "5. new_link" << endl;
}

void UI::update_admin()
{
	int update_option;
	string title;
	string presenter;
	int minutes;
	int seconds;
	int likes;
	string link;
	string title_ident;
	string presenter_ident;

	cout << "to identify the tutorial you want to update, you'll have to enter the title and the presenter" << endl;
	cout << "title(for identifying) >";
	getline(cin >> ws, title_ident);
	cout << "presenter(for identifying) >";
	getline(cin >> ws, presenter_ident);
	service.Process_Presenter(presenter_ident);
	service.Process_Title(title_ident);
	this->update_menu_entries();
	cout << "> ";
	cin >> update_option;
	if (update_option == 1)
	{
		cout << "new_title > ";
		getline(cin >> ws, title);
		service.Process_Title(title);
		service.Update_Tutorial(title_ident, presenter_ident, title, "", Duration(), 0, "", 1);
		cout << "title updated successfully\n\n";
	}
	else if (update_option == 2)
	{
		cout << "new_presenter > ";
		getline(cin >> ws, presenter);
		service.Process_Presenter(presenter);
		service.Update_Tutorial(title_ident, presenter_ident, "", presenter, Duration(), 0, "", 2);
		cout << "presenter updated successfully\n\n";
	}
	else if (update_option == 3)
	{
		cout << "minutes> ";
		cin >> minutes;
		cout << "seconds> ";
		cin >> seconds;
		service.Process_Duration(Duration(minutes, seconds));
		service.Update_Tutorial(title_ident, presenter_ident, "", "", Duration(minutes, seconds), 0, "", 3);						throw exception("duration couldn't be updated\n\n");
		cout << "duration updated successfully\n\n";
	}
	else if (update_option == 4)
	{
		cout << "new_likes> ";
		cin >> likes;
		service.Process_Likes(likes);
		service.Update_Tutorial(title_ident, presenter_ident, "", "", Duration(), likes, "", 4);
		cout << "likes updated successfully\n\n";
	}
	else if (update_option == 5)
	{
		cout << "new_link> ";
		getline(cin >> ws, link);
		service.Process_Link(link);
		service.Update_Tutorial(title_ident, presenter_ident, "", "", Duration(), 0, link, 5);
		cout << "link updated successfully\n\n";
	}
	else
		throw exception("inccorect option argument\n\n");
}

void UI::delete_admin()
{
	string title_ident;
	string presenter_ident;
	cout << "to identify the tutorial you want to delete, you'll have to enter the title and presenter" << endl;
	cout << "title(for identifying) >";
	getline(cin >> ws, title_ident);
	cout << "presenter(for identifying) >";
	getline(cin >> ws, presenter_ident);
	service.Process_Presenter(presenter_ident);
	service.Process_Title(title_ident);
	service.Delete_Tutorial_Admin(title_ident, presenter_ident);
	cout << "tutotorial deleted successfully\n\n";
}


void UI::add_admin()
{
	string title;
	string presenter;
	string link;
	int likes;
	int minutes;
	int seconds;
	cout << "title > ";
	getline(cin >> ws, title);
	service.Process_Title(title);
	cout << "presenter > ";
	getline(cin >> ws, presenter);
	service.Process_Presenter(presenter);
	cout << "minutes > ";
	cin >> minutes;
	cout << "seconds > ";
	cin >> seconds;
	service.Process_Duration(Duration(minutes, seconds));
	cout << "likes > ";
	cin >> likes;
	service.Process_Likes(likes);
	cout << "link > ";
	getline(cin >> ws, link);
	service.Process_Link(link);
	this->get_service().Add_Tutorial_Admin(title, presenter, Duration(minutes, seconds), likes, link);
}

void UI::see_tutorial_presenter()
{
	string presenter;
	int index = 0, length, add_choice, k = 0;
	Tutorial tutorial;
	Tutorial array_of_tut[100];
	tutorial = array_of_tut[0];
	cout << "presenter >";
	getline(cin >> ws, presenter);

	length = this->get_service().Tutorials_by_Presenter(presenter, array_of_tut);
	if (length == 0)
	{
		cout << "no tutorials found for this presenter\n\n";
		return;
	}
	system("cls");
	while (true)
	{
		tutorial = array_of_tut[index];
		if (k == 0)
		{
			cout << "1. add" << endl << "2. next" << endl << "3. stop" << endl;
			cout << tutorial.tostring();
		}
		cout << "> ";
		cin >> add_choice;
		if (add_choice == 1)
		{
			try {
				this->get_service().Add_Tutorial_User(tutorial.get_title(), tutorial.get_presenter(), tutorial.get_duration(), tutorial.get_likes(), tutorial.get_link());
				cout << "tutorial added to watchlist successfully!" << endl;
			}
			catch (exception& e)
			{
				cout << e.what();
			}
		}
		else if (add_choice == 2)
		{
			index++;
			system("cls");
			cout << "1. add" << endl << "2. next" << endl << "3. stop" << endl;
			cout << tutorial.tostring();
		}
		else if (add_choice == 3)
			break;

		if (index == length)
			index = 0;
		k++;
	}
}

void UI::delete_user()
{
	string title_ident, presenter_ident, like_status;
	cout << "to identify the tutorial, enter title and presenter\n";
	cout << "title >";
	getline(cin >> ws, title_ident);
	service.Process_Title(title_ident);
	cout << "presenter >";
	getline(cin >> ws, presenter_ident);
	Tutorial deleted_tutorial = service.Search_Tutorial_S(title_ident, presenter_ident);
	service.Process_Presenter(presenter_ident);
	this->get_service().Delete_Tutorial_User(title_ident, presenter_ident);
	cout << "tutotorial deleted successfully from the watchlist\n\n";

	cout << "did you like the video?(y/n)" << endl << "> ";
	getline(cin >> ws, like_status);
	if (like_status == "y")
	{
		this->get_service().Update_Tutorial(title_ident, presenter_ident, "", "", Duration(), deleted_tutorial.get_likes() + 1, "", 4);
		cout << "tutorial liked\n\n";
	}
}


Service& UI::get_service()
{
	return this->service;
}
