#pragma once
#include "Validator.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include "RepositoryExceptions.h"

template <typename TElem>

class Repository
{
private:
	vector<TElem> array;
	std::string repo_filename;
public:
	Repository(const string& repo_filename);
	Repository(int a);
	Repository();

	//add_admin to the admin_repo 10 tutorials
	void intialize_10_tutorials();

	//get the dynamic array
	vector<TElem>& get_vector();

	//adds an element to the repo
	void add_element(TElem element);

	//delete an element
	void delete_element(TElem element);

	//update_admin an element
	void update_element(TElem element_to_update, TElem new_element);

	//find an element by giving the element
	int find_element_position(TElem element_to_find);

	//search a tutorial by title and presenter
	Tutorial search_tutorial(string& title, string& presenter);

	//returns the dynamic array of elements in string form
	string repo_array_to_string();

	//return the postiion of a tutorial by presenter
	int Repository<TElem>::search_tut_by_pres(string& presenter, Tutorial* array_of_tutorials);

	//reads data from the file with this->repo_filename name
	void read_data_from_file();

	//writes data to file with this->repo_filename name
	void write_data_to_file();

	std::string get_filename();
};


template <class TElem>
void Repository<TElem>::add_element(TElem element)
{
	auto it = std::find(this->get_vector().begin(), this->get_vector().end(), element);
	if (it != get_vector().end())
		throw DuplicateTutorialException();
	this->get_vector().push_back(element);
}

template<typename TElem>
Repository<TElem>::Repository(): repo_filename{""}
{}

template <class TElem>
Repository<TElem>::Repository(const string& repo_filename)
{
	this->repo_filename = repo_filename;
	this->read_data_from_file();
}
template <class TElem>
Repository<TElem>::Repository(const int a)
{
	this->intialize_10_tutorials();
}
template <class TElem>
vector<TElem>& Repository<TElem>::get_vector()
{
	return this->array;
}
template <class TElem>
void Repository<TElem>::delete_element(TElem element)
{
	auto it = std::find(this->get_vector().begin(), this->get_vector().end(), element);
	if (it == get_vector().end())
		throw NonExistentTutorialException();
	this->get_vector().erase(it);
	this->write_data_to_file();
}
template <class TElem>
int Repository<TElem>::search_tut_by_pres(string& presenter, Tutorial* array_of_tutorials)
{
	int found = 0;
	auto v = this->get_vector();
	for (auto it:this->get_vector())
	{
		if (it.get_presenter() == presenter)
		{
			array_of_tutorials[found] = it;
			found++;
		}
	}
	return found;
}


template <class TElem>
Tutorial Repository<TElem>::search_tutorial(string& title, string& presenter)
{
	vector<TElem> vector_aux = this->get_vector();
	Tutorial tutorial_to_find{ title, presenter, Duration(), 0, string() };
	auto it = std::find(vector_aux.begin(), vector_aux.end(), tutorial_to_find);
	if(it == vector_aux.end())
		return Tutorial();
	return *it;
}

template <class TElem>
int Repository<TElem>::find_element_position(TElem element_to_find)
{
	auto it = std::find(this->get_vector().begin(),this->get_vector().end(), element_to_find);
	return it - this->get_vector().begin();
}

template <class TElem>
string Repository<TElem>::repo_array_to_string()
{
	string string_to_return;
	for (auto it : this->get_vector())
		string_to_return += it.tostring();
	return string_to_return;
}

template <class TElem>
void Repository<TElem>::update_element(TElem element_to_update, TElem new_element)
{	
	std::vector<TElem>& vector_aux = this->get_vector();
	std::replace(vector_aux.begin(), vector_aux.end(), element_to_update, new_element);
	auto it = std::find(vector_aux.begin(), vector_aux.end(), new_element);
	if (it == vector_aux.end())
		throw NonExistentTutorialException();
}


template <class TElem>
void Repository<TElem>:: intialize_10_tutorials()
{
	Tutorial t1 = Tutorial("C++", "RhabuDhab", Duration(100, 20), 5, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	Tutorial t2 = Tutorial("Python", "TechWithTim", Duration(60, 45), 4, "https://www.youtube.com/watch?v=_uQrJ0TkZlc");
	Tutorial t3 = Tutorial("Java", "Programming with Mosh", Duration(120, 10), 8, "https://www.youtube.com/watch?v=eIrMbAQSU34");
	Tutorial t4 = Tutorial("JavaScript", "Traversy Media", Duration(80, 15), 6, "https://www.youtube.com/watch?v=Qqx_wzMmFeA");
	Tutorial t5 = Tutorial("React", "FreeCodeCamp", Duration(45, 30), 3, "https://www.youtube.com/watch?v=DLX62G4lc44");
	Tutorial t6 = Tutorial("Node.js", "The Net Ninja", Duration(90, 50), 7, "https://www.youtube.com/watch?v=U8XF6AFGqlc");
	Tutorial t7 = Tutorial("HTML/CSS", "Dev Ed", Duration(70, 35), 5, "https://www.youtube.com/watch?v=CBMkfz_NTCk");
	Tutorial t8 = Tutorial("Machine Learning", "Sentdex", Duration(150, 0), 10, "https://www.youtube.com/watch?v=_P7X8tMplsw");
	Tutorial t9 = Tutorial("Data Structures", "Abdul Bari", Duration(200, 40), 9, "https://www.youtube.com/watch?v=BBpAmxU_NQo");
	Tutorial t10 = Tutorial("Flutter", "The Flutter Way", Duration(55, 10), 4, "https://www.youtube.com/watch?v=GLSG_Wh_YWc");

	this->add_element(t1);
	this->add_element(t2);
	this->add_element(t3);
	this->add_element(t4);
	this->add_element(t5);
	this->add_element(t6);
	this->add_element(t7);
	this->add_element(t8);
	this->add_element(t9);
	this->add_element(t10);
}

template <class TElem>
void Repository<TElem>::read_data_from_file()
{
	Tutorial tut;
	ifstream file;
	file.open(this->repo_filename);
	if (!file.is_open())
	{
		throw InvalidFileException();
	}
	while (file >> tut)
	{
		this->array.push_back(tut);
	}
	file.close();
	if (file.is_open())
	{
		throw FileStillOpenException();
	}
}


template <class TElem>
void Repository<TElem>::write_data_to_file()
{
	ofstream file;
	file.open(this->repo_filename);
	if (!file.is_open())
	{
		throw InvalidFileException();
	}
	for (auto obj : this->array)
	{
		file << obj<<'\n';
	}
	file.close();
	if (file.is_open())
	{
		throw FileStillOpenException();
	}
}

template<typename TElem>
std::string Repository<TElem>::get_filename()
{
	return this->repo_filename;
}


void test_repo();