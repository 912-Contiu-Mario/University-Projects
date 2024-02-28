#include "CSVWatchList.h"
#include "Utils.h"
#include <Windows.h>
#include <shellapi.h>
using namespace std;


void CSVWatchList::write_to_file()
{
	string filename= this->filename;
	ofstream file;
	file.open(filename);
	if (!file.is_open())
		throw InvalidFileException();
	vector<TElem> watch_list = this->get_vector();
	for (auto i : watch_list)
		file << i.get_title() << "," << i.get_presenter() << "," << i.get_duration().get_minutes() << ":" << i.get_duration().get_seconds() << "," << i.get_likes() << "," << i.get_link() << "\n";
	file.close();
	if (file.is_open())
		throw FileStillOpenException();
}

void CSVWatchList::display_watchlist()
{
	string fileLocation = "\"" + this->filename + "\"";

	ShellExecuteA(
		NULL,
		"open",
		"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
		fileLocation.c_str(),
		NULL,
		SW_SHOWNORMAL
	);
}
//void test_write_data_to_file()
//{
//	CSVWatchList uw("test_CSV_watchlist.csv");
//
//	Tutorial tutorial(string("Why are we here"), string("This is me"), Duration(22, 33), 1000, string("www.dada.com"));
//	uw.add_element(tutorial);
//	Tutorial tutorial1(string("Nobody knows"), string("This is you"), Duration(555, 22), 5000, string("www.google.com"));
//	uw.add_element(tutorial1);
//	uw.write_to_file();
//}




