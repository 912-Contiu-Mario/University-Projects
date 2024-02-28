#include "GUI.h"
#include <QtWidgets/QApplication>
#include "TaskRepository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaskRepository repository("Programmers.txt", "Tasks.txt");
    Service serv(repository);
    vector<mainWin*> windows;
    for (auto it : serv.getTaskRepository().getAllProgrammers())
    {
        mainWin* window = new mainWin(serv, it);
        windows.push_back(window);
    }
    for (int i =0;i< serv.getTaskRepository().getAllProgrammers().size();i++)
    {
        windows[i]->show();
    }
    return a.exec();

}
