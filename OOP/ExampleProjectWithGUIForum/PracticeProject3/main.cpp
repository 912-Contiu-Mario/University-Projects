
#include <QtWidgets/QApplication>
#include "ListModel.h"
#include "MainWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Service service(repo);
    QuestionModel* listModel = new QuestionModel(service);
    vector<MainWindow*> windows;
    vector<User> users = repo.getUsers();
    for (auto u : users)
    {
        MainWindow* mainWindow = new MainWindow(listModel, service,u);
        windows.push_back(mainWindow);
    }
    for (int i = 0; i < users.size(); i++)
        windows[i]->show();
    return a.exec();
}
