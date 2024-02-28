/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QSpinBox *spinBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QListView *questionView;
    QListWidget *answersWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *addQuestionButton;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *addAnswerButton;
    QPushButton *searchButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(828, 589);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(590, 150, 101, 21));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        questionView = new QListView(widget);
        questionView->setObjectName("questionView");

        horizontalLayout_3->addWidget(questionView);

        answersWidget = new QListWidget(widget);
        answersWidget->setObjectName("answersWidget");

        horizontalLayout_3->addWidget(answersWidget);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        addQuestionButton = new QPushButton(widget);
        addQuestionButton->setObjectName("addQuestionButton");

        verticalLayout->addWidget(addQuestionButton);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout);

        addAnswerButton = new QPushButton(widget);
        addAnswerButton->setObjectName("addAnswerButton");

        verticalLayout_2->addWidget(addAnswerButton);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        searchButton = new QPushButton(widget);
        searchButton->setObjectName("searchButton");

        verticalLayout_3->addWidget(searchButton);


        horizontalLayout_5->addLayout(verticalLayout_3);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 828, 22));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName("statusBar");
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindowClass", "Question", nullptr));
        addQuestionButton->setText(QCoreApplication::translate("MainWindowClass", "Add Question", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowClass", "Answer", nullptr));
        addAnswerButton->setText(QCoreApplication::translate("MainWindowClass", "Add Answer", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindowClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
