#include "Repository.h"


void test_add_element_repo()
{
	Duration duration(56, 55);
	Repository<Tutorial>  repo;
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	repo.add_element(tutorial);
	assert(repo.get_vector()[0].get_title()=="What is a pointer");
	assert(repo.get_vector()[0].get_presenter() == "Arabara");
	assert(repo.get_vector()[0].get_duration() == duration);
	assert(repo.get_vector()[0].get_likes() == 500);
	assert(repo.get_vector()[0].get_link() == "www.google.com");
}

void test_delete_element_repo()
{
	Duration duration(56, 55);
	Duration duration1(55, 55);
	Repository<Tutorial>  repo;
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	Tutorial tutorial1("What is apointer", "Arabara", duration1, 500, "www.google.com");
	repo.add_element(tutorial);
	repo.add_element(tutorial1);
	repo.delete_element(tutorial);
	assert(repo.get_vector()[0].get_title() == "What is apointer");
	assert(repo.get_vector()[0].get_presenter() == "Arabara");
	assert(repo.get_vector()[0].get_duration() == duration1);
	assert(repo.get_vector()[0].get_likes() == 500);
	assert(repo.get_vector()[0].get_link() == "www.google.com");
	assert(repo.get_vector().size() == 1);

}

void test_update_element_repo()
{
	Repository<Tutorial>  repo;
	Duration duration(56, 55);
	Duration duration1(33, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	Tutorial tutorial1("What is NULL apointer", "RhabuDhabi", duration1, 100, "www.youtube.com");
	repo.add_element(tutorial);
	repo.update_element(tutorial, tutorial1);
	assert(repo.get_vector()[0].get_title() == "What is NULL apointer");
	assert(repo.get_vector()[0].get_presenter() == "RhabuDhabi");
	assert(repo.get_vector()[0].get_duration() == duration1);
	assert(repo.get_vector()[0].get_likes() == 100);
	assert(repo.get_vector()[0].get_link() == "www.youtube.com");
}


void test_search_tutorial()
{
	Repository<Tutorial>  repo;
	Duration duration(56, 55);
	Duration duration1(33, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	Tutorial tutorial1("What is NULL apointer", "RhabuDhabi", duration1, 100, "www.youtube.com");
	repo.add_element(tutorial);
	repo.add_element(tutorial1);
	string str = "What is a pointer";
	string str1 = "Arabara";
	assert(repo.search_tutorial(str,  str1) == tutorial);
	str = "What is NULL apointer";
	str1 = "RhabuDhabi";
	assert(repo.search_tutorial(str, str1) == tutorial1);
}

void test_repo_to_string()
{
	Repository<Tutorial>  repo;
	Duration duration(56, 55);
	Duration duration1(33, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	repo.add_element(tutorial);
	string str = "Title: What is a pointer | Presenter: Arabara | Duration: 56:55 | Likes: 500 | Link: www.google.com\n";\
	assert(repo.repo_array_to_string() == str);

}
void test_find_element_position()
{
	Repository<Tutorial> repo;
	Duration duration(56, 55);
	Duration duration1(33, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	Tutorial tutorial1("What is NULL apointer", "RhabuDhabi", duration1, 100, "www.youtube.com");
	repo.add_element(tutorial);
	assert(repo.find_element_position(tutorial) == 0);
	repo.add_element(tutorial1);
	assert(repo.find_element_position(tutorial1) == 1);
	
}

void test_search_tut_by_pres()
{
	Repository<Tutorial> repo;
	Tutorial array[4];
	Duration duration(56, 55);
	Duration duration1(33, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	Tutorial tutorial1("What is NULL apointer", "Arabara", duration1, 100, "www.youtube.com");
	repo.add_element(tutorial);
	repo.add_element(tutorial1);
	string str = "Arabara";
	int length = repo.search_tut_by_pres(str, array);
	assert(array[0] == tutorial);
	assert(array[1] == tutorial1);
	assert(length == 2);


}

void test_read_from_file()
{
	/*What is a pointer | RhabuDhabi | 22 33 | 1000 | www.sadada.com
	What is a NULL poitner | Marian | 33 55 | 2000 | www.braras.com*/
	Repository<TElem> repo("test.txt");
	assert(repo.get_vector()[0].get_title() == "What is a pointer");
	assert(repo.get_vector()[0].get_presenter() == "RhabuDhabi");
	assert(repo.get_vector()[0].get_duration().get_minutes() == 22);
	assert(repo.get_vector()[0].get_duration().get_seconds() == 33);
	assert(repo.get_vector()[0].get_likes() == 1000);
	assert(repo.get_vector()[0].get_link() == "www.sadada.com");

	assert(repo.get_vector()[1].get_title() == "What is a NULL poitner");
	assert(repo.get_vector()[1].get_presenter() == "Marian");
	assert(repo.get_vector()[1].get_duration().get_minutes() == 33);
	assert(repo.get_vector()[1].get_duration().get_seconds() == 55);
	assert(repo.get_vector()[1].get_likes() == 2000);
	assert(repo.get_vector()[1].get_link() == "www.braras.com");
}

void test_write_to_file()
{
	Repository<TElem> repo("test1.txt");
	Duration duration(56, 55);
	Duration duration1(33, 55);
	Tutorial tutorial("What is a pointer", "Arabara", duration, 500, "www.google.com");
	Tutorial tutorial1("What is NULL apointer", "RhabuDhabi", duration1, 100, "www.youtube.com");
	repo.add_element(tutorial);
	repo.add_element(tutorial1);
	repo.write_data_to_file();
	Repository<TElem> repo1("test1.txt");
	assert(repo1.get_vector()[0].get_title() == "What is a pointer");
	assert(repo1.get_vector()[0].get_presenter() == "Arabara");
	assert(repo1.get_vector()[0].get_duration().get_minutes() == 56);
	assert(repo1.get_vector()[0].get_duration().get_seconds() == 55);
	assert(repo1.get_vector()[0].get_likes() == 500);
	assert(repo1.get_vector()[0].get_link() == "www.google.com");
}
void test_repo()
{
	test_add_element_repo();
	test_update_element_repo();
	test_delete_element_repo();
	test_search_tutorial();
	test_repo_to_string();
	test_find_element_position();
	test_search_tut_by_pres();
	test_read_from_file();
	test_write_to_file();
}
