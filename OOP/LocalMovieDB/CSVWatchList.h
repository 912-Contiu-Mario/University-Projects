#pragma once
#include "WatchList.h"

class CSVWatchList: public WatchList
{
public:
	CSVWatchList(std::string filename, std::string user_data_filelist): WatchList(filename, user_data_filelist) {}
	void write_to_file() override;
	void display_watchlist() override;
};