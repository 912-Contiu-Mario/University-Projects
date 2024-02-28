#include "MainWindow.h"

MainWindow::MainWindow(QuestionModel* model,Service& serv,User u,QWidget *parent)
	: QMainWindow(parent), service{serv}, model{model}, user{u}
{
	ui.setupUi(this);
	initWindow();
}

MainWindow::~MainWindow()
{}

void MainWindow::initWindow()
{
	service.sortQuestion();
	ui.questionView->setModel(this->model);
	connectSignalsandSlots();
	ui.spinBox->setMaximum(99999);
}


void MainWindow::connectSignalsandSlots()
{
	QObject::connect(ui.questionView, &QListView::clicked, this, &MainWindow::itemClicked);
	QObject::connect(ui.addQuestionButton, &QPushButton::clicked, this, &MainWindow::addQuestion);
	QObject::connect(ui.addAnswerButton, &QPushButton::clicked, this, &MainWindow::addAnswer);
	QObject::connect(ui.searchButton, &QPushButton::clicked, this, &MainWindow::searchWindowStart);
	QObject::connect(ui.spinBox, &QSpinBox::valueChanged, this, &MainWindow::updateValue);
	QObject::connect(ui.answersWidget, &QListWidget::itemSelectionChanged, this, &MainWindow::updateSpinbox);
}

void MainWindow::itemClicked()
{
	int index = ui.questionView->currentIndex().row();
	Question question = this->service.getRepo().getQuestions()[index];
	vector<Answer> answers = service.getAnswers(question);
	update(answers);
}

void MainWindow::addQuestion()
{
	string text = ui.lineEdit->text().toStdString();
	string userName = this->user.getName();
	this->service.addQuestion(text, userName);
	this->model->emitSigal();
}

void MainWindow::addAnswer()
{
	int q_id = this->service.getRepo().getQuestions()[ui.questionView->currentIndex().row()].getId();
	string text = ui.lineEdit_2->text().toStdString();
	service.addAnswer(q_id, user.getName(), text);

	Question question = this->service.getRepo().getQuestions()[ui.questionView->currentIndex().row()];
	vector<Answer> answers = service.getAnswers(question);
	update(answers);
}

void MainWindow::update(vector<Answer> answers)
{
	ui.answersWidget->clear();
	sort(answers.begin(), answers.end(), [](Answer a1, Answer a2) {
		return a1.getVotes() > a2.getVotes(); }
	);
	for (auto i : answers)
	{
		ui.answersWidget->addItem(QString::fromStdString(i.toString()));
	}
}

int MainWindow::getIndex()
{
	return ui.answersWidget->currentRow();
}

void MainWindow::searchWindowStart()
{
	SearchWindow* search = new SearchWindow(this->service, this);
	search->show();
}

void MainWindow::updateSpinbox()
{
	Question q = this->service.getRepo().getQuestions()[ui.questionView->currentIndex().row()];
	vector<Answer> answers = this->service.getAnswers(q);
	sort(answers.begin(), answers.end(), [](Answer a1, Answer a2) {
		return a1.getVotes() > a2.getVotes(); }
	);
	Answer answer = answers[ui.answersWidget->currentRow()];

	ui.spinBox->setValue(answer.getVotes());
}

void MainWindow::updateValue()
{
	Answer& answer = this->service.getRepo().getAnswers()[ui.answersWidget->currentRow()];
	answer.setVotes(ui.spinBox->value());
}




