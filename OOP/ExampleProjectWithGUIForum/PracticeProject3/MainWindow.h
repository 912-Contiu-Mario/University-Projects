#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "ListModel.h"
#include "SearchWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QuestionModel* model, Service& serv,User u, QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	Service& service;
	QuestionModel* model;
	void initWindow();
	void connectSignalsandSlots();
	void itemClicked();
	void addQuestion();
	void addAnswer();
	void update(vector<Answer> answers);
	int getIndex();
	void searchWindowStart();
	void updateSpinbox();
	void updateValue();
	User user;
	
};
