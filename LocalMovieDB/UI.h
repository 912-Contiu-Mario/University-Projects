#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
public:
	UI(Service& service);
	void delete_admin();
	void user_menu();
	void user_type_menu_entries();
	void administrator_menu();
	void administrator_menu_entries();
	void start_menu();
	void update_menu_entries();
	void update_admin();
	void add_admin();
	void see_tutorial_presenter();
	void delete_user();
	Service& get_service();
};