#pragma once
#include <assert.h>
#include <string>
#include <iostream>
#include "Duration.h"
using namespace std;
//Each Tutorial has a title, a presenter 
//(name of the presenter person), a duration 
//(minutes and seconds), a number of likes and
//a link towards the online resource containing 
//the tutorial.

class Tutorial
{
private:
	string title;
	string presenter;
	Duration duration;
	int likes;
	string link;

public:
	bool operator==(const Tutorial t);
	bool operator!=(const Tutorial t);
	friend istream& operator>>(istream& input, Tutorial& tutorial);
	friend ostream& operator<<(ostream& output, Tutorial& tutorial);
	Tutorial();
	Tutorial(string title, string presenter, Duration durantion, int likes, string link);

	//return the title of the tutorial
	string get_title();

	//retrun the presenter of the tutorial
	string get_presenter();

	//return the duration of the tutorial
	Duration get_duration();

	//get the likes
	int get_likes();

	//get the link
	string get_link();

	//set the title
	void set_title(string& new_title);

	//set the presenter
	void set_presenter(string& new_presenter);

	//set the duration
	void set_duration(Duration& new_duration);

	//set likes
	void set_likes(int new_likes);

	//set likes
	void set_link(string &new_link);

	//converts a Tutorial to string
	string tostring();
};
typedef Tutorial TElem;
void test_tutorial();