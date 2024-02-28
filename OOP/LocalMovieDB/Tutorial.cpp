#include "Tutorial.h"
#include <sstream>
#include <string.h>
#include <iostream>
#include <assert.h>
#include <fstream>
#include "Utils.h"

using namespace std;


bool Tutorial::operator==(const Tutorial t)
{
	return (this->title == t.title) && (this->presenter == t.presenter);
}

bool Tutorial::operator!=(const Tutorial t)
{
	return (this->title != t.title)||(this->presenter != t.presenter);
}

Tutorial::Tutorial()
{
	this->duration = Duration();
	this->likes = 0;
	this->link = "";
	this->presenter = "";
	this->title = "";
}
Tutorial::Tutorial(string title, string presenter, Duration duration, int likes, string link)
{
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->link = link;
}
//returns the title of the given tutorial
string Tutorial::get_title()
{
	return this->title;
}
// returns the presenter of the given tutorial
string Tutorial::get_presenter()
{
	return this->presenter;
}
//returns the duration of the tutorial
Duration Tutorial::get_duration()
{
	return this->duration;
}
//returns the number of likes of a tutorial
int Tutorial::get_likes()
{
	return this->likes;
}
//returns the link of the tutorial
string Tutorial::get_link()
{
	return this->link;
}
//sets the title of the given tutorial to the new_title
void Tutorial::set_title(string& new_title)
{
	this->title = new_title;
}
//sets the presenter of the given tutorial to the new_presenter
void Tutorial::set_presenter(string& new_presenter)
{
	this->presenter = new_presenter;
}
//sets the duration of the given tutorial to the new_duration
void Tutorial::set_duration(Duration& new_duration)
{
	this->duration = new_duration;
}
//sets the likes of the given tutorial to the new_likes
void Tutorial::set_likes(int new_likes)
{
	this->likes = new_likes;
}
//sets the link of the given tutorial to the new_link
void Tutorial::set_link(string& new_link)
{
	this->link = new_link;
}

string Tutorial::tostring()
{
	return "Title: "+ this->title + " " + "| Presenter: "+this->presenter + " " + "| Duration: "+ to_string(this->get_duration().get_minutes()) + ":" + to_string(this->duration.get_seconds()) + " " + "| Likes: "+ to_string(this->likes) + " " +"| Link: " + this->link + '\n';
}

istream& operator>>(istream& input, Tutorial& tutorial)
{
	string aux;
	int minutes, seconds;
	getline(input, aux, '|');
	tutorial.title = trim(aux);


	getline(input, aux, '|');
	tutorial.presenter = trim(aux);
	getline(input, aux, '|');
	aux = trim(aux);
	std::stringstream ss(aux);
	ss >> tutorial.duration;

	getline(input, aux, '|');
	aux = trim(aux);
	stringstream sss(aux);
	sss >> tutorial.likes;
	getline(input, aux);
	tutorial.link = trim(aux);

	return input;
}

ostream& operator<<(ostream& output, Tutorial& tutorial)
{
	output << tutorial.get_title() << " | " << tutorial.get_presenter()<< " | " << tutorial.get_duration() << " | " << tutorial.get_likes() << " | " << tutorial.get_link();
	return output;
}



void test_tutorial()
{
	string aux;
	Duration duration(56, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	assert(tutorial.get_title() == "What is a pointer");
	assert(tutorial.get_presenter() == "Arabara");

	assert(tutorial.get_duration().get_minutes() == 56);
	assert(tutorial.get_likes() == 500);
	assert(tutorial.get_link() == "www.google.com");
	aux = "What is a NULL pointer?";
	tutorial.set_title(aux);
	assert(tutorial.get_title() == "What is a NULL pointer?");
	assert(tutorial.get_likes() == 500);
	assert(tutorial.get_link() == "www.google.com");

	aux = "RabuDhabi";
	tutorial.set_presenter(aux);
	assert(tutorial.get_presenter() == "RabuDhabi");

	Duration duration1(55, 33);
	tutorial.set_duration(duration1);

	assert(tutorial.get_duration().get_minutes() == 55);
	assert(tutorial.get_duration().get_seconds() == 33);

	tutorial.set_likes(1000);
	assert(tutorial.get_likes() == 1000);

	aux = "www.youtube.com";
	tutorial.set_link(aux);
	assert(tutorial.get_link() == "www.youtube.com");

	assert(tutorial.tostring() == "Title: What is a NULL pointer? | Presenter: RabuDhabi | Duration: 55:33 | Likes: 1000 | Link: www.youtube.com\n");
	Tutorial tutorial1, tutorial2, tutorial3;
	ifstream testfile;
	testfile.open("test.txt");
	while (testfile >> tutorial1)
		cout << tutorial1.tostring();
	system("pause");
}


