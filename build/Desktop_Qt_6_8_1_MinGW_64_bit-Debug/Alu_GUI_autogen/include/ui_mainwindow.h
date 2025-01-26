/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *aInput;
    QLineEdit *bInput;
    QPushButton *computeButton;
    QLabel *resultLabel;
    QComboBox *opcodeInput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(452, 479);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        aInput = new QLineEdit(centralwidget);
        aInput->setObjectName("aInput");
        aInput->setGeometry(QRect(30, 70, 113, 28));
        bInput = new QLineEdit(centralwidget);
        bInput->setObjectName("bInput");
        bInput->setGeometry(QRect(30, 120, 113, 28));
        computeButton = new QPushButton(centralwidget);
        computeButton->setObjectName("computeButton");
        computeButton->setGeometry(QRect(160, 180, 83, 29));
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(300, 110, 91, 51));
        opcodeInput = new QComboBox(centralwidget);
        opcodeInput->setObjectName("opcodeInput");
        opcodeInput->setGeometry(QRect(40, 180, 82, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 452, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        aInput->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        bInput->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        computeButton->setText(QCoreApplication::translate("MainWindow", "Compute", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
