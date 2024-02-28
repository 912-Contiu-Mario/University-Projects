#pragma once
#include <iostream>
class Duration
{
private:
	int minutes;
	int seconds;
	public:
		bool operator==(const Duration d);
		friend std::istream &operator>>(std::istream& input, Duration& duration);
		friend std::ostream& operator<<(std::ostream& output, Duration duration);
		Duration();
		Duration(int minutes, int seconds);
		//returns the minutes 
		int get_minutes();

		//returns the seconds
		int get_seconds();

		//sets the minutes
		void set_minutes(int new_minutes);
		//sets the seconds
		void set_seconds(int new_seconds);
};



void test_duration();
