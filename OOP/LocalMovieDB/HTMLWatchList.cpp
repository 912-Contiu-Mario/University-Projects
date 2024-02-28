#include "HTMLWatchList.h"
#include <Windows.h>
#include <shellapi.h>

HTMLWatchList::HTMLWatchList(std::string filename, std::string user_data_filename): WatchList(filename, user_data_filename)
{}

void HTMLWatchList::write_to_file()
{
	
	ofstream file;
	file.open(this->filename);
	vector<TElem> data = this->get_vector();

	file << "<!DOCTYPE html>\n" << "<html>\n" << "<head>\n" << " <title>Tutorial Watchlist</title>\n" << "</head>\n" << "<body>\n" << "<table border = \"1\">\n";
	file << "<tr>\n" << "<td>Title</td>\n" << "<td>Presenter</td>\n" << "<td>Duration</td>\n" << "<td>Likes</td>\n" << "<td>Youtube link</td>\n"<<"</tr>\n";
	string title;
	string presenter;
	Duration duration;
	int likes;
	string link;
	for (auto i : data)
	{
		title = i.get_title();
		presenter = i.get_presenter();
		duration = i.get_duration();
		likes = i.get_likes();
		link = i.get_link();
		file << "<tr>\n" << "<td>" << title << "</td>\n" << "<td>" << presenter << "</td>\n" << "<td>" << duration << "</td>\n" << "<td>" << likes << "</td>\n" << "<td><a href=\"" << link <<"\">Link"<< "</a></td>\n" << "</tr>\n";
	}
	file << "</table>\n" << "</body>\n" << "</html>";
}

void HTMLWatchList::display_watchlist()
{
	std::string filename_loc = "C:\\Users\\mario\\source\\repos\\a89-912-Contiu-Mario\\" + this->filename;
	ShellExecuteA(
		NULL,
		"open",
		"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe",
		filename_loc.c_str(),
		NULL,
		SW_SHOWNORMAL
	);
}


//void test_write_to_file_html()
//{
//	HTMLWatchList uw("test__watchlist.html");
//	Tutorial tutorial(string("Why are we here"), string("This is me"), Duration(22, 33), 1000, string("www.dada.com"));
//	uw.add_element(tutorial);
//	Tutorial tutorial1(string("Nobody knows"), string("This is you"), Duration(555, 22), 5000, string("www.google.com"));
//	uw.add_element(tutorial1);
//	uw.write_to_file();
//}
