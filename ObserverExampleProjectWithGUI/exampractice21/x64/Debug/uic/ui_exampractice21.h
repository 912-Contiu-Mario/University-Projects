/********************************************************************************
** Form generated from reading UI file 'exampractice21.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPRACTICE21_H
#define UI_EXAMPRACTICE21_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exampractice21Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *exampractice21Class)
    {
        if (exampractice21Class->objectName().isEmpty())
            exampractice21Class->setObjectName("exampractice21Class");
        exampractice21Class->resize(600, 400);
        menuBar = new QMenuBar(exampractice21Class);
        menuBar->setObjectName("menuBar");
        exampractice21Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(exampractice21Class);
        mainToolBar->setObjectName("mainToolBar");
        exampractice21Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(exampractice21Class);
        centralWidget->setObjectName("centralWidget");
        exampractice21Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(exampractice21Class);
        statusBar->setObjectName("statusBar");
        exampractice21Class->setStatusBar(statusBar);

        retranslateUi(exampractice21Class);

        QMetaObject::connectSlotsByName(exampractice21Class);
    } // setupUi

    void retranslateUi(QMainWindow *exampractice21Class)
    {
        exampractice21Class->setWindowTitle(QCoreApplication::translate("exampractice21Class", "exampractice21", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exampractice21Class: public Ui_exampractice21Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPRACTICE21_H
