/********************************************************************************
** Form generated from reading UI file 'SearchWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

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

class Ui_SearchWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *SearchPushButton;
    QListWidget *searchListWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SearchWindowClass)
    {
        if (SearchWindowClass->objectName().isEmpty())
            SearchWindowClass->setObjectName("SearchWindowClass");
        SearchWindowClass->resize(600, 400);
        centralWidget = new QWidget(SearchWindowClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        searchLineEdit = new QLineEdit(centralWidget);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        SearchPushButton = new QPushButton(centralWidget);
        SearchPushButton->setObjectName("SearchPushButton");

        horizontalLayout->addWidget(SearchPushButton);


        verticalLayout->addLayout(horizontalLayout);

        searchListWidget = new QListWidget(centralWidget);
        searchListWidget->setObjectName("searchListWidget");

        verticalLayout->addWidget(searchListWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        SearchWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SearchWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        SearchWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SearchWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        SearchWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SearchWindowClass);
        statusBar->setObjectName("statusBar");
        SearchWindowClass->setStatusBar(statusBar);

        retranslateUi(SearchWindowClass);

        QMetaObject::connectSlotsByName(SearchWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SearchWindowClass)
    {
        SearchWindowClass->setWindowTitle(QCoreApplication::translate("SearchWindowClass", "SearchWindow", nullptr));
        SearchPushButton->setText(QCoreApplication::translate("SearchWindowClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWindowClass: public Ui_SearchWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
