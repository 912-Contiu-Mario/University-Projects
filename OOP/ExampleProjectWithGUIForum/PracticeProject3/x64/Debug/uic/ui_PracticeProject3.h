/********************************************************************************
** Form generated from reading UI file 'PracticeProject3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICEPROJECT3_H
#define UI_PRACTICEPROJECT3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticeProject3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticeProject3Class)
    {
        if (PracticeProject3Class->objectName().isEmpty())
            PracticeProject3Class->setObjectName("PracticeProject3Class");
        PracticeProject3Class->resize(600, 400);
        menuBar = new QMenuBar(PracticeProject3Class);
        menuBar->setObjectName("menuBar");
        PracticeProject3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticeProject3Class);
        mainToolBar->setObjectName("mainToolBar");
        PracticeProject3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(PracticeProject3Class);
        centralWidget->setObjectName("centralWidget");
        PracticeProject3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PracticeProject3Class);
        statusBar->setObjectName("statusBar");
        PracticeProject3Class->setStatusBar(statusBar);

        retranslateUi(PracticeProject3Class);

        QMetaObject::connectSlotsByName(PracticeProject3Class);
    } // setupUi

    void retranslateUi(QMainWindow *PracticeProject3Class)
    {
        PracticeProject3Class->setWindowTitle(QCoreApplication::translate("PracticeProject3Class", "PracticeProject3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PracticeProject3Class: public Ui_PracticeProject3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICEPROJECT3_H
