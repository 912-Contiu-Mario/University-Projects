#include "SearchWindow.h"

SearchWindow::SearchWindow(Service& serv, QWidget *parent):service{serv}, QMainWindow(parent)
{
	ui.setupUi(this);
	connectSignalsandSlots();
}

SearchWindow::~SearchWindow()
{}

void SearchWindow::connectSignalsandSlots()
{
	QObject::connect(ui.searchLineEdit, &QLineEdit::textChanged, this, &SearchWindow::updateList);
	QObject::connect(ui.SearchPushButton, &QPushButton::clicked, this, &SearchWindow::showBest);
}



void SearchWindow::updateList()
{
	string text = ui.searchLineEdit->text().toStdString();
	vector<Question> matched_questions = findBestMatching(text);
	ui.searchListWidget->clear();
	if(matched_questions.size()>0){

		for (auto q : matched_questions)
		{
			ui.searchListWidget->addItem(QString::fromStdString(q.toString()));
		}
	}
}

vector<Question> SearchWindow::findBestMatching(string to_match)
{
	vector<Question> questions = service.getRepo().getQuestions();
	int max = 0;
	Question found_q(0, "", "");
	vector<Question> matched_questions;
	for (Question q : questions)
	{
		int number = 0;
		string q_text = q.getText();
		int size = to_match.size();
		if (to_match.size() > q_text.size())
			size = q_text.size();
		for (int i = 0; i < size; i++)
		{
			if (to_match[i] == q_text[i])
				number++;
		}
		if (number > max)
		{
			max = number;
			found_q.setId(q.getId());
			found_q.setText(q.getText());
			found_q.setUserName(q.getUserName());
			matched_questions.clear();
			matched_questions.push_back(q);
		}
		else if (number == max)
		{
			matched_questions.push_back(q);
		}
	}
	return matched_questions;
}

void SearchWindow::showBest()
{
	string text = ui.searchLineEdit->text().toStdString();
	vector<Question> matched_questions = findBestMatching(text);
	Question best_match = matched_questions[0];
	ui.searchListWidget->clear();
	ui.searchListWidget->addItem(QString::fromStdString(best_match.toString()));
	vector<Answer> answers = service.getAnswers(best_match);
	sort(answers.begin(), answers.end(), [this](Answer a1, Answer a2)
		{
			return a1.getVotes() > a2.getVotes();
		});
	for (auto a : answers)
	{
		ui.searchListWidget->addItem(QString::fromStdString(a.toString()));
	}
}

