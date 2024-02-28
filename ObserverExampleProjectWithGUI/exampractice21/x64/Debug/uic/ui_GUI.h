/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QListWidget *taskWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *addTasklineEdit;
    QPushButton *addTaskButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *removeTaskButton;
    QPushButton *startTaskButton;
    QPushButton *doneTaskButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName("GUIClass");
        GUIClass->resize(724, 516);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName("centralWidget");
        taskWidget = new QListWidget(centralWidget);
        taskWidget->setObjectName("taskWidget");
        taskWidget->setGeometry(QRect(21, 11, 331, 421));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(380, 200, 321, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addTasklineEdit = new QLineEdit(widget);
        addTasklineEdit->setObjectName("addTasklineEdit");
        addTasklineEdit->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(addTasklineEdit);

        addTaskButton = new QPushButton(widget);
        addTaskButton->setObjectName("addTaskButton");
        addTaskButton->setMinimumSize(QSize(50, 30));
        addTaskButton->setBaseSize(QSize(10, 60));

        verticalLayout->addWidget(addTaskButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        removeTaskButton = new QPushButton(widget);
        removeTaskButton->setObjectName("removeTaskButton");

        horizontalLayout->addWidget(removeTaskButton);

        startTaskButton = new QPushButton(widget);
        startTaskButton->setObjectName("startTaskButton");

        horizontalLayout->addWidget(startTaskButton);

        doneTaskButton = new QPushButton(widget);
        doneTaskButton->setObjectName("doneTaskButton");

        horizontalLayout->addWidget(doneTaskButton);


        verticalLayout->addLayout(horizontalLayout);

        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 724, 22));
        GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUIClass);
        mainToolBar->setObjectName("mainToolBar");
        GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName("statusBar");
        GUIClass->setStatusBar(statusBar);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QCoreApplication::translate("GUIClass", "GUI", nullptr));
        addTaskButton->setText(QCoreApplication::translate("GUIClass", "Add", nullptr));
        removeTaskButton->setText(QCoreApplication::translate("GUIClass", "Remove", nullptr));
        startTaskButton->setText(QCoreApplication::translate("GUIClass", "Start", nullptr));
        doneTaskButton->setText(QCoreApplication::translate("GUIClass", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
