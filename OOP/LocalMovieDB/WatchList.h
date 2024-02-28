#include "Repository.h"
#pragma once
class WatchList: public Repository<TElem> {
protected:
	std::string filename;
public:
	WatchList(std::string filename, std::string user_data_filename);
	virtual void write_to_file() = 0;
	virtual void display_watchlist() = 0;
};