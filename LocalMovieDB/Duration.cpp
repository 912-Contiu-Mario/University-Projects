#include "Duration.h"

#include <assert.h>
#include <string>

Duration::Duration()
{
	this->minutes = 0;
	this->seconds = 0;

}
Duration::Duration(int minutes, int seconds)
{
	this->minutes = minutes;
	this->seconds = seconds;
}

bool Duration::operator==(const Duration d)
{
	return (this->minutes == d.minutes) && (this->seconds == d.seconds);
}

int Duration::get_minutes()
{
	return this->minutes;
}

int Duration::get_seconds()
{
	return this->seconds;
}

void Duration::set_minutes(int new_minutes)
{
	this->minutes = new_minutes;
}

void Duration::set_seconds(int new_seconds)
{
	this->seconds = new_seconds;
}

std::istream& operator>>(std::istream& input, Duration& duration)
{
	int minutes, seconds;
	input >> minutes >> seconds;
	duration.set_minutes(minutes);
	duration.set_seconds(seconds);
	return input;
}

std::ostream& operator<<(std::ostream& output, Duration duration)
{
	output << duration.get_minutes() << " " << duration.get_seconds();
	return output;
}

void test_duration()
{
	Duration duration{ 33,22 };
	assert(duration.get_minutes() == 33);
	assert(duration.get_seconds() == 22);
	duration.set_minutes(44);
	duration.set_seconds(55);
	assert(duration.get_minutes() ==44);
	assert(duration.get_seconds() ==55);
}