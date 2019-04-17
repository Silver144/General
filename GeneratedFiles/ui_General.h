/********************************************************************************
** Form generated from reading UI file 'General.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERAL_H
#define UI_GENERAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeneralClass)
    {
        if (GeneralClass->objectName().isEmpty())
            GeneralClass->setObjectName(QStringLiteral("GeneralClass"));
        GeneralClass->resize(600, 400);
        menuBar = new QMenuBar(GeneralClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GeneralClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeneralClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GeneralClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GeneralClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GeneralClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GeneralClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GeneralClass->setStatusBar(statusBar);

        retranslateUi(GeneralClass);

        QMetaObject::connectSlotsByName(GeneralClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeneralClass)
    {
        GeneralClass->setWindowTitle(QApplication::translate("GeneralClass", "General", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralClass: public Ui_GeneralClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAL_H
