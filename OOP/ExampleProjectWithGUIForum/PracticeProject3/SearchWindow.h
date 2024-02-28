#pragma once

#include <QMainWindow>
#include "ui_SearchWindow.h"
#include "Service.h"

class SearchWindow : public QMainWindow
{
	Q_OBJECT

public:
	SearchWindow(Service& service, QWidget *parent = nullptr);
	~SearchWindow();

private:
	Ui::SearchWindowClass ui;
	void connectSignalsandSlots();
	void updateList();
	vector<Question> findBestMatching(string to_match);
	void showBest();
	Service& service;
	
};
