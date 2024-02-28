#include "UI.h"
#include <crtdbg.h>
#include "CSVWatchList.h"
#include "HTMLWatchList.h"


WatchList* init_watchlist()
{
	cout << "Choose File Type:" << endl;
	cout << "1. HTML" << endl;
	cout << "2. CSV" << endl;
	std::string choice;
	cout << "Choice: ";
	cin >> choice;
	WatchList* watchlist;

	if (choice == "HTML") {
		watchlist = new HTMLWatchList("WatchList.html", "uwdata.txt");
		return watchlist;
	}
	else if (choice == "CSV") {
		watchlist = new CSVWatchList("WatchList.csv", "uwdata.txt");
		return watchlist;
	}
}

void run()
{
	Repository<Tutorial> repo("repodata.txt");
	WatchList* watchlist;
	try {
		watchlist = init_watchlist();
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	TutorialValidator validator;
	Service serv(repo, watchlist, validator);
	UI ui(serv);
	ui.start_menu();
	delete watchlist;
}

int main()
{
	run();
	_CrtDumpMemoryLeaks();
}
