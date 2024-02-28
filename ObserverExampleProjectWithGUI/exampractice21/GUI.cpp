#include "GUI.h"

mainWin::mainWin(Service& serv,Programmer& programmer, QWidget *parent)
	: QMainWindow(parent), service{serv}, user{programmer}
{
	ui.setupUi(this);
	initGUI();
}

void mainWin::initGUI()
{
	service.addObserver(this);
	update();
	connectSignalsandSlots();

	this->setWindowTitle(QString::fromStdString(user.getName()));
	ui.doneTaskButton->setEnabled(false);
}

void mainWin::update()
{
	service.sortTasks();
	ui.taskWidget->clear();
	vector<Task>& tasks = this->service.getTaskRepository().getAllTasks();
	for (auto task : tasks)
	{
		ui.taskWidget->addItem(QString::fromStdString(task.toString()));
	}
}

void mainWin::addTask()
{
	string description = ui.addTasklineEdit->text().toStdString();
	try {
		this->service.addTask(description, "open", 0);
	}
	catch (exception e) {
		QMessageBox::warning(nullptr, "Warning", e.what());
	}
}

void mainWin::deleteTask()
{
	int index = ui.taskWidget->currentRow();
	service.removeTask(index);
}

void mainWin::startTask()
{
	int index = ui.taskWidget->currentRow();
	service.startTask(index, user.getId());
}

void mainWin::doneTask()
{
	int index = ui.taskWidget->currentRow();
	service.doneTask(index, user.getId());
}


void mainWin::itemClicked()
{
	int index = ui.taskWidget->currentRow();
	if (service.getTaskRepository().getAllTasks()[index].getStatus() == "In progress")
		ui.doneTaskButton->setEnabled(true);
	else 		
		ui.doneTaskButton->setEnabled(false);

}
void mainWin::connectSignalsandSlots()
{
	QObject::connect(this->ui.addTaskButton, &QPushButton::clicked,this, &mainWin::addTask);
	QObject::connect(this->ui.taskWidget, &QListWidget::itemSelectionChanged, this, &mainWin::itemClicked);
	QObject::connect(this->ui.removeTaskButton, &QPushButton::clicked, this, &mainWin::deleteTask);
	QObject::connect(this->ui.startTaskButton, &QPushButton::clicked, this, &mainWin::startTask);
	QObject::connect(this->ui.doneTaskButton, &QPushButton::clicked, this, &mainWin::doneTask);

}





mainWin::~mainWin()
{}
