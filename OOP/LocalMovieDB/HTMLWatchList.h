#pragma once
#include "WatchList.h"

class HTMLWatchList: public WatchList {
public:

	HTMLWatchList(std::string filename, std::string user_data_filenmame);
	void write_to_file() override;
	void display_watchlist() override;
};