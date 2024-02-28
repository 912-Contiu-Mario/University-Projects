#pragma once

#include <QMainWindow>
#include "ui_GUI.h"
#include "Service.h"
#include <QMessageBox>

class mainWin : public QMainWindow, Observer
{
	Q_OBJECT

public:
	mainWin(Service& serv, Programmer& programmer, QWidget *parent = nullptr);
	void initGUI();
	void update();
	void connectSignalsandSlots();
	void addTask();
	void deleteTask();
	void startTask();
	void doneTask();
	void itemClicked();
	~mainWin();

private:
	Ui::GUIClass ui;
	Service& service;
	Programmer user;
};
